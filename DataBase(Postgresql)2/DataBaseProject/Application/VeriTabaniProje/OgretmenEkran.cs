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
    public partial class OgretmenEkran : Form
    {
        public OgretmenEkran()
        {
            InitializeComponent();
        }
        static public int ogretmen_id;
        static public int ogrenci_id;
        static public int kitap_stok;
        static public int kitap_fiyat;
        static public string kitap_isim;
        static public int kitap_id;
        static public int siparis_id;
        static public int ders_id;
        static public string ogretmen_adi;
        static public string ogretmen_soyadi;
        static public int ogretmen_yas;
        static public int kayit_sayisi;
        static public int hangi_kayit;
        NpgsqlConnection baglanti = new NpgsqlConnection("server=localHost; port=5432; Database = ProjeOdev; user Id=postgres; password=1234");

        private void OgretmenEkran_Load(object sender, EventArgs e)
        {
            baglanti.Open();
            NpgsqlCommand ogretmengetir = new NpgsqlCommand("select * from kullanici where kullaniciid =@ogretmen_id; ", baglanti);
            ogretmengetir.Parameters.AddWithValue("@ogretmen_id", ogretmen_id);
            NpgsqlDataReader okudoktor = ogretmengetir.ExecuteReader();
            if (okudoktor.Read())
            {
                ogretmen_adi = okudoktor[1].ToString();
                ogretmen_soyadi = okudoktor[2].ToString();
                label1.Text = "SAYIN " + ogretmen_adi + " " + ogretmen_soyadi + " SİSTEME GİRİŞ YAPTINIZ";
                ogretmen_yas = Convert.ToInt32(okudoktor[5].ToString());
            }
            okudoktor.Close();

            NpgsqlCommand ozeldersgetir = new NpgsqlCommand("select COUNT(*) from ozelders where ogretmenid = @ogretmen_id;", baglanti);
            ozeldersgetir.Parameters.AddWithValue("@ogretmen_id", ogretmen_id);
            kayit_sayisi = Convert.ToInt32(ozeldersgetir.ExecuteScalar());
            label3.Text =  " "+ ogretmen_adi + " " + ogretmen_soyadi + " BEY " + kayit_sayisi + " ADET ÖZEL DERS MEVCUT ";

            NpgsqlCommand kayıtsırala = new NpgsqlCommand("select kayit_sirala_ogretmen(@ogretmen_id)", baglanti);
            kayıtsırala.Parameters.AddWithValue("@ogretmen_id",ogretmen_id);
            NpgsqlDataReader getir = kayıtsırala.ExecuteReader();
            while (getir.Read())
            {
                comboBox1.Items.Add(getir[0].ToString());
            }
            getir.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            hangi_kayit = Convert.ToInt32(comboBox1.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NpgsqlCommand kayıtgetir = new NpgsqlCommand("select distinct ozeldersid,kullanici.ad,kullanici.soyad,kullanici.yas,kullanici.cinsiyet,ders.dersadi,ders.dersid,kullanici.kullaniciid from kullanici,dershane,bolum,ders,ogretmen,ozelders where ozelders.ogrenciid=kullanici.kullaniciid and ozelders.ogretmenid=ogretmen.ogretmenid and ozelders.dersid=ders.dersid and ozeldersid=@hangi_kayit", baglanti);
            kayıtgetir.Parameters.AddWithValue("@hangi_kayit", hangi_kayit);
            NpgsqlDataReader kayıtoku = kayıtgetir.ExecuteReader();
            if (kayıtoku.Read() == true)
            {
                ozeldersnolabel.Text = kayıtoku[0].ToString();
                ogrencilabel.Text = kayıtoku[1].ToString();
                ogrencisoyadlabel.Text = kayıtoku[2].ToString();
                ogrenciyaslabel.Text = kayıtoku[3].ToString();
                ogrencicinsiyetlabel.Text= kayıtoku[4].ToString();
                derslabel.Text = kayıtoku[5].ToString();
                ders_id = Convert.ToInt32(kayıtoku[6]);
                ogrenci_id = Convert.ToInt32(kayıtoku[7]);
            }
            kayıtoku.Close();

            label14.Text = derslabel.Text;

            NpgsqlCommand kitapgetir = new NpgsqlCommand("select kitapisim from kitap,ders where kitap.dersid=ders.dersid and ders.dersid=@ders_id", baglanti);
            kitapgetir.Parameters.AddWithValue("@ders_id",ders_id);
            NpgsqlDataReader kitapoku = kitapgetir.ExecuteReader();
            while (kitapoku.Read())
            {
                kitapcommbobox.Items.Add(kitapoku[0].ToString());
            }
            kitapoku.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (label14.Text != "")
            {
                NpgsqlCommand kitapyaz = new NpgsqlCommand("call siparis_ekle(@kitap_id,@ogrenci_id)", baglanti);
                kitapyaz.Parameters.AddWithValue("@ogrenci_id", ogrenci_id);
                kitapyaz.Parameters.AddWithValue("@kitap_id", kitap_id);
                kitapyaz.ExecuteNonQuery();
                MessageBox.Show("Kitap Kargoya Verildi");
                label22.Text = " ";
                label20.Text = " ";
                label18.Text = " ";
            }
        }


        private void kitapcommbobox_SelectedIndexChanged(object sender, EventArgs e)
        {
            kitap_isim = kitapcommbobox.Text;

            NpgsqlCommand kitapid = new NpgsqlCommand(" select kitapid from kitap where kitapisim = @kitap_isim;", baglanti);
            kitapid.Parameters.AddWithValue("@kitap_isim", kitap_isim);
            kitap_id = Convert.ToInt32(kitapid.ExecuteScalar().ToString());

            NpgsqlCommand kitapfiyat = new NpgsqlCommand(" select fiyat from kitap where kitapisim = @kitap_isim;", baglanti);
            kitapfiyat.Parameters.AddWithValue("@kitap_isim", kitap_isim);
            kitap_fiyat = Convert.ToInt32(kitapfiyat.ExecuteScalar().ToString());

            NpgsqlCommand kitapstok = new NpgsqlCommand(" select stokmiktari from kitap where kitapisim = @kitap_isim;", baglanti);
            kitapstok.Parameters.AddWithValue("@kitap_isim", kitap_isim);
            kitap_stok = Convert.ToInt32(kitapstok.ExecuteScalar().ToString());

            label22.Text = kitap_id.ToString();
            label20.Text = kitap_fiyat.ToString();
            label18.Text = kitap_stok.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            NpgsqlCommand ozelderssil = new NpgsqlCommand("call ozel_ders_sil(@hangi_kayit)", baglanti);
            ozelderssil.Parameters.AddWithValue("@hangi_kayit", hangi_kayit);
            ozelderssil.ExecuteNonQuery();
            MessageBox.Show("Randevu Silindi");
            comboBox1.Items.Clear();

            NpgsqlCommand ozeldersgetir = new NpgsqlCommand("select COUNT(*) from ozelders where ogretmenid = @ogretmen_id;", baglanti);
            ozeldersgetir.Parameters.AddWithValue("@ogretmen_id", ogretmen_id);
            kayit_sayisi = Convert.ToInt32(ozeldersgetir.ExecuteScalar());
            label3.Text = " " + ogretmen_adi + " " + ogretmen_soyadi + " BEY " + kayit_sayisi + " ADET MUAYENE MEVCUT ";

            NpgsqlCommand kayıtsırala = new NpgsqlCommand("select kayit_sirala_ogretmen(@ogretmen_id)", baglanti);
            kayıtsırala.Parameters.AddWithValue("@ogretmen_id", ogretmen_id);
            NpgsqlDataReader getir = kayıtsırala.ExecuteReader();
            while (getir.Read())
            {
                comboBox1.Items.Add(getir[0].ToString());
            }
            getir.Close();
            ozeldersnolabel.Text = "";
            ogrencilabel.Text = "";
            ogrencisoyadlabel.Text = "";
            ogrenciyaslabel.Text = "";
            ogrencicinsiyetlabel.Text = "";
            label14.Text = "";
            derslabel.Text = "";
            label22.Text = "";
            label20.Text = "";
            label18.Text = "";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            NpgsqlCommand istifaet = new NpgsqlCommand("delete from kullanici where kullaniciid=@ogretmen_id", baglanti);
            istifaet.Parameters.AddWithValue("@ogretmen_id", ogretmen_id); 
            istifaet.ExecuteNonQuery();
            MessageBox.Show("İstifa ettiniz");
            MessageBox.Show("ÇIKIŞINIZ YAPILIYOR ");
            Application.Exit();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            NpgsqlCommand siparisidbul = new NpgsqlCommand("select siparisid from siparis where ogrenciid = @ogrenci_id and kitapid=@kitap_id;", baglanti);
            siparisidbul.Parameters.AddWithValue("@ogrenci_id", ogrenci_id);
            siparisidbul.Parameters.AddWithValue("@kitap_id", kitap_id);
             siparis_id= Convert.ToInt32(siparisidbul.ExecuteScalar());


            NpgsqlCommand siparissil = new NpgsqlCommand("call siparis_sil(@siparis_id)", baglanti);
            siparissil.Parameters.AddWithValue("@siparis_id", siparis_id);
            siparissil.ExecuteNonQuery();
            MessageBox.Show("Siparis Silindi");

        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form1 form = new Form1();
            this.Hide();
            form.Show();

        }
    }
}
