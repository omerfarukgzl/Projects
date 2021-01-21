#include "Sinif.h"

void Sinif::ogrenciEkle(Ogrenci ogrenci)
{
	
	//Bu fonksiyon parametre olarak öðrenci nesnesi alor  ve aldýðý nesneyi öðrenci dizisine ekleyer(ogrenci sayýsýda he reklendiðinde bir arttýrýlýr)
	ogrenciListesi[ogrenciSayisi] = ogrenci;
	ogrenciSayisi++;
}


void Sinif::ogrenciSil(int numara)
{
     //Bu fonksiyon numarasý verilen öðrenciyi öðrenci dizisinden çýkarýr

	bool yerdegistir = false;

	for (int j = 0; j < 99; j++)  //öðrencinin silindiðini göstermek için seçilen öðrenciden itibaren alttaki öðrenci dizilerini bir üste kaydýran döngü
	{
		if (ogrenciListesi[j].getNumara() == numara || yerdegistir== true)   //seçilen öðrenciden sonraki öðrencileri kaydýrmak için kullanýlan koþul
		{
			ogrenciListesi[j] = ogrenciListesi[j+1];
			yerdegistir = true;
		}
	}

	if (yerdegistir == true) //deðiþimin gerçekleþtiðini kontrol edip true döndüðünde sayýyý bir azaltacak koþul
	{
		ogrenciSayisi--;
	}


}

