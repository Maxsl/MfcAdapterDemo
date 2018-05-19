using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Reflection;
using System.Diagnostics;

using AS.MfcHost;

namespace AS.FormsDemo
{
    public partial class MainForm : Form
    {
        MfcAppAdapter UmlEditor;
        MfcAppAdapter DlgEditor;
        ViewCtrl ctrl1;
        ViewCtrl ctrl2;
        RichTextBox richTextBox1;
        RichTextBox richTextBox2;
        
        public MainForm()
        {
            InitializeComponent();
            components = new Container();
            this.Load += new EventHandler(Form1_Load);
        }


        void Form1_Load(object sender, EventArgs e)
        {
            Application.Idle += new EventHandler(OnUpdateUI);
            this.panel1.SuspendLayout();
            try
            {
                Size prefSize;

                DlgEditor = AS.MfcHost.MfcAppAdapter.GetMfcAppAdapter(AS.DlgEditor.ModuleState.GetModuleState(), this.Handle);
                DlgEditor.OpenDocument("DLGEDI1.dlg",1);
                ctrl2 = new ViewCtrl();
                ctrl2.BuildWindow(DlgEditor.GetModuleState(), DlgEditor.GetCreatedView());
                this.Closing += ctrl2.ClosingDelegate;
                ctrl2.AutoSize = true;
                ctrl2.Dock = DockStyle.Top;
                this.panel1.Controls.Add(ctrl2);
                prefSize = ctrl2.GetPreferredSize(new Size(0, 0));
                ctrl2.ClientSize = new Size(prefSize.Width, prefSize.Height);
                ctrl2.MaximumSize = ctrl2.Size;
                ctrl2.MinimumSize = ctrl2.Size;


                richTextBox2 = new RichTextBox();
                richTextBox2.LoadFile("FormsDemo2.rtf");
                richTextBox2.ScrollBars = RichTextBoxScrollBars.None;
                richTextBox2.ContentsResized += new ContentsResizedEventHandler(richTextBox_ContentsResized);
                richTextBox2.Dock = DockStyle.Top;
                richTextBox2.BorderStyle = BorderStyle.None;
                this.panel1.Controls.Add(richTextBox2);

                UmlEditor = AS.MfcHost.MfcAppAdapter.GetMfcAppAdapter(AS.UmlEditor.ModuleState.GetModuleState(), this.Handle);
                UmlEditor.OpenDocument("UMLEDI1.uml",1);
                ctrl1 = new ViewCtrl();
                ctrl1.BuildWindow(UmlEditor.GetModuleState(), UmlEditor.GetCreatedView());
                this.Closing += ctrl1.ClosingDelegate;
                ctrl1.AutoSize = true;
                ctrl1.Dock = DockStyle.Top;
                this.panel1.Controls.Add(ctrl1);
                prefSize = ctrl1.GetPreferredSize(new Size(0, 0));
                ctrl1.ClientSize = new Size(prefSize.Width, prefSize.Height);
                ctrl1.MaximumSize = ctrl1.Size;
                ctrl1.MinimumSize = ctrl1.Size;

                richTextBox1 = new RichTextBox();
                richTextBox1.LoadFile("FormsDemo1.rtf");
                richTextBox1.ScrollBars = RichTextBoxScrollBars.None;
                richTextBox1.ContentsResized += new ContentsResizedEventHandler(richTextBox_ContentsResized);
                richTextBox1.Dock = DockStyle.Top;
                richTextBox1.BorderStyle = BorderStyle.None;
                this.panel1.Controls.Add(richTextBox1);
            }
            catch (Exception ex)
            {
                if (ex is System.IO.FileNotFoundException || ex is System.FormatException)
                {
                    MessageBoxButtons buttons = MessageBoxButtons.YesNo;

                    DialogResult res = MessageBox.Show("Not critical error: " + ex.Message + ". Do you want continue?", "", buttons);

                    if (res != DialogResult.Yes)
                        // terminated
                        throw ex;
                }
                else
                {
                    MessageBox.Show("Critical error: " + ex.Message + ". Application would be terminated.");
                    // terminated
                    throw ex;
                }
            }
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
        }

        void richTextBox_ContentsResized(object sender, ContentsResizedEventArgs e)
        {
            Control ctrl = sender as Control;
            if (ctrl != null)
                ctrl.Height = e.NewRectangle.Height + ctrl.Height - ctrl.ClientSize.Height;
        }

