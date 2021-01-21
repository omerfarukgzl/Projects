#pragma once
#include<string>
#include<windows.h>
#include<cstdlib>
#include<time.h>

using namespace std;

class Ogrenci
{

public:
	//De�i�kenlere eri�im �ye fonksiyonlar arac�l���yla yap�labilir.
	void setIsim(string isim);
	string getIsim();
	void setSoyisim(string soyisim);
	string getSoyisim();
	void setNumara(int numara);
	int getNumara();
	/*string ogrenciIsim();
	string ogrenciSoyIsim();
	int ogrenciNumara();*/


private:
	//	Ogrenci s�n�f� isim, soy isim ve numara de�erini bar�nd�rmal�d�r.
    //  S�n�f�n sahip oldu�u de�i�kenlerin d��ar�dan direk eri�ime kapal� olas� gerekir.
	string isim;
	string soyisim;
	int numara;
};




