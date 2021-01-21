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
	Sinif sinifListesi[100];//sýnýf dizisi
	void kayitlariYenidenYazDosyaya(); // dosyaya yazma
	void siniflariDosyadanOlustur();  //dosyadan okuma

	string isimGetir();//isim seçilir
	string soyIsimGetir();//soyisim seçilir
	int numaraGetir();//numara seçilir
	string sinifGetir();//sýnýf ismi seçilir
	int sinifSayisi;//sýnýf sayýsý bellekte tutulur
};

