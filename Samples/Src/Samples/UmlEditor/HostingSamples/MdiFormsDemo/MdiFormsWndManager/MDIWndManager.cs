// MDIWndManager.cs
/*
 * Copyright (c) 2005 Alexey Shalnov
 * All Rights Reserved
 * 
 * http://home.arcor.de/alexeyshalnov/home/
*/

using System;
using System.ComponentModel;
using System.Windows.Forms;
using System.Reflection;

namespace AS.MfcHost
{
	/// <summary>
	/// MDIWndManager is IWndManager interface realisation for 
	/// MDI framework. It attach WinForms Control to child form 
	/// and support update menu by Document open.
	/// </summary>
	internal class MDIWndManager : AS.MfcHost.IWndManager,IDisposable
	{
        private Form _Host = null;  //property
        private MenuStrip _FrameMenu = null; //property
        private MenuStrip _DocumentMenu = null; //property
        private MfcAppAdapter _MfcAppAdapter = null; //property
        private static MDIWndManager WndManager = null;

        private MDIWndManager() 
        {
        }

        internal static MDIWndManager CreateInstance()
        {
            if (WndManager == null)
            {
                WndManager = new MDIWndManager();
            }
            return WndManager;
        }

        #region MDIWndManager Properties
        internal MenuStrip FrameMenu
		{
			get	{return _FrameMenu;}
			set	{_FrameMenu=value;}
		}
        internal MenuStrip DocumentMenu
		{
			get	{return _DocumentMenu;}
			set	{_DocumentMenu=value;}
		}
		private Form Host
		{
			get	{return _Host;}
		}
        internal void InitMfc(Form host)
        {
            _Host = host;
			_Host.IsMdiContainer=true;

			// if FrameMenu and DocumentMenu defined, we have to support update menu
			_Host.Load+=new EventHandler(menu_Update);

            // start  init of MFC application.

            _MfcAppAdapter = AS.MfcHost.MfcAppAdapter.GetMfcAppAdapter(AS.UmlEditor.ModuleState.GetModuleState(), host.Handle);

        }
        internal MfcAppAdapter MfcAppAdapter
        {
            get { return _MfcAppAdapter; }
        }

        internal void AttachCtrl(Control ctrl, CancelEventHandler OnClosing)
        {
            ctrl.Dock = DockStyle.Fill;
            Form form = new Form();
            form.Controls.Add(ctrl);
            ctrl.TextChanged += new EventHandler(ctrl_TextChanged);
            form.MdiParent = Host;
            form.Text = ctrl.Text;
            form.Closing += OnClosing;

            //form with unmanaged resource has to be dispose by close!
            form.Closed += new EventHandler(form_Closed);
            if (FrameMenu != null && DocumentMenu != null)
            {
                Host.MainMenuStrip = DocumentMenu;
                FrameMenu.Visible = false;
                DocumentMenu.Visible = true;
            }
            form.Show();
        }

        internal System.IntPtr GetExternFrame()
        {
            return Host.Handle;
        }
		#endregion

        #region IDisposable Members

        public void Dispose()
        {
            // Only if all attached ViewCtrl controls are closed to this time we can carefull terminate 
            // Legacy Application !!!
            if (_MfcAppAdapter != null)
            {
                _MfcAppAdapter.Dispose();
                _MfcAppAdapter = null;
            }
        }

        #endregion

		#region IWndManager realisation
        public void Activate(Control ctrl)
        {
            Form form = ctrl.FindForm();
            System.Diagnostics.Debug.Assert(form != null, "Can not find container Form");
            if (form != null)
                form.Activate();
	    }
		#endregion
		
		#region Handlers
		private void menu_Update(object sender, EventArgs e)
		{
            if ((Host.MdiChildren.Length < 1) && FrameMenu != null)
            {
                Host.MainMenuStrip = FrameMenu;
                DocumentMenu.Visible = false;
                FrameMenu.Visible = true;
            }
            else if ((_Host.MdiChildren.Length >= 1) && DocumentMenu != null)
            {
                Host.MainMenuStrip = DocumentMenu;
                FrameMenu.Visible = false;
                DocumentMenu.Visible = true;
            }

		}
		/// By close application WndManager must dispose all windows with attached ViewCtrl
		/// before legacy application terminate. In our case we call form.Dispose() 
		/// by MDI child windows Closed event. 
		private void form_Closed(object sender, EventArgs e)
		{
			Form form = sender as Form;
            form.Dispose();
			menu_Update(sender,e);
		}

		private void ctrl_TextChanged(object sender, EventArgs e)
		{
			Control ctrl = sender as Control;
			if (ctrl!=null)
				ctrl.Parent.Text=ctrl.Text;
		}
		#endregion

    }
}
