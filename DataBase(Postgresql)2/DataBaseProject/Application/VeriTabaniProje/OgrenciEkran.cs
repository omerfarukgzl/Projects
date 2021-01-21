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
    public partial class OgrenciEkran : Form
    {
        public OgrenciEkran()
        {
            InitializeComponent();
        }
        static public int ogrenci_id;
        static public int kayıt_sayisi;
        static public int hangi_kayit;
        static public int ozelders_id;
        static public string ogrenci_adi;
        static public string ogrenci_soyadi;
        static public string dershane_adi;
        static public string bolum_adi;
        static public string ogretmen_adi;
        static public string ogretmen_adsoyad;
        static public string ders_adi;
        static public int dershane_id;
        static public int bolum_id;
        static public int ogretmen_id;
        static public int ders_id;
        NpgsqlConnection baglanti = new NpgsqlConnection("server=localHost; port=5432; Database = ProjeOdev; user Id=postgres; password=1234");
        public void dershaneYaz()
        {
            comboBox1.Items.Add("GaziosmanPasa Final");
            comboBox1.Items.Add("Arnavutköy Final");
            comboBox1.Items.Add("Besiktaş Boğaziçi");
            comboBox1.Items.Add("Bebek Boğaziçi");
            comboBox1.Items.Add("Eyüp Boğaziçi");
            comboBox1.Items.Add("Şişli Boğaziçi");
        }
        private void OgrenciEkran_Load(object sender, EventArgs e)
        {
            dershaneYaz();
            baglanti.Open();
            NpgsqlCommand komut = new NpgsqlCommand("SELECT * FROM kullanici Where kullaniciid = @ogrenci_id", baglanti);
            komut.Parameters.AddWithValue("@ogrenci_id", ogrenci_id);
            NpgsqlDataReader oku = komut.ExecuteReader();
            if (oku.Read() == true)
            {
                label1.Text = "SAYIN  " + oku[1] + " " + oku[2] + "  SİSTEMİMİZE HOŞGELDİNİZ";
                ogrenci_id = Convert.ToInt32(oku[0].ToString());
                ogrenci_adi = oku[1].ToString();
                ogrenci_soyadi = oku[2].ToString();
                isimtextbox.Text = oku[1].ToString();
                soyisimtextbox.Text = oku[2].ToString();
            }
            oku.Close();
            //NpgsqlCommand kayitsirala = new NpgsqlCommand("select ozeldersid from ozelders where ogrenciid =@ogrenci_id;", baglanti);
            //kayitsirala.Parameters.AddWithValue("@ogrenci_id", ogrenci_id);
            //NpgsqlDataReader oku2 = kayitsirala.ExecuteReader();
            //while (oku2.Read())
            //{
            //    comboBox5.Items.Add(oku2[0].ToString());
            //}
            //oku2.Close();
            NpgsqlCommand kayitsirala = new NpgsqlCommand("select ogrenci_kayitsirala(@ogrenci_id)", baglanti);
            kayitsirala.Parameters.AddWithValue("@ogrenci_id", ogrenci_id);
            NpgsqlDataReader oku2 = kayitsirala.ExecuteReader();
            while (oku2.Read())
            {
                comboBox5.Items.Add(oku2[0].ToString());
            }
            oku2.Close();
            NpgsqlCommand kackayitvar = new NpgsqlCommand("select COUNT(*) from ozelders where ogrenciid=@ogrenci_id;", baglanti);
            kackayitvar.Parameters.AddWithValue("ogrenci_id", ogrenci_id);
            kayıt_sayisi = Convert.ToInt32(kackayitvar.ExecuteScalar());
            label17.Text = kayıt_sayisi + " adet randevunuz bulunmaktadır";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == -1 || comboBox2.SelectedIndex == -1 || comboBox4.SelectedIndex == -1 || comboBox3.SelectedIndex == -1)
            {
                MessageBox.Show("Lütfen eksik bilgi girmeyiniz");
                baglanti.Close();
            }
            else
            {
                NpgsqlCommand ozeldersal = new NpgsqlCommand("call ozel_ders_ekle(@dershane_id,@bolum_id,@ders_id,@ogretmen_id,@ogrenci_id)", baglanti);
                ozeldersal.Parameters.AddWithValue("@dershane_id", dershane_id);
                ozeldersal.Parameters.AddWithValue("@bolum_id", bolum_id);
                ozeldersal.Parameters.AddWithValue("@ders_id", ders_id);
                ozeldersal.Parameters.AddWithValue("@ogretmen_id", ogretmen_id);
                ozeldersal.Parameters.AddWithValue("@ogrenci_id", ogrenci_id);
                ozeldersal.ExecuteNonQuery();

                MessageBox.Show("Randevunuz " + ogrenci_adi + " " + ogretmen_adi + " " + dershane_adi + " " + bolum_adi + " " + ders_adi + " " + " Başarıyla Oluşturuldu");
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            dershane_adi = comboBox1.Text;
            NpgsqlCommand dershanebul = new NpgsqlCommand("select dershaneid from dershane where dershaneadi=@dershaneadi",baglanti);
            dershanebul.Parameters.AddWithValue("@dershaneadi", dershane_adi);
            dershane_id = Convert.ToInt32(dershanebul.ExecuteScalar());
            NpgsqlCommand bolumlerigetir = new NpgsqlCommand("select bolumadi from bolum_dershane,bolum where bolum_dershane.dershaneid=@dershane_id and bolum_dershane.bolumid=bolum.bolumid ", baglanti);
            bolumlerigetir.Parameters.AddWithValue("@dershane_id", comboBox1.SelectedIndex + 1);
            NpgsqlDataReader oku1 = bolumlerigetir.ExecuteReader();
            while (oku1.Read())
            {
                comboBox2.Items.Add(oku1[0]);
            }
            oku1.Close();
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            bolum_adi = comboBox2.Text;
            NpgsqlCommand bolumnobul = new NpgsqlCommand("select bolumid from bolum where bolumadi=@bolum_adi", baglanti);
            bolumnobul.Parameters.AddWithValue("@bolum_adi", bolum_adi);
            bolum_id = Convert.ToInt32(bolumnobul.ExecuteScalar());
            NpgsqlCommand ogretmenlergetir = new NpgsqlCommand("select distinct  ogretmen.adsoyad  from ogretmen,dershane,ogretmen_dershane,bolum_dershane,bolum where ogretmen_dershane.ogretmenid=ogretmen.ogretmenid and ogretmen_dershane.dershaneid=dershane.dershaneid and  ogretmen_dershane.ogretmenid=ogretmen.ogretmenid and bolum_dershane.bolumid=bolum.bolumid and ogretmen.bolumid=bolum.bolumid and dershane.dershaneid=@dershane_id and bolum_dershane.bolumid=@bolum_id", baglanti);
            ogretmenlergetir.Parameters.AddWithValue("@bolum_id",comboBox2.SelectedIndex + 1);
            ogretmenlergetir.Parameters.AddWithValue("@dershane_id", dershane_id);

            NpgsqlDataReader oku3 = ogretmenlergetir.ExecuteReader();
            while (oku3.Read())
            {
                comboBox3.Items.Add(oku3[0]);
            }
            oku3.Close();
            NpgsqlCommand dersgetir = new NpgsqlCommand("select dersadi from ders where ders.bolumid=@bolum_id", baglanti);
            dersgetir.Parameters.AddWithValue("@bolum_id", comboBox2.SelectedIndex + 1);
            NpgsqlDataReader oku4 = dersgetir.ExecuteReader();
            while (oku4.Read())
            {
                comboBox4.Items.Add(oku3[0]);
            }
            oku4.Close();
        }

        private void comboBox4_SelectedIndexChanged(object sender, EventArgs e)
        {
            ders_adi = comboBox4.Text;
            NpgsqlCommand dersnobul = new NpgsqlCommand("select dersid from ders where dersadi=@ders_adi", baglanti);
            dersnobul.Parameters.AddWithValue("@ders_adi",ders_adi);
            ders_id = Convert.ToInt32(dersnobul.ExecuteScalar());
        }
        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {
            ogretmen_adsoyad = comboBox3.Text;
            NpgsqlCommand ogretmenbul = new NpgsqlCommand("select * from ogretmen where adsoyad = @ogretmen_adsoyad; ", baglanti);
            ogretmenbul.Parameters.AddWithValue("@ogretmen_adsoyad", ogretmen_adsoyad);
            ogretmen_id = Convert.ToInt32(ogretmenbul.ExecuteScalar());
        }

        private void button2_Click(object sender, EventArgs e)
        {

            NpgsqlCommand sorgula = new NpgsqlCommand("select ozeldersid,ogrenci.adsoyad,dershane.dershaneadi,bolum.bolumadi,ders.dersadi,ogretmen.adsoyad from ogrenci,dershane,bolum,ders,ogretmen,ozelders where ozelders.ogrenciid=ogrenci.ogrenciid and ozelders.ogretmenid=ogretmen.ogretmenid and ozelders.dersid=ders.dersid and ozelders.bolumid=bolum.bolumid and ozelders.dershaneid=dershane.dershaneid and ozeldersid=@hangi_kayit", baglanti);
            sorgula.Parameters.AddWithValue("@hangi_kayit", hangi_kayit);
            NpgsqlDataReader okusorgu = sorgula.ExecuteReader();
            if (okusorgu.Read() == true)
            {
                textBox1.Text = okusorgu[0].ToString();
                textBox2.Text = okusorgu[1].ToString();
                textBox4.Text = okusorgu[2].ToString() + "Dershanesi";
                textBox5.Text = okusorgu[3].ToString();
                textBox6.Text = okusorgu[4].ToString();
                textBox7.Text = okusorgu[5].ToString() + " Bey";
            }
            okusorgu.Close();
        }

        private void comboBox5_SelectedIndexChanged(object sender, EventArgs e)
        {
            hangi_kayit = Convert.ToInt32(comboBox5.Text);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form1 form = new Form1();
            this.Hide();
            form.Show();
        }
    }
}
