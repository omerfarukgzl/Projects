using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Npgsql;

namespace VeriTabaniProje
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        Ogretmen[] ogretmen = new Ogretmen[100];
        Ogrenci[] ogrenci = new Ogrenci[100];
        NpgsqlConnection baglanti = new NpgsqlConnection("server=localHost; port=5432; Database = ProjeOdev; user Id=postgres; password=1234");
        int i = 0;
        int giris_hakki = 3;
        int kullanici_sayisi;
        private void GirisButton_Click(object sender, EventArgs e)
        {
            if (OgretmenRadioBtn.Checked)
            {
                baglanti.Open();
                NpgsqlCommand komut = new NpgsqlCommand("SELECT * FROM kullanici Where kullaniciadi = @kullaniciaditxt", baglanti);
                komut.Parameters.AddWithValue("@kullaniciaditxt", textBox1.Text);
                NpgsqlDataReader oku = komut.ExecuteReader();
                if (oku.Read() == true)
                {
                    ogretmen[i] = new Ogretmen();
                    ogretmen[i].ogretmenid = int.Parse(oku[0].ToString());
                    ogretmen[i].ogretmenadi = oku[1].ToString();
                    ogretmen[i].ogretmensoyad = oku[2].ToString();
                    ogretmen[i].ogretmenkullanici = oku[3].ToString();
                    ogretmen[i].ogretmensifre = Convert.ToInt64(oku[4].ToString());
                    ogretmen[i].ogretmenyas = int.Parse(oku[5].ToString());
                    ogretmen[i].ogretmencinsiyet = oku[6].ToString();

                    if (ogretmen[i].kullanicituru == oku[7].ToString())
                    {

                        if (ogretmen[i].ogretmensifre == Convert.ToInt64((textBox2.Text.ToString())))
                        {
                            OgretmenEkran.ogretmen_id = int.Parse(oku[0].ToString());
                            OgretmenEkran.ogretmen_adi = oku[1].ToString();
                            OgretmenEkran.ogretmen_soyadi = oku[2].ToString();
                            OgretmenEkran ogretmenekran = new OgretmenEkran();
                            this.Hide();
                            ogretmenekran.Show();
                            baglanti.Close();


                        }
                        else
                        {
                            if (giris_hakki == 0)
                            {
                                MessageBox.Show("TÜM HAKLARINIZI KULLANDINIZ");
                                baglanti.Close();
                            }
                            else
                            {
                                MessageBox.Show("SAYIN " + ogretmen[i].ogretmenadi + " ŞİFRENİZ YANLIŞ");
                                giris_hakki--;
                                label4.Text = giris_hakki.ToString();
                                baglanti.Close();
                            }
                        }
                    }
                    else
                    {
                        MessageBox.Show("LÜTFEN KULLANICI TÜRÜNÜ DOĞRU SEÇİNİZ");
                        baglanti.Close();

                    }
                }
                else
                {
                    if (giris_hakki == 0)
                    {
                        MessageBox.Show("TÜM HAKLARINIZI KULLANDINIZ");
                        baglanti.Close();
                    }
                    else
                    {
                        MessageBox.Show("BÖYLE BİR KULLANICI BULUNAMADI");
                        giris_hakki--;
                        label4.Text = giris_hakki.ToString();
                        baglanti.Close();
                    }
                }
            }
            if (OgrenciRadioBtn.Checked)
            {
                baglanti.Open();
                NpgsqlCommand komut = new NpgsqlCommand("SELECT * FROM kullanici Where kullaniciadi = @kullaniciaditxt", baglanti);
                komut.Parameters.AddWithValue("@kullaniciaditxt", textBox1.Text);
                NpgsqlDataReader oku = komut.ExecuteReader();
                if (oku.Read() == true)
                {
                    ogrenci[i] = new Ogrenci();
                    ogrenci[i].ogrenciid = int.Parse(oku[0].ToString());
                    ogrenci[i].ogrenciad = oku[1].ToString();
                    ogrenci[i].ogrencesoyad = oku[2].ToString();
                    ogrenci[i].ogrencikullanici = oku[3].ToString();
                    ogrenci[i].ogrencisifre = Convert.ToInt64(oku[4].ToString());
                    ogrenci[i].ogrenciyas = int.Parse(oku[5].ToString());
                    ogrenci[i].ogrencicinsiyet = oku[6].ToString();

                    if (ogrenci[i].kullanicituru == oku[7].ToString())
                    {

                        if (ogrenci[i].ogrencisifre == Convert.ToInt64(textBox2.Text))
                        {
                            OgrenciEkran.ogrenci_id = int.Parse(oku[0].ToString());
                            OgrenciEkran ogrenciekran = new OgrenciEkran();
                            this.Hide();
                            ogrenciekran.Show();
                            baglanti.Close();


                        }
                        else
                        {
                            if (giris_hakki == 0)
                            {
                                MessageBox.Show("TÜM HAKLARINIZI KULLANDINIZ");
                                baglanti.Close();
                            }
                            else
                            {
                                MessageBox.Show("SAYIN " + ogretmen[i].ogretmenadi + " ŞİFRENİZ YANLIŞ");
                                giris_hakki--;
                                label4.Text = giris_hakki.ToString();
                                baglanti.Close();
                            }
                        }
                    }
                    else
                    {
                        MessageBox.Show("LÜTFEN KULLANICI TÜRÜNÜ DOĞRU SEÇİNİZ");
                        baglanti.Close();
                    }
                }
                else
                {
                    if (giris_hakki == 0)
                    {
                        MessageBox.Show("TÜM HAKLARINIZI KULLANDINIZ");
                        baglanti.Close();
                    }
                    else
                    {
                        MessageBox.Show("BÖYLE BİR KULLANICI BULUNAMADI");
                        giris_hakki--;
                        label4.Text = giris_hakki.ToString();
                        baglanti.Close();
                    }
                }

            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            baglanti.Open();
            NpgsqlCommand kullanicisayisi = new NpgsqlCommand("SELECT toplam from toplam_kullanici;", baglanti);
            kullanici_sayisi = Convert.ToInt32(kullanicisayisi.ExecuteScalar());
            textBox3.Text = kullanici_sayisi.ToString();
            baglanti.Close();
        }
        private void yenilebttn_Click(object sender, EventArgs e)
        {
            baglanti.Open();
            NpgsqlCommand kullanicisayisi = new NpgsqlCommand("SELECT toplam from toplam_kullanici;", baglanti);
            kullanici_sayisi = Convert.ToInt32(kullanicisayisi.ExecuteScalar());
            textBox3.Text = kullanici_sayisi.ToString();
            baglanti.Close();
        }

        private void KaydolButton_Click(object sender, EventArgs e)
        {
            OgrenciKayit kaydolmaekrani = new OgrenciKayit();
            this.Hide();
            kaydolmaekrani.Show();
        }

        private void SifreDegisButton_Click(object sender, EventArgs e)
        {
            SifreDegistir sifredegismeekrani = new SifreDegistir();
            this.Hide();
            sifredegismeekrani.Show();
        }
    }
}
