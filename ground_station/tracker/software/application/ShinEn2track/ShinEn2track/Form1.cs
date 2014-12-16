using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Net;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.IO;

namespace ShinEn2track
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            string[] iniSet = File.ReadAllLines(@"ShinEn2track.ini");
            textBox2.Text = iniSet[0];
            textBox3.Text = iniSet[1];
            textBox4.Text = iniSet[2];
        }

        [DataContract]
        public class DespatchInfo
        {
            [DataMember]
            public double time { get; set; }
            [DataMember]
            public double elevation { get; set; }
            [DataMember]
            public double azimuth { get; set; }
            [DataMember]
            public double doppler_down { get; set; }
            [DataMember]
            public double doppler_up { get; set; }
            [DataMember]
            public double distance { get; set; }
            [DataMember]
            public double declination { get; set; }
            [DataMember]
            public double right_ascension { get; set; }
//            [DataMember]
//            public string phase { get; set; }
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            DateTime dtStart = new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Local);//from 1970/1/1 00:00:00 to now
            DateTime dtSource1 = dateTimePicker1.Value;
            TimeSpan resultTime = dtSource1.Subtract(dtStart);
            double unixTimeSource = resultTime.TotalSeconds;
            unixTimeSource = Math.Floor(unixTimeSource);
            textBox1.Text = unixTimeSource.ToString();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            WebClient client = new WebClient();
            client.QueryString["time"] = textBox1.Text;
            client.QueryString["lat"] = textBox2.Text;
            client.QueryString["lon"] = textBox3.Text;
            client.QueryString["alt"] = textBox4.Text;

            var jsonStr = client.DownloadString("http://api.artsat.jp/sinen2/track.json");
            var serializer = new DataContractJsonSerializer(typeof(DespatchInfo));
            var jsonBytes = Encoding.Unicode.GetBytes(jsonStr);
            var sr = new MemoryStream(jsonBytes);///System.IO
            var obj = (DespatchInfo)serializer.ReadObject(sr);


            textBox5.Text = obj.time.ToString();
            textBox6.Text = obj.elevation.ToString();
            textBox7.Text = obj.azimuth.ToString();
            double dFrequency = double.Parse(comboBox1.SelectedItem.ToString());
            if (dFrequency == 0)
            {
                dFrequency = 435.270;
            }
            double frequency = dFrequency * obj.doppler_down;
            textBox8.Text = frequency.ToString();
            double uFrequency = double.Parse(textBox14.Text.ToString());
            frequency = uFrequency * obj.doppler_up;
            textBox12.Text = frequency.ToString();
            textBox9.Text = obj.distance.ToString();
            textBox10.Text = obj.declination.ToString();
            textBox11.Text = obj.right_ascension.ToString();
            //            textBox12.Text = obj.phase;
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            DateTime now = DateTime.UtcNow;
            DateTime startTime = new DateTime(2014, 12, 03, 06, 20, 12, 0, DateTimeKind.Utc);
            DateTime endTime = new DateTime(2014, 12, 20, 06, 22, 0, 0, DateTimeKind.Utc);
            if (now < startTime)
            {
                now = startTime;
            }
            else if (now > endTime)
            {
                now = endTime;
            }
            dateTimePicker1.Value = now;
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            File.WriteAllText(@"ShinEn2track.ini", textBox2.Text + "\n" + textBox3.Text + "\n" + textBox4.Text);
        }
    }
}
