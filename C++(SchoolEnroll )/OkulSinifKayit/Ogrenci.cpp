#include "Ogrenci.h"
#include <string>
#include"DosyaYonetimi.h"


void Ogrenci::setIsim(string isim)
{
	this->isim = isim;
}
string Ogrenci::getIsim()
{
	return isim;
}
void Ogrenci::setSoyisim(string soyisim)
{
	this->soyisim = soyisim;
}
string Ogrenci::getSoyisim()
{
	return soyisim;
}
void Ogrenci::setNumara(int numara)
{
	this->numara = numara;
}
int Ogrenci::getNumara()
{
	return numara;
}


