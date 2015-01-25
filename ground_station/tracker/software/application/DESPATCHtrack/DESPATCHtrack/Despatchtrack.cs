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

namespace DESPATCHtrack
{
    public partial class Despatchtrack : Form
    {
        public Despatchtrack()
        {
            InitializeComponent();
            string[] iniSet = File.ReadAllLines(@"DESPATCHtrack.ini");
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
            [DataMember]
            public string phase { get; set; }
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

        private void button1_Click(object sender, EventArgs e)
        {
            WebClient client = new WebClient();
            client.QueryString["time"] = textBox1.Text;
            client.QueryString["lat"] = textBox2.Text;
            client.QueryString["lon"] = textBox3.Text;
            client.QueryString["alt"] = textBox4.Text;

            var jsonStr = client.DownloadString("http://api.artsat.jp/despatch/track.json");
            var serializer = new DataContractJsonSerializer(typeof(DespatchInfo));
            var jsonBytes = Encoding.Unicode.GetBytes(jsonStr);
            var sr = new MemoryStream(jsonBytes);///System.IO
            var obj = (DespatchInfo)serializer.ReadObject(sr); 
            

            textBox5.Text = obj.time.ToString();
            textBox6.Text = obj.elevation.ToString("N6");
            textBox7.Text = obj.azimuth.ToString("N6");
            double frequency = 437.325 * obj.doppler_down;
            textBox8.Text = frequency.ToString("N6");
            double distance = obj.distance / 1000d;
            textBox9.Text = distance.ToString("N0");
            textBox10.Text = obj.declination.ToString("N6");
            textBox11.Text = obj.right_ascension.ToString("N6");
            textBox12.Text = obj.phase;

        }

        private void button2_Click(object sender, EventArgs e)
        {
            File.WriteAllText(@"DESPATCHtrack.ini", textBox2.Text + "\n" + textBox3.Text + "\n" + textBox4.Text);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            DateTime now = DateTime.UtcNow;
            DateTime startTime = new DateTime(2014, 12, 03, 06, 20, 12, 0, DateTimeKind.Utc);
//            DateTime endTime = new DateTime(2015, 01, 02, 06, 20, 0, 0, DateTimeKind.Utc);
            if (now < startTime){
                now = startTime;
//            }else if(now > endTime){
//                now = endTime;
            }
            dateTimePicker1.Value = now;
        }
    }
}
