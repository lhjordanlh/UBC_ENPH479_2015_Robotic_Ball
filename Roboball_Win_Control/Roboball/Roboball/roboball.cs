using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Roboball
{
    public partial class roboball : Form
    {
        //Initialize the parameter
        int vel = 0;
        int turn = 0;
        int joy_x = 49;
        int joy_y = 53;
        Point origin;
        private Queue<int> incoming_Data = new Queue<int>();

        public roboball()
        {
           InitializeComponent();
            origin = joystick.Location;
        }


        //////////////////////////////////////////////////////////////////////////////////////////////
        //The following functions and events are for connecting to the serial port
        private void bttnConnect_Click(object sender, EventArgs e)
        {
            if (drpListComPorts.SelectedItem != null)
            {
                if (serialPort.IsOpen)
                {
                    bttnConnect.Text = "Connect";
                    serialPort.Close();
                }
                else
                {
                    bttnConnect.Text = "Disconnect";
                    serialPort.PortName = drpListComPorts.SelectedItem.ToString();
                    serialPort.Open();
                }
            }
        }
        private void drpListComPorts_Click(object sender, EventArgs e)
        {
            if (!serialPort.IsOpen)
            {
                drpListComPorts.Items.Clear();
                drpListComPorts.Items.AddRange(System.IO.Ports.SerialPort.GetPortNames().ToArray());
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        private void joystickbackground_MouseMove(object sender, MouseEventArgs e)
        {
            joystick.Location = joystickbackground.PointToClient(Cursor.Position);
            joy_x = joystick.Location.X;
            joy_y = joystick.Location.Y;
            textBox_x.Text = turn.ToString();
            textBox_y.Text = vel.ToString();
        }

        private void joystickbackground_MouseLeave(object sender, EventArgs e)
        {
            joystick.Location = origin;
            textBox_y.Text = joystickbackground.PointToClient(Cursor.Position).ToString();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            textBox_y.Text = joystick.Location.Y.ToString();
            textBox_x.Text = joystick.Location.X.ToString();
        }

        
        private void sendData(int joy_x, int joy_y)
        {
            vel = 40- joy_y;
            turn = joy_x;
            if (vel <= 1) { vel = 1; }
            else if(vel>40) { vel = 40; }
            if (turn <=0) { turn = 1; }
            else if(turn> 100) { turn = 100; }

            byte[] TxBytes = new Byte[3];

            try
            {
                if (serialPort.IsOpen)
                {
                  TxBytes[0] = Convert.ToByte("255");
                  serialPort.Write(TxBytes, 0, 1);
                  TxBytes[1] = Convert.ToByte(vel.ToString());
                  serialPort.Write(TxBytes, 1, 1);
                  TxBytes[2] = Convert.ToByte(turn.ToString());
                  serialPort.Write(TxBytes, 2, 1);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void roboball_FormClosing(object sender, FormClosingEventArgs e)
        {
            serialPort.Close();
        }

        private void serialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            while (serialPort.BytesToRead > 0 && serialPort.IsOpen)
            {
                incoming_Data.Enqueue(serialPort.ReadByte());
            }
        }

        private void timerUpdate_Tick(object sender, EventArgs e)
        {
            while (incoming_Data.Count() > 0) {
                veldata.Text = incoming_Data.Dequeue().ToString();
            }
        }

        private void timerSend_Tick(object sender, EventArgs e)
        {
            sendData(joy_x, joy_y);
        }
    }
}