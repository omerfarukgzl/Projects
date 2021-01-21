/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2020-2021 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:SORU 2
**				ÖĞRENCİ ADI............:ÖMER FARUK GÜZEL
**				ÖĞRENCİ NUMARASI.......:G191210068
**              DERSİN ALINDIĞI GRUP...:1.SINIF 2. ÖĞRETİM C GRUBU
****************************************************************************/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace G191210068_Soru2
{
    public partial class Form1 : Form
    {
        public int sayi1;
        public int sayi2;
       
        public Form1()
        {
            InitializeComponent();
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }
        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)//sadece sayı(pozitif) girişini sağlıyoruz
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }
        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)//sadece sayı(pozitif) girişini sağlıyoruz
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }
        Label X = new Label();
        Label Y = new Label();
        ListBox bolumlerX = new ListBox();
        ListBox bolumlerY = new ListBox();
        Label Toplamlar = new Label();
        TextBox kutu1 = new TextBox();
        TextBox kutu2 = new TextBox();
        private void button1_Click(object sender, EventArgs e)//Arkadaşmı butonu
        {
            bolumlerX.Items.Clear();
            bolumlerY.Items.Clear();
            int bolumler1 = 0;
            int bolumler2 = 0;
           
            X.Left = 450;
            X.Top = 50;
            X.Text = "X";
            this.Controls.Add(X);
           
            Y.Left = 600;
            Y.Top = 50;
            Y.Text = "Y";
            this.Controls.Add(Y);
    
            bolumlerX.Left = 400;
            bolumlerX.Top = 100;
            bolumlerX.Height = 200;
            this.Controls.Add(bolumlerX);
          
            bolumlerY.Left = 550;
            bolumlerY.Top = 100;
            bolumlerY.Height = 200;
            this.Controls.Add(bolumlerY);

            Toplamlar.Left = 300;
            Toplamlar.Top = 320;
            Toplamlar.Text = "Toplamlar";
            this.Controls.Add(Toplamlar);

            kutu1.Left = 400;
            kutu1.Top = 320;
            this.Controls.Add(kutu1);

            kutu2.Left = 550;
            kutu2.Top = 320;
            this.Controls.Add(kutu2);

            sayi1 = Convert.ToInt32(textBox1.Text);
            sayi2 = Convert.ToInt32(textBox2.Text);

            for (int i = 1; i < sayi1; i++)//girilen sayi1 in çarpanlarını bulmak ve çarpan toplamlarını bulmak için hazırlanan döngü
            {
                if (sayi1 % i == 0)//for döngüsünde sayi1 in i ile bölümünden kalanın 0 olduğu yani tam bölündüğünü sağlayan koşul(çarpanı ifade eder)
                {
                    bolumlerX.Items.Add(i);
                    bolumler1 += i;
                }
            }
            string bolum1 = Convert.ToString(bolumler1);
            kutu1.Text = bolum1;
            for (int j = 1; j < sayi2; j++)//girilen sayi2 in çarpanlarını bulmak ve çarpan toplamlarını bulmak için hazırlanan döngü
            {
                if (sayi2 % j == 0)//for döngüsünde sayi2 nin i ile bölümünden kalanın 0 olduğu yani tam bölündüğünü sağlayan koşul(çarpanı ifade eder)
                {
                    bolumlerY.Items.Add(j);
                    bolumler2 += j;
                }
            }
            string bolum2 = Convert.ToString(bolumler2);
            kutu2.Text = bolum2;
            if (kutu2.Text == textBox1.Text && kutu1.Text == textBox2.Text)//sayiların arkadaş olup olmadığını kontrol edden koşul
            {
                MessageBox.Show("Bu Sayilar Arkadastir");
            }
            else//sayiların arkadaş olup olmadığını kontrol edden koşul
            {
                MessageBox.Show("Bu Sayilar Arkadas Degildir");
            }
        }
        private void button2_Click(object sender, EventArgs e)//son butonuna tıklanınca program kapatılıyor
        {
            Application.Exit();
        }
    }
}
