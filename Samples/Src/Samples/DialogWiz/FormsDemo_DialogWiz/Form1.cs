using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using AS.MfcHost;

namespace TestForm
{
    public partial class Form1 : Form
    {
        private MfcAppAdapter m_MfcAppAdapter = null;

        public Form1()
        {
            InitializeComponent();
            this.Load += new EventHandler(Form1_Load);
        }

        void Form1_Load(object sender, EventArgs e)
        {
            m_MfcAppAdapter = MfcAppAdapter.GetMfcAppAdapter(ModuleState.GetModuleState(), this.Handle);
            Application.Idle += new EventHandler(m_MfcAppAdapter.OnIdle);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            m_MfcAppAdapter.OnCmdMsg((int)MfcCommand.APP_ABOUT);
        }
    }
}