#include "Sinif.h"

void Sinif::ogrenciEkle(Ogrenci ogrenci)
{
	
	//Bu fonksiyon parametre olarak ��renci nesnesi alor  ve ald��� nesneyi ��renci dizisine ekleyer(ogrenci say�s�da he reklendi�inde bir artt�r�l�r)
	ogrenciListesi[ogrenciSayisi] = ogrenci;
	ogrenciSayisi++;
}


void Sinif::ogrenciSil(int numara)
{
     //Bu fonksiyon numaras� verilen ��renciyi ��renci dizisinden ��kar�r

	bool yerdegistir = false;

	for (int j = 0; j < 99; j++)  //��rencinin silindi�ini g�stermek i�in se�ilen ��renciden itibaren alttaki ��renci dizilerini bir �ste kayd�ran d�ng�
	{
		if (ogrenciListesi[j].getNumara() == numara || yerdegistir== true)   //se�ilen ��renciden sonraki ��rencileri kayd�rmak i�in kullan�lan ko�ul
		{
			ogrenciListesi[j] = ogrenciListesi[j+1];
			yerdegistir = true;
		}
	}

	if (yerdegistir == true) //de�i�imin ger�ekle�ti�ini kontrol edip true d�nd���nde say�y� bir azaltacak ko�ul
	{
		ogrenciSayisi--;
	}


}

