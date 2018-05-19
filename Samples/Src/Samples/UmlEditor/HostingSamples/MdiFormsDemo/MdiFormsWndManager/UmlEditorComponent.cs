// UmlEditorComponent.cs
/*
 * Copyright (c) 2005 Alexey Shalnov
 * All Rights Reserved
 * 
 * http://home.arcor.de/alexeyshalnov/home/
*/

using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Drawing.Design;
using System.Data;
using System.Windows.Forms;
using System.Windows.Forms.Design;
using System.Diagnostics;
using System.ComponentModel.Design;
using System.ComponentModel.Design.Serialization ;
using System.Globalization;
using System.Reflection;
using System.CodeDom;

using AS.UmlEditor;

namespace AS.MfcHost
{
	/// <summary>
	/// UmlEditorComponent provides "CommandName" property for ToolStripMenuItem and ToolStripButton.
	/// With this property you can assign command from enum "MfcCommand" which 
    /// would be processed in MDIWndManager by ToolStripMenuItem.Click or ToolStripButton.Click.
	/// Assigned command would be update Enabled, Text, Checked, RadioCheck properties
    /// of ToolStripMenuItem and Enabled, Text of ToolStripButton.
	/// 
	/// The UmlEditorComponent self has properties DocumentMenu, FrameMenu. You can define 
	/// different menu for document and frame (as for MDI application).
	/// 
	/// </summary>
    [
    ProvideProperty("CommandName", typeof(Component)),
    DesignerAttribute(typeof(HostInsertingComponentDesigner), typeof(IDesigner))
    ]
    public class UmlEditorComponent : Component, IExtenderProvider, ISupportInitialize
	{
		public enum MDIMenuType	{None,Document,Framework};
		
		// here we safe CommandName for every component(ToolStripMenuItem or ToolStripButton)
		private Hashtable m_ComandsTable = new Hashtable();

		private Form _Host = null;	        //property
	
		private ToolStrip m_ToolStrip = null;
        private MDIWndManager m_WndManager = null;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		public UmlEditorComponent()
		{

			InitializeComponent();

            // create WndManager
            m_WndManager = MDIWndManager.CreateInstance();

        }

		public UmlEditorComponent(IContainer container):this()
		{
			if(container != null)
			{
				container.Add(this);
			}
		}
		
		/// <summary> 
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if(components != null)
				{
					components.Dispose();
				}
			}
            
            m_WndManager.Dispose();

