namespace ASCOM.GS_touch
{
    partial class ResetForm
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
            this.label_ResetPosition = new System.Windows.Forms.Label();
            this.textBox_ResetPosition = new System.Windows.Forms.TextBox();
            this.button_Reset = new System.Windows.Forms.Button();
            this.button_Cancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label_ResetPosition
            // 
            this.label_ResetPosition.AutoSize = true;
            this.label_ResetPosition.Location = new System.Drawing.Point(26, 36);
            this.label_ResetPosition.Name = "label_ResetPosition";
            this.label_ResetPosition.Size = new System.Drawing.Size(81, 12);
            this.label_ResetPosition.TabIndex = 0;
            this.label_ResetPosition.Text = "Position want";
            // 
            // textBox_ResetPosition
            // 
            this.textBox_ResetPosition.Location = new System.Drawing.Point(128, 30);
            this.textBox_ResetPosition.Name = "textBox_ResetPosition";
            this.textBox_ResetPosition.Size = new System.Drawing.Size(150, 21);
            this.textBox_ResetPosition.TabIndex = 2;
            // 
            // button_Reset
            // 
            this.button_Reset.Location = new System.Drawing.Point(128, 65);
            this.button_Reset.Name = "button_Reset";
            this.button_Reset.Size = new System.Drawing.Size(70, 25);
            this.button_Reset.TabIndex = 4;
            this.button_Reset.Text = "Apply";
            this.button_Reset.UseVisualStyleBackColor = true;
            this.button_Reset.Click += new System.EventHandler(this.button_Reset_Click);
            // 
            // button_Cancel
            // 
            this.button_Cancel.Location = new System.Drawing.Point(208, 65);
            this.button_Cancel.Name = "button_Cancel";
            this.button_Cancel.Size = new System.Drawing.Size(70, 25);
            this.button_Cancel.TabIndex = 5;
            this.button_Cancel.Text = "Cancel";
            this.button_Cancel.UseVisualStyleBackColor = true;
            this.button_Cancel.Click += new System.EventHandler(this.button_Cancel_Click);
            // 
            // ResetForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(304, 111);
            this.Controls.Add(this.button_Cancel);
            this.Controls.Add(this.button_Reset);
            this.Controls.Add(this.textBox_ResetPosition);
            this.Controls.Add(this.label_ResetPosition);
            this.Name = "ResetForm";
            this.Text = "Reset Settings";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_ResetPosition;
        private System.Windows.Forms.TextBox textBox_ResetPosition;
        private System.Windows.Forms.Button button_Reset;
        private System.Windows.Forms.Button button_Cancel;
    }
}