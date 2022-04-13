using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;



// main code v 0.01
namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            button1.Enabled = false;
            button2.Enabled = false;
            button3.Enabled = false;
            button4.Enabled = false;
            button5.Enabled = false;
            button6.Enabled = false;
            button7.Enabled = false;
            button8.Enabled = false;
            button9.Enabled = false;
            button10.Enabled = false;
            button14.Enabled = false;
            button15.Enabled = false;
            checkBox1.Enabled = false;
        }

        string[] st;
        const String Filepath = @"e:\temp\Text.txt";

        private void button1_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт

            serialPort1.Write("left");
            //  using (StreamWriter sw = File.CreateText(Filepath))
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("left");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("right");
            // writefile("right");

            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("right");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("up1");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("up1");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("down1");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("down1");
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("up2");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("up2");
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("down2");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("down2");
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("delight");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("delight");
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("delight1");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("delight1");
            } 
        }

        private void button9_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("up3");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("up3");
            }
        }

        private void button10_Click(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("down3");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("down3");
            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            st = SerialPort.GetPortNames();
            for (int i = 0; i < st.Length; i++)
                comboBox1.Items.Add(st[i]);
        }

        private void button12_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                MessageBox.Show("Ви вже підключені до COM PORT", "COM PORT", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else if (comboBox1.SelectedItem == null)
            {
                MessageBox.Show("Не вибран COM PORT", "COM PORT", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            else
            {
                serialPort1.PortName = comboBox1.SelectedItem.ToString();
                serialPort1.BaudRate = 115200;
                serialPort1.Open();
                button1.Enabled = true;
                button2.Enabled = true;
                button3.Enabled = true;
                button4.Enabled = true;
                button5.Enabled = true;
                button6.Enabled = true;
                button7.Enabled = true;
                button8.Enabled = true;
                button9.Enabled = true;
                button10.Enabled = true;
                button14.Enabled = true;
                button15.Enabled = true;
                checkBox1.Enabled = true;
            }
        }

        private void button13_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                serialPort1.Close();
                comboBox1.Items.Clear();
                st = null;
                button1.Enabled = false;
                button2.Enabled = false;
                button3.Enabled = false;
                button4.Enabled = false;
                button5.Enabled = false;
                button6.Enabled = false;
                button7.Enabled = false;
                button8.Enabled = false;
                button9.Enabled = false;
                button10.Enabled = false;
                button14.Enabled = false;
                button15.Enabled = false;
                checkBox1.Enabled = false;
            }
            else
                MessageBox.Show("Немає підключення", "COM PORT", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button14_Click(object sender, EventArgs e)
        {
            serialPort1.Write("reset");
        }

        private void button15_Click(object sender, EventArgs e)
        {
            if (File.Exists(Filepath) != true)
                //Console.WriteLine("Немає такого файлу!");
                MessageBox.Show("Немає такого файлу!");
            else
            {
                string[] allText = File.ReadAllLines(Filepath);         //Read input data

                foreach (string s in allText)      //Output data
                {
                    serialPort1.Write(s);
                    Thread.Sleep(1000);
                    Console.WriteLine(s);
                }
                   
            }
        }

        private void button16_Click(object sender, EventArgs e)
        {
           // Передача данных из текстового поля в порт
            serialPort1.Write("left2");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("left2");
            }
         }

         private void button17_Click_1(object sender, EventArgs e)
        {
            // Передача данных из текстового поля в порт
            serialPort1.Write("right2");
            if (checkBox1.Checked == true)
            {
                using (StreamWriter sw = File.AppendText(Filepath))
                    sw.WriteLine("right2");
            }
        }


    }

}

