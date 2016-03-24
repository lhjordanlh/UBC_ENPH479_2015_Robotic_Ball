namespace Roboball
{
    partial class roboball
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(roboball));
            this.bttnConnect = new System.Windows.Forms.Button();
            this.drpListComPorts = new System.Windows.Forms.ComboBox();
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.joystick = new System.Windows.Forms.Button();
            this.joystickbackground = new System.Windows.Forms.PictureBox();
            this.textBox_y = new System.Windows.Forms.TextBox();
            this.textBox_x = new System.Windows.Forms.TextBox();
            this.veldata = new System.Windows.Forms.TextBox();
            this.timerSend = new System.Windows.Forms.Timer(this.components);
            this.timerUpdate = new System.Windows.Forms.Timer(this.components);
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.joystickbackground)).BeginInit();
            this.SuspendLayout();
            // 
            // bttnConnect
            // 
            this.bttnConnect.Location = new System.Drawing.Point(36, 145);
            this.bttnConnect.Name = "bttnConnect";
            this.bttnConnect.Size = new System.Drawing.Size(75, 23);
            this.bttnConnect.TabIndex = 0;
            this.bttnConnect.Text = "Connect";
            this.bttnConnect.UseVisualStyleBackColor = true;
            this.bttnConnect.Click += new System.EventHandler(this.bttnConnect_Click);
            // 
            // drpListComPorts
            // 
            this.drpListComPorts.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.drpListComPorts.FormattingEnabled = true;
            this.drpListComPorts.Location = new System.Drawing.Point(13, 79);
            this.drpListComPorts.Name = "drpListComPorts";
            this.drpListComPorts.Size = new System.Drawing.Size(121, 24);
            this.drpListComPorts.TabIndex = 1;
            this.drpListComPorts.Click += new System.EventHandler(this.drpListComPorts_Click);
            // 
            // serialPort
            // 
            this.serialPort.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort_DataReceived);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(7, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(138, 34);
            this.label1.TabIndex = 2;
            this.label1.Text = "Roboball";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.joystick);
            this.panel1.Controls.Add(this.joystickbackground);
            this.panel1.Location = new System.Drawing.Point(151, 21);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(160, 160);
            this.panel1.TabIndex = 3;
            // 
            // joystick
            // 
            this.joystick.BackColor = System.Drawing.Color.OrangeRed;
            this.joystick.Location = new System.Drawing.Point(65, 65);
            this.joystick.Name = "joystick";
            this.joystick.Size = new System.Drawing.Size(40, 40);
            this.joystick.TabIndex = 5;
            this.joystick.UseVisualStyleBackColor = false;
            // 
            // joystickbackground
            // 
            this.joystickbackground.Dock = System.Windows.Forms.DockStyle.Fill;
            this.joystickbackground.Image = ((System.Drawing.Image)(resources.GetObject("joystickbackground.Image")));
            this.joystickbackground.Location = new System.Drawing.Point(0, 0);
            this.joystickbackground.Margin = new System.Windows.Forms.Padding(0);
            this.joystickbackground.Name = "joystickbackground";
            this.joystickbackground.Size = new System.Drawing.Size(160, 160);
            this.joystickbackground.TabIndex = 4;
            this.joystickbackground.TabStop = false;
            this.joystickbackground.MouseLeave += new System.EventHandler(this.joystickbackground_MouseLeave);
            this.joystickbackground.MouseMove += new System.Windows.Forms.MouseEventHandler(this.joystickbackground_MouseMove);
            // 
            // textBox_y
            // 
            this.textBox_y.Location = new System.Drawing.Point(12, 109);
            this.textBox_y.Name = "textBox_y";
            this.textBox_y.Size = new System.Drawing.Size(55, 22);
            this.textBox_y.TabIndex = 6;
            // 
            // textBox_x
            // 
            this.textBox_x.Location = new System.Drawing.Point(79, 109);
            this.textBox_x.Name = "textBox_x";
            this.textBox_x.Size = new System.Drawing.Size(55, 22);
            this.textBox_x.TabIndex = 7;
            // 
            // veldata
            // 
            this.veldata.Location = new System.Drawing.Point(23, 8);
            this.veldata.Name = "veldata";
            this.veldata.Size = new System.Drawing.Size(100, 22);
            this.veldata.TabIndex = 8;
            // 
            // timerSend
            // 
            this.timerSend.Enabled = true;
            this.timerSend.Interval = 250;
            this.timerSend.Tick += new System.EventHandler(this.timerSend_Tick);
            // 
            // timerUpdate
            // 
            this.timerUpdate.Enabled = true;
            this.timerUpdate.Tick += new System.EventHandler(this.timerUpdate_Tick);
            // 
            // roboball
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(323, 193);
            this.Controls.Add(this.veldata);
            this.Controls.Add(this.textBox_x);
            this.Controls.Add(this.textBox_y);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.drpListComPorts);
            this.Controls.Add(this.bttnConnect);
            this.Name = "roboball";
            this.Text = "Roboball";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.roboball_FormClosing);
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.joystickbackground)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bttnConnect;
        private System.Windows.Forms.ComboBox drpListComPorts;
        private System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button joystick;
        private System.Windows.Forms.TextBox textBox_y;
        private System.Windows.Forms.PictureBox joystickbackground;
        private System.Windows.Forms.TextBox textBox_x;
        private System.Windows.Forms.TextBox veldata;
        private System.Windows.Forms.Timer timerSend;
        private System.Windows.Forms.Timer timerUpdate;
    }
}

