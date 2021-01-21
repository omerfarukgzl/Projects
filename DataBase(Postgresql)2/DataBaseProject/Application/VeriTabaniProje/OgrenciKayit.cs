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
    public partial class OgrenciKayit : Form
    {
        public OgrenciKayit()
        {
            InitializeComponent();
        }
        NpgsqlConnection baglanti = new NpgsqlConnection("server=localHost; port=5432; Database = ProjeOdev; user Id=postgres; password=1234");
        public string cinsiyet;
        public static int adres_ID;
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            baglanti.Open();


            if (textBox1.Text == "" || textBox2.Text == "" || textBox3.Text == "" || textBox5.Text == "" || textBox6.Text == "" || (radioButton1.Checked == false && radioButton2.Checked == false) || textBox7.Text == "" || textBox8.Text == "" || textBox4.Text == "")
            {
                MessageBox.Show("Lütfen bilgilerinizi eksiksiz girin");
            }
            else
            {
                NpgsqlCommand AdresiEkle = new NpgsqlCommand("insert into ogrenciadres values('" + textBox7.Text + "','" + textBox8.Text + "','" + textBox4.Text + "')", baglanti);

                if (radioButton1.Checked)
                {
                    cinsiyet = "erkek";
                }
                else if (radioButton2.Checked)
                {
                    cinsiyet = "kadin";
                }
                NpgsqlCommand kayit = new NpgsqlCommand("call ogrenci_kayit(@ad,@soyad,@kullanici,@sifre,@yas,@cinsiyet,@tur)", baglanti);
                kayit.Parameters.AddWithValue("@ad", textBox1.Text);
                kayit.Parameters.AddWithValue("@soyad", textBox2.Text);
                kayit.Parameters.AddWithValue("@kullanici", textBox5.Text);
                kayit.Parameters.AddWithValue("@sifre", int.Parse(textBox6.Text));
                kayit.Parameters.AddWithValue("@yas", int.Parse(textBox3.Text));
                kayit.Parameters.AddWithValue("@cinsiyet", cinsiyet);
                kayit.Parameters.AddWithValue("@tur", "ogrenci");
                kayit.ExecuteNonQuery();

                MessageBox.Show("Kaydınız Tamamlandı");
                baglanti.Close();
                Form1 ekran = new Form1();
                this.Hide();
                ekran.Show();
            }
        }
    }
}
