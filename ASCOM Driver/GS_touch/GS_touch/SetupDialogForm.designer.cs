namespace ASCOM.GS_touch
{
    partial class SetupDialogForm
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
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.cmdOK = new System.Windows.Forms.Button();
            this.cmdCancel = new System.Windows.Forms.Button();
            this.Title = new System.Windows.Forms.Label();
            this.picASCOM = new System.Windows.Forms.PictureBox();
            this.Comport = new System.Windows.Forms.Label();
            this.comboBoxComPort = new System.Windows.Forms.ComboBox();
            this.showUI = new System.Windows.Forms.CheckBox();
            this.MS_mode = new System.Windows.Forms.Label();
            this.comboBoxMS = new System.Windows.Forms.ComboBox();
            this.chkTrace = new System.Windows.Forms.CheckBox();
            this.Reconnect = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picASCOM)).BeginInit();
            this.SuspendLayout();
            // 
            // cmdOK
            // 
            this.cmdOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.cmdOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.cmdOK.Location = new System.Drawing.Point(328, 112);
            this.cmdOK.Name = "cmdOK";
            this.cmdOK.Size = new System.Drawing.Size(69, 22);
            this.cmdOK.TabIndex = 0;
            this.cmdOK.Text = "OK";
            this.cmdOK.UseVisualStyleBackColor = true;
            this.cmdOK.Click += new System.EventHandler(this.cmdOK_Click);
            // 
            // cmdCancel
            // 
            this.cmdCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.cmdCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cmdCancel.Location = new System.Drawing.Point(328, 140);
            this.cmdCancel.Name = "cmdCancel";
            this.cmdCancel.Size = new System.Drawing.Size(69, 23);
            this.cmdCancel.TabIndex = 1;
            this.cmdCancel.Text = "Cancel";
            this.cmdCancel.UseVisualStyleBackColor = true;
            this.cmdCancel.Click += new System.EventHandler(this.cmdCancel_Click);
            // 
            // Title
            // 
            this.Title.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F);
            this.Title.Location = new System.Drawing.Point(12, 8);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(335, 31);
            this.Title.TabIndex = 2;
            this.Title.Text = "GS-touch ASCOM Driver (v 1.1)";
            // 
            // picASCOM
            // 
            this.picASCOM.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.picASCOM.Cursor = System.Windows.Forms.Cursors.Hand;
            this.picASCOM.Image = global::ASCOM.GS_touch.Properties.Resources.ASCOM;
            this.picASCOM.Location = new System.Drawing.Point(17, 42);
            this.picASCOM.Name = "picASCOM";
            this.picASCOM.Size = new System.Drawing.Size(48, 56);
            this.picASCOM.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.picASCOM.TabIndex = 3;
            this.picASCOM.TabStop = false;
            this.picASCOM.Click += new System.EventHandler(this.BrowseToAscom);
            this.picASCOM.DoubleClick += new System.EventHandler(this.BrowseToAscom);
            // 
            // Comport
            // 
            this.Comport.AutoSize = true;
            this.Comport.Location = new System.Drawing.Point(93, 53);
            this.Comport.Name = "Comport";
            this.Comport.Size = new System.Drawing.Size(161, 12);
            this.Comport.TabIndex = 5;
            this.Comport.Text = "Baudrate 115200 : COM port";
            // 
            // comboBoxComPort
            // 
            this.comboBoxComPort.FormattingEnabled = true;
            this.comboBoxComPort.Location = new System.Drawing.Point(260, 50);
            this.comboBoxComPort.Name = "comboBoxComPort";
            this.comboBoxComPort.Size = new System.Drawing.Size(137, 20);
            this.comboBoxComPort.TabIndex = 7;
            // 
            // showUI
            // 
            this.showUI.AutoSize = true;
            this.showUI.Location = new System.Drawing.Point(20, 120);
            this.showUI.Name = "showUI";
            this.showUI.Size = new System.Drawing.Size(114, 16);
            this.showUI.TabIndex = 8;
            this.showUI.Text = "Show Controller";
            this.showUI.UseVisualStyleBackColor = true;
            this.showUI.CheckedChanged += new System.EventHandler(this.showUI_CheckedChanged);
            // 
            // MS_mode
            // 
            this.MS_mode.AutoSize = true;
            this.MS_mode.Location = new System.Drawing.Point(133, 78);
            this.MS_mode.Name = "MS_mode";
            this.MS_mode.Size = new System.Drawing.Size(121, 12);
            this.MS_mode.TabIndex = 9;
            this.MS_mode.Text = "Microstepping Mode";
            // 
            // comboBoxMS
            // 
            this.comboBoxMS.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxMS.FormattingEnabled = true;
            this.comboBoxMS.Location = new System.Drawing.Point(260, 76);
            this.comboBoxMS.Name = "comboBoxMS";
            this.comboBoxMS.Size = new System.Drawing.Size(137, 20);
            this.comboBoxMS.TabIndex = 10;
            this.comboBoxMS.SelectedIndexChanged += new System.EventHandler(this.MS_SelectedIndexChanged);
            // 
            // chkTrace
            // 
            this.chkTrace.AutoSize = true;
            this.chkTrace.Location = new System.Drawing.Point(20, 142);
            this.chkTrace.Name = "chkTrace";
            this.chkTrace.Size = new System.Drawing.Size(75, 16);
            this.chkTrace.TabIndex = 6;
            this.chkTrace.Text = "Trace on";
            this.chkTrace.UseVisualStyleBackColor = true;
            this.chkTrace.CheckedChanged += new System.EventHandler(this.chkTrace_CheckedChanged);
            // 
            // Reconnect
            // 
            this.Reconnect.Location = new System.Drawing.Point(233, 112);
            this.Reconnect.Name = "Reconnect";
            this.Reconnect.Size = new System.Drawing.Size(89, 52);
            this.Reconnect.TabIndex = 11;
            this.Reconnect.Text = "Connect";
            this.Reconnect.UseVisualStyleBackColor = true;
            this.Reconnect.Click += new System.EventHandler(this.Reconnect_Click);
            // 
            // SetupDialogForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(408, 169);
            this.Controls.Add(this.Reconnect);
            this.Controls.Add(this.comboBoxMS);
            this.Controls.Add(this.MS_mode);
            this.Controls.Add(this.showUI);
            this.Controls.Add(this.comboBoxComPort);
            this.Controls.Add(this.chkTrace);
            this.Controls.Add(this.Comport);
            this.Controls.Add(this.picASCOM);
            this.Controls.Add(this.Title);
            this.Controls.Add(this.cmdCancel);
            this.Controls.Add(this.cmdOK);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SetupDialogForm";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "GS-touch ASCOM Setup";
            ((System.ComponentModel.ISupportInitialize)(this.picASCOM)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox picASCOM;
        private System.Windows.Forms.Button cmdOK;
        private System.Windows.Forms.Button cmdCancel;
        private System.Windows.Forms.Button Reconnect;
        private System.Windows.Forms.Label Title;
        private System.Windows.Forms.Label Comport;
        private System.Windows.Forms.Label MS_mode;
        private System.Windows.Forms.ComboBox comboBoxComPort;
        private System.Windows.Forms.ComboBox comboBoxMS;
        private System.Windows.Forms.CheckBox chkTrace;
        private System.Windows.Forms.CheckBox showUI;
    }
}