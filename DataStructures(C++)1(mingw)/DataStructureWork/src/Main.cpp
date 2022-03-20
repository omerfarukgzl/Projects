/**
* @file			Veri yapilari 1. odev
* @description	Txt deki sayıları düğüme atma ve ortanca değeri en büyük olan ile en küçüğü çaprazlama 
* @course		2A
* @date			29/11/2020
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Kontrol.h"

using namespace std;


int main()
{
	Kontrol *k=new Kontrol();
	k->DosyaIslemleri();
	k->Caprazlama();
}