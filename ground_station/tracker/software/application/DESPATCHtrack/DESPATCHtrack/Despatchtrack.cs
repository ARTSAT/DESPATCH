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
//            [DataMember]
//            public double frequency { get; set; }
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

//            var jsonStr = @"{""time"": 1417436300, ""elevation"": 7.014275933903012, ""azimuth"": 223.29925819880032, ""frequency"": 437318391, ""distance"": 210195729, ""declination"": -29.68670318681606, ""right_ascension"": 22.52960541339547, ""mode"": ""baudot""}";

            var jsonStr = client.DownloadString("http://api.artsat.jp/despatch/track.json");
            var serializer = new DataContractJsonSerializer(typeof(DespatchInfo));
            var jsonBytes = Encoding.Unicode.GetBytes(jsonStr);
            var sr = new MemoryStream(jsonBytes);///System.IO
            var obj = (DespatchInfo)serializer.ReadObject(sr); 
            

            textBox5.Text = obj.time.ToString();
            textBox6.Text = obj.elevation.ToString();
            textBox7.Text = obj.azimuth.ToString();
            double frequency = 437.325 * obj.doppler_down;
            textBox8.Text = frequency.ToString();
            textBox9.Text = obj.distance.ToString();
            textBox10.Text = obj.declination.ToString();
            textBox11.Text = obj.right_ascension.ToString();
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
            DateTime endTime = new DateTime(2014, 12, 23, 06, 20, 0, 0, DateTimeKind.Utc);
            if (now < startTime){
                now = startTime;
            }else if(now > endTime){
                now = endTime;
            }
            dateTimePicker1.Value = now;
        }
    }
}
