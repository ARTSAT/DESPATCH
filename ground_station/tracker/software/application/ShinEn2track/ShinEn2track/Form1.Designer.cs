namespace ShinEn2track
{
    partial class Form1
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.textBox10 = new System.Windows.Forms.TextBox();
            this.textBox11 = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button3 = new System.Windows.Forms.Button();
            this.label10 = new System.Windows.Forms.Label();
            this.textBox12 = new System.Windows.Forms.TextBox();
            this.textBox14 = new System.Windows.Forms.TextBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.CustomFormat = "yyyy/MM/dd HH:mm:ss";
            this.dateTimePicker1.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dateTimePicker1.Location = new System.Drawing.Point(86, 15);
            this.dateTimePicker1.MaxDate = new System.DateTime(2014, 12, 20, 6, 22, 0, 0);
            this.dateTimePicker1.MinDate = new System.DateTime(2014, 12, 3, 6, 20, 12, 0);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.ShowUpDown = true;
            this.dateTimePicker1.Size = new System.Drawing.Size(163, 19);
            this.dateTimePicker1.TabIndex = 0;
            this.dateTimePicker1.Value = new System.DateTime(2014, 12, 3, 6, 20, 12, 0);
            this.dateTimePicker1.ValueChanged += new System.EventHandler(this.dateTimePicker1_ValueChanged);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(86, 51);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(74, 19);
            this.textBox1.TabIndex = 2;
            this.textBox1.Text = "1417587612";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 54);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 12);
            this.label1.TabIndex = 3;
            this.label1.Tag = "";
            this.label1.Text = "Unix Time";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(17, 20);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(28, 12);
            this.label2.TabIndex = 4;
            this.label2.Text = "UTC";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(18, 179);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(271, 22);
            this.button1.TabIndex = 5;
            this.button1.Text = "Get Shin-en2 Information";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(17, 210);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 12);
            this.label3.TabIndex = 6;
            this.label3.Text = "Time";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(17, 233);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 12);
            this.label4.TabIndex = 7;
            this.label4.Text = "Elevation";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(17, 259);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(46, 12);
            this.label5.TabIndex = 8;
            this.label5.Text = "Azimuth";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(17, 284);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(58, 12);
            this.label6.TabIndex = 9;
            this.label6.Text = "Down Link";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(16, 336);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(71, 12);
            this.label7.TabIndex = 10;
            this.label7.Text = "Distance (m)";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(17, 361);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(62, 12);
            this.label8.TabIndex = 11;
            this.label8.Text = "Declination";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(17, 386);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(89, 12);
            this.label9.TabIndex = 12;
            this.label9.Text = "Right Ascension";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(6, 28);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(46, 12);
            this.label11.TabIndex = 14;
            this.label11.Text = "Latitude";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(6, 50);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(54, 12);
            this.label12.TabIndex = 15;
            this.label12.Text = "Longitude";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(6, 72);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(45, 12);
            this.label13.TabIndex = 16;
            this.label13.Text = "Altitude";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(75, 25);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(74, 19);
            this.textBox2.TabIndex = 18;
            this.textBox2.Text = "35.610514";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(75, 47);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(74, 19);
            this.textBox3.TabIndex = 19;
            this.textBox3.Text = "139.351106";
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(75, 69);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(74, 19);
            this.textBox4.TabIndex = 20;
            this.textBox4.Text = "148";
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(97, 207);
            this.textBox5.Name = "textBox5";
            this.textBox5.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textBox5.Size = new System.Drawing.Size(101, 19);
            this.textBox5.TabIndex = 21;
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(97, 230);
            this.textBox6.Name = "textBox6";
            this.textBox6.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textBox6.Size = new System.Drawing.Size(101, 19);
            this.textBox6.TabIndex = 22;
            // 
            // textBox7
            // 
            this.textBox7.Location = new System.Drawing.Point(97, 256);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(101, 19);
            this.textBox7.TabIndex = 23;
            // 
            // textBox8
            // 
            this.textBox8.Location = new System.Drawing.Point(97, 281);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(101, 19);
            this.textBox8.TabIndex = 24;
            // 
            // textBox9
            // 
            this.textBox9.Location = new System.Drawing.Point(97, 333);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(101, 19);
            this.textBox9.TabIndex = 25;
            // 
            // textBox10
            // 
            this.textBox10.Location = new System.Drawing.Point(111, 358);
            this.textBox10.Name = "textBox10";
            this.textBox10.Size = new System.Drawing.Size(136, 19);
            this.textBox10.TabIndex = 26;
            // 
            // textBox11
            // 
            this.textBox11.Location = new System.Drawing.Point(111, 383);
            this.textBox11.Name = "textBox11";
            this.textBox11.Size = new System.Drawing.Size(136, 19);
            this.textBox11.TabIndex = 27;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(168, 46);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(40, 21);
            this.button2.TabIndex = 29;
            this.button2.Text = "Save";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click_1);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.textBox4);
            this.groupBox1.Controls.Add(this.textBox3);
            this.groupBox1.Controls.Add(this.textBox2);
            this.groupBox1.Controls.Add(this.label13);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Location = new System.Drawing.Point(11, 77);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(246, 98);
            this.groupBox1.TabIndex = 30;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Observer\'s Location";
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(263, 12);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(41, 22);
            this.button3.TabIndex = 31;
            this.button3.Text = "Now";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click_1);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(17, 311);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(44, 12);
            this.label10.TabIndex = 32;
            this.label10.Text = "Up Link";
            // 
            // textBox12
            // 
            this.textBox12.Location = new System.Drawing.Point(97, 308);
            this.textBox12.Name = "textBox12";
            this.textBox12.Size = new System.Drawing.Size(101, 19);
            this.textBox12.TabIndex = 33;
            // 
            // textBox14
            // 
            this.textBox14.Location = new System.Drawing.Point(224, 308);
            this.textBox14.Name = "textBox14";
            this.textBox14.Size = new System.Drawing.Size(63, 19);
            this.textBox14.TabIndex = 35;
            this.textBox14.Text = "145.942";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "435.270",
            "437.505",
            "437.385"});
            this.comboBox1.Location = new System.Drawing.Point(224, 281);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(65, 20);
            this.comboBox1.TabIndex = 36;
            this.comboBox1.Text = "435.270";
            // 
            // Form1
            // 
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(318, 415);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.textBox14);
            this.Controls.Add(this.textBox12);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.textBox11);
            this.Controls.Add(this.textBox10);
            this.Controls.Add(this.textBox9);
            this.Controls.Add(this.textBox8);
            this.Controls.Add(this.textBox7);
            this.Controls.Add(this.textBox6);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.dateTimePicker1);
            this.Name = "Form1";
            this.Text = "ShinEn2track20141213";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.TextBox textBox10;
        private System.Windows.Forms.TextBox textBox11;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBox12;
        private System.Windows.Forms.TextBox textBox14;
        private System.Windows.Forms.ComboBox comboBox1;

    }
}
