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
using Newtonsoft.Json;

using System.IO;

namespace DESPATCHpass
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            string[] iniSet = File.ReadAllLines(@"DESPATCHpass.ini");
            textBox2.Text = iniSet[0];
            textBox3.Text = iniSet[1];
            textBox4.Text = iniSet[2];
        }

        public readonly static DateTime UnixEpoch = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);

        [DataContract]
        public class DespatchInfo
        {
            [DataMember(Name = "time")]
            public int time { get; set; }
            [DataMember(Name = "elevation")]
            public double elevation { get; set; }
            [DataMember(Name = "azimuth")]
            public double azimuth { get; set; }
//            [DataMember(Name = "frequency")]
//            public int frequency { get; set; }
            [DataMember]
            public double doppler_down { get; set; }
            [DataMember]
            public double doppler_up { get; set; }
            [DataMember(Name = "distance")]
            public double distance { get; set; }
            [DataMember(Name = "declination")]
            public double declination { get; set; }
            [DataMember(Name = "right_ascension")]
            public double right_ascension { get; set; }
            [DataMember(Name = "phase")]
            public string phase { get; set; }
        }

        [DataContract]
        public class Pass
        {
            [DataContract]
            public class Aos
            {
                [DataMember(Name = "aos")]
                public DespatchInfo aos { get; set; }
            }

            [DataContract]
            public class Tca
            {
                [DataMember(Name = "tca")]
                public DespatchInfo tca { get; set; }
            }

            [DataContract]
            public class Los
            {
                [DataMember(Name = "los")]
                public DespatchInfo los { get; set; }
            }
        }



        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
//            DateTime dtStart = new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Local);
            DateTime dtSource1 = dateTimePicker1.Value;
//            TimeSpan resultTime = dtSource1.Subtract(dtStart);
            TimeSpan resultTime = dtSource1.Subtract(UnixEpoch);
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

            var gotData = client.DownloadString("http://api.artsat.jp/despatch/pass.json");
            List<Pass.Aos> despatchPasses1 = JsonConvert.DeserializeObject<List<Pass.Aos>>(gotData);
            List<Pass.Tca> despatchPasses2 = JsonConvert.DeserializeObject<List<Pass.Tca>>(gotData);
            List<Pass.Los> despatchPasses3 = JsonConvert.DeserializeObject<List<Pass.Los>>(gotData);

            double despatchFreq = 437.325;
            
            int val = 0;

            Pass.Aos despatchPass1 = despatchPasses1[val];
            Pass.Tca despatchPass2 = despatchPasses2[val];
            Pass.Los despatchPass3 = despatchPasses3[val];

            textBox5.Text = despatchPass1.aos.time.ToString();
            textBox6.Text = despatchPass2.tca.time.ToString();
            textBox7.Text = despatchPass3.los.time.ToString();

            textBox29.Text = UnixEpoch.AddSeconds(despatchPass1.aos.time).ToString();
            textBox30.Text = UnixEpoch.AddSeconds(despatchPass2.tca.time).ToString();
            textBox31.Text = UnixEpoch.AddSeconds(despatchPass3.los.time).ToString();

            textBox8.Text = despatchPass1.aos.elevation.ToString();
            textBox9.Text = despatchPass2.tca.elevation.ToString();
            textBox10.Text = despatchPass3.los.elevation.ToString();

            textBox11.Text = despatchPass1.aos.azimuth.ToString();
            textBox12.Text = despatchPass2.tca.azimuth.ToString();
            textBox13.Text = despatchPass3.los.azimuth.ToString();

            double frequency = despatchFreq * despatchPass1.aos.doppler_down;
            textBox14.Text = frequency.ToString();
            frequency = despatchFreq * despatchPass2.tca.doppler_down;
            textBox15.Text = frequency.ToString();
            frequency = despatchFreq * despatchPass3.los.doppler_down;
            textBox16.Text = frequency.ToString();

            textBox17.Text = despatchPass1.aos.distance.ToString();
            textBox18.Text = despatchPass2.tca.distance.ToString();
            textBox19.Text = despatchPass3.los.distance.ToString();

            textBox20.Text = despatchPass1.aos.declination.ToString();
            textBox21.Text = despatchPass2.tca.declination.ToString();
            textBox22.Text = despatchPass3.los.declination.ToString();

            textBox23.Text = despatchPass1.aos.right_ascension.ToString();
            textBox24.Text = despatchPass2.tca.right_ascension.ToString();
            textBox25.Text = despatchPass3.los.right_ascension.ToString();

            textBox26.Text = despatchPass1.aos.phase.ToString();
            textBox27.Text = despatchPass2.tca.phase.ToString();
            textBox28.Text = despatchPass3.los.phase.ToString();

            val = 1;

            despatchPass1 = despatchPasses1[val];
            despatchPass2 = despatchPasses2[val];
            despatchPass3 = despatchPasses3[val];

            textBox58.Text = despatchPass1.aos.time.ToString();
            textBox57.Text = despatchPass2.tca.time.ToString();
            textBox56.Text = despatchPass3.los.time.ToString();

            textBox34.Text = UnixEpoch.AddSeconds(despatchPass1.aos.time).ToString();
            textBox33.Text = UnixEpoch.AddSeconds(despatchPass2.tca.time).ToString();
            textBox32.Text = UnixEpoch.AddSeconds(despatchPass3.los.time).ToString();

            textBox55.Text = despatchPass1.aos.elevation.ToString();
            textBox54.Text = despatchPass2.tca.elevation.ToString();
            textBox53.Text = despatchPass3.los.elevation.ToString();

            textBox52.Text = despatchPass1.aos.azimuth.ToString();
            textBox51.Text = despatchPass2.tca.azimuth.ToString();
            textBox50.Text = despatchPass3.los.azimuth.ToString();

            frequency = despatchFreq * despatchPass1.aos.doppler_down;
            textBox49.Text = frequency.ToString();
            frequency = despatchFreq * despatchPass2.tca.doppler_down;
            textBox48.Text = frequency.ToString();
            frequency = despatchFreq * despatchPass3.los.doppler_down;
            textBox47.Text = frequency.ToString();

            textBox46.Text = despatchPass1.aos.distance.ToString();
            textBox45.Text = despatchPass2.tca.distance.ToString();
            textBox44.Text = despatchPass3.los.distance.ToString();

            textBox43.Text = despatchPass1.aos.declination.ToString();
            textBox42.Text = despatchPass2.tca.declination.ToString();
            textBox41.Text = despatchPass3.los.declination.ToString();

            textBox40.Text = despatchPass1.aos.right_ascension.ToString();
            textBox39.Text = despatchPass2.tca.right_ascension.ToString();
            textBox38.Text = despatchPass3.los.right_ascension.ToString();

            textBox37.Text = despatchPass1.aos.phase.ToString();
            textBox36.Text = despatchPass2.tca.phase.ToString();
            textBox35.Text = despatchPass3.los.phase.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            File.WriteAllText(@"DESPATCHpass.ini", textBox2.Text +"\n"+ textBox3.Text +"\n"+ textBox4.Text);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            DateTime now = DateTime.UtcNow;
            DateTime startTime = new DateTime(2014, 12, 03, 06, 20, 12, 0, DateTimeKind.Utc);
            DateTime endTime = new DateTime(2014, 12, 11, 18, 35, 59, 0, DateTimeKind.Utc);
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

    }
}
