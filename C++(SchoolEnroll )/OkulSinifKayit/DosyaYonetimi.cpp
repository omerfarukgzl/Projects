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
	//Sýnýf, çaðrýldýðýnda isimler.txt dosyasýný okuyup buradan rastgele bir isim getirecek bir fonksiyon
	ifstream dosya1;
	dosya1.open("isimler.txt", ios::in);
	int random = rand() % isimBoyut;
	int sayac1 = 0;

	while (getline(dosya1, isimSatir)) //Dosyanýn sonuna kadar okuyup rastgele bir isim getiren döngü
	{
		sayac1++;
		if (sayac1 == random)         //sayacýn random sayýya gelip o ismi seçmesi için kullanýlan koþul
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
	//	Sýnýf, çaðrýldýðýnda soyisimler.txt dosyasýný okuyup buradaki soy isimlerden rastgele birisini getirecek bir fonksiyon.
	ifstream dosya2;
	dosya2.open("soyisimler.txt", ios::in);

	int random2 = rand() % soyisimBoyut;
	int sayac2 = 0;
	while (getline(dosya2, SoyisimSatir))  //Dosyanýn sonuna kadar okuyup rastgele bir isim getiren döngü
	{
		sayac2++;
		if (sayac2 == random2)             //sayacýn random sayýya gelip o soyismi seçmesi için kullanýlan koþul
		{
			getline(dosya2, SoyisimSatir);
			break;
		}
	}
	return SoyisimSatir;
}


int DosyaYonetimi::numaraGetir()
{
	//sýnýf çaðýrýldýðýnda rastgele þekilde 100 ile 200 arasý sayý getirecek fonksiyon
	int ogrencinumara;
	ogrencinumara = rand() % 100 + 100;
	return ogrencinumara;
}

string DosyaYonetimi::sinifGetir()
{
	//sýnýf çaðýrýldýðýnda sinif dizisindeki alfabetik harflerden rastgele þekilde harf getirecek fonksiyon
	srand(time(NULL));

	string sinif[27] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	int a = rand() % 26;
	int yeniSinif = sinifSayisi + 1;
	return to_string(yeniSinif) + sinif[a];  // fonksiyonun döndürdüðü deðer string olacaðý için sinif sayýsý stringe çevrilip sýnýf ismiyle birleþtirildi
}

void DosyaYonetimi::kayitlariYenidenYazDosyaya()
{
	//	Sýnýf, Kayýtlarýn kayitlar.txt e yazýlmasýný saðlar (herzaman güncel kayýtlar yazýlýr)
	fstream dosya;
	dosya.open("kayitlar.txt", ios::out);
	for (int i = 0; i < sinifSayisi; i++)       // sýnýf sayýsý kadar dögüyü dönürüp sýnýf adý sýnýf numarasý ve öðrenci bilgileri yazmasý için kullanýlan döngü
	{
		Sinif sinif = sinifListesi[i];
		dosya << sinif.sinifIsmi << endl << sinif.ogrenciSayisi;
		
		if (sinif.ogrenciSayisi == 0 && i==sinifSayisi-1)  // kayýtlar ilk oluþtuðurken içi boþ olduðunda ilk satiri boþ deðer döndürüp 
		{
			break;                                         //sýnýf adýna boþ deðer vermemesi için kurulan koþul
		}
		else
		{
			dosya << endl;
		}


		for (int j = 0; j < sinif.ogrenciSayisi; j++)      // ogreni sayýsý kadar dönüp öðrenci bilgilerini yazdýran döngü
		{
			
			Ogrenci tmpOgrenci = sinif.ogrenciListesi[j];
			dosya << tmpOgrenci.getIsim() << " " << tmpOgrenci.getSoyisim() << " " << tmpOgrenci.getNumara();

			if(i==sinifSayisi-1 && j==sinif.ogrenciSayisi-1)   //kayitlar.txtin sonuna boþluk koymamasý için
			{                                                  //( boþluk koyduðu takdirde o boþluk okunup bir sinif ismine sahip olur)
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
	// fonksiyon kayitlar.txt ten okuduðu deðerleri sýnýf dizisine ve sýnýf dizisinin içindeki öðrenci dizisine atar
	string satir;
	string ad;
	string soyad;
	int numara;
	int ogrencisayisi;
	int sinifSayac = 0;
	ifstream dosya;
	dosya.open("kayitlar.txt", ios::in);
	
	while (!dosya.eof())    //Dosyanýn sonuna kadar okuyup sýnýf sayýsýný bulan döngü (sýnýf sayýsý diðer fonksiyonlarda gerekince kullanýlýr)
	{
		dosya >> satir;
		if (satir == "")    //kayitlar.txt in ilk açýldýðýnda ilk satýrdaki boþluðunu atlamak için kullanýlan koþul
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

	while (!dosya.eof()) //sýnýf ismini ,sýnýf içindeki öðrenci sayýsýný ve öðrenci  bilgilerini okuyup diziye atama yapamasý için dosyasýn sonuna gitmesini saðlayan döngü
	{
		dosya >> satir;
		if (satir == "")   //kayitlar.txt ilk açýldýðndaki ilk satýrýn boþluðunu bir deðere atamamasý için kullanýlan koþul
		{
			break;
		}

		sinifListesi[sinifIndex].sinifIsmi = satir;//okunan satýr sýnýf ismine atanýr 
		dosya >> ogrencisayisi;
		sinifListesi[sinifIndex].ogrenciSayisi = ogrencisayisi;//ogrenci sayýsý okunur 

		for (int i = 0; i < ogrencisayisi; i++) // öðrenci  bilgilerini okuyup diziye atama yapan döngü
		{
			dosya >> ad >> soyad >> numara;
			sinifListesi[sinifIndex].ogrenciListesi[i].setIsim(ad);
			sinifListesi[sinifIndex].ogrenciListesi[i].setSoyisim(soyad);
			sinifListesi[sinifIndex].ogrenciListesi[i].setNumara(numara);
		}
		sinifIndex++;
	}
}


