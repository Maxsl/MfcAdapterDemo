using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using AS.MfcHost;

namespace FormTest
{
    public partial class Form1 : Form
    {
        MfcAppAdapter SimpleTest;

        public Form1()
        {
            InitializeComponent();
            this.IsMdiContainer = true;
            components = new Container();
            this.Load += new EventHandler(Form1_Load);
        }

        void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                SimpleTest = AS.MfcHost.MfcAppAdapter.GetMfcAppAdapter(AS.SimpleTest.ModuleState.GetModuleState(), this.Handle);
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
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SimpleTest.OnCmdMsg((int)AS.SimpleTest.MfcCommand.APP_ABOUT);

        }

        private void scrollToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SimpleTest.OnCmdMsg((int)AS.SimpleTest.MfcCommand.BUTTON_SCROLL);
            ViewCtrl ctrl = new ViewCtrl();
            ctrl.BuildWindow(SimpleTest.GetModuleState(), SimpleTest.GetCreatedView());
            Form form = new Form();
            ctrl.Dock = DockStyle.Fill;
            form.Controls.Add(ctrl);
            form.Closing += ctrl.ClosingDelegate;
            form.MdiParent = this;
            form.Show();
        }

        private void listToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SimpleTest.OnCmdMsg((int)AS.SimpleTest.MfcCommand.BUTTON_LIST);
            ViewCtrl ctrl = new ViewCtrl();
            ctrl.BuildWindow(SimpleTest.GetModuleState(), SimpleTest.GetCreatedView());
            Form form = new Form();
            ctrl.Dock = DockStyle.Fill;
            form.Controls.Add(ctrl);
            form.Closing += ctrl.ClosingDelegate;
            form.MdiParent = this;
            form.Show();

        }

    }
}