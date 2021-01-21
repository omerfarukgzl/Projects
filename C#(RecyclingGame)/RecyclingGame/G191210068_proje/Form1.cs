using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace G191210068_proje
{
    public partial class Form1 : Form
    {
        public class Atik : IAtikKutusu, IAtik
        {
            public bool eklendi = true;
            public bool bosaltildi = true;
            private int hacim;
            private int bosaltmaPuani;
            private int kapasite;
            private int doluHacim;
            private int dolulukOrani;
            public int Kapasite
            {
                get
                {
                    return kapasite;
                }
                set
                {
                    kapasite = value;
                }
            }
            public int DoluHacim
            {
                get
                {
                    return doluHacim;
                }
                set
                {
                    doluHacim = value;
                }
            }
            public int DolulukOrani
            {
                get
                {
                    return dolulukOrani;
                }
                set
                {
                    dolulukOrani = value;
                }
            }
            public int BosaltmaPuani
            {
                get
                {
                    return bosaltmaPuani;
                }
                set
                {
                    bosaltmaPuani = value;
                }
            }
            public int Hacim
            {
                get
                {
                    return hacim;
                }
                set
                {
                    hacim = value;
                }
            }
            public bool Ekle(Atik atik)
            {
                atik.DoluHacim += atik.Hacim;
                atik.DolulukOrani = (atik.DoluHacim*100) / (atik.Kapasite);
                if (atik.DolulukOrani <100)//yeni eklenecek atıkla birlikte kutu doluluk oranı %100 ün altında olursa true döner ve atık kutusuna kalıtım alarak eklenir.
                {
                    eklendi = true;
                }
                else//yeni eklenecek atıkla birlikte kutu doluluk oranı %100 ün üstünde olursa false döner ve atık kutusuna kalıtım alarak eklenmez.
                {
                    eklendi = false;
                }
                return eklendi;
            }
            public bool Bosalt()
            {
                if (DolulukOrani <= 75)//atık kutusu doluluk oranı %75 üstünde ise boşalt butonu kalıtım alınarak aktif hale getirilir ve kutu boşaltılır.
                {
                    bosaltildi = false;
                }
                else//atık kutusu doluluk oranı %75 altnda ise boşalt butonu kalıtım alınarak aktif halden çıkar.
                {
                    bosaltildi = true;
                }
                return bosaltildi;
            }
        }
        public interface IAtik
        {
            int Hacim { get; set; }
        }
        public interface IAtikKutusu : IDolabilen 
        {
            int BosaltmaPuani { get; set; }
            bool Ekle(Atik atik);
            bool Bosalt();
        }
        public interface IDolabilen
        {
            int Kapasite { get; set;}
            int DoluHacim { get; set; }
            int DolulukOrani { get; set; }
        }
        public Form1()
        {
            InitializeComponent();
        }
        public string[] resimler = Directory.GetFiles(@"Resimler"); //resimler diziye aktarılır ve bu diziden rastgele resimler seçilir.
        Random ResimSayi = new Random();
        public int puan = 0;
        public int saniye = 60;
        private void Form1_Load(object sender, EventArgs e)
        {
            Sure.Text = Convert.ToString(saniye);
            Puan.Text = Convert.ToString(puan);
        }
        private void YeniOyunButon_Click(object sender, EventArgs e)//yeni oyun butonu
        {
            saniye = 60;
            puan = 0;
            Sure.Text = Convert.ToString(saniye);
            Puan.Text = Convert.ToString(puan);
            OrganikAtık.Items.Clear();
            Kagit.Items.Clear();
            Cam.Items.Clear();
            Metal.Items.Clear();
            OrganikAtıkYuzde.Value = 0;
            KagitYuzde.Value = 0;
            CamYuzde.Value = 0;
            MetalYuzde.Value = 0;
            Organik.DoluHacim = 0;
            KagitAtik.DoluHacim = 0;
            CamAtik.DoluHacim = 0;
            MetalAtik.DoluHacim = 0;
            AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length-1)];
            OrganikAtikBosalt.Enabled = true;
            OrganikAtikBosalt.Enabled = true;
            KagitEkle.Enabled = true;
            KagitBosalt.Enabled = true;
            CamEkle.Enabled = true;
            CamBosalt.Enabled = true;
            MetalEkle.Enabled = true;
            MetalBosalt.Enabled = true;
            YeniOyunButon.Enabled = false;
            timer1.Start();
        }
        private void timer1_Tick(object sender, EventArgs e)//sure çalışma fonksiyonu
        {
            Sure.Text = ((saniye - 1).ToString());
            saniye -=1;
            if(Sure.Text=="0")//sure bitince yani oyun bitince butonlar devre dışı bırakılır ve oyun bitti mesajı çıkarılır.
            {
                timer1.Stop();
                MessageBox.Show("OYUN BİTTİ !");
                Color Renk = Color.White;
                Sure.BackColor = Renk;
                Puan.BackColor = Renk;
                OrganikAtikBosalt.Enabled = false;
                OrganikAtikBosalt.Enabled = false;
                KagitEkle.Enabled = false;
                KagitBosalt.Enabled = false;
                CamEkle.Enabled = false;
                CamBosalt.Enabled = false;
                MetalEkle.Enabled = false;
                MetalBosalt.Enabled = false;
                YeniOyunButon.Enabled = true;
            }
        }
        Atik Organik = new Atik();
        Atik KagitAtik = new Atik();
        Atik CamAtik = new Atik();
        Atik MetalAtik = new Atik();
        private void OrganikAtikEkle_Click(object sender, EventArgs e)//organik atık ekle butonu
        {
            if (AtıkResim.ImageLocation == resimler[0])//resim eğer domates ise yapılacak işlemler
            {
                Organik.Hacim = 150;
                Organik.Kapasite = 700;
                puan += Organik.Hacim;
                Organik.Ekle(Organik);
                if (Organik.eklendi)//atik kutusu eklenirse yapılacak işlemler
                {
                    Puan.Text = Convert.ToString(puan);
                    OrganikAtıkYuzde.Value = (Organik.DolulukOrani);
                    OrganikAtık.Items.Add("DOMATES(150)");
                    AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length - 1)];
                }
            }
           else if (AtıkResim.ImageLocation == resimler[1])//resim eğer salatalık ise yapılacak işlemler
            {
                Organik.Hacim = 120;
                Organik.Kapasite = 700;
                puan += Organik.Hacim;
                Organik.Ekle(Organik);
                if (Organik.eklendi)//atik kutusu eklenirse yapılacak işlemler
                {
                    Puan.Text = Convert.ToString(puan);
                    OrganikAtıkYuzde.Value = (Organik.DolulukOrani);
                    OrganikAtık.Items.Add("SALATALIK(120)");
                    AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length - 1)];
                }
            }
        }
        private void KagitEkle_Click(object sender, EventArgs e)//kağıt atık ekle butonu
        {
            if (AtıkResim.ImageLocation == resimler[2])//resim eğer kağıt ise yapılacak işlemler
            {
                KagitAtik.Hacim = 250;
                KagitAtik.Kapasite = 1200;
                puan += KagitAtik.Hacim;
                KagitAtik.Ekle(KagitAtik);
                if (KagitAtik.eklendi)//atik kutusu eklenirse yapılacak işlemler
                {
                    Puan.Text = Convert.ToString(puan);
                    KagitYuzde.Value = (KagitAtik.DolulukOrani);
                    Kagit.Items.Add("GAZETE(250)");
                    AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length - 1)];
                }
            }
            else if (AtıkResim.ImageLocation == resimler[3])//resim eğer gazete ise yapılacak işlemler
            {
                KagitAtik.Hacim = 200;
                KagitAtik.Kapasite = 1200;
                puan += KagitAtik.Hacim;
                KagitAtik.Ekle(KagitAtik);
                if (KagitAtik.eklendi)//atik kutusu eklenirse yapılacak işlemler
                {
                    Puan.Text = Convert.ToString(puan);
                    KagitYuzde.Value = (KagitAtik.DolulukOrani);
                    Kagit.Items.Add("DERGİ(200)");
                    AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length - 1)];
                }
            }
        }
        private void CamEkle_Click(object sender, EventArgs e)//cam atık ekle butonu
        {
            if (AtıkResim.ImageLocation == resimler[4])//resim eğer bardak ise yapılacak işlemler
            {
                CamAtik.Hacim = 250;
                CamAtik.Kapasite = 2200;
                puan += CamAtik.Hacim;
                CamAtik.Ekle(CamAtik);
                if (CamAtik.eklendi)//atik kutusu eklenirse yapılacak işlemler
                {
                    Puan.Text = Convert.ToString(puan);
                    CamYuzde.Value = (CamAtik.DolulukOrani);
                    Cam.Items.Add("CAM BARDAK(250)");
                    AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length - 1)];
                }
            }
            else if (AtıkResim.ImageLocation == resimler[5])//resim eğer şişe ise yapılacak işlemler
            {
                CamAtik.Hacim = 600;
                CamAtik.Kapasite = 2200;
                puan += CamAtik.Hacim;
                CamAtik.Ekle(CamAtik);
                if (CamAtik.eklendi)//atik kutusu eklenirse yapılacak işlemler
                {
                    Puan.Text = Convert.ToString(puan);
                    CamYuzde.Value = (CamAtik.DolulukOrani);
                    Cam.Items.Add("CAM ŞIŞE(600)");
                    AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length - 1)];
                }
            }
        }
        private void MetalEkle_Click(object sender, EventArgs e)//metal atık ekle butonu
        {
            if (AtıkResim.ImageLocation == resimler[6])//resim eğer kola kutusu ise yapılack işlemler
            {
                MetalAtik.Hacim = 350;
                MetalAtik.Kapasite = 2300;
                puan += MetalAtik.Hacim;
                MetalAtik.Ekle(MetalAtik);
                if (MetalAtik.eklendi)//atik kutusu eklenirse yapılacak işlemler
                {
                    Puan.Text = Convert.ToString(puan);
                    MetalYuzde.Value = (MetalAtik.DolulukOrani);
                    Metal.Items.Add("KOLA KUTUSU(350)");
                    AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length - 1)];
                }
            }
            else if (AtıkResim.ImageLocation == resimler[7])//resim eğer salça kutusu ise yapılack işlemler
            {
                MetalAtik.Hacim = 550;
                MetalAtik.Kapasite = 2300;
                puan += MetalAtik.Hacim;
                MetalAtik.Ekle(MetalAtik);
                if (MetalAtik.eklendi)//atik kutusu eklenirse yapılacak işlemler
                {
                    Puan.Text = Convert.ToString(puan);
                     Puan.Text = Convert.ToString(puan);
                    MetalYuzde.Value = (MetalAtik.DolulukOrani);
                    Metal.Items.Add("SALÇA KUTUSU(550)");
                    AtıkResim.ImageLocation = resimler[ResimSayi.Next(resimler.Length - 1)];
                }
            }
        }
        private void OrganikAtikBosalt_Click(object sender, EventArgs e)//organik atık boşalt butonu
        {
            Organik.Bosalt();
            if (Organik.bosaltildi)//atik kutusu boşaltılırsa yapılacak işlemler
            {
                OrganikAtık.Items.Clear();
                OrganikAtık.Items.Clear();
                OrganikAtıkYuzde.Value = 0;
                saniye += 3;
                Organik.DoluHacim = 0;
            }
        }
        private void KagitBosalt_Click(object sender, EventArgs e)//kağıt atık boşalt butonu
        {
            KagitAtik.BosaltmaPuani = 1000;
            KagitAtik.Bosalt();
            if (KagitAtik.bosaltildi)//atik kutusu boşaltılırsa yapılacak işlemler
            {
                puan += KagitAtik.BosaltmaPuani;
                Puan.Text = Convert.ToString(puan);
                KagitYuzde.Value = 0;
                Kagit.Items.Clear();
                saniye += 3;
                KagitAtik.DoluHacim = 0;
            }
        }
        private void CamBosalt_Click(object sender, EventArgs e)//cam atık boşalt butonu
        {
            CamAtik.BosaltmaPuani = 600;
            CamAtik.Bosalt();
            if (CamAtik.bosaltildi)//atik kutusu boşaltılırsa yapılacak işlemler
            {
                puan += CamAtik.BosaltmaPuani;
                Puan.Text = Convert.ToString(puan);
                CamYuzde.Value = 0;
                Cam.Items.Clear();
                saniye += 3;
                CamAtik.DoluHacim = 0;
            }
        }
        private void MetalBosalt_Click(object sender, EventArgs e)//metal atık boşalt butonu
        {
            MetalAtik.BosaltmaPuani = 800;
            MetalAtik.Bosalt();
            if (MetalAtik.bosaltildi)//atik kutusu boşaltılırsa yapılacak işlemler
            {
                puan += MetalAtik.BosaltmaPuani;
                Puan.Text = Convert.ToString(puan);
                MetalYuzde.Value = 0;
                Metal.Items.Clear();
                saniye += 3;
                MetalAtik.DoluHacim = 0;
            }
        }
        private void Cikis_Click(object sender, EventArgs e)//çıkış butonu
        {
            this.Close();
            Application.Exit();
        }
    }
}
