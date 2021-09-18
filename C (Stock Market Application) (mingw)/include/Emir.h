/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 24.04.2021 - 16.05.2021 
* @course  2B
* <p>
* Borsa İşlemleri Kar Zarar Ve Maliyet Hesabı
* </p>
*/



#ifndef EMIR_H
#define EMIR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct EMIR
{
  char oku;
  char **E_sembol;
  char **E_id;
  char **E_islem;
  char **E_adet;
  int *E_iAdet;
  int E_hisseSayi;
};
typedef struct EMIR * Emir;

Emir EmirOlustur();
void E_DosyaOku(Emir);
int E_HisseSayiAl();
void E_YokEt(Emir);

#endif
