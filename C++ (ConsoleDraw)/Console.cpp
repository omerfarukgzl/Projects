//**********************************************************************************
// ***********           PROGRAMLAMAYA GÝRÝÞ ÖDEV 1                      ***********
//************           AD:    ÖMER FARUK GÜZEL                         ***********
//************           NUMARA:  G191210068                             ***********
//************           SINIF: 2.öðretim C grubu                        ***********
//************           ÖÐRETÝM GÖREVLÝSÝ: DR.OÐRT.ÜYESÝ GÜLÝZAR ÇÝT    ***********
//************           ÖÐRETÝM GÖREVLÝSÝ: ARÞ.GÖR. KAYHAN AYAR         ***********
//**********************************************************************************

#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{

	int sutun;
	int satir;

	cout << " satir sayisi giriniz:(Lutfen satir sayisini 5 ile 15 arasinda giriniz.) " << endl;
	cin >> satir;

	while (satir < 5 || satir > 15)  //girilen satýr sayýsýný 5 ile 15 arasýnda girilip girilmediðini kontrol edip eðer koþul yanlýþsa kullanýcýdan sütun sayýsýný tekrar girdiren döngü
	{

		cout << "Satir sayisini hatali girdiniz!! Lutfen satir sayisini 5 ile 15 arasinda giriniz." << endl;
		cin >> satir;

	}

	cout << "Sutun sayisini giriniz.(Lutfen sutun sayisini 5 ile 40 arasinda giriniz)" << endl;
	cin >> sutun;

	while (sutun < 5 || sutun> 40)  //girilen sütun sayýsýný 5 ile 40 arasýnda girilip girilmediðini kontrol edip eðer koþul yanlýþsa kullanýcýdan sütun sayýsýný tekrar girdiren döngü
	{

		cout << "Sutun sayisini hatali girdiniz!! Lutfen sutun sayisini 5 ile 40 arasinda giriniz." << endl;
		cin >> sutun;

	}

	while (satir * 2 != sutun) //sütun sayýsýnýn satýr sayýsýnýn 2 katý olup olmadýðýný kontrol eden ve kullanýcýdan deðerleri tekrar girdirip o deðerlerinde doðru koþullar içinde yazdýp yazmadýðýný kontrol eden döngü 
	{

		cout << "Sutun sayisi satir sayisinin iki kati olmalidir" << endl;

		cout << " Satir sayisi giriniz:(Satir sayisi 5 ile 15 arasinda olmalidir.) " << endl;

		cin >> satir;


		while (satir < 5 || satir > 15)   //girilen satýr sayýsýný 5 ile 15 arasýnda girilip girilmediðini kontrol edip eðer koþul yanlýþsa kullanýcýdan sütun sayýsýný tekrar girdiren döngü
		{

			cout << "Satir sayisini hatali girdiniz!! Lutfen satir sayisini 5 ile 15 arasinda giriniz." << endl;
			cin >> satir;

		}

		cout << "Sutun sayisini giriniz!! Lutfen sutun sayisini 5 ile 40 arasinda giriniz." << endl;
		cin >> sutun;

		while (sutun < 5 || sutun > 40)  //girilen sütun sayýsýný 5 ile 40 arasýnda girilip girilmediðini kontrol edip eðer koþul yanlýþsa kullanýcýdan sütun sayýsýný tekrar girdiren döngü
		{

			cout << "Sutun sayisini hatali girdiniz!! Lutfen sutun sayisini 5 ile 40 arasinda giriniz." << endl;
			cin >> sutun;

		}

	}


	//1. ve 2. þekilde örüntü , þeklin sol tarafýndan sað tarafýna doðru þekillendirilmiþtir.

	//1.þeklin örüntüsü bu döngüyle baþlar.

	for (int i = 0; i < sutun; i++)       //1.sekildeki karede üst taban kenar örüntüsünü hazýrlayan döngü
	{

		Sleep(30);
		cout << "*";

	}


	for (int j = sutun - 2; j > 1; j--)    //1. þeklin iç örüntüsünü hazýrlayan iç içe baðlý döngü (sütun sayýsý baz alýnarak kurulmuþtur)
	{

		if (j % 2 != 0)   // 1. þekilde (yýldýz-alt satýra geçme) örüntüsünü kurmak için yapýlan tek veya çift sayi kontrolü ile kurulan koþul( fora baðlý deðiþken deðerinde azalarak örüntüsel ilerleyen tek sayilarda al satýra geçer , çift sayýlarda yýldýzlarla (*) oluþacak örüntü komutunu baþlatýr)
		{

			Sleep(30);
			cout << "*";

			for (int k = ((j + 3) / 2) - 3; k > 0; k--)   //1.þekilde karede sol taraftaki dik üçgensel bölgedenin boþluk(iç) ve kenar(hiptenüs) örüntüsünü iç içe for döngüsüne baðlý olarak hazýrlayan döngü
			{

				cout << " ";

			}

			Sleep(30);
			cout << "*";

			for (int l = sutun-1 - j; l > 0; l--)   // 1. þekilde kare içindeki ikizkenar üçgensel bölgenin boþluk(iç) ve kenar(sað) örüntüsünü hazýrlayan iç içe for döngüsüne baðlý döngü
			{
				cout << " ";

			}
			Sleep(30);
			cout << "*";

			for (int k = ((j + 3) / 2) - 3; k > 0; k--)  //1.þekilde karedeki sað taraftaki dik üçgensel bölgenin boþluk(iç) ve kenar(hipotenüs) örüntüsünü hazýrlayan döngü
			{

				cout << " ";

			}
			Sleep(30);
			cout << "*";
		}

		else     // 1. þekilde (yýldýz-alt satýra geçme) örüntüsünü kurmak için yapýlan koþul ( fora baðlý deðiþken deðerinde azalarak örüntüsel ilerleyen tek sayilarda al satýra geçer , çift sayýlarda yýldýzlarla (*) oluþacak örüntü komutunu baþlatýr)
		{
			cout << endl;
		}

	}



	for (int i = 0; i < sutun; i++)   //1.sekildeki karede alt taban kenar örüntüsünü hazýrlayan döngü (sütun sayýsý baz alýnarak kurulmuþtur)
	{
		Sleep(30);
		cout << "*";

	}

	cout << endl << endl;



	//2. þeklin örüntüsü bu dögüyle baþlar

	for (int i = 0; i < sutun; i++)  //2.sekildeki karede üst kenar örüntüsünü hazýrlayan döngü (sütun sayýsý baz alýnarak kurulmuþtur)
	{
		Sleep(30);
		cout << "*";

	}

	for (int j = 2; j < sutun - 2; j++) //2. þeklin iç örüntüsünü hazýrlayan iç içe baðlý döngü (sütun sayýsý baz alýnarak kurulmuþtur)
	{

		if (j % 2 != 0)     // 2. þekilde (yýldýz-alt satýra geçme) örüntüsünü kurmak için yapýlan tek veya çift sayi kontrolü ile kurulan koþul ( fora baðlý deðiþken deðerinde artarak örüntüsel ilerleyen tek sayilarda al satýra geçer , çift sayýlarda yýldýzlarla (*) oluþacak örüntü komutunu baþlatýr)
		{

			Sleep(30);
			cout << "*";

			for (int k = 0; k < ((j + 3) / 2) - 3; k++)    //2.þekilde karedeki sol taraftaki dik üçgensel bölgede boþluk(iç) ve kenar(hipotenüs) örüntüsünü hazýrlayan döngü
			{

				cout << " ";

			}

			Sleep(30);
			cout << "*";

			for (int l = 0; l < sutun - 1 - j; l++)    // 2. þekilde kare içindeki ikizkenar üçgensel bölgenin boþluk(iç) ve kenar(sað) örüntüsünü hazýrlayan döngü(sütün sayýsý baz alýnarak kurulmuþtur)
			{
				cout << " ";

			}

			Sleep(30);
			cout << "*";

			for (int k = 0; k < ((j + 3) / 2) - 3; k++)  //2.þekilde karedeki sað taraftaki dik üçgensel bölgenin boþluk(iç) ve kenar(hipotesnüs) örüntüsünü hazýrlayan döngü
			{

				cout << " ";

			}
			Sleep(30);

			cout << "*";
		}

		else      //2. þekilde (yýldýz-alt satýra geçme) örüntüsünü kurmak için yapýlan koþul ( fora baðlý deðiþken deðerinde artarak örüntüsel ilerleyen tek sayilarda al satýra geçer , çift sayýlarda yýldýzlarla (*) oluþacak örüntü komutunu baþlatýr)
		{
			cout << endl;
		}

	}

	cout << endl;

	for (int i = 0; i < sutun; i++)   // 2. þekildeki karesel bölgenin alt taban kenar örüntüsünü hazýrlayan sütün baz alýnarak kurulmuþ döngü
	{
		Sleep(30);
		cout << "*";

	}

	cout << endl<<endl;
	system("pause");

}