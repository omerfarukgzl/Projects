
// ***********           PROGRAMLAMAYA G�R�� �DEV 2                      ***********
//************           AD SOYAD: �MER FARUK G�ZEL                      ***********
//************           NUMARA:  G191210068                             ***********
//************           SINIF: 1.S�n�f 2.��retim C grubu                ***********
//************           ��RET�M G�REVL�S�: DR.O�RT.�YES� G�L�ZAR ��T    ***********
//************           ��RET�M G�REVL�S�: AR�.G�R. KAYHAN AYAR         ***********

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

	while (boyut < 5 || boyut>25)      // matris boyut say�s�n�n 5 ile 25 aras�nda olup olmad���n� kontrol eden de�ilse kullan�c�dan boyut de�erini tekrar girdiren d�ng�
	{

		cout << "Matris boyutu 25'den kucuk 5'den buyuk olmalidir. Matris boyutunu tekrar giriniz:  ";
		cin >> boyut;

	}

	cout << "Matrisin boyutu :  " << boyut;
	cout << endl << endl;

	int** matris = new int* [boyut];    //matrisin kullan�c� taraf�ndan girilen boyutunun tan�mlanmas� (dynamic array)

	for (int i = 0; i < boyut; i++)
	{
		matris[i] = new int[boyut];
	}

	int** yedek = new int* [boyut];     //matris elemanlar�n� yedekte tutmak i�in tan�mlanan de�i�ken boyutunun tan�mlanmas� (dynamic array)

	for (int i = 0; i < boyut; i++)
	{
		yedek[i] = new int[boyut];
	}




	cout << "     ";
	for (int k = 0; k < boyut; k++)       //matris g�r�nt�s�nde s�ras�yla s�tun sayisini veren d�ng�

	{
		cout << k + 1 << "      ";
	}

	cout << endl << "   ";


	for (int i = 0; i < boyut; i++)      //matris g�r�nt�s�nde s�tun sayisininin altindaki �izgi �r�nt�s�n� s�ras�yla veren d�ng�
	{

		cout << "____" << "   ";

	}


	cout << endl << endl;

	srand(time(NULL));

	for (int i = 0; i < boyut; i++)       // matris g�r�nt�s�ndeki matris elemanlar�n� �r�nt�sel �ekilde yazd�ran d�ng�
	{
		cout << i + 1 << "|";
		for (int j = 0; j < boyut; j++)   // matris g�r�nt�s�ndeki matris elemanlar�n� rastgele bi�imde boyut say�s�n� baz alarak s�ralayan d�ng�
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


	if (secim == 1)           //1. i�lemin se�ilmesine ba�l� olarakilgilenmesi gereken sat�r� ve s�tunu se�tiren ko�ul
	{
		cout << "Degismesini istediginiz satir ve sutun sayisini sirasiyla giriniz" << endl;
		cout << "satir sayisi: ";
		cin >> satir;
		cout << endl;
		cout << "sutun sayisi: ";
		cin >> sutun;
		cout << endl;
	}
	if (secim == 2)          //2. i�lemin se�ilmesine ba�l� olarak ilgilenmesi gereken sat�r� se�tiren ko�ul
	{
		cout << "islem yaptirmak istediginiz satir sayisini  giriniz" << endl;
		cout << "satir sayisi: ";
		cin >> satir;
		cout << endl;
	}
	if (secim == 3)          //3. i�lemin se�ilmesine ba�l� olarak ilgilenmesi gereken s�tunu se�tiren ko�ul
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
		for (int k = 0; k < boyut; k++)        //matris g�r�nt�s�nde s�ras�yla s�tun sayisini veren d�ng�

		{
			cout << k + 1 << "      ";
		}

		cout << endl << "   ";


		for (int i = 0; i < boyut; i++)        //matris g�r�nt�s�nde s�tun sayisininin altindaki �izgi �r�nt�s�n� s�ras�yla veren d�ng�
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


		if (secim == 1)          //1. i�lemin se�ilmesine ba�l� olarakilgilenmesi gereken sat�r� ve s�tunu se�tiren ko�ul
		{
			cout << "Degismesini istediginiz satir ve sutun sayisini sirasiyla giriniz" << endl;
			cout << "satir sayisi: ";
			cin >> satir;
			cout << endl;
			cout << "sutun sayisi: ";
			cin >> sutun;
			cout << endl;
		}
		if (secim == 2)          //2. i�lemin se�ilmesine ba�l� olarakilgilenmesi gereken sat�r� se�tiren ko�ul
		{
			cout << "islem yaptirmak istediginiz satir sayisini  giriniz" << endl;
			cout << "satir sayisi: ";
			cin >> satir;
			cout << endl;
		}
		if (secim == 3)          //3. i�lemin se�ilmesine ba�l� olarakilgilenmesi gereken s�tunu se�tiren ko�ul
		{
			cout << "islem yaptirmak istediginiz sutun sayisini  giriniz" << endl;
			cout << "sutun sayisi: ";
			cin >> sutun;
			cout << endl;
		}

	}

	//***************************    1. ��LEM      **********************************


	if (secim == 1)                            //1. i�lemin se�ilmesine ba�l� olarak yap�lacak i�lemleri i�eren ko�ul
	{

		for (int i = 0; i < boyut; i++)        //1. i�lem i�in matrisin t�m elemanlar�n� yedekleyen fonksiyon
		{
			for (int j = 0; j < boyut; j++)
			{

				yedek[i][j] = matris[i][j];
			}
		}


		for (int k = 0; k < boyut; k++)       //1. i�lem i�in matrisde se�ilen sat�r� se�ilen s�tunun yerine yerle�time
		{
			yedek[k][sutun - 1] = matris[satir - 1][k];
		}


		int sayi1 = yedek[satir - 1][sutun - 1];


		for (int k = 0; k < boyut; k++)       //1. i�lem i�in  matrisde se�ilen sutunu se�ilen sat�r�n yerine yerle�time
		{
			yedek[satir - 1][k] = matris[k][sutun - 1];
		}

		int sayi2 = yedek[satir - 1][sutun - 1];
		yedek[satir - 1][sutun - 1] = sayi1 + sayi2;



		cout << "      ";
		for (int k = 0; k < boyut; k++)           //matris sutun sayisini sirayla veren d�ng�

		{
			cout << k + 1 << "      ";
		}

		cout << endl << "    ";


		for (int i = 0; i < boyut; i++)             //matris g�r�nt�s�nde s�tun sayisininin altindaki �izgi �r�nt�s�n� s�ras�yla veren d�ng�
		{

			cout << "____" << "   ";

		}


		cout << endl << endl;

		matrisGosterimi(yedek, boyut, boyut);

	}

	//***************************   2. ��LEM    ******************************


	else if (secim == 2)                     //2. i�lemin se�ilmesine ba�l� olarak yap�lacak i�lemleri i�eren ko�ul
	{

		for (int i = 0; i < boyut; i++)       //2. i�lemin se�ilmesine ba�l� olarak ilgili sat�rdaki tek say�lar� ba�a �ift say�lar� sona alan d�ng�
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
		for (int k = 0; k < boyut; k++)           //matris sutun sayisini sirayla veren d�ng�

		{
			cout << k + 1 << "      ";
		}

		cout << endl << "    ";


		for (int i = 0; i < boyut; i++)             //matris g�r�nt�s�nde s�tun sayisininin altindaki �izgi �r�nt�s�n� s�ras�yla veren d�ng�
		{

			cout << "____" << "   ";

		}


		cout << endl << endl;

		matrisGosterimi(matris, boyut, boyut);

	}

	//***************************  3. ��LEM   ******************************


	else if (secim == 3)                       //3. i�lemin se�ilmesine ba�l� olarak yap�lacak i�lemleri i�eren ko�ul
	{

		for (int i = 0; i < boyut / 2; i++)      //3. i�lemin se�ilmesine ba�l� olarak ilgili s�tundaki s�tunca s�ras�yla dizilmi� say�lar� tersten yazd�ran d�ng�
		{
			yedek[i][sutun - 1] = matris[i][sutun - 1];
			matris[i][sutun - 1] = matris[boyut - i - 1][sutun - 1];
			matris[boyut - i - 1][sutun - 1] = yedek[i][sutun - 1];

		}




		cout << "      ";
		for (int k = 0; k < boyut; k++)           //matris sutun sayisini sirayla veren d�ng�

		{
			cout << k + 1 << "      ";
		}

		cout << endl << "    ";


		for (int i = 0; i < boyut; i++)             //matris g�r�nt�s�nde s�tun sayisininin altindaki �izgi �r�nt�s�n� s�ras�yla veren d�ng�
		{

			cout << "____" << "   ";

		}


		cout << endl << endl;

		matrisGosterimi(matris, boyut, boyut);

	}

	//*************************   4.i�lem   **********************************


	else if (secim == 4)                   //4. i�lemin se�ilmesine ba�l� olarak yap�lacak i�lemleri i�eren ko�ul
	{
		int toplam = 0;
		int toplamYedek{};

		for (int i = 0; i < boyut; i++)       //4. i�lemin se�ilmesine ba�l� olarak matrisin t�m elemanlar�n� toplayan d�ng�
		{
			for (int j = 0; j < boyut; j++)
			{
				toplam += matris[i][j];

			}

		}
		toplam == toplamYedek;

		for (int i = 0; i < boyut; i++)        //4. i�lemin se�ilmesine ba�l� olarak matrisin t�m elemanlar�n� toplay�p ilk elemana bu toplam� yazan, ikinci elemana toplamdan ikinci elaman� ��kar�p yazan ve bir �nceki sonu� eleman�ndan ilgili dizi de�erini ��kar�p yazd�ran d�ng�
		{
			for (int j = 0; j < boyut; j++)
			{

				matris[i][j] = toplam - matris[i][j];
				toplam = matris[i][j];

			}
		}

		matris[0][0] == toplamYedek;

		cout << "       ";
		for (int k = 0; k < boyut; k++)         //matris g�r�nt�s�nde s�ras�yla s�tun sayisini veren d�ng�

		{
			cout << k + 1 << "        ";
		}

		cout << endl << "      ";


		for (int i = 0; i < boyut; i++)         //matris sutun sayisininin altindaki �izgi �r�nt�s�n� sirayla veren d�ng�
		{

			cout << "__" << "       ";

		}
		cout << endl << endl;

		for (int i = 0; i < boyut; i++)        // matris g�r�nt�s�ndeki matris elemanlar�n� �r�nt�sel �ekilde yazd�ran d�ng�
		{
			cout << i + 1 << "| ";

			for (int j = 0; j < boyut; j++)    // matris g�r�nt�s�ndeki matris elemanlar�n� rastgele bi�imde boyut say�s�n� baz alarak s�ralayan d�ng�
			{
				if (matris[i][j] >= 100)                          // matris g�r�nt� kaymas�n� engellemek i�in kullan�lan ko�ul
				{
					cout << "   " << matris[i][j] << "   ";
				}
				if (matris[i][j] < 100 && matris[i][j] >= 10)     // matris g�r�nt� kaymas�n� engellemek i�in kullan�lan ko�ul
				{
					cout << "   " << matris[i][j] << "    ";
				}
				if (matris[i][j] < 10)                             // matris g�r�nt� kaymas�n� engellemek i�in kullan�lan ko�ul
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

	for (int i = 0; i < x; i++)   // matrisin sat�r say�s� �r�nt�s�n� ve elemanlar�n� yazd�ran d�ng�
	{
		cout << i + 1 << "|";
		for (int j = 0; j < y; j++)
		{
			cout << "    " << arr[i][j] << "  ";
		}
		cout << endl << endl;
	}
}
