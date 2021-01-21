#pragma once
#include "DosyaYonetimi.h"
#include <string>
#include "Ogrenci.h"
#include "Sinif.h"
#include "Okul.h"
#include <iostream>
using namespace std;

class DosyaYonetimi
{
public:
	Sinif sinifListesi[100];//s�n�f dizisi
	void kayitlariYenidenYazDosyaya(); // dosyaya yazma
	void siniflariDosyadanOlustur();  //dosyadan okuma

	string isimGetir();//isim se�ilir
	string soyIsimGetir();//soyisim se�ilir
	int numaraGetir();//numara se�ilir
	string sinifGetir();//s�n�f ismi se�ilir
	int sinifSayisi;//s�n�f say�s� bellekte tutulur
};

