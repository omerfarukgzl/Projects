/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 24.04.2021 - 16.05.2021 
* @course  2B
* <p>
* Borsa İşlemleri Kar Zarar Ve Maliyet Hesabı
* </p>
*/

#ifndef BANKA_H
#define BANKA_H
#include <stdio.h>
#include <stdlib.h>
# include "Emir.h"

struct BANKA
{
  char * B_islemSatis;
  char * B_islemAlis;
  
  char ** B_sembolAlis;
  char ** B_sembolSatis;
  
  double B_toplamKarZarar;
  double *B_guncelAdet;
  double *B_guncelFiyat;
  double *B_maliyet;
  double *B_karZararHesap;
  
  
};
typedef struct BANKA * Banka;

Banka BankaOlustur(Emir);
void EmirlerHesap(Banka,Emir);
void B_YokEt(Banka);


#endif