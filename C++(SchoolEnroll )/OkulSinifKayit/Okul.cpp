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

void koordinat(int x, int y)    // �mleci belirtilen koordinata g�t�ren fonksiyon.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ustYazdir(int elemanSayisi) //kutunun �st �ekli
{

	cout << solUstKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagUstKose;
}

void altYazdir(int elemanSayisi) //kutunun alt �ekli
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
		//s�n�f ve ��rencileri ekrana ��kartmal�

		dosyaYonetimi.siniflariDosyadanOlustur();

		for (int i = 0; i < dosyaYonetimi.sinifSayisi; i++)  //ekrana s�n�f say�s� kadar s�n�f ��kartacak d�g�
		{
			Sinif sinif = dosyaYonetimi.sinifListesi[i];

			koordinat((16 * i) + 1,  1);
			ustYazdir(12);
			koordinat((16 * i) + 3,  2);
			cout << sinif.sinifIsmi;
			koordinat((16 * i) + 1, 3);
			altYazdir(12);


			for (int k = 0; k < sinif.ogrenciSayisi; k++) //ekrana ��renci say�s� kadar ��renci ��karacak d�g�
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
	//Ogrenci ekle se�imi yap�ld���nda ��renci getiren fonksiyon
	string secimSinif;
	cout << "Sinif Giriniz: ";
	cin >> secimSinif;

	for (int i = 0; i < dosyaYonetimi.sinifSayisi; i++) //s�n�f say�s� kadar d�nd�r�lerek o s�n�f�n ��renci dizisine ula��l�r
	{
		if (dosyaYonetimi.sinifListesi[i].sinifIsmi == secimSinif)//s�n�f dizisinden hangi s�n�fa eklenmsi gerekti�i ko�ulun sa�layan ko�ul
		{
			Ogrenci ogrenci;
			ogrenci.setIsim(dosyaYonetimi.isimGetir());//yeni ��rencinin ad�
			ogrenci.setSoyisim(dosyaYonetimi.soyIsimGetir());//yeni ��rencinin soyad�
			ogrenci.setNumara(dosyaYonetimi.numaraGetir());//yeni ��rencinin numaras�
			dosyaYonetimi.sinifListesi[i].ogrenciEkle(ogrenci);//se�ilen yeni ��renci ��renci dizisine yazd�r�l�r ve ��renci say�s� bir artt�r�l�r
			dosyaYonetimi.kayitlariYenidenYazDosyaya();  //se�ilen yeni ��renci kay�tlara yazd�r�l�r
			break;
		}
	}
}

void Okul::ogrenciSil()
{
	//se�ilen ��renci dizide kayd�r�larak silinir
	int secimNumara;
	cout << "Okul Numarasini Giriniz: ";
	cin >> secimNumara;

	for (int i = 0; i < dosyaYonetimi.sinifSayisi; i++)//s�n�f say�s� kadar d�nd�r�lerek o s�n�f�n ��renci dizisine ula��l�r
	{
		for (int j = 0; j < dosyaYonetimi.sinifListesi[i].ogrenciSayisi; j++) //��renci say�s� kadar d�nend�r�lerek hedef ��renciye ula��l�r
		{
			if (dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].getNumara() == secimNumara)//se�ilen numara o ��renciye ait oldu�unu buluan ko�ul
			{
				dosyaYonetimi.sinifListesi[i].ogrenciSil(secimNumara); //ogrenci dizisini kayd�ran fonksiyon
				dosyaYonetimi.kayitlariYenidenYazDosyaya();           // yeni dizi kaydedilir
				break;
			}
		}
	}
}

void Okul::ogrenciDegistir()
{
	//secilen numara kontrol edilir ve o numaraya sahip ��renci ile rastgele se�ilen bi ��renci sahip oldu�u dizide de�i�ir
	int secimNumara;
	cout << "Numara Giriniz: ";
	cin >> secimNumara;

	for (int i = 0; i < dosyaYonetimi.sinifSayisi; i++)//s�n�f say�s� d�nd�r�lerek o s�n�f�n ��renci dizisine ula��l�r
	{
		for (int j = 0; j < dosyaYonetimi.sinifListesi[i].ogrenciSayisi; j++)//��renci say�s� kadar d�nend�r�lerek hedef ��renciye ula��l�r
		{
			if (dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].getNumara() == secimNumara)//secilen numaraya ula��l�nca o numaraya sahip ��renci bilgileri yeni ��renciyle de�isir
			{
				dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].setIsim(dosyaYonetimi.isimGetir());//yeni ��rencinin ad�
				dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].setSoyisim(dosyaYonetimi.soyIsimGetir());//yeni ��rencinin soyad�
				dosyaYonetimi.sinifListesi[i].ogrenciListesi[j].setNumara(dosyaYonetimi.numaraGetir());//yeni ��rencinin numaras�
				
				break;
			}
		}
	}
	dosyaYonetimi.kayitlariYenidenYazDosyaya();
}



void Okul::sinifEkle()
{
	//dosya yonetimde olu�an s�n�f ismini alarak yeni s�n�f olu�turan fonksiyon
	dosyaYonetimi.sinifListesi[dosyaYonetimi.sinifSayisi].sinifIsmi =dosyaYonetimi.sinifGetir();
	dosyaYonetimi.sinifSayisi++;
	dosyaYonetimi.kayitlariYenidenYazDosyaya();
}

void Okul::sinifSil()
{
	//s�n�f dizisini kayd�rarak s�n�f silen fonksiyon
	string secimSinif;
	cout << "Sinifi Giriniz: ";
	cin >> secimSinif;

	bool yerdegistir = false;
	for (int j = 0; j < 99; j++) //s�n�f dizisinin bir eksi�i boyutu kadar d�n�p o s�n�f dizisindeki se�ilen s�n�f�n dizisini(��rencilerle birlikte)kayd�r�p silinmi� g�stren d�ng�
	{
		if (dosyaYonetimi.sinifListesi[j].sinifIsmi == secimSinif || yerdegistir == true)//s�n�f ismi ve yerde�i�me ko�ulu sa�land��� zaman kayd�rma i�lemlerini sa�layan ko�ul
		{
			dosyaYonetimi.sinifListesi[j] = dosyaYonetimi.sinifListesi[j + 1];
			yerdegistir = true;
		}
	}

	if (yerdegistir == true)//yerde�i�tirme sa�land�ysa s�n�f say�s� bir azal�r
	{
		dosyaYonetimi.sinifSayisi--;
	}

	dosyaYonetimi.kayitlariYenidenYazDosyaya();//yeniden yeni kay�tlar yap�l�r
}




