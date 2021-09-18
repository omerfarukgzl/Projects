/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 24.04.2021 - 16.05.2021 
* @course  2B
* <p>
* Borsa İşlemleri Kar Zarar Ve Maliyet Hesabı
* </p>
*/

#ifndef PORTFOY_H
#define PORTFOY_H
#include <stdio.h>
#include <stdlib.h>
struct PORTFOY
{
  char oku;
  char **P_sembol;
  char **P_id;
  char **P_maliyet;
  char **P_adet;
  int *P_iAdet;
  double *P_dMaliyet;
  int P_hisseSayi;
};
typedef struct PORTFOY * Portfoy;

Portfoy PortfoyOlustur();
void P_DosyaOku(Portfoy);
int P_HisseSayiAl();
void P_YokEt(Portfoy);
#endif