			base.Dispose( disposing );
		}

		#region Component Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			components = new System.ComponentModel.Container();
		}
		#endregion

		#region UmlEditorComponent Properties
        
        public MenuStrip FrameMenu
		{
			get	{return m_WndManager.FrameMenu;}
			set	{m_WndManager.FrameMenu=value;}
		}

        public MenuStrip DocumentMenu
		{
			get	{return m_WndManager.DocumentMenu;}
			set	{m_WndManager.DocumentMenu=value;}
		}

		[Browsable(false)]
		public Form Host
		{
			get	{return _Host;}
			set	
			{
				_Host = value;
				if(!this.DesignMode)
				{
					Debug.Assert(_Host != null,"UmlEditorComponent has not defined Parent Form");
					
                    // Initiate MFC application
					m_WndManager.InitMfc(_Host);
					
					_Host.Load += new EventHandler(MainFrame_Load);
					
				}
			}
		}
		#endregion
		
		#region IExtenderProvider Members
		
		// we can extend properties ToolStripMenuItem and ToolStripButton only
		bool IExtenderProvider.CanExtend(object target) 
		{
            if (target is ToolStripMenuItem)
            {
                ToolStripMenuItem item = (ToolStripMenuItem) target;
                // Not extend PopUp MenuItems:
                // In DesignMode disigner adds empty ToolStripMenuItem
                // So PopUp items have more then one DropDownItems
                if (item.DropDownItems.Count < 2)
                    return true;
                else
                    return false;
            }
            else if (target is ToolStripButton)
                return true;

			return false;
		}

        [
        Category("Command Engine")
        , DefaultValue(MfcCommand.None)
        , Description("Gets or Sets the UmlEditor Command Name")
        , EditorAttribute(typeof(DropDownEnumEditor<MfcCommand>), typeof(UITypeEditor))
        ]
        public MfcCommand GetCommandName(Component component)
        {
            if (m_ComandsTable.Contains(component))
                return (MfcCommand)m_ComandsTable[component];
            else
                return MfcCommand.None;
        }
        public void SetCommandName(Component component, MfcCommand value)
        {
            if (value == MfcCommand.None)
            {
                m_ComandsTable.Remove(component);
            }
            else
            {
                m_ComandsTable[component] = value;
            }
        }
		#endregion
		
		#region Handlers
		
		// we process some commands here
		private void InternalCmdHandler(object sender, EventArgs e) 
		{
			ToolStripMenuItem item = sender as ToolStripMenuItem;
			switch(GetCommandName(item))   
			{         
				case MfcCommand.FILE_PRINT_PREVIEW:   
					MessageBox.Show("m_MfcAppAdapter doesn't support File Print Preview");
					break;  
				case MfcCommand.APP_EXIT:   
					Host.Close();
					break;  
				case MfcCommand.FILE_CLOSE:   
					Host.ActiveMdiChild.Close();
					break;  
				case MfcCommand.WINDOW_ARRANGE:            
					Host.LayoutMdi(MdiLayout.ArrangeIcons);
					break;                  
				case MfcCommand.WINDOW_CASCADE:            
					Host.LayoutMdi(MdiLayout.Cascade);
					break;                  
				case MfcCommand.WINDOW_TILE_HORZ:            
					Host.LayoutMdi(MdiLayout.TileHorizontal);
					break;                  
				case MfcCommand.WINDOW_TILE_VERT:            
					Host.LayoutMdi(MdiLayout.TileVertical);
					break;                  
				case MfcCommand.VIEW_TOOLBAR:            
					
					// We have to sinchronize Toolbar with Toolbar button state
					if(item.Checked)
					{
						m_ToolStrip.Visible = false;
						item.Checked = false;
					}
					else
					{
						m_ToolStrip.Visible=true;
						item.Checked = true;
					}
					break;                  
			}
		}

		// Assigned command would be update some UI properties of ToolStripMenuItem and ToolStripButton.
		private void OnUpdateUI(object sender, EventArgs e)
		{
			bool IsRecentUpdated = false;

			ToolStripMenuItem item = sender as ToolStripMenuItem;
            if (item != null)
			{
                MfcCommand nID = GetCommandName(item);
				if(nID >= MfcCommand.FILE_MRU_FIRST && nID < MfcCommand.FILE_MRU_LAST)	// Update Recent menu items
				{
					// one time UpdateRecentItems
					if(IsRecentUpdated==false)
					{
                        UpdateRecentItems(item);
						IsRecentUpdated=true;
					}
				}
                // we set state of VIEW_TOOLBAR item externally
                else if (nID == MfcCommand.VIEW_TOOLBAR)
                { }
                else
					// update menu item in MFC application
                    m_WndManager.MfcAppAdapter.OnUpdateCmdMsg((int)nID, new MenuItemCmdUI(item));
			}
			else	// sender Application.Idle
			{
				IEnumerator iter = m_ComandsTable.Keys.GetEnumerator();
                while (iter.MoveNext() && iter.Current != null)
                {
                    if (iter.Current is ToolStripButton)
                    {
                        ToolStripButton pToolStripButton = (ToolStripButton)iter.Current;

                        // update ToolStripButton in MFC application
                        m_WndManager.MfcAppAdapter.OnUpdateCmdMsg((int)GetCommandName(pToolStripButton), new ButtonCmdUI(pToolStripButton));
                    }
                }
			}
		}
		private void UpdateRecentItems(ToolStripMenuItem item)
		{
            ToolStripMenuItem parent = (ToolStripMenuItem)item.OwnerItem;
			int first_index = parent.DropDownItems.IndexOf(item);

			// remove old recent items
			int collection_index = first_index;
			for(collection_index=first_index;collection_index < parent.DropDownItems.Count;)
			{
                MfcCommand RemoveId = GetCommandName(parent.DropDownItems[collection_index]);

				if(RemoveId==MfcCommand.None)
					break;

				if(RemoveId >= MfcCommand.FILE_MRU_FIRST && RemoveId < MfcCommand.FILE_MRU_LAST)
				{	
					// remove menu item from m_ComandsTable
                    SetCommandName(parent.DropDownItems[collection_index], MfcCommand.None);
					// remove menu item from PopUp menu
                    parent.DropDownItems.RemoveAt(collection_index);
				}
				else
					break;
			}

			// add new recent items
			collection_index = first_index;
			MfcCommand tmpID = MfcCommand.FILE_MRU_FILE1;
			
			// update recent items in MFC application
            m_WndManager.MfcAppAdapter.OnUpdateCmdMsg((int)tmpID, new MenuItemCmdUI(item));

			while(true)
			{
                string sRecentFile = m_WndManager.MfcAppAdapter.GetMfcMenuString((int)tmpID);
				if(sRecentFile=="")
					break;
				ToolStripMenuItem RecentMenuItem = new ToolStripMenuItem(sRecentFile);
                
                RecentMenuItem.Click += new EventHandler(OnClick);

                // add menu item to m_ComandsTable
				SetCommandName(RecentMenuItem,tmpID);

				if(RecentMenuItem.Text=="Recent File")
					RecentMenuItem.Enabled = false;
				
				// add menu item to PopUp menu
                parent.DropDownItems.Insert(collection_index++, RecentMenuItem);
				tmpID++;
			}
		}
		#endregion

		#region ISupportInitialize Members
		// we have to set handlers for Popup (ToolStripMenuItem) and ButtonClick (ToolStripButton) events
		// in EndInit()
		public void BeginInit(){}
		public void EndInit()
		{
			if(!this.DesignMode)
			{
				IEnumerator iter = m_ComandsTable.Keys.GetEnumerator();
				while( iter.MoveNext() && iter.Current!=null)
				{
					if(iter.Current is ToolStripMenuItem)
					{
						ToolStripMenuItem item = (ToolStripMenuItem)(iter.Current);
                        item.Paint += new PaintEventHandler(item_Paint);
                        switch ((MfcCommand)m_ComandsTable[iter.Current])
                        {
                            case MfcCommand.APP_EXIT:
                            case MfcCommand.FILE_CLOSE:
                            case MfcCommand.WINDOW_ARRANGE:
                            case MfcCommand.WINDOW_CASCADE:
                            case MfcCommand.WINDOW_TILE_HORZ:
                            case MfcCommand.WINDOW_TILE_VERT:
                            case MfcCommand.VIEW_TOOLBAR:
                            case MfcCommand.FILE_PRINT_PREVIEW:
                                item.Click += new EventHandler(InternalCmdHandler);
                                break;
                            default:
                                item.Click += new EventHandler(OnClick);
                                break;
                        }
                    }
					else if(iter.Current is ToolStripButton)
					{
  						ToolStripButton button = (ToolStripButton)iter.Current;

                        if (m_ToolStrip == null)
                        {
                            // init UpdateUI event for ToolStrip  
                            Application.Idle += new EventHandler(OnUpdateUI);
                             
                            m_ToolStrip = button.GetCurrentParent();
                        }
                        button.Click += new EventHandler(OnClick);
					}
				}
			}
		}

        void item_Paint(object sender, PaintEventArgs e)
        {
            OnUpdateUI(sender, e);
        }

        private void OnClick(object sender, EventArgs e)
        {
            MfcCommand id = GetCommandName(sender as Component);
            bool bRes = m_WndManager.MfcAppAdapter.OnCmdMsg((int)id);

            if (bRes && (id == MfcCommand.FILE_NEW
            || id == MfcCommand.FILE_OPEN
            || id == MfcCommand.WINDOW_NEW
            || (id >= MfcCommand.FILE_MRU_FIRST && id < MfcCommand.FILE_MRU_LAST)))
            {
                AttachCreatedView();
            }
        }

		private void AttachCreatedView()
        {
            ViewCtrl ctrl = new ViewCtrl();
            ctrl.BuildWindow(AS.UmlEditor.ModuleState.GetModuleState(),
            m_WndManager.MfcAppAdapter.GetCreatedView());
            m_WndManager.AttachCtrl(ctrl, ctrl.ClosingDelegate);
        }
		private void MainFrame_Load(object sender, EventArgs e)
		{
 		    // we create New Document by start as in MFC application
            m_WndManager.MfcAppAdapter.OnCmdMsg((int)MfcCommand.FILE_NEW);
            AttachCreatedView();
        }

		#endregion
	}

    /// <summary>
    /// This class makes setting of the Host for UmlEditorComponent 
    /// when a UmlEditorComponent dropped on a Form Designer.
    /// </summary>
    public class HostInsertingComponentDesigner : System.ComponentModel.Design.ComponentDesigner
    {
        public override void Initialize(System.ComponentModel.IComponent component)
        {
            base.Initialize(component);

            IDesignerHost designerHost = (IDesignerHost)this.GetService(typeof(IDesignerHost));

            Form host = designerHost.RootComponent as Form;
            if (host == null)
                throw (new ApplicationException("A UmlEditorComponent can only be dropped on a Form Designer"));

            UmlEditorComponent UmlEditorComponent = component as UmlEditorComponent;
            UmlEditorComponent.Host = host;

        }
    }

    /// <summary>
    /// DropDownEnumEditor realisation of the UITypeEditor for enumeration type (Generic parameter).
    /// We use this editor, because standard editor doesn't make Sort by Name
    /// </summary>
    [System.Security.Permissions.PermissionSet(System.Security.Permissions.SecurityAction.Demand, Name = "FullTrust")]
    public class DropDownEnumEditor <T> : System.Drawing.Design.UITypeEditor
    {
        private bool m_IsEditorOpened;
        private IWindowsFormsEditorService m_edSvc;

        public override System.Drawing.Design.UITypeEditorEditStyle GetEditStyle(System.ComponentModel.ITypeDescriptorContext context)
        {
            // Indicates that this editor can display a control-based 
            // drop-down interface.
            return UITypeEditorEditStyle.DropDown;
        }

        public override object EditValue(System.ComponentModel.ITypeDescriptorContext context, System.IServiceProvider provider, object value)
        {
            // Attempts to obtain an IWindowsFormsEditorService.
            m_edSvc = (IWindowsFormsEditorService)provider.GetService(typeof(IWindowsFormsEditorService));
            if (m_edSvc == null)
                return value;

            // Displays a drop-down control.
            ListBox listBox = new ListBox();
            m_IsEditorOpened = true;
            string[] names = Enum.GetNames(typeof(T));
            listBox.Items.AddRange(names);
            listBox.Sorted = true;
            listBox.SelectedIndex = listBox.Items.IndexOf(Enum.GetName(typeof(T), value));
            listBox.DoubleClick += new EventHandler(ListBox_DoubleClick);

            m_edSvc.DropDownControl(listBox);
            if (m_IsEditorOpened)
                m_edSvc.CloseDropDown();

            return (T)Enum.Parse(typeof(T), (string)listBox.SelectedItem);
        }

        void ListBox_DoubleClick(object sender, EventArgs e)
        {
            m_edSvc.CloseDropDown();
            m_IsEditorOpened = false;
        }
    }
}
