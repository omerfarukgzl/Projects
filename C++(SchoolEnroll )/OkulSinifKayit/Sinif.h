#pragma once
#include <string>
#include"Ogrenci.h"
using namespace std;


class Sinif
{
public:
	string sinifIsmi;
	int ogrenciSayisi;
	Ogrenci ogrenciListesi[100];
	void ogrenciEkle(Ogrenci ogrenci);
	void ogrenciSil(int numara);

};

