/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2020-2021 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:3. ÖDEV
**				ÖĞRENCİ ADI............:ÖMER FARUK GÜZEL
**				ÖĞRENCİ NUMARASI.......:G191210068
**              DERSİN ALINDIĞI GRUP...:1. SINIF 2. ÖĞRETİM C GRUBU
****************************************************************************/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace G191210068_Soru3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public class Urun
        {
            public string Ad, Marka, Model, Ozellik;
            public int StokAdedi, SecilenAdet;
            public double HamFiyat, KdvliFiyat;

            public double KdvUygula(int secilenadet)
            {
                if (Ad == "BUZDOLABI")//kalıtımla alığımız seçilen ürün adını kontrol edip , ürüne ait hesaplamaları yapman koşul
                {
                    SecilenAdet = secilenadet;
                    KdvliFiyat = HamFiyat * SecilenAdet * (1.05);
                }
                if (Ad == "TV")//kalıtımla alığımız seçilen ürün adını kontrol edip , ürüne ait hesaplamaları yapman koşul
                {
                    SecilenAdet = secilenadet;
                    KdvliFiyat = HamFiyat * SecilenAdet * (1.18);
                }
                if (Ad == "TELEFON")//kalıtımla alığımız seçilen ürün adını kontrol edip , ürüne ait hesaplamaları yapman koşul
                {
                    SecilenAdet = secilenadet;
                    KdvliFiyat = HamFiyat * SecilenAdet * (1.15);
                }
                if (Ad == "LAPTOP")//kalıtımla alığımız seçilen ürün adını kontrol edip , ürüne ait hesaplamaları yapman koşul
                {
                    SecilenAdet = secilenadet;
                    KdvliFiyat = HamFiyat * SecilenAdet * (1.2);
                }
                return KdvliFiyat;
            }
        }
        public class Buzdolabi: Urun     //Urun sınıfından miras alıp özellikler atanır
        {
            public string IcHacim, EnerjiSinifi;
           public Buzdolabi(string ad, string marka, string model, string ozellik, string ichacim, string enerjisinifi,double hamfiyat)
            {
                Ad = ad;
                Marka = marka;
                Model = model;
                Ozellik = ozellik;
                IcHacim = ichacim;
                EnerjiSinifi =enerjisinifi;
                HamFiyat = hamfiyat;
                Random RastgeleSayi = new Random((int)DateTime.Now.Ticks);
                StokAdedi = RastgeleSayi.Next(1, 100);
            }
        }
        public class LedTv : Urun     //Urun sınıfından miras alıp özellikler atanır
        {
            public string EkranBoyutu, EkranCozunurlugu;
            public LedTv(string ad, string marka, string model, string ozellik, string ekranboyutu, string ekrancozunurlugu ,double hamfiyat )
            {
                Ad = ad;
                Marka = marka;
                Model = model;
                Ozellik = ozellik;
                EkranBoyutu = ekranboyutu;
                EkranCozunurlugu = ekrancozunurlugu;
                HamFiyat = hamfiyat;
                Random RastgeleSayi2 = new Random((int)DateTime.Now.Ticks);
                StokAdedi = RastgeleSayi2.Next(1, 100);
            }
        }
       public class CepTel : Urun     //Urun sınıfından miras alıp özellikler atanır
        {
            public string DahiliHafiza, RamKapasitesi, PilGucu;
           public CepTel(string ad, string marka, string model, string ozellik, string dahilihafiza, string ramkapasitesi,string pilgucu,double hamfiyat)
            {
                Ad = ad;
                Marka = marka;
                Model = model;
                Ozellik = ozellik;
                DahiliHafiza = dahilihafiza;
                RamKapasitesi = ramkapasitesi;
                PilGucu = pilgucu;
                HamFiyat = hamfiyat;
                Random RastgeleSayi3 = new Random((int)DateTime.Now.Ticks);
                StokAdedi = RastgeleSayi3.Next(1, 100);
            }
        }
        public class Laptop : Urun     //Urun sınıfından miras alıp özellikler atanır
        {
            public string EkranBoyutu, EkranCozunurluk, DahiliHafiza, RamKapasitesi, PilGucu;
            public Laptop(string ad,string marka,string model,string ozellik,string ekranboyutu,string ekrancozunurluk,string dahilihafiza,string ramkapasitesi,string pilgucu,double hamfiyat)
            {
                Ad = ad;
                Marka = marka;
                Model = model;
                Ozellik = ozellik;
                EkranBoyutu = ekranboyutu;
                EkranCozunurluk = ekrancozunurluk;
                DahiliHafiza = dahilihafiza;
                RamKapasitesi = ramkapasitesi;
                PilGucu = pilgucu;
                HamFiyat = hamfiyat;
                Random RastgeleSayi4 = new Random((int)DateTime.Now.Ticks);
                StokAdedi = RastgeleSayi4.Next(1, 100);
            }
        }
        //Nesne oluştutururken kurucu fonksiyonkara ait parametreleri yolluyoruz
        Buzdolabi buzdolabi = new Buzdolabi("BUZDOLABI", "BOSCH", "A+", "2020", "10m3", "AA", 4000);
        LedTv ledtv = new LedTv("TV", "VESTEL", "LCD", "FULL HD", "1000 CM", "1200 PX", 2800);
        CepTel ceptel = new CepTel("TELEFON", "XİAOMİ", "NOTE 3", "4 CAM", "64 GB", "6 GB", "4600 amp", 2600);
        Laptop laptop = new Laptop("LAPTOP", "LENOVO", "G 50", "SSD", "50 INC", "4800 PX", "1 TB", " 8GB", "4900 AMP", 4700);
        private void Form1_Load(object sender, EventArgs e) //Program çalıştığında stok adedleri ve hamfiyat özellikleri yazdırılır
        {
            TelFiyat.Text = Convert.ToString(ceptel.HamFiyat);
            TelStok.Text = Convert.ToString(ceptel.StokAdedi);
            TvFiyat.Text = Convert.ToString(ledtv.HamFiyat);
            TvStok.Text =  Convert.ToString(ledtv.StokAdedi);
            BuzdolabiFiyat.Text = Convert.ToString(buzdolabi.HamFiyat);
            BuzdolabiStok.Text = Convert.ToString(buzdolabi.StokAdedi);
            PcFiyat.Text = Convert.ToString(laptop.HamFiyat);
            PcStok.Text = Convert.ToString(laptop.StokAdedi);
            numericUpDown1.Maximum = Convert.ToInt32(TelStok.Text);
            numericUpDown2.Maximum = Convert.ToInt32(TvStok.Text);
            numericUpDown3.Maximum = Convert.ToInt32(BuzdolabiStok.Text);
            numericUpDown4.Maximum = Convert.ToInt32(PcStok.Text);
            button2.Enabled = false;//sepete ekle butonuna tıklandığında yani sepete ürün eklendiğinde aktif olması için hazırlanan ön koşul
        }
        public class Sepet
        {
            public double toplam = 0;
            public double SepeteUrunEkle(Urun urun,int Secilenadet) //Sepete ekle butonuna tıklanınca Sepet sınıfının fonksiyonu olan bu fonksiyondan kalıtım alınarak Kdvli fiyatlar hesaplanır
            {
                double yedektoplam;
                urun.KdvUygula(Secilenadet);
                yedektoplam = urun.KdvUygula(Secilenadet);
                toplam += yedektoplam;
                return urun.KdvliFiyat;
            }
        }
        int secilen1 = 0;//nummericUpDown1 değerini tutan değişken
        int secilen2 = 0;//nummericUpDown2 değerini tutan değişken
        int secilen3 = 0;//nummericUpDown3 değerini tutan değişken
        int secilen4 = 0;//nummericUpDown4 değerini tutan değişken
        private void button1_Click(object sender, EventArgs e)//Sepete ekle butonu
        {
            if (listBox1.Items.Count != 0)//listboxun yani sepet doluysa temizlenmesi için mesaj gönderen koşul
            {
                MessageBox.Show("ÖNCE SEPET TEMİZLENMELİDİR");
            }
            else//sepet boşsa gerçekleşecek işlemler
            {
                ceptel.SecilenAdet = Convert.ToInt32(numericUpDown1.Value);
                ledtv.SecilenAdet = Convert.ToInt32(numericUpDown2.Value);
                buzdolabi.SecilenAdet = Convert.ToInt32(numericUpDown3.Value);
                laptop.SecilenAdet = Convert.ToInt32(numericUpDown4.Value);
                Sepet sepet = new Sepet();
                if (numericUpDown1.Value > 0) //telefon için seçilen adet varsa işleme girecekler
                {
                    listBox1.Items.Add(ceptel.SecilenAdet);
                    listBox2.Items.Add(ceptel.Ad);
                    listBox3.Items.Add(Convert.ToString(sepet.SepeteUrunEkle(ceptel, ceptel.SecilenAdet)));
                    TelStok.Text = Convert.ToString(Convert.ToInt32(TelStok.Text) - numericUpDown1.Value);
                    secilen1 = Convert.ToInt32(numericUpDown1.Value);
                }
                if (numericUpDown2.Value > 0)//televizyon için seçlen adet varsa işleme girecekler
                {
                    listBox1.Items.Add(ledtv.SecilenAdet);
                    listBox2.Items.Add(ledtv.Ad);
                    listBox3.Items.Add(Convert.ToString(sepet.SepeteUrunEkle(ledtv, ledtv.SecilenAdet)));
                    TvStok.Text = Convert.ToString(Convert.ToInt32(TvStok.Text) - numericUpDown2.Value);
                    secilen2 = Convert.ToInt32(numericUpDown2.Value);
                }
                if (numericUpDown3.Value > 0)//buzdolabı için seçilen adet varsa işleme girecekler
                {
                    listBox1.Items.Add(buzdolabi.SecilenAdet);
                    listBox2.Items.Add(buzdolabi.Ad);
                    listBox3.Items.Add(Convert.ToString(sepet.SepeteUrunEkle(buzdolabi, buzdolabi.SecilenAdet)));
                    BuzdolabiStok.Text = Convert.ToString(Convert.ToInt32(BuzdolabiStok.Text) - numericUpDown3.Value);
                    secilen3 = Convert.ToInt32(numericUpDown3.Value);
                }
                if (numericUpDown4.Value > 0)//bilgisayar için seçilen adet varsa işleme girecekler
                {
                    listBox1.Items.Add(laptop.SecilenAdet);
                    listBox2.Items.Add(laptop.Ad);
                    listBox3.Items.Add(Convert.ToString(sepet.SepeteUrunEkle(laptop, laptop.SecilenAdet)));
                    PcStok.Text = Convert.ToString(Convert.ToInt32(PcStok.Text) - numericUpDown4.Value);
                    secilen4 = Convert.ToInt32(numericUpDown4.Value);
                }
                ToplamFiyat.Text = Convert.ToString(sepet.toplam);//toplam fiyat sepet sınıfınan kalıtımla alınır
                button2.Enabled = true;
            }
        }
        private void button2_Click(object sender, EventArgs e)//Sepeti temizle butonu
        {
            if (numericUpDown1.Value > 0)//telefon için seçilen adet varsa adet kadar stoğa geri ekleme
            {
                TelStok.Text = Convert.ToString(Convert.ToInt32(TelStok.Text) + secilen1);
            }
            if (numericUpDown2.Value > 0)//televizyon için seçilen adet varsa adet kadar stoğa geri ekleme
            {
                TvStok.Text = Convert.ToString(Convert.ToInt32(TvStok.Text) + secilen2);
            }
            if (numericUpDown3.Value > 0)//buzdolabı için seçilen adet varsa adet kadar stoğa geri ekleme
            {
                BuzdolabiStok.Text = Convert.ToString(Convert.ToInt32(BuzdolabiStok.Text) + secilen3);
            }
            if (numericUpDown4.Value > 0)//bilgisayar için seçilen adet varsa adet kadar stoğa geri ekleme
            {
                PcStok.Text = Convert.ToString(Convert.ToInt32(PcStok.Text) + secilen4);
            }
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            listBox3.Items.Clear();
            ToplamFiyat.Text =default;
            numericUpDown1.Value = 0;
            numericUpDown2.Value = 0;
            numericUpDown3.Value = 0;
            numericUpDown4.Value = 0;
            button2.Enabled = false;//nummericUpDown daki değeri arttırıp sepete ekle butonuna basmadan sepeti temizle butonuna basılıp stoklara o değeri eklememesi için hazırlanan koşul
        }
    }
}
