using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using AS.UmlEditor;

namespace AS.MdiFormsDemo
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void ToolStripMenuItemAboutHosting_Click(object sender, EventArgs e)
        {
            ToolStripMenuItem mi = sender as ToolStripMenuItem;
            MessageBox.Show("Copyright (C) 2005 Alexey Shalnov", mi.Text, MessageBoxButtons.OK);
        }
    }
}