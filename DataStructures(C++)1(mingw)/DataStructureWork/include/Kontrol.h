/**
* @file			Veri yapilari 1. odev
* @description	Txt deki sayıları düğüme atma ve ortanca değeri en büyük olan ile en küçüğü çaprazlama 
* @course		2A
* @date			29/11/2020
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#ifndef KONTROL_H
#define KONTROL_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct listeler
{
	int data;
	listeler * next;
	listeler * prev;
};
class Kontrol
{

public:
    Kontrol();
	void DosyaIslemleri();
	void Caprazlama();
	void NodeEkle(int**,int,int);
	void Bastir(int);
    int ListSayisi();
private:
    int listsayisi;
    struct listeler ** orta;
	struct listeler ** temp;
	struct listeler ** temp2;
};


#endif