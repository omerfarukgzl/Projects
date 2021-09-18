/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 24.04.2021 - 16.05.2021 
* @course  2B
* <p>
* Borsa İşlemleri Kar Zarar Ve Maliyet Hesabı
* </p>
*/

#ifndef HISSE_H
#define HISSE_H
#include <stdio.h>
#include <stdlib.h>
struct HISSE
{
  char oku;
  char **sembol;
  char **id;
  char **ad;
  char **fiyat;
  double *dFiyat;
  int hisseSayi;
};
typedef struct HISSE * Hisse;


Hisse HisseOlustur();
void DosyaOku(Hisse);
int HisseSayiAl();
void YokEt(Hisse);
#endif