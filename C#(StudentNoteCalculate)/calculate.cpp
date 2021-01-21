/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2020-2021 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 1. ÖDEV 
**				ÖĞRENCİ ADI............: ÖMER FARUK GÜZEL
**				ÖĞRENCİ NUMARASI.......: G191210068
**                         DERSİN ALINDIĞI GRUP...: 1. SINIF 2. ÖĞRETİM C GRUBU
****************************************************************************/
using System;
using System.IO;
namespace G191210069_Soru1
{
    class Program
    {
        static void Main(string[] args)
        {
            string ogrenci;
            double[,] toplamNotlar = new double[50, 50];
            double [, ]notlar = new double [50,50];
            string[,] bilgi=new string[50,10];
            string[] kelimeler = new string[10];
            string[] dizi = new string[50];
            int OgrenciSayac = 1;
            int satirsayac = 0;
            int diziSayac = 0;
            int AAsayac = 0;
            int BAsayac = 0;
            int BBsayac = 0;
            int CBsayac = 0;
            int CCsayac = 0;
            int DCsayac = 0;
            int DDsayac = 0;
            int FDsayac = 0;
            int FFsayac = 0;
            StreamReader textoku = new StreamReader(@"ornek.txt");//text okuma fonksiyonu
            StreamWriter textyaz = new StreamWriter(@"hesap.txt");//text yazma fonksiyonu
            ogrenci = textoku.ReadLine();
            while (true) //okuma işlemi sonlanana kadar öğrenci bilgilerini satır satır okuyan while döngüsü
            {
                if (ogrenci == null) //okuma işlemi sürerken, işlem null(0) olduğunda while döngüsünün sonlanması için yazılan döngü
                {
                    break;
                }
                dizi[OgrenciSayac] = ogrenci;
                kelimeler = dizi[OgrenciSayac].Split(new[]{ ' ' }); //satır satır okunan bilgileri kelime kelime ayıran fonksiyon
                for (int i = satirsayac; i < OgrenciSayac; i++) //ogrenci sayısına kadar dönüp kelime kelime ayrıan bilgileri diziye atan döngü
                {
                    for (int j = 0; j < 7; j++) //kelime sayısına (bilgi sayısı) kadar dönüp kelime kelime ayrıan bilgileri diziye atan iç içe döngü
                    {
                        bilgi[i, j] = kelimeler[j];
                    }
                }
                satirsayac++;
                OgrenciSayac++;
                ogrenci = textoku.ReadLine();
            }
           textoku.Close();
            OgrenciSayac = OgrenciSayac - 1;

            for (int i = 1; i < OgrenciSayac; i++)//ogrenci sayısına kadar dönüp sınıf başarı oranını yazdıran döngü
            {
                for (int j = 0; j < 7; j++)//bilgi sayısına kadar dönüp başarı oranı yazdıran iç içe döngü
                {
                    if (j <= 2)//döngüdeki 'j' değişkeninin küçüktür 2 olması(ad soyad, numara) ile yazdırılan koşul
                    {
                        textyaz.Write(bilgi[i, j] + "  ");
                        Console.Write(bilgi[i, j] + "  ");
                    }
                    else if (j > 2)//döngüdeki 'j' değişkeninin büyüktür 2 olması(odev1, odev2, vize ,final) ile yazdırılan koşul
                    {
                        notlar[i, j] = Convert.ToDouble(bilgi[i, j]);

                        if (j == 3 || j == 4)//odev1 ve odev2 notları yüzde puanı için hazırlanan koşul
                        {
                            
                            (notlar[i, j])/=10;
                        }
                        if (j == 5)//vize notu yüzde puanı için hazırlanan koşul
                        {
                                notlar[i, j] *=(0.3);
                        }
                        if (j == 6)//final notu yüzde puanı  için hazırlanan koşul
                        {
                            notlar[i, j] *= (0.5);
                        }
                        toplamNotlar[i, diziSayac] += notlar[i,j];
                    }
                }
                textyaz.Write(" Not Ortalamasi:"+toplamNotlar[i,diziSayac]+"  Harf Notu: ");

                if (toplamNotlar[i, diziSayac] >= 90)//AA harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("AA");
                    Console.WriteLine("AA");
                    AAsayac++;
                }
                if (toplamNotlar[i, diziSayac] < 90 && toplamNotlar[i, diziSayac]>=85)//BA harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("BA");
                    Console.WriteLine("BA");
                    BAsayac++;
                }
                if (toplamNotlar[i, diziSayac] <85 && toplamNotlar[i, diziSayac] >= 80)//BB harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("BB");
                    Console.WriteLine("BB");
                    BBsayac++;
                }
                if (toplamNotlar[i, diziSayac] < 80 && toplamNotlar[i, diziSayac] >= 75)//CB harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("CB");
                    Console.WriteLine("CB");
                    CBsayac++;
                }
                if (toplamNotlar[i, diziSayac] < 75 && toplamNotlar[i, diziSayac] >= 65)//CC harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("CC");
                    Console.WriteLine("CC");
                    CCsayac++;
                }
                if (toplamNotlar[i, diziSayac] < 65 && toplamNotlar[i, diziSayac] >= 58)//DC harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("DC");
                    Console.WriteLine("DC");
                    DCsayac++;
                }
                if (toplamNotlar[i, diziSayac] < 58 && toplamNotlar[i, diziSayac] >= 50)//DD harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("DD");
                    Console.WriteLine("DD");
                    DDsayac++;
                }
                if (toplamNotlar[i, diziSayac] < 50 && toplamNotlar[i, diziSayac] >= 40)//FD harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("FD");
                    Console.WriteLine("FD");
                    FDsayac++;
                }
                if (toplamNotlar[i, diziSayac] < 40 && toplamNotlar[i, diziSayac] >= 0)//FF harf notu hesaplamak için yazılan koşul
                {
                    textyaz.WriteLine("FF");
                    Console.WriteLine("FF");
                    FFsayac++;
                }
                diziSayac++;
            }
            double AAyuzde,BAyuzde, BByuzde,CByuzde, CCyuzde, DCyuzde,DDyuzde ,FDyuzde, FFyuzde;
            double aaSayac = Convert.ToDouble(AAsayac);
            double baSayac = Convert.ToDouble(BAsayac);
            double bbSayac = Convert.ToDouble(BBsayac);
            double cbSayac = Convert.ToDouble(CBsayac);
            double ccSayac = Convert.ToDouble(CCsayac);
            double dcSayac = Convert.ToDouble(DCsayac);
            double ddSayac = Convert.ToDouble(DDsayac);
            double fdSayac = Convert.ToDouble(FDsayac);
            double ffSayac = Convert.ToDouble(FFsayac);
            OgrenciSayac--;
            AAyuzde = (aaSayac / OgrenciSayac) * 100;
            BAyuzde = (baSayac / OgrenciSayac) * 100;
            BByuzde = (bbSayac / OgrenciSayac) * 100;
            CByuzde = (cbSayac / OgrenciSayac) * 100;
            CCyuzde = (ccSayac / OgrenciSayac) * 100;
            DCyuzde = (dcSayac / OgrenciSayac) * 100;
            DDyuzde = (ddSayac / OgrenciSayac) * 100;
            FDyuzde = (fdSayac / OgrenciSayac) * 100;
            FFyuzde = (ffSayac / OgrenciSayac) * 100;
            
            textyaz.WriteLine("AA alan kisi sayisi:  " + aaSayac + "  yuzdesi: " + " %" + AAyuzde);
            textyaz.WriteLine("BA alan kisi sayisi:  " + baSayac + "  yuzdesi: " + " %" + BAyuzde);
            textyaz.WriteLine("BB alan kisi sayisi:  " + bbSayac + "  yuzdesi: " + " %" + BByuzde);
            textyaz.WriteLine("CB alan kisi sayisi:  " + cbSayac + "  yuzdesi: " + " %" + CByuzde);
            textyaz.WriteLine("CC alan kisi sayisi:  " + ccSayac + "  yuzdesi: " + " %" + CCyuzde);
            textyaz.WriteLine("DC alan kisi sayisi:  " + dcSayac + "  yuzdesi: " + " %" + DCyuzde);
            textyaz.WriteLine("DD alan kisi sayisi:  " + ddSayac + "  yuzdesi: " + " %" + DDyuzde);
            textyaz.WriteLine("FD alan kisi sayisi:  " + fdSayac + "  yuzdesi: " + " %" + FDyuzde);
            textyaz.WriteLine("FF alan kisi sayisi:  " + ffSayac + "  yuzdesi: " + " %" + FFyuzde);

            Console.WriteLine("AA alan kisi sayisi:  " + aaSayac + "  yuzdesi: " + " %" + AAyuzde);
            Console.WriteLine("BA alan kisi sayisi:  " + baSayac + "  yuzdesi: " + " %" + BAyuzde);
            Console.WriteLine("BB alan kisi sayisi:  " + bbSayac + "  yuzdesi: " + " %" + BByuzde);
            Console.WriteLine("CB alan kisi sayisi:  " + cbSayac + "  yuzdesi: " + " %" + CByuzde);
            Console.WriteLine("CC alan kisi sayisi:  " + ccSayac + "  yuzdesi: " + " %" + CCyuzde);
            Console.WriteLine("DC alan kisi sayisi:  " + dcSayac + "  yuzdesi: " + " %" + DCyuzde);
            Console.WriteLine("DD alan kisi sayisi:  " + ddSayac + "  yuzdesi: " + " %" + DDyuzde);
            Console.WriteLine("FD alan kisi sayisi:  " + fdSayac + "  yuzdesi: " + " %" + FDyuzde);
            Console.WriteLine("FF alan kisi sayisi:  " + ffSayac + "  yuzdesi: " + " %" + FFyuzde);
            textyaz.Close();
        }
    }
}