        private void OnUpdateUI(object sender, EventArgs e)
        {
            if (ctrl1 != null && ctrl1.ContainsFocus)
            {
                toolStripUmlEditor.Visible = true;
                toolStripDlgEditor.Visible = false;
                toolStripTextBox.Visible = false;
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_CUT, new ButtonCmdUI(toolStripButtonCut));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_COPY, new ButtonCmdUI(toolStripButtonCopy));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_PASTE, new ButtonCmdUI(toolStripButtonPaste));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_CLASS, new ButtonCmdUI(toolStripButtonClass));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_TEMPLATE, new ButtonCmdUI(toolStripButtonTemplate));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_INTERFACE, new ButtonCmdUI(toolStripButtonInterface));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_NOTE, new ButtonCmdUI(toolStripButtonNote));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_LABEL, new ButtonCmdUI(toolStripButtonLabel));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_LINK, new ButtonCmdUI(toolStripButtonLink));
                UmlEditor.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_DISPLAY_PROPERTIES, new ButtonCmdUI(toolStripButtonDisplSet));
            }
            else if (ctrl2 != null && ctrl2.ContainsFocus)
            {
                toolStripDlgEditor.Visible = true;
                toolStripUmlEditor.Visible = false;
                toolStripTextBox.Visible = false;
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_CUT, new ButtonCmdUI(toolStripButton5));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_COPY, new ButtonCmdUI(toolStripButton6));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_PASTE, new ButtonCmdUI(toolStripButton7));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.FILE_PRINT, new ButtonCmdUI(toolStripButton8));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ZOOM_IN_, new ButtonCmdUI(toolStripButton4));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ZOOM_OUT_, new ButtonCmdUI(toolStripButton24));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.SETTINGS, new ButtonCmdUI(toolStripButton9));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.RESTRAIN, new ButtonCmdUI(toolStripButton10));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.MARGINS, new ButtonCmdUI(toolStripButton11));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.SNAP_TO_GRID, new ButtonCmdUI(toolStripButton12));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.SHOW_GRID, new ButtonCmdUI(toolStripButton13));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.BUTTON_MULTIDRAW, new ButtonCmdUI(toolStripButton14));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_NONE, new ButtonCmdUI(toolStripButton15));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_BUTTON, new ButtonCmdUI(toolStripButton16));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_EDIT, new ButtonCmdUI(toolStripButton17));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_STATIC, new ButtonCmdUI(toolStripButton18));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_CHECKBOX, new ButtonCmdUI(toolStripButton19));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_RADIOBUTTON, new ButtonCmdUI(toolStripButton20));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_COMBOBOX, new ButtonCmdUI(toolStripButton21));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_LISTBOX, new ButtonCmdUI(toolStripButton22));
                DlgEditor.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_GROUPBOX, new ButtonCmdUI(toolStripButton23));
            }
            else if ((richTextBox1 != null && richTextBox1.ContainsFocus) ||
       (richTextBox2 != null && richTextBox2.ContainsFocus))
            {
                toolStripDlgEditor.Visible = false;
                toolStripUmlEditor.Visible = false;
                toolStripTextBox.Visible = true;
            }
        }


        #region toolStripButton_Click DlgEditor
        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.FILE_NEW);
        }
        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.FILE_OPEN);
        }
        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.FILE_SAVE);
        }
        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_CUT);
        }
        private void toolStripButton6_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_COPY);
        }
        private void toolStripButton7_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_PASTE);
        }
        private void toolStripButton8_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.FILE_PRINT);
        }
        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ZOOM_IN_);
        }
        private void toolStripButton24_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ZOOM_OUT_);
        }
        private void toolStripButton9_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.SETTINGS);
        }
        private void toolStripButton10_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.RESTRAIN);
        }
        private void toolStripButton11_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.MARGINS);
        }
        private void toolStripButton12_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.SNAP_TO_GRID);
        }
        private void toolStripButton13_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.SHOW_GRID);
        }
        private void toolStripButton14_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.BUTTON_MULTIDRAW);
        }
        private void toolStripButton15_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_NONE);
        }
        private void toolStripButton16_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_BUTTON);
        }
        private void toolStripButton17_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_EDIT);
        }
        private void toolStripButton18_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_STATIC);
        }
        private void toolStripButton19_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_CHECKBOX);
        }
        private void toolStripButton20_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_RADIOBUTTON);
        }
        private void toolStripButton21_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_COMBOBOX);
        }
        private void toolStripButton22_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_LISTBOX);
        }
        private void toolStripButton23_Click(object sender, EventArgs e)
        {
            DlgEditor.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_GROUPBOX);
        }
        #endregion

        #region toolStripButton_Click UmlEditor
        private void toolStripButtonNew_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.FILE_NEW);
        }
        private void toolStripButtonOpen_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.FILE_OPEN);
        }
        private void toolStripButtonSave_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.FILE_SAVE);
        }
        private void toolStripButtonCut_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_CUT);
        }
        private void toolStripButtonCopy_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_COPY);
        }
        private void toolStripButtonPaste_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_PASTE);
        }
        private void toolStripButtonPrint_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.FILE_PRINT);
        }
        private void toolStripButtonClass_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_CLASS);
        }
        private void toolStripButtonTemplate_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_TEMPLATE);
        }
        private void toolStripButtonPackage_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_PACKAGE);
        }
        private void toolStripButtonInterface_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_INTERFACE);
        }
        private void toolStripButtonNote_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_NOTE);
        }
        private void toolStripButtonLabel_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_LABEL);
        }
        private void toolStripButtonLink_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_LINK);
        }
        private void toolStripButtonDisplSet_Click(object sender, EventArgs e)
        {
            UmlEditor.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_DISPLAY_PROPERTIES);
        }
        #endregion


    }
}
