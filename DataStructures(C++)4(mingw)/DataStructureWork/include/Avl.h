/**
* @file			Veri yapilari 2. odev
* @description	AVL Agaci
* @course		1B
* @date			26/12/2021
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#ifndef KONTROL_H
#define KONTROL_H
#include <iostream>
#include <string>

#include "DogruKuyrugu.h"
using namespace std;

struct AVL
{
	DogruKuyrugu dogrukuyrugu;
	int yukseklik;
	AVL* sag;
	AVL* sol;
};
class Avl
{
public:
	Avl();
	AVL* YeniNode(DogruKuyrugu);
	AVL* AvlEkle(AVL*, DogruKuyrugu);
	int Max(int, int);
	int Denge(AVL*);
	int Yukseklik(AVL* node);
	AVL* SagDonus(AVL*);
	AVL* SolDonus(AVL*);
	void Postorder(AVL*);
	struct AVL* root;
private:
};


#endif