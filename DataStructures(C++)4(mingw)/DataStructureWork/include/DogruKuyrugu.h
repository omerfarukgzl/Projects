/**
* @file			Veri yapilari 2. odev
* @description	AVL Agaci
* @course		1B
* @date			26/12/2021
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#ifndef DOGRUKUYRUGU_H
#define DOGRUKUYRUGU_H
#include <iostream>
#include <string>
using namespace std;
struct Nokta{
	int noktalar[3];
    int uzaklik;
    Nokta *next;
};

class DogruKuyrugu {
public:
	DogruKuyrugu();
	void  push(int* , int);
	Nokta* newNode(int* , int);
	int toplamUzunluk;
	struct Nokta* head;
	struct Nokta* rear;
private:
};
 

#endif