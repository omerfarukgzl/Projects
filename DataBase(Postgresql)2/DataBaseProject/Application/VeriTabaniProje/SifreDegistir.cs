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
    public partial class SifreDegistir : Form
    {
        public SifreDegistir()
        {
            InitializeComponent();
        }
        NpgsqlConnection baglanti = new NpgsqlConnection("server=localHost; port=5432; Database = ProjeOdev; user Id=postgres; password=1234");
        private void YeniSifreButton_Click(object sender, EventArgs e)
        {
            baglanti.Open();
            NpgsqlCommand sifredegis = new NpgsqlCommand("select *from kullanici where kullaniciadi='" + textBox1.Text.ToString() + "'", baglanti);
            NpgsqlDataReader sifreoku = sifredegis.ExecuteReader();
            if (sifreoku.Read() == true)
            {
                Ogrenci ogrenci = new Ogrenci();
                ogrenci.ogrenciid = int.Parse(sifreoku[0].ToString());
                ogrenci.ogrenciad = sifreoku[1].ToString();
                ogrenci.ogrencesoyad = sifreoku[2].ToString();
                ogrenci.ogrenciyas = int.Parse(sifreoku[5].ToString());
                ogrenci.ogrencicinsiyet = sifreoku[6].ToString();
                ogrenci.ogrencisifre = int.Parse(sifreoku[4].ToString());
                ogrenci.ogrencikullanici = sifreoku[3].ToString();
                sifreoku.Close();
                if (textBox2.Text == ogrenci.ogrencisifre.ToString())
                {
                    if (textBox4.Text == textBox3.Text)
                    {
                        NpgsqlCommand guncelle = new NpgsqlCommand("update kullanici set sifre='" + int.Parse(textBox3.Text.ToString()) + "' where kullaniciadi='" + textBox1.Text.ToString() + "' ", baglanti);
                        NpgsqlDataReader yenilendi = guncelle.ExecuteReader();
                        yenilendi.Read();
                        MessageBox.Show("SAYIN " + ogrenci.ogrenciad + " ŞİFRENİZ GÜNCELLENDİ");
                        baglanti.Close();

                        Form1 form = new Form1();
                        this.Hide();
                        form.Show();
                    }
                    else
                    {
                        MessageBox.Show("LÜTFEN YENİ ŞİFRENİZİ TEKRAR GİRİN");
                        baglanti.Close();
                    }
                }
                else
                {
                    MessageBox.Show("MEVCUT ŞİFRENİZ HATALI");
                    baglanti.Close();
                }
            }
            else
            {
                MessageBox.Show("BÖYLE BİR PERSONEL BULUNAMADI");
                baglanti.Close();
            }


        }
    }
}
