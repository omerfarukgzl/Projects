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
#include "DogruKuyrugu.h"
using namespace std;

DogruKuyrugu::DogruKuyrugu()
{
	head = NULL;
	rear=NULL;
	toplamUzunluk=0;
}
 Nokta* DogruKuyrugu::newNode(int* x, int p) //Kuyruk Yeni Node EKle
{
    Nokta *nokta = new Nokta;
	for(int i = 0;i < 3;i++){
    	nokta->noktalar[i] = x[i];
    }
	nokta->uzaklik=p;
	nokta->next=NULL;
    return nokta;
}
void DogruKuyrugu:: push(int* x, int p)//Oncelikli Kuyruk EKle
{
        Nokta *nokta = newNode(x, p);
    if (head == NULL) {
        head = nokta;
        return;
    }  
    Nokta *temp = head;
    Nokta *prev = NULL;
    while (temp != NULL && temp->uzaklik < p) //öncelik değerine göre en yakın noktayı yerleştirme
	{
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        prev->next = nokta;
    } else {
        if (prev == NULL) {

            nokta->next = head;
            head = nokta;
        } else {

            nokta->next = temp;
            prev->next = nokta;
        }
    }
}