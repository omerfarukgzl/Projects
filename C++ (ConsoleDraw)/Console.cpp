//**********************************************************************************
// ***********           PROGRAMLAMAYA G�R�� �DEV 1                      ***********
//************           AD:    �MER FARUK G�ZEL                         ***********
//************           NUMARA:  G191210068                             ***********
//************           SINIF: 2.��retim C grubu                        ***********
//************           ��RET�M G�REVL�S�: DR.O�RT.�YES� G�L�ZAR ��T    ***********
//************           ��RET�M G�REVL�S�: AR�.G�R. KAYHAN AYAR         ***********
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

	while (satir < 5 || satir > 15)  //girilen sat�r say�s�n� 5 ile 15 aras�nda girilip girilmedi�ini kontrol edip e�er ko�ul yanl��sa kullan�c�dan s�tun say�s�n� tekrar girdiren d�ng�
	{

		cout << "Satir sayisini hatali girdiniz!! Lutfen satir sayisini 5 ile 15 arasinda giriniz." << endl;
		cin >> satir;

	}

	cout << "Sutun sayisini giriniz.(Lutfen sutun sayisini 5 ile 40 arasinda giriniz)" << endl;
	cin >> sutun;

	while (sutun < 5 || sutun> 40)  //girilen s�tun say�s�n� 5 ile 40 aras�nda girilip girilmedi�ini kontrol edip e�er ko�ul yanl��sa kullan�c�dan s�tun say�s�n� tekrar girdiren d�ng�
	{

		cout << "Sutun sayisini hatali girdiniz!! Lutfen sutun sayisini 5 ile 40 arasinda giriniz." << endl;
		cin >> sutun;

	}

	while (satir * 2 != sutun) //s�tun say�s�n�n sat�r say�s�n�n 2 kat� olup olmad���n� kontrol eden ve kullan�c�dan de�erleri tekrar girdirip o de�erlerinde do�ru ko�ullar i�inde yazd�p yazmad���n� kontrol eden d�ng� 
	{

		cout << "Sutun sayisi satir sayisinin iki kati olmalidir" << endl;

		cout << " Satir sayisi giriniz:(Satir sayisi 5 ile 15 arasinda olmalidir.) " << endl;

		cin >> satir;


		while (satir < 5 || satir > 15)   //girilen sat�r say�s�n� 5 ile 15 aras�nda girilip girilmedi�ini kontrol edip e�er ko�ul yanl��sa kullan�c�dan s�tun say�s�n� tekrar girdiren d�ng�
		{

			cout << "Satir sayisini hatali girdiniz!! Lutfen satir sayisini 5 ile 15 arasinda giriniz." << endl;
			cin >> satir;

		}

		cout << "Sutun sayisini giriniz!! Lutfen sutun sayisini 5 ile 40 arasinda giriniz." << endl;
		cin >> sutun;

		while (sutun < 5 || sutun > 40)  //girilen s�tun say�s�n� 5 ile 40 aras�nda girilip girilmedi�ini kontrol edip e�er ko�ul yanl��sa kullan�c�dan s�tun say�s�n� tekrar girdiren d�ng�
		{

			cout << "Sutun sayisini hatali girdiniz!! Lutfen sutun sayisini 5 ile 40 arasinda giriniz." << endl;
			cin >> sutun;

		}

	}


	//1. ve 2. �ekilde �r�nt� , �eklin sol taraf�ndan sa� taraf�na do�ru �ekillendirilmi�tir.

	//1.�eklin �r�nt�s� bu d�ng�yle ba�lar.

	for (int i = 0; i < sutun; i++)       //1.sekildeki karede �st taban kenar �r�nt�s�n� haz�rlayan d�ng�
	{

		Sleep(30);
		cout << "*";

	}


	for (int j = sutun - 2; j > 1; j--)    //1. �eklin i� �r�nt�s�n� haz�rlayan i� i�e ba�l� d�ng� (s�tun say�s� baz al�narak kurulmu�tur)
	{

		if (j % 2 != 0)   // 1. �ekilde (y�ld�z-alt sat�ra ge�me) �r�nt�s�n� kurmak i�in yap�lan tek veya �ift sayi kontrol� ile kurulan ko�ul( fora ba�l� de�i�ken de�erinde azalarak �r�nt�sel ilerleyen tek sayilarda al sat�ra ge�er , �ift say�larda y�ld�zlarla (*) olu�acak �r�nt� komutunu ba�lat�r)
		{

			Sleep(30);
			cout << "*";

			for (int k = ((j + 3) / 2) - 3; k > 0; k--)   //1.�ekilde karede sol taraftaki dik ��gensel b�lgedenin bo�luk(i�) ve kenar(hipten�s) �r�nt�s�n� i� i�e for d�ng�s�ne ba�l� olarak haz�rlayan d�ng�
			{

				cout << " ";

			}

			Sleep(30);
			cout << "*";

			for (int l = sutun-1 - j; l > 0; l--)   // 1. �ekilde kare i�indeki ikizkenar ��gensel b�lgenin bo�luk(i�) ve kenar(sa�) �r�nt�s�n� haz�rlayan i� i�e for d�ng�s�ne ba�l� d�ng�
			{
				cout << " ";

			}
			Sleep(30);
			cout << "*";

			for (int k = ((j + 3) / 2) - 3; k > 0; k--)  //1.�ekilde karedeki sa� taraftaki dik ��gensel b�lgenin bo�luk(i�) ve kenar(hipoten�s) �r�nt�s�n� haz�rlayan d�ng�
			{

				cout << " ";

			}
			Sleep(30);
			cout << "*";
		}

		else     // 1. �ekilde (y�ld�z-alt sat�ra ge�me) �r�nt�s�n� kurmak i�in yap�lan ko�ul ( fora ba�l� de�i�ken de�erinde azalarak �r�nt�sel ilerleyen tek sayilarda al sat�ra ge�er , �ift say�larda y�ld�zlarla (*) olu�acak �r�nt� komutunu ba�lat�r)
		{
			cout << endl;
		}

	}



	for (int i = 0; i < sutun; i++)   //1.sekildeki karede alt taban kenar �r�nt�s�n� haz�rlayan d�ng� (s�tun say�s� baz al�narak kurulmu�tur)
	{
		Sleep(30);
		cout << "*";

	}

	cout << endl << endl;



	//2. �eklin �r�nt�s� bu d�g�yle ba�lar

	for (int i = 0; i < sutun; i++)  //2.sekildeki karede �st kenar �r�nt�s�n� haz�rlayan d�ng� (s�tun say�s� baz al�narak kurulmu�tur)
	{
		Sleep(30);
		cout << "*";

	}

	for (int j = 2; j < sutun - 2; j++) //2. �eklin i� �r�nt�s�n� haz�rlayan i� i�e ba�l� d�ng� (s�tun say�s� baz al�narak kurulmu�tur)
	{

		if (j % 2 != 0)     // 2. �ekilde (y�ld�z-alt sat�ra ge�me) �r�nt�s�n� kurmak i�in yap�lan tek veya �ift sayi kontrol� ile kurulan ko�ul ( fora ba�l� de�i�ken de�erinde artarak �r�nt�sel ilerleyen tek sayilarda al sat�ra ge�er , �ift say�larda y�ld�zlarla (*) olu�acak �r�nt� komutunu ba�lat�r)
		{

			Sleep(30);
			cout << "*";

			for (int k = 0; k < ((j + 3) / 2) - 3; k++)    //2.�ekilde karedeki sol taraftaki dik ��gensel b�lgede bo�luk(i�) ve kenar(hipoten�s) �r�nt�s�n� haz�rlayan d�ng�
			{

				cout << " ";

			}

			Sleep(30);
			cout << "*";

			for (int l = 0; l < sutun - 1 - j; l++)    // 2. �ekilde kare i�indeki ikizkenar ��gensel b�lgenin bo�luk(i�) ve kenar(sa�) �r�nt�s�n� haz�rlayan d�ng�(s�t�n say�s� baz al�narak kurulmu�tur)
			{
				cout << " ";

			}

			Sleep(30);
			cout << "*";

			for (int k = 0; k < ((j + 3) / 2) - 3; k++)  //2.�ekilde karedeki sa� taraftaki dik ��gensel b�lgenin bo�luk(i�) ve kenar(hipotesn�s) �r�nt�s�n� haz�rlayan d�ng�
			{

				cout << " ";

			}
			Sleep(30);

			cout << "*";
		}

		else      //2. �ekilde (y�ld�z-alt sat�ra ge�me) �r�nt�s�n� kurmak i�in yap�lan ko�ul ( fora ba�l� de�i�ken de�erinde artarak �r�nt�sel ilerleyen tek sayilarda al sat�ra ge�er , �ift say�larda y�ld�zlarla (*) olu�acak �r�nt� komutunu ba�lat�r)
		{
			cout << endl;
		}

	}

	cout << endl;

	for (int i = 0; i < sutun; i++)   // 2. �ekildeki karesel b�lgenin alt taban kenar �r�nt�s�n� haz�rlayan s�t�n baz al�narak kurulmu� d�ng�
	{
		Sleep(30);
		cout << "*";

	}

	cout << endl<<endl;
	system("pause");

}