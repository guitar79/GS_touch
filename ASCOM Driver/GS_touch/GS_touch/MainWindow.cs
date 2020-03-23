using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ASCOM.GS_touch
{
    public partial class MainWindow : Form
    {

        ASCOM.GS_touch.Focuser focuser;

        public MainWindow(Focuser focuser)
        {
            this.focuser = focuser;
            this.focuser.FocuserValueChanged += FocuserValueChanged;
            this.focuser.FocuserStateChanged += FocuserStateChanged;
            this.focuser.FocuserHumidityChanged += FocuserHumidityChanged;
            this.focuser.FocuserTemperatureChanged += FocuserTemperatureChanged;
            InitializeComponent();
            InitControls();

            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        delegate void SetCurrentPositionCallBack(int position);
        delegate void SetCurrentStateCallBack(bool isMoving);
        delegate void SetCurrentTemperatureCallBack(string temperature);
        delegate void SetCurrentHumidityCallBack(string humidity);

        private void SetCurrentTemperature(string temperature)
        {
            textBox_Temperature.InvokeIfRequired(textBox_Temperature => { textBox_Temperature.Text = temperature; });
        }

        private void SetCurrentHumidity(string humidity)
        {

            textBox_Humidity.InvokeIfRequired(textBox_Humidity => { textBox_Humidity.Text = humidity; });
        }

        public void SetCurrentPosition(int position)
        {

            textBox_Position.InvokeIfRequired(textBox_Position => { textBox_Position.Text = position.ToString(); });
        }

        private void FocuserValueChanged(object sender, FocuserValueChangedEventArgs e)
        {
            //this.textBoxCurrentPosition.Text = e.NewValue.ToString();
            SetCurrentPosition(e.NewValue);
        }

        private void SetCurrentState(bool isMoving)
        {
            if (label_Moving.InvokeRequired)
            {
                SetCurrentStateCallBack d = new SetCurrentStateCallBack(SetCurrentState);
                this.Invoke(d, new object[] { isMoving });
            }
            else
            {
                if (isMoving)
                {
                    label_Moving.Text = "MOVING...";
                }
                else
                {
                    label_Moving.Text = "READY...";
                }
            }
        }

        #region Changed EventArg Declaration

        private void FocuserHumidityChanged(object sender, FocuserHumidityChangedEventArgs e)
        {
            SetCurrentHumidity(e.Humidity);
        }

        private void FocuserTemperatureChanged(object sender, FocuserTemperatureChangedEventArgs e)
        {
            SetCurrentTemperature(e.Temperature);
        }

        private void FocuserStateChanged(object sender, FocuserStateChangedEventArgs e)
        {
            SetCurrentState(e.IsMoving);
        }
        #endregion

        private void InitControls()
        {
            textBox_Position.Text = focuser.Position.ToString();
            label_MS.Text = "MicroStepping Mode : ";
            switch (focuser.MicroStepMode)
            {
                case 1:
                    label_MS.Text += "1 (full step)";
                    focuser.Action("M", Convert.ToString(1));
                    break;

                case 2:
                    label_MS.Text += "2 (half step)";
                    focuser.Action("M", Convert.ToString(2));
                    break;

                case 3:
                    label_MS.Text += "3 (1/4 step)";
                    focuser.Action("M", Convert.ToString(3));
                    break;

                case 4:
                    label_MS.Text += "4 (1/8 step)";
                    focuser.Action("M", Convert.ToString(4));
                    break;
            }
        }

        private ResetForm resetForm;
        private void button_Reset_Click(object sender, EventArgs e)
        {
            resetForm = new ResetForm(this);
            resetForm.Show();
            InitControls();
        }

        private void button_Advanced_Click(object sender, EventArgs e)
        {
            panel_Advanced.Visible = !panel_Advanced.Visible;

            if (panel_Advanced.Visible)
            {
                this.Height = 430;
                button_Advanced.Text = "Briefly";
            }
            else
            {
                this.Height = 280;
                button_Advanced.Text = "Advanced";
            }
        }

        private void button_Apply_Click(object sender, EventArgs e)
        {
            focuser.Move(Convert.ToInt16(textBox_MoveTo.Text));
        }

        private void button_stop_Click(object sender, EventArgs e)
        {
            focuser.Halt();
        }

        private void button_moveleft_Click(object sender, EventArgs e)
        {
            focuser.CommandString("B", true);
        }

        private void button_moveright_Click(object sender, EventArgs e)
        {
            focuser.CommandString("C", true);
        }

        private void numericUpDown_SingleStep_ValueChanged(object sender, EventArgs e)
        {
            focuser.StepSize = Convert.ToDouble(numericUpDown_SingleStep.Value);
        }

        private void numericUpDown_Speed_ValueChanged(object sender, EventArgs e)
        {
            focuser.Action("J", numericUpDown_Speed.Value.ToString());
        }

        private void numericUpDown_Acceleration_ValueChanged(object sender, EventArgs e)
        {
            focuser.Action("H", numericUpDown_Acceleration.Value.ToString());
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            // do not disrupt the motor when it is moving
            if (!focuser.IsMoving)
            {
                System.Diagnostics.Debug.WriteLine("Getting Temperature");
                focuser.Action("k", "");
            }
        }

        private void groupBox_Advanced_Enter(object sender, EventArgs e)
        {

        }

        public String askPosition()
        {
            return focuser.Position.ToString();
        }
        public void applyPosition(String resetPosition)
        {
            focuser.Action("G", resetPosition);
            SetCurrentPosition(Convert.ToInt32(resetPosition));
            return;
        }

        private void MainWindow_Load(object sender, EventArgs e)
        {

        }

        private void label_GStouch_Click(object sender, EventArgs e)
        {

        }
    }

    #region ExtensionMethods

    public static class ExtensionMethods
    {
        public static void InvokeIfRequired(this TextBox control, Action<TextBox> action)
        {
            if (control.InvokeRequired)
            {
                control.Invoke(new Action(() => action(control)));
            }
            else
            {
                action(control);
            }
        }
    }
    #endregion
}
