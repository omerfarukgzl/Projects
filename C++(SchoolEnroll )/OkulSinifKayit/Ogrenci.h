#pragma once
#include<string>
#include<windows.h>
#include<cstdlib>
#include<time.h>

using namespace std;

class Ogrenci
{

public:
	//Deðiþkenlere eriþim üye fonksiyonlar aracýlýðýyla yapýlabilir.
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
	//	Ogrenci sýnýfý isim, soy isim ve numara deðerini barýndýrmalýdýr.
    //  Sýnýfýn sahip olduðu deðiþkenlerin dýþarýdan direk eriþime kapalý olasý gerekir.
	string isim;
	string soyisim;
	int numara;
};




