/**
* @file			Veri yapilari 1. odev
* @description	Txt deki veriler ile ekle sil komutları çalıştırılması
* @course		1B 
* @date			14/11/2021
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#ifndef ISLEM_H
#define ISLEM_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
struct Node
{
	string data;
	Node * next;
	Node * prev;
};
class Islem
{

public:
    Islem();
	~Islem();
	void NodeEkle(string , int);
	void DosyaIslemleri();
	void EkranaYazdir(Node*);
	void NodeSil(int);
private:

 struct Node * root ; 
};
#endif