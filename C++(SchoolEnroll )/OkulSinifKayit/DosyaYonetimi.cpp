#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream> 
#include<windows.h>
#include<time.h>
#include"DosyaYonetimi.h"
#include "Ogrenci.h"
#include"Okul.h"
#include "Sinif.h"

using namespace std;

string isimSatir;
string SoyisimSatir;
int ogrencinumara;
string SinifIsmi;
int isimBoyut = 4946;
int soyisimBoyut = 278;

string DosyaYonetimi::isimGetir()
{
	//S�n�f, �a�r�ld���nda isimler.txt dosyas�n� okuyup buradan rastgele bir isim getirecek bir fonksiyon
	ifstream dosya1;
	dosya1.open("isimler.txt", ios::in);
	int random = rand() % isimBoyut;
	int sayac1 = 0;

	while (getline(dosya1, isimSatir)) //Dosyan�n sonuna kadar okuyup rastgele bir isim getiren d�ng�
	{
		sayac1++;
		if (sayac1 == random)         //sayac�n random say�ya gelip o ismi se�mesi i�in kullan�lan ko�ul
		{
			getline(dosya1, isimSatir);
			break;
		}
	}

	dosya1.close();
	return isimSatir;
}

string DosyaYonetimi::soyIsimGetir()
{
	//	S�n�f, �a�r�ld���nda soyisimler.txt dosyas�n� okuyup buradaki soy isimlerden rastgele birisini getirecek bir fonksiyon.
	ifstream dosya2;
	dosya2.open("soyisimler.txt", ios::in);

	int random2 = rand() % soyisimBoyut;
	int sayac2 = 0;
	while (getline(dosya2, SoyisimSatir))  //Dosyan�n sonuna kadar okuyup rastgele bir isim getiren d�ng�
	{
		sayac2++;
		if (sayac2 == random2)             //sayac�n random say�ya gelip o soyismi se�mesi i�in kullan�lan ko�ul
		{
			getline(dosya2, SoyisimSatir);
			break;
		}
	}
	return SoyisimSatir;
}


int DosyaYonetimi::numaraGetir()
{
	//s�n�f �a��r�ld���nda rastgele �ekilde 100 ile 200 aras� say� getirecek fonksiyon
	int ogrencinumara;
	ogrencinumara = rand() % 100 + 100;
	return ogrencinumara;
}

string DosyaYonetimi::sinifGetir()
{
	//s�n�f �a��r�ld���nda sinif dizisindeki alfabetik harflerden rastgele �ekilde harf getirecek fonksiyon
	srand(time(NULL));

	string sinif[27] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	int a = rand() % 26;
	int yeniSinif = sinifSayisi + 1;
	return to_string(yeniSinif) + sinif[a];  // fonksiyonun d�nd�rd��� de�er string olaca�� i�in sinif say�s� stringe �evrilip s�n�f ismiyle birle�tirildi
}

void DosyaYonetimi::kayitlariYenidenYazDosyaya()
{
	//	S�n�f, Kay�tlar�n kayitlar.txt e yaz�lmas�n� sa�lar (herzaman g�ncel kay�tlar yaz�l�r)
	fstream dosya;
	dosya.open("kayitlar.txt", ios::out);
	for (int i = 0; i < sinifSayisi; i++)       // s�n�f say�s� kadar d�g�y� d�n�r�p s�n�f ad� s�n�f numaras� ve ��renci bilgileri yazmas� i�in kullan�lan d�ng�
	{
		Sinif sinif = sinifListesi[i];
		dosya << sinif.sinifIsmi << endl << sinif.ogrenciSayisi;
		
		if (sinif.ogrenciSayisi == 0 && i==sinifSayisi-1)  // kay�tlar ilk olu�tu�urken i�i bo� oldu�unda ilk satiri bo� de�er d�nd�r�p 
		{
			break;                                         //s�n�f ad�na bo� de�er vermemesi i�in kurulan ko�ul
		}
		else
		{
			dosya << endl;
		}


		for (int j = 0; j < sinif.ogrenciSayisi; j++)      // ogreni say�s� kadar d�n�p ��renci bilgilerini yazd�ran d�ng�
		{
			
			Ogrenci tmpOgrenci = sinif.ogrenciListesi[j];
			dosya << tmpOgrenci.getIsim() << " " << tmpOgrenci.getSoyisim() << " " << tmpOgrenci.getNumara();

			if(i==sinifSayisi-1 && j==sinif.ogrenciSayisi-1)   //kayitlar.txtin sonuna bo�luk koymamas� i�in
			{                                                  //( bo�luk koydu�u takdirde o bo�luk okunup bir sinif ismine sahip olur)
				break;
			}
			else
			{
				dosya << endl;
			}
		}
	}
	dosya.close();
}


void  DosyaYonetimi::siniflariDosyadanOlustur()
{
	// fonksiyon kayitlar.txt ten okudu�u de�erleri s�n�f dizisine ve s�n�f dizisinin i�indeki ��renci dizisine atar
	string satir;
	string ad;
	string soyad;
	int numara;
	int ogrencisayisi;
	int sinifSayac = 0;
	ifstream dosya;
	dosya.open("kayitlar.txt", ios::in);
	
	while (!dosya.eof())    //Dosyan�n sonuna kadar okuyup s�n�f say�s�n� bulan d�ng� (s�n�f say�s� di�er fonksiyonlarda gerekince kullan�l�r)
	{
		dosya >> satir;
		if (satir == "")    //kayitlar.txt in ilk a��ld���nda ilk sat�rdaki bo�lu�unu atlamak i�in kullan�lan ko�ul
		{
			break;
		}
		dosya >> ogrencisayisi;
		for (int i = 0; i < ogrencisayisi; i++) //Ogrencilerin bilgilerini okur 
		{
			dosya >> ad >> soyad >> numara;
		}
		sinifSayac++;
	}

	sinifSayisi = sinifSayac;

	dosya.close();
	dosya.open("kayitlar.txt", ios::in);
	int sinifIndex = 0;

	while (!dosya.eof()) //s�n�f ismini ,s�n�f i�indeki ��renci say�s�n� ve ��renci  bilgilerini okuyup diziye atama yapamas� i�in dosyas�n sonuna gitmesini sa�layan d�ng�
	{
		dosya >> satir;
		if (satir == "")   //kayitlar.txt ilk a��ld��ndaki ilk sat�r�n bo�lu�unu bir de�ere atamamas� i�in kullan�lan ko�ul
		{
			break;
		}

		sinifListesi[sinifIndex].sinifIsmi = satir;//okunan sat�r s�n�f ismine atan�r 
		dosya >> ogrencisayisi;
		sinifListesi[sinifIndex].ogrenciSayisi = ogrencisayisi;//ogrenci say�s� okunur 

		for (int i = 0; i < ogrencisayisi; i++) // ��renci  bilgilerini okuyup diziye atama yapan d�ng�
		{
			dosya >> ad >> soyad >> numara;
			sinifListesi[sinifIndex].ogrenciListesi[i].setIsim(ad);
			sinifListesi[sinifIndex].ogrenciListesi[i].setSoyisim(soyad);
			sinifListesi[sinifIndex].ogrenciListesi[i].setNumara(numara);
		}
		sinifIndex++;
	}
}


