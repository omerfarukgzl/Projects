
// ***********           PROGRAMLAMAYA GÝRÝÞ ÖDEV 2                      ***********
//************           AD SOYAD: ÖMER FARUK GÜZEL                      ***********
//************           NUMARA:  G191210068                             ***********
//************           SINIF: 1.Sýnýf 2.öðretim C grubu                ***********
//************           ÖÐRETÝM GÖREVLÝSÝ: DR.OÐRT.ÜYESÝ GÜLÝZAR ÇÝT    ***********
//************           ÖÐRETÝM GÖREVLÝSÝ: ARÞ.GÖR. KAYHAN AYAR         ***********

#include<iostream>
#include <time.h>

using namespace std;
void matrisGosterimi(int**, int, int);

int main()
{
	int boyut;
	int secim;
	int satir{};
	int sutun{};

	cout << "Bir kare matris icin matris boyutu seciniz :  ";
	cin >> boyut;

	while (boyut < 5 || boyut>25)      // matris boyut sayýsýnýn 5 ile 25 arasýnda olup olmadýðýný kontrol eden deðilse kullanýcýdan boyut deðerini tekrar girdiren döngü
	{

		cout << "Matris boyutu 25'den kucuk 5'den buyuk olmalidir. Matris boyutunu tekrar giriniz:  ";
		cin >> boyut;

	}

	cout << "Matrisin boyutu :  " << boyut;
	cout << endl << endl;

	int** matris = new int* [boyut];    //matrisin kullanýcý tarafýndan girilen boyutunun tanýmlanmasý (dynamic array)

	for (int i = 0; i < boyut; i++)
	{
		matris[i] = new int[boyut];
	}

	int** yedek = new int* [boyut];     //matris elemanlarýný yedekte tutmak için tanýmlanan deðiþken boyutunun tanýmlanmasý (dynamic array)

	for (int i = 0; i < boyut; i++)
	{
		yedek[i] = new int[boyut];
	}




	cout << "     ";
	for (int k = 0; k < boyut; k++)       //matris görüntüsünde sýrasýyla sütun sayisini veren döngü

	{
		cout << k + 1 << "      ";
	}

	cout << endl << "   ";


	for (int i = 0; i < boyut; i++)      //matris görüntüsünde sütun sayisininin altindaki çizgi örüntüsünü sýrasýyla veren döngü
	{

		cout << "____" << "   ";

	}


	cout << endl << endl;

	srand(time(NULL));

	for (int i = 0; i < boyut; i++)       // matris görüntüsündeki matris elemanlarýný örüntüsel þekilde yazdýran döngü
	{
		cout << i + 1 << "|";
		for (int j = 0; j < boyut; j++)   // matris görüntüsündeki matris elemanlarýný rastgele biçimde boyut sayýsýný baz alarak sýralayan döngü
		{
			matris[i][j] = rand() % 9 + 1;

			cout << "   " << matris[i][j] << "   ";
		}

		cout << endl << endl;
	}

	cout << endl << endl;
	cout << "Asagidaki islemlerden yaptirmak istediginizi seciniz " << endl;
	cout<< "(Secim 1 ile 4 arasinda olmalidir) " << endl << endl;
	cout << "1. islem : Satir - Sutun degisimi " << endl;
	cout << "2. islem : Satirdaki tek sayilari basa al " << endl;
	cout << "3. islem : Sutundaki rakamlari tersten yazdir " << endl;
	cout << "4. islem : Toplamlari yazdir " << endl << endl;
	cout << "secim:  ";
	cin >> secim;
	cout << endl << endl;


	if (secim == 1)           //1. iþlemin seçilmesine baðlý olarakilgilenmesi gereken satýrý ve sütunu seçtiren koþul
	{
		cout << "Degismesini istediginiz satir ve sutun sayisini sirasiyla giriniz" << endl;
		cout << "satir sayisi: ";
		cin >> satir;
		cout << endl;
		cout << "sutun sayisi: ";
		cin >> sutun;
		cout << endl;
	}
	if (secim == 2)          //2. iþlemin seçilmesine baðlý olarak ilgilenmesi gereken satýrý seçtiren koþul
	{
		cout << "islem yaptirmak istediginiz satir sayisini  giriniz" << endl;
		cout << "satir sayisi: ";
		cin >> satir;
		cout << endl;
	}
	if (secim == 3)          //3. iþlemin seçilmesine baðlý olarak ilgilenmesi gereken sütunu seçtiren koþul
	{
		cout << "islem yaptirmak istediginiz sutun sayisini  giriniz" << endl;
		cout << "sutun sayisi: ";
		cin >> sutun;
		cout << endl;
	}
	if (secim == 4)
	{
		cout << " Sectiginiz islemin sonucu :" << endl;

	}

	while (satir > boyut || sutun > boyut)
	{
		cout << endl << endl;

		cout << "     ";
		for (int k = 0; k < boyut; k++)        //matris görüntüsünde sýrasýyla sütun sayisini veren döngü

		{
			cout << k + 1 << "      ";
		}

		cout << endl << "   ";


		for (int i = 0; i < boyut; i++)        //matris görüntüsünde sütun sayisininin altindaki çizgi örüntüsünü sýrasýyla veren döngü
		{

			cout << "____" << "   ";

		}

		cout << endl << endl;
		matrisGosterimi(matris, boyut, boyut);

		cout << endl << endl;
		cout << "Hatali deger girdiniz. Sectiginiz deger maris boyutundan buyuk olamaz." << endl;
		cout<< "Asagidaki islemlerden yaptirmak istediginizi tekrar seciniz" << endl << endl;
		cout << "1. islem : Satir - Sutun degisimi " << endl;
		cout << "2. islem : Satirdaki tek sayilari basa al " << endl;
		cout << "3. islem : Sutundaki rakamlari tersten yazdir " << endl;
		cout << "4. islem : Toplamlari yazdir " << endl << endl;
		cout << "secim:  ";
		cin >> secim;
		cout << endl << endl;


		if (secim == 1)          //1. iþlemin seçilmesine baðlý olarakilgilenmesi gereken satýrý ve sütunu seçtiren koþul
		{
			cout << "Degismesini istediginiz satir ve sutun sayisini sirasiyla giriniz" << endl;
			cout << "satir sayisi: ";
			cin >> satir;
			cout << endl;
			cout << "sutun sayisi: ";
			cin >> sutun;
			cout << endl;
		}
		if (secim == 2)          //2. iþlemin seçilmesine baðlý olarakilgilenmesi gereken satýrý seçtiren koþul
		{
			cout << "islem yaptirmak istediginiz satir sayisini  giriniz" << endl;
			cout << "satir sayisi: ";
			cin >> satir;
			cout << endl;
		}
		if (secim == 3)          //3. iþlemin seçilmesine baðlý olarakilgilenmesi gereken sütunu seçtiren koþul
		{
			cout << "islem yaptirmak istediginiz sutun sayisini  giriniz" << endl;
			cout << "sutun sayisi: ";
			cin >> sutun;
			cout << endl;
		}

	}

	//***************************    1. ÝÞLEM      **********************************


	if (secim == 1)                            //1. iþlemin seçilmesine baðlý olarak yapýlacak iþlemleri içeren koþul
	{

		for (int i = 0; i < boyut; i++)        //1. iþlem için matrisin tüm elemanlarýný yedekleyen fonksiyon
		{
			for (int j = 0; j < boyut; j++)
			{

				yedek[i][j] = matris[i][j];
			}
		}


		for (int k = 0; k < boyut; k++)       //1. iþlem için matrisde seçilen satýrý seçilen sütunun yerine yerleþtime
		{
			yedek[k][sutun - 1] = matris[satir - 1][k];
		}


		int sayi1 = yedek[satir - 1][sutun - 1];


		for (int k = 0; k < boyut; k++)       //1. iþlem için  matrisde seçilen sutunu seçilen satýrýn yerine yerleþtime
		{
			yedek[satir - 1][k] = matris[k][sutun - 1];
		}

		int sayi2 = yedek[satir - 1][sutun - 1];
		yedek[satir - 1][sutun - 1] = sayi1 + sayi2;



		cout << "      ";
		for (int k = 0; k < boyut; k++)           //matris sutun sayisini sirayla veren döngü

		{
			cout << k + 1 << "      ";
		}

		cout << endl << "    ";


		for (int i = 0; i < boyut; i++)             //matris görüntüsünde sütun sayisininin altindaki çizgi örüntüsünü sýrasýyla veren döngü
		{

			cout << "____" << "   ";

		}


		cout << endl << endl;

		matrisGosterimi(yedek, boyut, boyut);

	}

	//***************************   2. ÝÞLEM    ******************************


	else if (secim == 2)                     //2. iþlemin seçilmesine baðlý olarak yapýlacak iþlemleri içeren koþul
	{

		for (int i = 0; i < boyut; i++)       //2. iþlemin seçilmesine baðlý olarak ilgili satýrdaki tek sayýlarý baþa çift sayýlarý sona alan döngü
		{
			for (int j = 0; j < boyut - 1; j++)
			{
				if (matris[satir - 1][j] % 2 == 0)
				{
					yedek[i][j] = matris[satir - 1][j];
					matris[satir - 1][j] = matris[satir - 1][j + 1];
					matris[satir - 1][j + 1] = yedek[i][j];

				}
			}
		}


		cout << "      ";
		for (int k = 0; k < boyut; k++)           //matris sutun sayisini sirayla veren döngü

		{
			cout << k + 1 << "      ";
		}

		cout << endl << "    ";


		for (int i = 0; i < boyut; i++)             //matris görüntüsünde sütun sayisininin altindaki çizgi örüntüsünü sýrasýyla veren döngü
		{

			cout << "____" << "   ";

		}


		cout << endl << endl;

		matrisGosterimi(matris, boyut, boyut);

	}

	//***************************  3. ÝÞLEM   ******************************


	else if (secim == 3)                       //3. iþlemin seçilmesine baðlý olarak yapýlacak iþlemleri içeren koþul
	{

		for (int i = 0; i < boyut / 2; i++)      //3. iþlemin seçilmesine baðlý olarak ilgili sütundaki sütunca sýrasýyla dizilmiþ sayýlarý tersten yazdýran döngü
		{
			yedek[i][sutun - 1] = matris[i][sutun - 1];
			matris[i][sutun - 1] = matris[boyut - i - 1][sutun - 1];
			matris[boyut - i - 1][sutun - 1] = yedek[i][sutun - 1];

		}




		cout << "      ";
		for (int k = 0; k < boyut; k++)           //matris sutun sayisini sirayla veren döngü

		{
			cout << k + 1 << "      ";
		}

		cout << endl << "    ";


		for (int i = 0; i < boyut; i++)             //matris görüntüsünde sütun sayisininin altindaki çizgi örüntüsünü sýrasýyla veren döngü
		{

			cout << "____" << "   ";

		}


		cout << endl << endl;

		matrisGosterimi(matris, boyut, boyut);

	}

	//*************************   4.iþlem   **********************************


	else if (secim == 4)                   //4. iþlemin seçilmesine baðlý olarak yapýlacak iþlemleri içeren koþul
	{
		int toplam = 0;
		int toplamYedek{};

		for (int i = 0; i < boyut; i++)       //4. iþlemin seçilmesine baðlý olarak matrisin tüm elemanlarýný toplayan döngü
		{
			for (int j = 0; j < boyut; j++)
			{
				toplam += matris[i][j];

			}

		}
		toplam == toplamYedek;

		for (int i = 0; i < boyut; i++)        //4. iþlemin seçilmesine baðlý olarak matrisin tüm elemanlarýný toplayýp ilk elemana bu toplamý yazan, ikinci elemana toplamdan ikinci elamaný çýkarýp yazan ve bir önceki sonuç elemanýndan ilgili dizi deðerini çýkarýp yazdýran döngü
		{
			for (int j = 0; j < boyut; j++)
			{

				matris[i][j] = toplam - matris[i][j];
				toplam = matris[i][j];

			}
		}

		matris[0][0] == toplamYedek;

		cout << "       ";
		for (int k = 0; k < boyut; k++)         //matris görüntüsünde sýrasýyla sütun sayisini veren döngü

		{
			cout << k + 1 << "        ";
		}

		cout << endl << "      ";


		for (int i = 0; i < boyut; i++)         //matris sutun sayisininin altindaki çizgi örüntüsünü sirayla veren döngü
		{

			cout << "__" << "       ";

		}
		cout << endl << endl;

		for (int i = 0; i < boyut; i++)        // matris görüntüsündeki matris elemanlarýný örüntüsel þekilde yazdýran döngü
		{
			cout << i + 1 << "| ";

			for (int j = 0; j < boyut; j++)    // matris görüntüsündeki matris elemanlarýný rastgele biçimde boyut sayýsýný baz alarak sýralayan döngü
			{
				if (matris[i][j] >= 100)                          // matris görüntü kaymasýný engellemek için kullanýlan koþul
				{
					cout << "   " << matris[i][j] << "   ";
				}
				if (matris[i][j] < 100 && matris[i][j] >= 10)     // matris görüntü kaymasýný engellemek için kullanýlan koþul
				{
					cout << "   " << matris[i][j] << "    ";
				}
				if (matris[i][j] < 10)                             // matris görüntü kaymasýný engellemek için kullanýlan koþul
				{
					cout << "   " << matris[i][j] << "     ";

				}

			}

			cout << endl << endl;
		}

	}

	system("pause");

}


void matrisGosterimi(int** arr, int x, int y)
{

	cout << endl;

	for (int i = 0; i < x; i++)   // matrisin satýr sayýsý örüntüsünü ve elemanlarýný yazdýran döngü
	{
		cout << i + 1 << "|";
		for (int j = 0; j < y; j++)
		{
			cout << "    " << arr[i][j] << "  ";
		}
		cout << endl << endl;
	}
}
