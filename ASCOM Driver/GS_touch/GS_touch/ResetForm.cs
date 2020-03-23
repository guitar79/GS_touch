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
    public partial class ResetForm : Form
    {
        private ASCOM.GS_touch.MainWindow mainWindow;
        public ResetForm(MainWindow mainWindow)
        {
            this.mainWindow = mainWindow;
            InitializeComponent();
            textBox_ResetPosition.Text = mainWindow.askPosition();
        }

        internal const int MaxStep = 500000;

        private void button_Reset_Click(object sender, EventArgs e)
        {
            if (Convert.ToInt32(textBox_ResetPosition.Text) > MaxStep || Convert.ToInt32(textBox_ResetPosition.Text) < 0)
            {
                System.Windows.Forms.MessageBox.Show("Reset Position Out of Range");
            }
            else
            {
                mainWindow.applyPosition(textBox_ResetPosition.Text);
                //mainWindow.SetCurrentPosition(Convert.ToInt32(textBox_ResetPosition));
                this.Close();
            }
        }

        private void button_Cancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
