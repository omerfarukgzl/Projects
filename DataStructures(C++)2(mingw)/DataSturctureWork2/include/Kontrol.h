/**
* @file			Veri yapilari 2. odev
* @description	AVL Agaci
* @course		2A
* @date			27/12/2020
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#ifndef KONTROL_H
#define KONTROL_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct AVL
{
	int kisiSayisi;
	int yukseklik;
	string isYeri;
	int yilDeger;
	string adSoyad;
	AVL * sag;
	AVL * sol;
	AVL * baglanti;
};
class Kontrol
{
public:
    Kontrol();
 	void DosyaIslemleri();
	int ListSayisi();
	AVL* NodeUpdate(AVL*,AVL*); 
    AVL* YeniNodeIc(int,string);
	AVL* YeniNodeDis(int ,string ,int ,int  ,string );
	AVL* AvlEkleIc(AVL*,int,string);
	int Max(int, int);
	int Denge(AVL *);
	int Yukseklik(AVL * node)  ;
	AVL* SagDonus(AVL *);  
	AVL* SolDonus(AVL *); 
	AVL* AvlEkleDis(AVL*, int , string,int ,int ,string);
	void PostorderDis(AVL *);
	void PostorderIc(AVL *);
private:
	int listsayisi;
	struct AVL  ** avl_ic;
	struct AVL ** avl_dis;
};


#endif