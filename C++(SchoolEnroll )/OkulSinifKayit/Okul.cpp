#include "Okul.h"
#include"Ogrenci.h"
#include"DosyaYonetimi.h"
#include<iostream>
#include<Windows.h>
#include<fstream>

char solUstKose = 201;
char duz = 205;
char sagUstKose = 187;
char solAltKose = 200;
char sagAltKose = 188;
char dikey = 186;

DosyaYonetimi dosyaYonetimi; 

void koordinat(int x, int y)    // Ýmleci belirtilen koordinata götüren fonksiyon.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ustYazdir(int elemanSayisi) //kutunun üst þekli
{

	cout << solUstKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagUstKose;
}

void altYazdir(int elemanSayisi) //kutunun alt þekli
{
	cout << solAltKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagAltKose;
}

void Okul::yazdir()
{
		//sýnýf ve öðrencileri ekrana çýkartmalý

		dosyaYonetimi.siniflariDosyadanOlustur();

		for (int i = 0; i < dosyaYonetimi.sinifSayisi; i++)  //ekrana sýnýf sayýsý kadar sýnýf çýkartacak dögü
		{
			Sinif sinif = dosyaYonetimi.sinifListesi[i];

			koordinat((16 * i) + 1,  1);
			ustYazdir(12);
			koordinat((16 * i) + 3,  2);
			cout << sinif.sinifIsmi;
			koordinat((16 * i) + 1, 3);
			altYazdir(12);


			for (int k = 0; k < sinif.ogrenciSayisi; k++) //ekrana öðrenci sayýsý kadar öðrenci çýkaracak dögü
			{
				koordinat((16 * i) + 1, 7 * k + 5);
				ustYazdir(12);
				koordinat((16 * i) + 3, 7 * k + 6);
				cout << sinif.ogrenciListesi[k].getIsim();
				koordinat((16 * i) + 3, 7 * k + 7);
				cout << sinif.ogrenciListesi[k].getSoyisim();
				koordinat((16 * i) + 3, 7 * k + 8);
				cout << sinif.ogrenciListesi[k].getNumara();
				koordinat((16 * i) + 1, 7 * k + 9);
				altYazdir(12);
			}
		}
}


void Okul::ogrenciEkle()
{
	//Ogrenci ekle seçimi yapýldýðýnda öðrenci getiren fonksiyon
	string secimSinif;
	cout << "Sinif Giriniz: ";
	cin >> secimSinif;

	for (int i = 0; i < dosyaYonetimi.sinifSayisi; i++) //sýnýf sayýsý kadar döndürülerek o sýnýfýn öðrenci dizisine ulaþýlýr
	{
		if (dosyaYonetimi.sinifListesi[i].sinifIsmi == secimSinif)//sýnýf dizisinden hangi sýnýfa eklenmsi gerektiði koþulun saðlayan koþul
		{
			Ogrenci ogrenci;
			ogrenci.setIsim(dosyaYonetimi.isimGetir());//yeni öðrencinin adý
			ogrenci.setSoyisim(dosyaYonetimi.soyIsimGetir());//yeni öðrencinin soyadý
			ogrenci.setNumara(dosyaYonetimi.numaraGetir());//yeni öðrencinin numarasý
			dosyaYonetimi.sinifListesi[i].ogrenciEkle(ogrenci);//seçilen yeni öðrenci öðrenci dizisine yazdýrýlýr ve öðrenci sayýsý bir arttýrýlýr
			dosyaYonetimi.kayitlariYenidenYazDosyaya();  //seçilen yeni öðrenci kayýtlara yazdýrýlýr
			break;
		}
	}
}

void Okul::ogrenciSil()
{
	//seçilen öðrenci dizide kaydýrýlarak silinir
	int secimNumara;
	cout << "Okul Numarasini Giriniz: ";
	cin >> secimNumara;

	for (int i = 0; i < dosyaYonetimi.sinifSayisi; i++)//sýnýf sayýsý kadar döndürülerek o sýnýfýn öðrenci dizisine ulaþýlýr
	{
		for (int j = 0; j < dosyaYonetimi.sinifListesi[i].ogrenciSayisi; j++) //öðrenci sayýsý kadar dönendürülerek hedef öðrenciye ulaþýlýr
		{
			if (dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].getNumara() == secimNumara)//seçilen numara o öðrenciye ait olduðunu buluan koþul
			{
				dosyaYonetimi.sinifListesi[i].ogrenciSil(secimNumara); //ogrenci dizisini kaydýran fonksiyon
				dosyaYonetimi.kayitlariYenidenYazDosyaya();           // yeni dizi kaydedilir
				break;
			}
		}
	}
}

void Okul::ogrenciDegistir()
{
	//secilen numara kontrol edilir ve o numaraya sahip öðrenci ile rastgele seçilen bi öðrenci sahip olduðu dizide deðiþir
	int secimNumara;
	cout << "Numara Giriniz: ";
	cin >> secimNumara;

	for (int i = 0; i < dosyaYonetimi.sinifSayisi; i++)//sýnýf sayýsý döndürülerek o sýnýfýn öðrenci dizisine ulaþýlýr
	{
		for (int j = 0; j < dosyaYonetimi.sinifListesi[i].ogrenciSayisi; j++)//öðrenci sayýsý kadar dönendürülerek hedef öðrenciye ulaþýlýr
		{
			if (dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].getNumara() == secimNumara)//secilen numaraya ulaþýlýnca o numaraya sahip öðrenci bilgileri yeni öðrenciyle deðisir
			{
				dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].setIsim(dosyaYonetimi.isimGetir());//yeni öðrencinin adý
				dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].setSoyisim(dosyaYonetimi.soyIsimGetir());//yeni öðrencinin soyadý
				dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].setNumara(dosyaYonetimi.numaraGetir());//yeni öðrencinin numarasý
				
				break;
			}
		}
	}
	dosyaYonetimi.kayitlariYenidenYazDosyaya();
}



void Okul::sinifEkle()
{
	//dosya yonetimde oluþan sýnýf ismini alarak yeni sýnýf oluþturan fonksiyon
	dosyaYonetimi.sinifListesi[dosyaYonetimi.sinifSayisi].sinifIsmi =dosyaYonetimi.sinifGetir();
	dosyaYonetimi.sinifSayisi++;
	dosyaYonetimi.kayitlariYenidenYazDosyaya();
}

void Okul::sinifSil()
{
	//sýnýf dizisini kaydýrarak sýnýf silen fonksiyon
	string secimSinif;
	cout << "Sinifi Giriniz: ";
	cin >> secimSinif;

	bool yerdegistir = false;
	for (int j = 0; j < 99; j++) //sýnýf dizisinin bir eksiði boyutu kadar dönüp o sýnýf dizisindeki seçilen sýnýfýn dizisini(öðrencilerle birlikte)kaydýrýp silinmiþ göstren döngü
	{
		if (dosyaYonetimi.sinifListesi[j].sinifIsmi == secimSinif || yerdegistir == true)//sýnýf ismi ve yerdeðiþme koþulu saðlandýðý zaman kaydýrma iþlemlerini saðlayan koþul
		{
			dosyaYonetimi.sinifListesi[j] = dosyaYonetimi.sinifListesi[j + 1];
			yerdegistir = true;
		}
	}

	if (yerdegistir == true)//yerdeðiþtirme saðlandýysa sýnýf sayýsý bir azalýr
	{
		dosyaYonetimi.sinifSayisi--;
	}

	dosyaYonetimi.kayitlariYenidenYazDosyaya();//yeniden yeni kayýtlar yapýlýr
}




