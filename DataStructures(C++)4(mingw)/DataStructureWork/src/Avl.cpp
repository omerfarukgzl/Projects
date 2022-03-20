/**
* @file			Veri yapilari 2. odev
* @description	AVL Agaci
* @course		1B
* @date			26/12/2021
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include "Avl.h"
#include "DogruKuyrugu.h"
using namespace std;
Avl::Avl()
{
	root=NULL;
}
int Avl::Yukseklik(AVL* node)
{
	if (node == NULL)
		return 0;
	return node->yukseklik;
}
int Avl::Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
AVL* Avl::SagDonus(AVL* a)
{
	//denge şartı için sağa döndürme
	//düğümlerin bağlantılarını yedekleyerek yapılır
	AVL* b = a->sol;
	AVL* c = b->sag;
	b->sag = a;
	a->sol = c;
	a->yukseklik = Max(Yukseklik(a->sol), Yukseklik(a->sag)) + 1;
	b->yukseklik = Max(Yukseklik(b->sol), Yukseklik(b->sag)) + 1;
	delete c;
	return b;
}
AVL* Avl::SolDonus(AVL* b)
{
	//denge şartı için sola döndürme
	//düğümlerin bağlantılarını yedekleyerek yapılır
	AVL* a = b->sag;
	AVL* c = a->sol;
	a->sol = b;
	b->sag = c;
	b->yukseklik = Max(Yukseklik(b->sol), Yukseklik(b->sag)) + 1;
	a->yukseklik = Max(Yukseklik(a->sol), Yukseklik(a->sag)) + 1;
	delete c;
	return a;
}
int Avl::Denge(AVL* Node)//avl agacı yaprak dengesi
{
	if (Node == NULL)
		return 0;
	return Yukseklik(Node->sol) - Yukseklik(Node->sag);
}
AVL* Avl::YeniNode(DogruKuyrugu dogrukuyrugu)	//yeni avl node oluşturma 
{
	AVL* dugum = new AVL();
	dugum->dogrukuyrugu = dogrukuyrugu;
	dugum->sol = NULL;
	dugum->sag = NULL;
	dugum->yukseklik = 1;
	return (dugum);
}
AVL* Avl::AvlEkle(AVL* node, DogruKuyrugu dogrukuyrugu) //avl node ekleme 
{
	int uzunluk = dogrukuyrugu.toplamUzunluk;
	if (node == NULL)  //eklenecek olan avl boşsa
	{
		return YeniNode(dogrukuyrugu);
	}
	if (uzunluk < node->dogrukuyrugu.toplamUzunluk)  //eklenecek değer ebeveyn düğümün değerinden küçükse
		node->sol = AvlEkle(node->sol, dogrukuyrugu);
	else if (uzunluk > node->dogrukuyrugu.toplamUzunluk)   //eklenecek değer ebeveyn düğümün değerinden büyükse
		node->sag = AvlEkle(node->sag, dogrukuyrugu);
	else if (uzunluk == node->dogrukuyrugu.toplamUzunluk)   //eklenecek değer ebeveyn düğümün değerine eşitse
		node->sol = AvlEkle(node->sol, dogrukuyrugu);

	node->yukseklik = 1 + Max(Yukseklik(node->sol), Yukseklik(node->sag));  //avl nin yüksekliğini güncelleme ve tanımlama

	int denge = Denge(node);
	if (denge > 1 && uzunluk < node->sol->dogrukuyrugu.toplamUzunluk)
		return SagDonus(node);

	if (denge < -1 && uzunluk > node->sag->dogrukuyrugu.toplamUzunluk)
		return SolDonus(node);

	if (denge > 1 && uzunluk > node->sol->dogrukuyrugu.toplamUzunluk)
	{
		node->sol = SolDonus(node->sol);
		return SagDonus(node);
	}
	if (denge < -1 && uzunluk < node->sag->dogrukuyrugu.toplamUzunluk)
	{
		node->sag = SagDonus(node->sag);
		return SolDonus(node);
	}
	return node;
}
void Avl::Postorder(AVL* t)// avl posterder yazdırma
{
	if (t == NULL)
		return;
	Postorder(t->sol);
	Postorder(t->sag);
	Nokta* nokta = t->dogrukuyrugu.head;
	while (nokta->next != NULL) {
		cout << nokta->uzaklik << " ";
		nokta = nokta->next;
	}
	cout << nokta->uzaklik << "\n";
}