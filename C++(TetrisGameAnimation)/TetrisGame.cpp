//**********************************************************************************
// ***********           PROGRAMLAMAYA G�R�� �DEV 3                      ***********
//************           AD:    �MER FARUK G�ZEL                         ***********
//************           NUMARA:  G191210068                             ***********
//************           SINIF: 2.��retim C grubu                        ***********
//************           ��RET�M G�REVL�S�: DR.O�RT.�YES� G�L�ZAR ��T    ***********
//************           ��RET�M G�REVL�S�: AR�.G�R. KAYHAN AYAR         ***********
//**********************************************************************************

#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void renkVer(int n)// karakterlere renk ekler
{
	HANDLE renkVer;

	renkVer = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(renkVer, n);
}


void koordinat(int x, int y) // koordinatlar� kullanmak i�in yaz�lan fonksiyon
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void kursorgizle()  // kursor gizlemek i�in kullan�lan fonksiyon
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
struct sahne
{
	int		genislik;
	int		yukseklik;
	char	karakter;
};
sahne s;     // Sahne yap�s�n� kullanmak i�in olu�turulan 's' nesnesi

struct LSekli
{
	int	x;
	int	y;
	char karakterL;
	int boyut;
};

LSekli L;   // LSekil yap�s�n� kullanmak i�in olu�turulan 'L' nesnesi

sahne sahneOlustur(sahne)   // Sahne olu�turmak i�in kullan�lan fonksiyon
{

	int rastgelesayi = rand() % 3;
	int genislikDizi[3] = { 30,40,50 };
	s.genislik = genislikDizi[rastgelesayi];
	s.yukseklik = rand() % 11 + 20;
	int rastgeleKarakter = rand() % 5;
	char karakterDizi[5] = { '*','#','$','+','@' };
	s.karakter = karakterDizi[rastgeleKarakter];
	return s;
}
void sahneCiz(sahne) // Olu�turulan sahneyi �izdirmek i�in kullan�lan fonksiyon
{
	for (int i = 0; i < s.yukseklik; i++)  // �izilen sahnenin sol k�sm�n� haz�rlayan d�ng�
	{
		koordinat(0, i);
		cout << s.karakter;
	}
	for (int j = 0; j < s.genislik; j++)   //�izilen sahnenin tavan k�sm�n� haz�rlayan d�ng�
	{
		koordinat(j, 0);
		cout << s.karakter;
	}
	for (int k = 0; k < s.yukseklik; k++)  //�izilen sahnenin sa� k�sm�n� haz�rlayan d�ng�
	{
		koordinat(s.genislik - 1, k);
		cout << s.karakter;
	}
	for (int l = 0; l < s.genislik; l++)  //�izilen sahnenin taban k�sm�n� haz�rlayan d�ng� 
	{
		koordinat(l, s.yukseklik - 1);
		cout << s.karakter;
	}


}
LSekli LSekliOlustur(LSekli)  // L �eklini olu�turmak i�in kullan�lan fonksiyon
{


	int rastgelesayiL = rand() % 21 + 5;
	L.x = rastgelesayiL;
	L.y = 3;
	int rastgeleKarakterL = rand() % 5;
	char LkarakterDizi[5] = { '*','#','$','+','@' };
	L.karakterL = LkarakterDizi[rastgeleKarakterL];
	int rastgeleBoyut = rand() % 7 + 1;
	L.boyut = rastgeleBoyut;
	return L;

}
void LSekliCiz(LSekli) // Olu�turulan L �eklini �izdirmek i�in kullan�lan fonksiyon
{
	renkVer(rand() % 15);
	for (int i = 0; i < L.boyut; i++)            //L seklinin tavan �r�nt�s�
	{
		koordinat(L.x + i, L.y);
		cout << L.karakterL;
	}
	for (int i = 0; i < L.boyut + 2; i++)          //L seklinin sa� k�sm�n�n �st b�l�m�n�n �r�nt�s�
	{
		koordinat(L.x + L.boyut, L.y + i);

		cout << L.karakterL;
	}

	for (int i = 0; i < L.boyut + 2; i++)  //L seklinin orta k�s�m �r�nt�s�
	{

		koordinat(L.boyut + L.x + i, L.boyut + L.y + 1);
		cout << L.karakterL;
	}

	for (int i = 0; i < L.boyut; i++)            //L seklinin sa� k�sm�n�n alt b�l�m�n�n �r�nt�s�
	{

		koordinat(2 * L.boyut + 1 + L.x, L.boyut + L.y + i + 2);
		cout << L.karakterL;
	}
	for (int i = 0; i < (2 * L.boyut) + 2; i++)            //L seklinin taban �r�nt�s�
	{
		koordinat(L.x + i, 2 * L.boyut + L.y + 2);
		cout << L.karakterL;
	}
	for (int i = 0; i < (2 * L.boyut) + 3; i++)            //L seklinin sol k�s�m �r�nt�s�
	{
		koordinat(L.x, L.y + i);
		cout << L.karakterL;
	}


}

LSekli LsekliAsagi�ndir(LSekli) // L �eklinin a�a�� inmesini sa�layan fonksiyon
{

	L.y = L.y++;

	return L;
}



int main()
{


	srand(time(NULL));
	sahneOlustur(s);

	while (true) // Yaz�lan fonksiyonlar�n L �ekli sahnenin taban�na de�ince L �eklinin de�erlerinin yeniden girilmesini i�in ko�ulu sa�layan d�ng�
	{
		srand(time(NULL));
		LSekliOlustur(L);

		while (L.y + (2 * L.boyut) + 3 != s.yukseklik)// Yaz�lan fonksiyonlar�n s�rekli olarak tekrar tekrar �al��mas�n� sa�layan ko�ul(L �ekli sahnenin taban�na de�ene kadar) 
		{

			system("cls");
			kursorgizle();
			sahneCiz(s);
			LSekliCiz(L);
			LsekliAsagi�ndir(L);
			Sleep(100);
		}

	}


	system("pause");
}