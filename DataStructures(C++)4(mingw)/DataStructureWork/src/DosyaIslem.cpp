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
#include "DosyaIslem.h"
#include "DogruKuyrugu.h"

using namespace std;
void DosyaIslem::DosyaOku()
{
	string satir;
	ifstream dosya1;
	dosya1.open("Noktalar.txt", ios::in);
	int noktaArray[3];
	AVL* root = NULL;
	while (getline(dosya1, satir))//satir da kelime kelime okunan verileri (Boşluklara kadar okunan) Dogru Kuyrugu sınıfının nokta structına eklenmesi 
	{
		DogruKuyrugu kuyruk;
		string tempSatir = satir;
		istringstream iss(tempSatir);
		istringstream iss2(satir);
		string tempNokta;
		string nokta;
		int noktaSay = 0;
		while (iss >> tempNokta)//boşluksuz olarak okunan kelime
		{
			noktaSay++;
		}
		while (noktaSay)//okunan kelime sayısı
		{
			for (int i = 0; i < 3; i++)// x y x noktalarının eklenmesi
			{
				iss2 >> nokta;
				noktaArray[i] = stoi(nokta);
				noktaSay--;
			}
			int noktaUzaklik = sqrt(pow(noktaArray[0], 2) + pow(noktaArray[1], 2) + pow(noktaArray[2], 2));
			kuyruk.push(noktaArray, noktaUzaklik);
		}
		Nokta* iter = kuyruk.head;
		while (iter->next != NULL)//kuyruk toplam uzunluk bulunması
		{
			kuyruk.toplamUzunluk += sqrt(pow((iter->noktalar[0] - iter->next->noktalar[0]), 2) + pow((iter->noktalar[1] - iter->next->noktalar[1]), 2) + pow((iter->noktalar[2] - iter->next->noktalar[2]), 2));
			iter = iter->next;
		}
		avl.root = avl.AvlEkle(avl.root, kuyruk);
	}
	avl.Postorder(avl.root);
}