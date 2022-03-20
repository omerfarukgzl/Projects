/**
* @file			Veri yapilari 1. odev
* @description	Txt deki veriler ile ekle sil komutları çalıştırılması
* @course		1B 
* @date			14/11/2021
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Islem.h"

using namespace std;
int main()
{
	Islem *i=new Islem();
	i->DosyaIslemleri();
}