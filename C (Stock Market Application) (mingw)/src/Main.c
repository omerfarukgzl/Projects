/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 24.04.2021 - 16.05.2021 
* @course  2B
* <p>
* Borsa İşlemleri Kar Zarar Ve Maliyet Hesabı
* </p>
*/

#include <stdio.h>
#include <stdlib.h>
#include "Hisse.h"
#include "Portfoy.h"
#include "Emir.h"
#include "Banka.h"

int main()
{
	Emir e = EmirOlustur();
	E_DosyaOku(e);
	Banka b = BankaOlustur(e);
	EmirlerHesap(b,e);
	B_YokEt(b);

	
	
}