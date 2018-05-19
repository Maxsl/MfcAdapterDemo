namespace AS.FormsDemo
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }

            // dispose controls
            if (ctrl1 != null)
                ctrl1.Dispose();
            if (ctrl2 != null)
                ctrl2.Dispose();
            
            // dispose adapters
            if (UmlEditor != null)
                UmlEditor.Dispose();
            if (DlgEditor != null)
                DlgEditor.Dispose();

            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.panel2 = new System.Windows.Forms.Panel();
            this.toolStripDlgEditor = new System.Windows.Forms.ToolStrip();
            this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton5 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton6 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton7 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator9 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton8 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator10 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton4 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton24 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator16 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton9 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton10 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton11 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator11 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton12 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton13 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator13 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton14 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator12 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton15 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton16 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton17 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton18 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton19 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton20 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton21 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton22 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton23 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator17 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripUmlEditor = new System.Windows.Forms.ToolStrip();
            this.toolStripButtonCut = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonCopy = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonPaste = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonPrint = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonClass = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonTemplate = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonPackage = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonInterface = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonNote = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonLabel = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonLink = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonDisplSet = new System.Windows.Forms.ToolStripButton();
            this.toolStripTextBox = new System.Windows.Forms.ToolStrip();
            this.toolStripButtonTextBox = new System.Windows.Forms.ToolStripButton();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2.SuspendLayout();
            this.toolStripDlgEditor.SuspendLayout();
            this.toolStripUmlEditor.SuspendLayout();
            this.toolStripTextBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.toolStripDlgEditor);
            this.panel2.Controls.Add(this.toolStripUmlEditor);
            this.panel2.Controls.Add(this.toolStripTextBox);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(714, 32);
            this.panel2.TabIndex = 5;
            // 
            // toolStripDlgEditor
            // 
            this.toolStripDlgEditor.Dock = System.Windows.Forms.DockStyle.Fill;
            this.toolStripDlgEditor.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSeparator8,
            this.toolStripButton5,
            this.toolStripButton6,
            this.toolStripButton7,
            this.toolStripSeparator9,
            this.toolStripButton8,
            this.toolStripSeparator10,
            this.toolStripButton4,
            this.toolStripButton24,
            this.toolStripSeparator16,
            this.toolStripButton9,
            this.toolStripButton10,
            this.toolStripButton11,
            this.toolStripSeparator11,
            this.toolStripButton12,
            this.toolStripButton13,
            this.toolStripSeparator13,
            this.toolStripButton14,
            this.toolStripSeparator12,
            this.toolStripButton15,
            this.toolStripButton16,
            this.toolStripButton17,
            this.toolStripButton18,
            this.toolStripButton19,
            this.toolStripButton20,
            this.toolStripButton21,
            this.toolStripButton22,
            this.toolStripButton23,
            this.toolStripSeparator17});
            this.toolStripDlgEditor.Location = new System.Drawing.Point(0, 0);
            this.toolStripDlgEditor.Name = "toolStripDlgEditor";
            this.toolStripDlgEditor.Size = new System.Drawing.Size(714, 32);
            this.toolStripDlgEditor.TabIndex = 8;
            this.toolStripDlgEditor.Text = "toolStrip1";
            // 
            // toolStripSeparator8
            // 
            this.toolStripSeparator8.Name = "toolStripSeparator8";
            this.toolStripSeparator8.Size = new System.Drawing.Size(6, 32);
            // 
            // toolStripButton5
            // 
            this.toolStripButton5.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton5.Image = global::FormsDemo.ToolbarResource.Cut;
            this.toolStripButton5.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton5.Name = "toolStripButton5";
            this.toolStripButton5.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton5.Text = "toolStripButton5";
            this.toolStripButton5.Click += new System.EventHandler(this.toolStripButton5_Click);
            // 
            // toolStripButton6
            // 
            this.toolStripButton6.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton6.Image = global::FormsDemo.ToolbarResource.Copy;
            this.toolStripButton6.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton6.Name = "toolStripButton6";
            this.toolStripButton6.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton6.Text = "toolStripButton6";
            this.toolStripButton6.Click += new System.EventHandler(this.toolStripButton6_Click);
            // 
            // toolStripButton7
            // 
            this.toolStripButton7.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton7.Image = global::FormsDemo.ToolbarResource.Paste;
            this.toolStripButton7.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton7.Name = "toolStripButton7";
            this.toolStripButton7.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton7.Text = "toolStripButton7";
            this.toolStripButton7.Click += new System.EventHandler(this.toolStripButton7_Click);
            // 
            // toolStripSeparator9
            // 
            this.toolStripSeparator9.Name = "toolStripSeparator9";
            this.toolStripSeparator9.Size = new System.Drawing.Size(6, 32);
            // 
            // toolStripButton8
            // 
            this.toolStripButton8.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton8.Image = global::FormsDemo.ToolbarResource.Print;
            this.toolStripButton8.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton8.Name = "toolStripButton8";
            this.toolStripButton8.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton8.Text = "toolStripButton8";
            this.toolStripButton8.Click += new System.EventHandler(this.toolStripButton8_Click);
            // 
            // toolStripSeparator10
            // 
            this.toolStripSeparator10.Name = "toolStripSeparator10";
            this.toolStripSeparator10.Size = new System.Drawing.Size(6, 32);
            // 
            // toolStripButton4
            // 
            this.toolStripButton4.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton4.Image = global::FormsDemo.ToolbarResource.ZoomIn;
            this.toolStripButton4.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton4.Name = "toolStripButton4";
            this.toolStripButton4.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton4.Text = "toolStripButton4";
            this.toolStripButton4.Click += new System.EventHandler(this.toolStripButton4_Click);
            // 
            // toolStripButton24
            // 
            this.toolStripButton24.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton24.Image = global::FormsDemo.ToolbarResource.ZoomOut;
            this.toolStripButton24.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton24.Name = "toolStripButton24";
            this.toolStripButton24.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton24.Text = "toolStripButton24";
            this.toolStripButton24.Click += new System.EventHandler(this.toolStripButton24_Click);
            // 
            // toolStripSeparator16
            // 
            this.toolStripSeparator16.Name = "toolStripSeparator16";
            this.toolStripSeparator16.Size = new System.Drawing.Size(6, 32);
            // 
            // toolStripButton9
            // 
            this.toolStripButton9.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton9.Image = global::FormsDemo.ToolbarResource.Settings;
            this.toolStripButton9.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton9.Name = "toolStripButton9";
            this.toolStripButton9.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton9.Text = "toolStripButton9";
            this.toolStripButton9.Click += new System.EventHandler(this.toolStripButton9_Click);
            // 
            // toolStripButton10
            // 
            this.toolStripButton10.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton10.Image = global::FormsDemo.ToolbarResource.Restrain;
            this.toolStripButton10.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton10.Name = "toolStripButton10";
            this.toolStripButton10.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton10.Text = "toolStripButton10";
            this.toolStripButton10.Click += new System.EventHandler(this.toolStripButton10_Click);
            // 
            // toolStripButton11
            // 
            this.toolStripButton11.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton11.Image = global::FormsDemo.ToolbarResource.Margins;
            this.toolStripButton11.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton11.Name = "toolStripButton11";
            this.toolStripButton11.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton11.Text = "toolStripButton11";
            this.toolStripButton11.Click += new System.EventHandler(this.toolStripButton11_Click);
            // 
            // toolStripSeparator11
            // 
            this.toolStripSeparator11.Name = "toolStripSeparator11";
            this.toolStripSeparator11.Size = new System.Drawing.Size(6, 32);
            // 
            // toolStripButton12
            // 
            this.toolStripButton12.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton12.Image = global::FormsDemo.ToolbarResource.SnapToGrid;
            this.toolStripButton12.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton12.Name = "toolStripButton12";
            this.toolStripButton12.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton12.Text = "toolStripButton12";
            this.toolStripButton12.Click += new System.EventHandler(this.toolStripButton12_Click);
            // 
            // toolStripButton13
            // 
            this.toolStripButton13.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton13.Image = global::FormsDemo.ToolbarResource.ShowGrid;
            this.toolStripButton13.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton13.Name = "toolStripButton13";
            this.toolStripButton13.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton13.Text = "toolStripButton13";
            this.toolStripButton13.Click += new System.EventHandler(this.toolStripButton13_Click);
            // 
            // toolStripSeparator13
            // 
            this.toolStripSeparator13.Name = "toolStripSeparator13";
            this.toolStripSeparator13.Size = new System.Drawing.Size(6, 32);
            // 
            // toolStripButton14
            // 
            this.toolStripButton14.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton14.Image = global::FormsDemo.ToolbarResource.ButtonMultidraw;
            this.toolStripButton14.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton14.Name = "toolStripButton14";
            this.toolStripButton14.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton14.Text = "toolStripButton14";
            this.toolStripButton14.Click += new System.EventHandler(this.toolStripButton14_Click);
            // 
            // toolStripSeparator12
            // 
            this.toolStripSeparator12.Name = "toolStripSeparator12";
            this.toolStripSeparator12.Size = new System.Drawing.Size(6, 32);
            // 
            // toolStripButton15
            // 
            this.toolStripButton15.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton15.Image = global::FormsDemo.ToolbarResource.AddNone;
            this.toolStripButton15.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton15.Name = "toolStripButton15";
            this.toolStripButton15.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton15.Text = "toolStripButton15";
            this.toolStripButton15.Click += new System.EventHandler(this.toolStripButton15_Click);
            // 
            // toolStripButton16
            // 
            this.toolStripButton16.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton16.Image = global::FormsDemo.ToolbarResource.AddButton;
            this.toolStripButton16.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton16.Name = "toolStripButton16";
            this.toolStripButton16.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton16.Text = "toolStripButton16";
            this.toolStripButton16.Click += new System.EventHandler(this.toolStripButton16_Click);
            // 
            // toolStripButton17
            // 
            this.toolStripButton17.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton17.Image = global::FormsDemo.ToolbarResource.AddEdit;
            this.toolStripButton17.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton17.Name = "toolStripButton17";
            this.toolStripButton17.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton17.Text = "toolStripButton17";
            this.toolStripButton17.Click += new System.EventHandler(this.toolStripButton17_Click);
            // 
            // toolStripButton18
            // 
            this.toolStripButton18.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton18.Image = global::FormsDemo.ToolbarResource.AddStatic;
            this.toolStripButton18.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton18.Name = "toolStripButton18";
            this.toolStripButton18.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton18.Text = "toolStripButton18";
            this.toolStripButton18.Click += new System.EventHandler(this.toolStripButton18_Click);
            // 
            // toolStripButton19
            // 
            this.toolStripButton19.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton19.Image = global::FormsDemo.ToolbarResource.AddCheckbox;
            this.toolStripButton19.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton19.Name = "toolStripButton19";
            this.toolStripButton19.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton19.Text = "toolStripButton19";
            this.toolStripButton19.Click += new System.EventHandler(this.toolStripButton19_Click);
            // 
            // toolStripButton20
            // 
            this.toolStripButton20.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton20.Image = global::FormsDemo.ToolbarResource.AddRadiobutton;
            this.toolStripButton20.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton20.Name = "toolStripButton20";
            this.toolStripButton20.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton20.Text = "toolStripButton20";
            this.toolStripButton20.Click += new System.EventHandler(this.toolStripButton20_Click);
            // 
            // toolStripButton21
            // 
            this.toolStripButton21.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton21.Image = global::FormsDemo.ToolbarResource.AddCombobox;
            this.toolStripButton21.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton21.Name = "toolStripButton21";
            this.toolStripButton21.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton21.Text = "toolStripButton21";
            this.toolStripButton21.Click += new System.EventHandler(this.toolStripButton21_Click);
            // 
            // toolStripButton22
            // 
            this.toolStripButton22.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton22.Image = global::FormsDemo.ToolbarResource.AddListbox;
            this.toolStripButton22.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton22.Name = "toolStripButton22";
            this.toolStripButton22.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton22.Text = "toolStripButton22";
            this.toolStripButton22.Click += new System.EventHandler(this.toolStripButton22_Click);
            // 
            // toolStripButton23
            // 
            this.toolStripButton23.CheckOnClick = true;
            this.toolStripButton23.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton23.Image = global::FormsDemo.ToolbarResource.AddGroupbox;
            this.toolStripButton23.ImageTransparentColor = System.Drawing.Color.Silver;
            this.toolStripButton23.Name = "toolStripButton23";
            this.toolStripButton23.Size = new System.Drawing.Size(23, 29);
            this.toolStripButton23.Text = "toolStripButton23";
            this.toolStripButton23.Click += new System.EventHandler(this.toolStripButton23_Click);
            // 
            // toolStripSeparator17
            // 
            this.toolStripSeparator17.Name = "toolStripSeparator17";
            this.toolStripSeparator17.Size = new System.Drawing.Size(6, 32);
            // 
            // toolStripUmlEditor
            // 
            this.toolStripUmlEditor.Dock = System.Windows.Forms.DockStyle.Fill;
            this.toolStripUmlEditor.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButtonCut,
            this.toolStripButtonCopy,
            this.toolStripButtonPaste,
            this.toolStripButtonPrint,
            this.toolStripButtonClass,
            this.toolStripButtonTemplate,
            this.toolStripButtonPackage,
            this.toolStripButtonInterface,
            this.toolStripButtonNote,
            this.toolStripButtonLabel,
            this.toolStripButtonLink,
            this.toolStripButtonDisplSet});
            this.toolStripUmlEditor.Location = new System.Drawing.Point(0, 0);
            this.toolStripUmlEditor.Name = "toolStripUmlEditor";
            this.toolStripUmlEditor.Size = new System.Drawing.Size(714, 32);
            this.toolStripUmlEditor.TabIndex = 7;
            // 
            // toolStripButtonCut
            // 
            this.toolStripButtonCut.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonCut.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonCut.Image")));
            this.toolStripButtonCut.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonCut.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonCut.Name = "toolStripButtonCut";
            this.toolStripButtonCut.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonCut.Text = "toolStripButton1";
            this.toolStripButtonCut.ToolTipText = "Cut";
            this.toolStripButtonCut.Click += new System.EventHandler(this.toolStripButtonCut_Click);
            // 
            // toolStripButtonCopy
            // 
            this.toolStripButtonCopy.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonCopy.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonCopy.Image")));
            this.toolStripButtonCopy.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonCopy.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonCopy.Name = "toolStripButtonCopy";
            this.toolStripButtonCopy.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonCopy.Text = "toolStripButton1";
            this.toolStripButtonCopy.ToolTipText = "Copy";
            this.toolStripButtonCopy.Click += new System.EventHandler(this.toolStripButtonCopy_Click);
            // 
            // toolStripButtonPaste
            // 
            this.toolStripButtonPaste.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonPaste.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonPaste.Image")));
            this.toolStripButtonPaste.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonPaste.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonPaste.Name = "toolStripButtonPaste";
            this.toolStripButtonPaste.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonPaste.Text = "toolStripButton1";
            this.toolStripButtonPaste.ToolTipText = "Paste";
            this.toolStripButtonPaste.Click += new System.EventHandler(this.toolStripButtonPaste_Click);
            // 
            // toolStripButtonPrint
            // 
            this.toolStripButtonPrint.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonPrint.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonPrint.Image")));
            this.toolStripButtonPrint.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonPrint.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonPrint.Name = "toolStripButtonPrint";
            this.toolStripButtonPrint.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonPrint.Text = "toolStripButton1";
            this.toolStripButtonPrint.ToolTipText = "Print";
            this.toolStripButtonPrint.Click += new System.EventHandler(this.toolStripButtonPrint_Click);
            // 
            // toolStripButtonClass
            // 
            this.toolStripButtonClass.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonClass.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonClass.Image")));
            this.toolStripButtonClass.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonClass.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonClass.Name = "toolStripButtonClass";
            this.toolStripButtonClass.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonClass.Text = "Class";
            this.toolStripButtonClass.Click += new System.EventHandler(this.toolStripButtonClass_Click);
            // 
            // toolStripButtonTemplate
            // 
            this.toolStripButtonTemplate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonTemplate.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonTemplate.Image")));
            this.toolStripButtonTemplate.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonTemplate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonTemplate.Name = "toolStripButtonTemplate";
            this.toolStripButtonTemplate.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonTemplate.Text = "Template";
            this.toolStripButtonTemplate.Click += new System.EventHandler(this.toolStripButtonTemplate_Click);
            // 
            // toolStripButtonPackage
            // 
            this.toolStripButtonPackage.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonPackage.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonPackage.Image")));
            this.toolStripButtonPackage.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonPackage.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonPackage.Name = "toolStripButtonPackage";
            this.toolStripButtonPackage.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonPackage.Text = "Package";
            this.toolStripButtonPackage.Click += new System.EventHandler(this.toolStripButtonPackage_Click);
            // 
            // toolStripButtonInterface
            // 
            this.toolStripButtonInterface.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonInterface.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonInterface.Image")));
            this.toolStripButtonInterface.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonInterface.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonInterface.Name = "toolStripButtonInterface";
            this.toolStripButtonInterface.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonInterface.Text = "toolStripButton1";
            this.toolStripButtonInterface.ToolTipText = "Interface";
            this.toolStripButtonInterface.Click += new System.EventHandler(this.toolStripButtonInterface_Click);
            // 
            // toolStripButtonNote
            // 
            this.toolStripButtonNote.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonNote.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonNote.Image")));
            this.toolStripButtonNote.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonNote.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonNote.Name = "toolStripButtonNote";
            this.toolStripButtonNote.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonNote.Text = "toolStripButton1";
            this.toolStripButtonNote.ToolTipText = "Note";
            this.toolStripButtonNote.Click += new System.EventHandler(this.toolStripButtonNote_Click);
            // 
            // toolStripButtonLabel
            // 
            this.toolStripButtonLabel.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonLabel.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonLabel.Image")));
            this.toolStripButtonLabel.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonLabel.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonLabel.Name = "toolStripButtonLabel";
            this.toolStripButtonLabel.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonLabel.Text = "toolStripButton1";
            this.toolStripButtonLabel.ToolTipText = "Label";
            this.toolStripButtonLabel.Click += new System.EventHandler(this.toolStripButtonLabel_Click);
            // 
            // toolStripButtonLink
            // 
            this.toolStripButtonLink.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonLink.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonLink.Image")));
            this.toolStripButtonLink.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonLink.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonLink.Name = "toolStripButtonLink";
            this.toolStripButtonLink.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonLink.Text = "toolStripButton1";
            this.toolStripButtonLink.ToolTipText = "Link";
            this.toolStripButtonLink.Click += new System.EventHandler(this.toolStripButtonLink_Click);
            // 
            // toolStripButtonDisplSet
            // 
            this.toolStripButtonDisplSet.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonDisplSet.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonDisplSet.Image")));
            this.toolStripButtonDisplSet.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripButtonDisplSet.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonDisplSet.Name = "toolStripButtonDisplSet";
            this.toolStripButtonDisplSet.Size = new System.Drawing.Size(23, 29);
            this.toolStripButtonDisplSet.Text = "toolStripButton1";
            this.toolStripButtonDisplSet.ToolTipText = "Display Settings";
            this.toolStripButtonDisplSet.Click += new System.EventHandler(this.toolStripButtonDisplSet_Click);
            // 
            // toolStripTextBox
            // 
            this.toolStripTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.toolStripTextBox.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButtonTextBox});
            this.toolStripTextBox.Location = new System.Drawing.Point(0, 0);
            this.toolStripTextBox.Name = "toolStripTextBox";
            this.toolStripTextBox.Size = new System.Drawing.Size(714, 32);
            this.toolStripTextBox.TabIndex = 3;
            this.toolStripTextBox.Text = "toolStrip3";
            // 
            // toolStripButtonTextBox
            // 
            this.toolStripButtonTextBox.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButtonTextBox.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonTextBox.Image")));
            this.toolStripButtonTextBox.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonTextBox.Name = "toolStripButtonTextBox";
            this.toolStripButtonTextBox.Size = new System.Drawing.Size(102, 29);
            this.toolStripButtonTextBox.Text = "TextBoxButtons...";
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.BackColor = System.Drawing.SystemColors.Window;
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(0, 32);
            this.panel1.Name = "panel1";
            this.panel1.Padding = new System.Windows.Forms.Padding(40);
            this.panel1.Size = new System.Drawing.Size(714, 560);
            this.panel1.TabIndex = 6;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(714, 592);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.panel2);
            this.Name = "MainForm";
            this.Text = "FormsDemo";
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.toolStripDlgEditor.ResumeLayout(false);
            this.toolStripDlgEditor.PerformLayout();
            this.toolStripUmlEditor.ResumeLayout(false);
            this.toolStripUmlEditor.PerformLayout();
            this.toolStripTextBox.ResumeLayout(false);
            this.toolStripTextBox.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.ToolStrip toolStripTextBox;
        private System.Windows.Forms.ToolStripButton toolStripButtonTextBox;
        private System.Windows.Forms.ToolStrip toolStripUmlEditor;
        private System.Windows.Forms.ToolStripButton toolStripButtonCut;
        private System.Windows.Forms.ToolStripButton toolStripButtonCopy;
        private System.Windows.Forms.ToolStripButton toolStripButtonPaste;
        private System.Windows.Forms.ToolStripButton toolStripButtonPrint;
        private System.Windows.Forms.ToolStripButton toolStripButtonClass;
        private System.Windows.Forms.ToolStripButton toolStripButtonTemplate;
        private System.Windows.Forms.ToolStripButton toolStripButtonPackage;
        private System.Windows.Forms.ToolStripButton toolStripButtonInterface;
        private System.Windows.Forms.ToolStripButton toolStripButtonNote;
        private System.Windows.Forms.ToolStripButton toolStripButtonLabel;
        private System.Windows.Forms.ToolStripButton toolStripButtonLink;
        private System.Windows.Forms.ToolStripButton toolStripButtonDisplSet;
        private System.Windows.Forms.ToolStrip toolStripDlgEditor;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator8;
        private System.Windows.Forms.ToolStripButton toolStripButton5;
        private System.Windows.Forms.ToolStripButton toolStripButton6;
        private System.Windows.Forms.ToolStripButton toolStripButton7;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator9;
        private System.Windows.Forms.ToolStripButton toolStripButton8;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator10;
        private System.Windows.Forms.ToolStripButton toolStripButton4;
        private System.Windows.Forms.ToolStripButton toolStripButton24;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator16;
        private System.Windows.Forms.ToolStripButton toolStripButton9;
        private System.Windows.Forms.ToolStripButton toolStripButton10;
        private System.Windows.Forms.ToolStripButton toolStripButton11;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator11;
        private System.Windows.Forms.ToolStripButton toolStripButton12;
        private System.Windows.Forms.ToolStripButton toolStripButton13;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator13;
        private System.Windows.Forms.ToolStripButton toolStripButton14;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator12;
        private System.Windows.Forms.ToolStripButton toolStripButton15;
        private System.Windows.Forms.ToolStripButton toolStripButton16;
        private System.Windows.Forms.ToolStripButton toolStripButton17;
        private System.Windows.Forms.ToolStripButton toolStripButton18;
        private System.Windows.Forms.ToolStripButton toolStripButton19;
        private System.Windows.Forms.ToolStripButton toolStripButton20;
        private System.Windows.Forms.ToolStripButton toolStripButton21;
        private System.Windows.Forms.ToolStripButton toolStripButton22;
        private System.Windows.Forms.ToolStripButton toolStripButton23;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator17;

    }
}

