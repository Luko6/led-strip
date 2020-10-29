using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace led_controller
{
    public partial class Form1 : Form
    {
        //object serialport to listen usb
        System.IO.Ports.SerialPort Port;

        public Form1()
        {
            InitializeComponent();

            //configuration of arduino, you check if com3 is the port correct, 
            //in arduino ide you can make it
            Port = new System.IO.Ports.SerialPort();
            Port.PortName = "COM3";
            Port.BaudRate = 9600;
            Port.ReadTimeout = 500;

            try
            {
                Port.Open();
                Port.Write("FFFFFF");
                Port.Write("000000");
            }
            catch { }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Port.Write("000000");
            //when the form will be closed this line close the serial port
            if (Port.IsOpen)
                Port.Close();
        }

        private void btn_Red_Click(object sender, EventArgs e)
        {
            Port.Write("FF0000");
        }

        private void btn_Green_Click(object sender, EventArgs e)
        {
            Port.Write("00FF00");
        }

        private void btn_Blue_Click(object sender, EventArgs e)
        {
            Port.Write("0000FF");
        }

        private void btn_Purple_Click(object sender, EventArgs e)
        {
            Port.Write("FF00FF");
        }

        private void btn_Yellow_Click(object sender, EventArgs e)
        {
            Port.Write("FFFF00");
        }

        private void btn_Cyan_Click(object sender, EventArgs e)
        {
            Port.Write("00FFFF");
        }

        private void btn_Open_Click(object sender, EventArgs e)
        {
            if (!Port.IsOpen)
                Port.Open();
            Port.Write("FFFFFF");
        }

        private void btn_Close_Click(object sender, EventArgs e)
        {
            Port.Write("000000");
            if (Port.IsOpen)
                Port.Close();
        }

        private void btn_White_Click_1(object sender, EventArgs e)
        {
            Port.Write("FFFFFF");
        }

        private void btn_Off_Click_1(object sender, EventArgs e)
        {
            Port.Write("000000");
        }
    }
}