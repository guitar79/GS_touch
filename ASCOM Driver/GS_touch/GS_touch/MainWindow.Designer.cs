namespace ASCOM.GS_touch
{
    partial class MainWindow
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
            this.components = new System.ComponentModel.Container();
            this.label_CurrentPosition = new System.Windows.Forms.Label();
            this.button_Reset = new System.Windows.Forms.Button();
            this.button_stop = new System.Windows.Forms.Button();
            this.button_moveright = new System.Windows.Forms.Button();
            this.button_moveleft = new System.Windows.Forms.Button();
            this.button_Apply = new System.Windows.Forms.Button();
            this.label_MoveTo = new System.Windows.Forms.Label();
            this.button_Advanced = new System.Windows.Forms.Button();
            this.label_GStouch = new System.Windows.Forms.Label();
            this.textBox_Position = new System.Windows.Forms.TextBox();
            this.label_OneStep = new System.Windows.Forms.Label();
            this.numericUpDown_SingleStep = new System.Windows.Forms.NumericUpDown();
            this.textBox_MoveTo = new System.Windows.Forms.TextBox();
            this.label_Moving = new System.Windows.Forms.Label();
            this.groupBox_Advanced = new System.Windows.Forms.GroupBox();
            this.label_MS = new System.Windows.Forms.Label();
            this.numericUpDown_Acceleration = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown_Speed = new System.Windows.Forms.NumericUpDown();
            this.textBox_Humidity = new System.Windows.Forms.TextBox();
            this.textBox_Temperature = new System.Windows.Forms.TextBox();
            this.label_Acceleration = new System.Windows.Forms.Label();
            this.label_Speed = new System.Windows.Forms.Label();
            this.label_Humidity = new System.Windows.Forms.Label();
            this.label_Temperature = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.panel_Advanced = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_SingleStep)).BeginInit();
            this.groupBox_Advanced.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_Acceleration)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_Speed)).BeginInit();
            this.panel_Advanced.SuspendLayout();
            this.SuspendLayout();
            // 
            // label_CurrentPosition
            // 
            this.label_CurrentPosition.AutoSize = true;
            this.label_CurrentPosition.CausesValidation = false;
            this.label_CurrentPosition.Enabled = false;
            this.label_CurrentPosition.Location = new System.Drawing.Point(12, 14);
            this.label_CurrentPosition.Name = "label_CurrentPosition";
            this.label_CurrentPosition.Size = new System.Drawing.Size(50, 12);
            this.label_CurrentPosition.TabIndex = 0;
            this.label_CurrentPosition.Text = "Position";
            // 
            // button_Reset
            // 
            this.button_Reset.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.button_Reset.Font = new System.Drawing.Font("Arial", 10F);
            this.button_Reset.Location = new System.Drawing.Point(30, 339);
            this.button_Reset.Name = "button_Reset";
            this.button_Reset.Size = new System.Drawing.Size(240, 46);
            this.button_Reset.TabIndex = 4;
            this.button_Reset.Text = "Reset Position";
            this.button_Reset.UseMnemonic = false;
            this.button_Reset.UseVisualStyleBackColor = true;
            this.button_Reset.Click += new System.EventHandler(this.button_Reset_Click);
            // 
            // button_stop
            // 
            this.button_stop.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.button_stop.Location = new System.Drawing.Point(96, 70);
            this.button_stop.Name = "button_stop";
            this.button_stop.Size = new System.Drawing.Size(72, 25);
            this.button_stop.TabIndex = 5;
            this.button_stop.Text = "STOP";
            this.button_stop.UseVisualStyleBackColor = true;
            this.button_stop.Click += new System.EventHandler(this.button_stop_Click);
            // 
            // button_moveright
            // 
            this.button_moveright.Location = new System.Drawing.Point(172, 70);
            this.button_moveright.Name = "button_moveright";
            this.button_moveright.Size = new System.Drawing.Size(80, 25);
            this.button_moveright.TabIndex = 6;
            this.button_moveright.Text = ">";
            this.button_moveright.UseVisualStyleBackColor = true;
            this.button_moveright.Click += new System.EventHandler(this.button_moveright_Click);
            // 
            // button_moveleft
            // 
            this.button_moveleft.Location = new System.Drawing.Point(12, 70);
            this.button_moveleft.Name = "button_moveleft";
            this.button_moveleft.Size = new System.Drawing.Size(80, 25);
            this.button_moveleft.TabIndex = 7;
            this.button_moveleft.Text = "<";
            this.button_moveleft.UseVisualStyleBackColor = true;
            this.button_moveleft.Click += new System.EventHandler(this.button_moveleft_Click);
            // 
            // button_Apply
            // 
            this.button_Apply.Location = new System.Drawing.Point(95, 127);
            this.button_Apply.Name = "button_Apply";
            this.button_Apply.Size = new System.Drawing.Size(156, 25);
            this.button_Apply.TabIndex = 8;
            this.button_Apply.Text = "Apply";
            this.button_Apply.UseVisualStyleBackColor = true;
            this.button_Apply.Click += new System.EventHandler(this.button_Apply_Click);
            // 
            // label_MoveTo
            // 
            this.label_MoveTo.AutoSize = true;
            this.label_MoveTo.Location = new System.Drawing.Point(12, 106);
            this.label_MoveTo.Name = "label_MoveTo";
            this.label_MoveTo.Size = new System.Drawing.Size(55, 12);
            this.label_MoveTo.TabIndex = 9;
            this.label_MoveTo.Text = "Move To";
            // 
            // button_Advanced
            // 
            this.button_Advanced.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button_Advanced.Location = new System.Drawing.Point(12, 390);
            this.button_Advanced.Name = "button_Advanced";
            this.button_Advanced.Size = new System.Drawing.Size(75, 23);
            this.button_Advanced.TabIndex = 10;
            this.button_Advanced.Text = "Advanced";
            this.button_Advanced.UseVisualStyleBackColor = true;
            this.button_Advanced.Click += new System.EventHandler(this.button_Advanced_Click);
            // 
            // label_GStouch
            // 
            this.label_GStouch.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label_GStouch.AutoSize = true;
            this.label_GStouch.Location = new System.Drawing.Point(138, 396);
            this.label_GStouch.Name = "label_GStouch";
            this.label_GStouch.Size = new System.Drawing.Size(149, 12);
            this.label_GStouch.TabIndex = 11;
            this.label_GStouch.Text = "GS-touch Main Controller";
            this.label_GStouch.Click += new System.EventHandler(this.label_GStouch_Click);
            // 
            // textBox_Position
            // 
            this.textBox_Position.Location = new System.Drawing.Point(96, 9);
            this.textBox_Position.Name = "textBox_Position";
            this.textBox_Position.ReadOnly = true;
            this.textBox_Position.Size = new System.Drawing.Size(154, 21);
            this.textBox_Position.TabIndex = 12;
            // 
            // label_OneStep
            // 
            this.label_OneStep.AutoSize = true;
            this.label_OneStep.Location = new System.Drawing.Point(12, 45);
            this.label_OneStep.Name = "label_OneStep";
            this.label_OneStep.Size = new System.Drawing.Size(69, 12);
            this.label_OneStep.TabIndex = 13;
            this.label_OneStep.Text = "Single Step";
            // 
            // numericUpDown_SingleStep
            // 
            this.numericUpDown_SingleStep.Location = new System.Drawing.Point(96, 39);
            this.numericUpDown_SingleStep.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.numericUpDown_SingleStep.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown_SingleStep.Name = "numericUpDown_SingleStep";
            this.numericUpDown_SingleStep.Size = new System.Drawing.Size(154, 21);
            this.numericUpDown_SingleStep.TabIndex = 14;
            this.numericUpDown_SingleStep.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDown_SingleStep.Value = new decimal(new int[] {
            500,
            0,
            0,
            0});
            this.numericUpDown_SingleStep.ValueChanged += new System.EventHandler(this.numericUpDown_SingleStep_ValueChanged);
            // 
            // textBox_MoveTo
            // 
            this.textBox_MoveTo.Location = new System.Drawing.Point(96, 101);
            this.textBox_MoveTo.Name = "textBox_MoveTo";
            this.textBox_MoveTo.Size = new System.Drawing.Size(154, 21);
            this.textBox_MoveTo.TabIndex = 15;
            // 
            // label_Moving
            // 
            this.label_Moving.AutoSize = true;
            this.label_Moving.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label_Moving.Location = new System.Drawing.Point(12, 133);
            this.label_Moving.Name = "label_Moving";
            this.label_Moving.Size = new System.Drawing.Size(65, 12);
            this.label_Moving.TabIndex = 16;
            this.label_Moving.Text = "READY...";
            // 
            // groupBox_Advanced
            // 
            this.groupBox_Advanced.Controls.Add(this.label_MS);
            this.groupBox_Advanced.Controls.Add(this.numericUpDown_Acceleration);
            this.groupBox_Advanced.Controls.Add(this.numericUpDown_Speed);
            this.groupBox_Advanced.Controls.Add(this.textBox_Humidity);
            this.groupBox_Advanced.Controls.Add(this.textBox_Temperature);
            this.groupBox_Advanced.Controls.Add(this.label_Acceleration);
            this.groupBox_Advanced.Controls.Add(this.label_Speed);
            this.groupBox_Advanced.Controls.Add(this.label_Humidity);
            this.groupBox_Advanced.Controls.Add(this.label_Temperature);
            this.groupBox_Advanced.Location = new System.Drawing.Point(2, 3);
            this.groupBox_Advanced.Name = "groupBox_Advanced";
            this.groupBox_Advanced.Size = new System.Drawing.Size(245, 171);
            this.groupBox_Advanced.TabIndex = 22;
            this.groupBox_Advanced.TabStop = false;
            this.groupBox_Advanced.Text = "Advanced";
            this.groupBox_Advanced.Enter += new System.EventHandler(this.groupBox_Advanced_Enter);
            // 
            // label_MS
            // 
            this.label_MS.AutoSize = true;
            this.label_MS.Location = new System.Drawing.Point(25, 22);
            this.label_MS.Name = "label_MS";
            this.label_MS.Size = new System.Drawing.Size(198, 12);
            this.label_MS.TabIndex = 8;
            this.label_MS.Text = "MicroStepping Mode : 1 (full step)";
            // 
            // numericUpDown_Acceleration
            // 
            this.numericUpDown_Acceleration.Location = new System.Drawing.Point(85, 132);
            this.numericUpDown_Acceleration.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            0});
            this.numericUpDown_Acceleration.Minimum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericUpDown_Acceleration.Name = "numericUpDown_Acceleration";
            this.numericUpDown_Acceleration.Size = new System.Drawing.Size(154, 21);
            this.numericUpDown_Acceleration.TabIndex = 7;
            this.numericUpDown_Acceleration.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDown_Acceleration.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // numericUpDown_Speed
            // 
            this.numericUpDown_Speed.Location = new System.Drawing.Point(85, 105);
            this.numericUpDown_Speed.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.numericUpDown_Speed.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDown_Speed.Name = "numericUpDown_Speed";
            this.numericUpDown_Speed.Size = new System.Drawing.Size(154, 21);
            this.numericUpDown_Speed.TabIndex = 6;
            this.numericUpDown_Speed.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDown_Speed.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // textBox_Humidity
            // 
            this.textBox_Humidity.Location = new System.Drawing.Point(85, 73);
            this.textBox_Humidity.Name = "textBox_Humidity";
            this.textBox_Humidity.ReadOnly = true;
            this.textBox_Humidity.Size = new System.Drawing.Size(154, 21);
            this.textBox_Humidity.TabIndex = 5;
            // 
            // textBox_Temperature
            // 
            this.textBox_Temperature.Location = new System.Drawing.Point(85, 46);
            this.textBox_Temperature.Name = "textBox_Temperature";
            this.textBox_Temperature.ReadOnly = true;
            this.textBox_Temperature.Size = new System.Drawing.Size(154, 21);
            this.textBox_Temperature.TabIndex = 4;
            // 
            // label_Acceleration
            // 
            this.label_Acceleration.AutoSize = true;
            this.label_Acceleration.Location = new System.Drawing.Point(4, 137);
            this.label_Acceleration.Name = "label_Acceleration";
            this.label_Acceleration.Size = new System.Drawing.Size(75, 12);
            this.label_Acceleration.TabIndex = 3;
            this.label_Acceleration.Text = "Acceleration";
            // 
            // label_Speed
            // 
            this.label_Speed.AutoSize = true;
            this.label_Speed.Location = new System.Drawing.Point(38, 110);
            this.label_Speed.Name = "label_Speed";
            this.label_Speed.Size = new System.Drawing.Size(41, 12);
            this.label_Speed.TabIndex = 2;
            this.label_Speed.Text = "Speed";
            // 
            // label_Humidity
            // 
            this.label_Humidity.AutoSize = true;
            this.label_Humidity.Location = new System.Drawing.Point(25, 79);
            this.label_Humidity.Name = "label_Humidity";
            this.label_Humidity.Size = new System.Drawing.Size(54, 12);
            this.label_Humidity.TabIndex = 1;
            this.label_Humidity.Text = "Humidity";
            // 
            // label_Temperature
            // 
            this.label_Temperature.AutoSize = true;
            this.label_Temperature.Location = new System.Drawing.Point(2, 52);
            this.label_Temperature.Name = "label_Temperature";
            this.label_Temperature.Size = new System.Drawing.Size(77, 12);
            this.label_Temperature.TabIndex = 0;
            this.label_Temperature.Text = "Temperature";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 3000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // panel_Advanced
            // 
            this.panel_Advanced.Controls.Add(this.groupBox_Advanced);
            this.panel_Advanced.Location = new System.Drawing.Point(10, 155);
            this.panel_Advanced.Name = "panel_Advanced";
            this.panel_Advanced.Size = new System.Drawing.Size(252, 177);
            this.panel_Advanced.TabIndex = 22;
            this.panel_Advanced.Visible = false;
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Silver;
            this.ClientSize = new System.Drawing.Size(300, 425);
            this.Controls.Add(this.label_Moving);
            this.Controls.Add(this.textBox_MoveTo);
            this.Controls.Add(this.numericUpDown_SingleStep);
            this.Controls.Add(this.label_OneStep);
            this.Controls.Add(this.textBox_Position);
            this.Controls.Add(this.label_GStouch);
            this.Controls.Add(this.button_Advanced);
            this.Controls.Add(this.label_MoveTo);
            this.Controls.Add(this.button_Apply);
            this.Controls.Add(this.button_moveleft);
            this.Controls.Add(this.button_moveright);
            this.Controls.Add(this.button_stop);
            this.Controls.Add(this.button_Reset);
            this.Controls.Add(this.label_CurrentPosition);
            this.Controls.Add(this.panel_Advanced);
            this.Name = "MainWindow";
            this.ShowIcon = false;
            this.Text = "GS-touch MainControler";
            this.Load += new System.EventHandler(this.MainWindow_Load);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_SingleStep)).EndInit();
            this.groupBox_Advanced.ResumeLayout(false);
            this.groupBox_Advanced.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_Acceleration)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_Speed)).EndInit();
            this.panel_Advanced.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_CurrentPosition;
        private System.Windows.Forms.Button button_Reset;
        private System.Windows.Forms.Button button_stop;
        private System.Windows.Forms.Button button_moveright;
        private System.Windows.Forms.Button button_moveleft;
        private System.Windows.Forms.Button button_Apply;
        private System.Windows.Forms.Label label_MoveTo;
        private System.Windows.Forms.Button button_Advanced;
        private System.Windows.Forms.Label label_GStouch;
        private System.Windows.Forms.TextBox textBox_Position;
        private System.Windows.Forms.Label label_OneStep;
        private System.Windows.Forms.NumericUpDown numericUpDown_SingleStep;
        private System.Windows.Forms.TextBox textBox_MoveTo;
        private System.Windows.Forms.Label label_Moving;
        private System.Windows.Forms.GroupBox groupBox_Advanced;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Panel panel_Advanced;
        private System.Windows.Forms.NumericUpDown numericUpDown_Acceleration;
        private System.Windows.Forms.NumericUpDown numericUpDown_Speed;
        private System.Windows.Forms.TextBox textBox_Humidity;
        private System.Windows.Forms.TextBox textBox_Temperature;
        private System.Windows.Forms.Label label_Acceleration;
        private System.Windows.Forms.Label label_Speed;
        private System.Windows.Forms.Label label_Humidity;
        private System.Windows.Forms.Label label_Temperature;
        private System.Windows.Forms.Label label_MS;
    }
}