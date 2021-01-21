namespace G191210068_proje
{
    partial class Form1
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
            this.YeniOyunButon = new System.Windows.Forms.Button();
            this.CamYuzde = new System.Windows.Forms.ProgressBar();
            this.OrganikAtıkYuzde = new System.Windows.Forms.ProgressBar();
            this.KagitYuzde = new System.Windows.Forms.ProgressBar();
            this.MetalYuzde = new System.Windows.Forms.ProgressBar();
            this.OrganikAtikBosalt = new System.Windows.Forms.Button();
            this.KagitBosalt = new System.Windows.Forms.Button();
            this.CamBosalt = new System.Windows.Forms.Button();
            this.MetalBosalt = new System.Windows.Forms.Button();
            this.Cikis = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.Sure = new System.Windows.Forms.TextBox();
            this.Puan = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.Cam = new System.Windows.Forms.ListBox();
            this.Metal = new System.Windows.Forms.ListBox();
            this.OrganikAtık = new System.Windows.Forms.ListBox();
            this.Kagit = new System.Windows.Forms.ListBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.OrganikAtikEkle = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.KagitEkle = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.MetalEkle = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.CamEkle = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.AtıkResim = new System.Windows.Forms.PictureBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AtıkResim)).BeginInit();
            this.groupBox6.SuspendLayout();
            this.SuspendLayout();
            // 
            // YeniOyunButon
            // 
            this.YeniOyunButon.BackColor = System.Drawing.Color.DarkSlateGray;
            this.YeniOyunButon.Location = new System.Drawing.Point(9, 16);
            this.YeniOyunButon.Name = "YeniOyunButon";
            this.YeniOyunButon.Size = new System.Drawing.Size(171, 43);
            this.YeniOyunButon.TabIndex = 1;
            this.YeniOyunButon.Text = "YENİ OYUN";
            this.YeniOyunButon.UseVisualStyleBackColor = false;
            this.YeniOyunButon.Click += new System.EventHandler(this.YeniOyunButon_Click);
            // 
            // CamYuzde
            // 
            this.CamYuzde.Location = new System.Drawing.Point(22, 228);
            this.CamYuzde.Name = "CamYuzde";
            this.CamYuzde.Size = new System.Drawing.Size(125, 21);
            this.CamYuzde.TabIndex = 3;
            // 
            // OrganikAtıkYuzde
            // 
            this.OrganikAtıkYuzde.Location = new System.Drawing.Point(22, 222);
            this.OrganikAtıkYuzde.Name = "OrganikAtıkYuzde";
            this.OrganikAtıkYuzde.Size = new System.Drawing.Size(125, 21);
            this.OrganikAtıkYuzde.TabIndex = 4;
            // 
            // KagitYuzde
            // 
            this.KagitYuzde.Location = new System.Drawing.Point(22, 222);
            this.KagitYuzde.Name = "KagitYuzde";
            this.KagitYuzde.Size = new System.Drawing.Size(125, 21);
            this.KagitYuzde.TabIndex = 5;
            // 
            // MetalYuzde
            // 
            this.MetalYuzde.Location = new System.Drawing.Point(22, 230);
            this.MetalYuzde.Name = "MetalYuzde";
            this.MetalYuzde.Size = new System.Drawing.Size(125, 21);
            this.MetalYuzde.TabIndex = 6;
            // 
            // OrganikAtikBosalt
            // 
            this.OrganikAtikBosalt.Location = new System.Drawing.Point(22, 249);
            this.OrganikAtikBosalt.Name = "OrganikAtikBosalt";
            this.OrganikAtikBosalt.Size = new System.Drawing.Size(125, 33);
            this.OrganikAtikBosalt.TabIndex = 7;
            this.OrganikAtikBosalt.Text = "BOŞALT";
            this.OrganikAtikBosalt.UseVisualStyleBackColor = true;
            this.OrganikAtikBosalt.Click += new System.EventHandler(this.OrganikAtikBosalt_Click);
            // 
            // KagitBosalt
            // 
            this.KagitBosalt.Location = new System.Drawing.Point(22, 249);
            this.KagitBosalt.Name = "KagitBosalt";
            this.KagitBosalt.Size = new System.Drawing.Size(125, 33);
            this.KagitBosalt.TabIndex = 8;
            this.KagitBosalt.Text = "BOŞALT";
            this.KagitBosalt.UseVisualStyleBackColor = true;
            this.KagitBosalt.Click += new System.EventHandler(this.KagitBosalt_Click);
            // 
            // CamBosalt
            // 
            this.CamBosalt.Location = new System.Drawing.Point(22, 255);
            this.CamBosalt.Name = "CamBosalt";
            this.CamBosalt.Size = new System.Drawing.Size(125, 33);
            this.CamBosalt.TabIndex = 9;
            this.CamBosalt.Text = "BOŞALT";
            this.CamBosalt.UseVisualStyleBackColor = true;
            this.CamBosalt.Click += new System.EventHandler(this.CamBosalt_Click);
            // 
            // MetalBosalt
            // 
            this.MetalBosalt.Location = new System.Drawing.Point(22, 258);
            this.MetalBosalt.Name = "MetalBosalt";
            this.MetalBosalt.Size = new System.Drawing.Size(125, 30);
            this.MetalBosalt.TabIndex = 10;
            this.MetalBosalt.Text = "BOŞALT";
            this.MetalBosalt.UseVisualStyleBackColor = true;
            this.MetalBosalt.Click += new System.EventHandler(this.MetalBosalt_Click);
            // 
            // Cikis
            // 
            this.Cikis.BackColor = System.Drawing.Color.DarkSlateGray;
            this.Cikis.Location = new System.Drawing.Point(9, 358);
            this.Cikis.Name = "Cikis";
            this.Cikis.Size = new System.Drawing.Size(171, 36);
            this.Cikis.TabIndex = 11;
            this.Cikis.Text = "ÇIKIŞ";
            this.Cikis.UseVisualStyleBackColor = false;
            this.Cikis.Click += new System.EventHandler(this.Cikis_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.Teal;
            this.textBox1.Location = new System.Drawing.Point(9, 65);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(171, 41);
            this.textBox1.TabIndex = 12;
            this.textBox1.Text = " SÜRE";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Sure
            // 
            this.Sure.BackColor = System.Drawing.Color.Turquoise;
            this.Sure.Font = new System.Drawing.Font("Microsoft Sans Serif", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.Sure.Location = new System.Drawing.Point(9, 106);
            this.Sure.Multiline = true;
            this.Sure.Name = "Sure";
            this.Sure.Size = new System.Drawing.Size(171, 91);
            this.Sure.TabIndex = 13;
            this.Sure.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Puan
            // 
            this.Puan.BackColor = System.Drawing.Color.Turquoise;
            this.Puan.Font = new System.Drawing.Font("Microsoft Sans Serif", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.Puan.Location = new System.Drawing.Point(9, 262);
            this.Puan.Multiline = true;
            this.Puan.Name = "Puan";
            this.Puan.Size = new System.Drawing.Size(171, 80);
            this.Puan.TabIndex = 15;
            this.Puan.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox4
            // 
            this.textBox4.BackColor = System.Drawing.Color.Teal;
            this.textBox4.Location = new System.Drawing.Point(9, 225);
            this.textBox4.Multiline = true;
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(171, 42);
            this.textBox4.TabIndex = 14;
            this.textBox4.Text = " PUAN";
            this.textBox4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Cam
            // 
            this.Cam.BackColor = System.Drawing.SystemColors.Info;
            this.Cam.FormattingEnabled = true;
            this.Cam.Location = new System.Drawing.Point(22, 51);
            this.Cam.Name = "Cam";
            this.Cam.Size = new System.Drawing.Size(125, 173);
            this.Cam.TabIndex = 16;
            // 
            // Metal
            // 
            this.Metal.BackColor = System.Drawing.SystemColors.Info;
            this.Metal.FormattingEnabled = true;
            this.Metal.Location = new System.Drawing.Point(22, 51);
            this.Metal.Name = "Metal";
            this.Metal.Size = new System.Drawing.Size(125, 173);
            this.Metal.TabIndex = 17;
            // 
            // OrganikAtık
            // 
            this.OrganikAtık.BackColor = System.Drawing.SystemColors.Info;
            this.OrganikAtık.FormattingEnabled = true;
            this.OrganikAtık.Location = new System.Drawing.Point(22, 43);
            this.OrganikAtık.Name = "OrganikAtık";
            this.OrganikAtık.Size = new System.Drawing.Size(125, 173);
            this.OrganikAtık.TabIndex = 18;
            // 
            // Kagit
            // 
            this.Kagit.BackColor = System.Drawing.SystemColors.Info;
            this.Kagit.FormattingEnabled = true;
            this.Kagit.Location = new System.Drawing.Point(22, 43);
            this.Kagit.Name = "Kagit";
            this.Kagit.Size = new System.Drawing.Size(125, 173);
            this.Kagit.TabIndex = 19;
            // 
            // textBox7
            // 
            this.textBox7.BackColor = System.Drawing.SystemColors.Info;
            this.textBox7.Location = new System.Drawing.Point(222, 13);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(344, 20);
            this.textBox7.TabIndex = 24;
            this.textBox7.Text = "ATIK KUTULARI";
            this.textBox7.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Teal;
            this.groupBox1.Controls.Add(this.OrganikAtikEkle);
            this.groupBox1.Controls.Add(this.OrganikAtık);
            this.groupBox1.Controls.Add(this.OrganikAtıkYuzde);
            this.groupBox1.Controls.Add(this.OrganikAtikBosalt);
            this.groupBox1.Location = new System.Drawing.Point(222, 39);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(168, 292);
            this.groupBox1.TabIndex = 25;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "groupBox1";
            // 
            // OrganikAtikEkle
            // 
            this.OrganikAtikEkle.Location = new System.Drawing.Point(22, 13);
            this.OrganikAtikEkle.Name = "OrganikAtikEkle";
            this.OrganikAtikEkle.Size = new System.Drawing.Size(125, 24);
            this.OrganikAtikEkle.TabIndex = 19;
            this.OrganikAtikEkle.Text = "ORGANİK ATIK";
            this.OrganikAtikEkle.UseVisualStyleBackColor = true;
            this.OrganikAtikEkle.Click += new System.EventHandler(this.OrganikAtikEkle_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.Color.Teal;
            this.groupBox2.Controls.Add(this.KagitEkle);
            this.groupBox2.Controls.Add(this.Kagit);
            this.groupBox2.Controls.Add(this.KagitYuzde);
            this.groupBox2.Controls.Add(this.KagitBosalt);
            this.groupBox2.Location = new System.Drawing.Point(396, 39);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(170, 292);
            this.groupBox2.TabIndex = 26;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "groupBox2";
            // 
            // KagitEkle
            // 
            this.KagitEkle.Location = new System.Drawing.Point(22, 13);
            this.KagitEkle.Name = "KagitEkle";
            this.KagitEkle.Size = new System.Drawing.Size(125, 24);
            this.KagitEkle.TabIndex = 20;
            this.KagitEkle.Text = "KAĞIT";
            this.KagitEkle.UseVisualStyleBackColor = true;
            this.KagitEkle.Click += new System.EventHandler(this.KagitEkle_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.BackColor = System.Drawing.Color.Teal;
            this.groupBox3.Controls.Add(this.MetalEkle);
            this.groupBox3.Controls.Add(this.Metal);
            this.groupBox3.Controls.Add(this.MetalYuzde);
            this.groupBox3.Controls.Add(this.MetalBosalt);
            this.groupBox3.Location = new System.Drawing.Point(396, 337);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(170, 297);
            this.groupBox3.TabIndex = 27;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "groupBox3";
            // 
            // MetalEkle
            // 
            this.MetalEkle.Location = new System.Drawing.Point(22, 21);
            this.MetalEkle.Name = "MetalEkle";
            this.MetalEkle.Size = new System.Drawing.Size(125, 24);
            this.MetalEkle.TabIndex = 22;
            this.MetalEkle.Text = "METAL";
            this.MetalEkle.UseVisualStyleBackColor = true;
            this.MetalEkle.Click += new System.EventHandler(this.MetalEkle_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.BackColor = System.Drawing.Color.Teal;
            this.groupBox4.Controls.Add(this.CamEkle);
            this.groupBox4.Controls.Add(this.Cam);
            this.groupBox4.Controls.Add(this.CamYuzde);
            this.groupBox4.Controls.Add(this.CamBosalt);
            this.groupBox4.Location = new System.Drawing.Point(222, 337);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(168, 297);
            this.groupBox4.TabIndex = 28;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "groupBox4";
            // 
            // CamEkle
            // 
            this.CamEkle.Location = new System.Drawing.Point(22, 21);
            this.CamEkle.Name = "CamEkle";
            this.CamEkle.Size = new System.Drawing.Size(125, 24);
            this.CamEkle.TabIndex = 21;
            this.CamEkle.Text = "CAM";
            this.CamEkle.UseVisualStyleBackColor = true;
            this.CamEkle.Click += new System.EventHandler(this.CamEkle_Click);
            // 
            // groupBox5
            // 
            this.groupBox5.BackColor = System.Drawing.SystemColors.Info;
            this.groupBox5.Controls.Add(this.AtıkResim);
            this.groupBox5.Location = new System.Drawing.Point(12, 13);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(191, 201);
            this.groupBox5.TabIndex = 29;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "groupBox5";
            // 
            // AtıkResim
            // 
            this.AtıkResim.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.AtıkResim.Location = new System.Drawing.Point(9, 27);
            this.AtıkResim.Name = "AtıkResim";
            this.AtıkResim.Size = new System.Drawing.Size(171, 153);
            this.AtıkResim.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.AtıkResim.TabIndex = 0;
            this.AtıkResim.TabStop = false;
            // 
            // groupBox6
            // 
            this.groupBox6.BackColor = System.Drawing.SystemColors.Info;
            this.groupBox6.Controls.Add(this.YeniOyunButon);
            this.groupBox6.Controls.Add(this.Puan);
            this.groupBox6.Controls.Add(this.Cikis);
            this.groupBox6.Controls.Add(this.textBox1);
            this.groupBox6.Controls.Add(this.Sure);
            this.groupBox6.Controls.Add(this.textBox4);
            this.groupBox6.Location = new System.Drawing.Point(12, 219);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(191, 415);
            this.groupBox6.TabIndex = 30;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "groupBox6";
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkSlateGray;
            this.ClientSize = new System.Drawing.Size(590, 648);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.textBox7);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.AtıkResim)).EndInit();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox AtıkResim;
        private System.Windows.Forms.Button YeniOyunButon;
        private System.Windows.Forms.ProgressBar CamYuzde;
        private System.Windows.Forms.ProgressBar OrganikAtıkYuzde;
        private System.Windows.Forms.ProgressBar KagitYuzde;
        private System.Windows.Forms.ProgressBar MetalYuzde;
        private System.Windows.Forms.Button OrganikAtikBosalt;
        private System.Windows.Forms.Button KagitBosalt;
        private System.Windows.Forms.Button CamBosalt;
        private System.Windows.Forms.Button MetalBosalt;
        private System.Windows.Forms.Button Cikis;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox Sure;
        private System.Windows.Forms.TextBox Puan;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.ListBox Cam;
        private System.Windows.Forms.ListBox Metal;
        private System.Windows.Forms.ListBox OrganikAtık;
        private System.Windows.Forms.ListBox Kagit;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button OrganikAtikEkle;
        private System.Windows.Forms.Button KagitEkle;
        private System.Windows.Forms.Button MetalEkle;
        private System.Windows.Forms.Button CamEkle;
    }
}

