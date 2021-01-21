//**********************************************************************************
// ***********           PROGRAMLAMAYA GÝRÝÞ ÖDEV 3                      ***********
//************           AD:    ÖMER FARUK GÜZEL                         ***********
//************           NUMARA:  G191210068                             ***********
//************           SINIF: 2.öðretim C grubu                        ***********
//************           ÖÐRETÝM GÖREVLÝSÝ: DR.OÐRT.ÜYESÝ GÜLÝZAR ÇÝT    ***********
//************           ÖÐRETÝM GÖREVLÝSÝ: ARÞ.GÖR. KAYHAN AYAR         ***********
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


void koordinat(int x, int y) // koordinatlarý kullanmak için yazýlan fonksiyon
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void kursorgizle()  // kursor gizlemek için kullanýlan fonksiyon
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
sahne s;     // Sahne yapýsýný kullanmak için oluþturulan 's' nesnesi

struct LSekli
{
	int	x;
	int	y;
	char karakterL;
	int boyut;
};

LSekli L;   // LSekil yapýsýný kullanmak için oluþturulan 'L' nesnesi

sahne sahneOlustur(sahne)   // Sahne oluþturmak için kullanýlan fonksiyon
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
void sahneCiz(sahne) // Oluþturulan sahneyi çizdirmek için kullanýlan fonksiyon
{
	for (int i = 0; i < s.yukseklik; i++)  // çizilen sahnenin sol kýsmýný hazýrlayan döngü
	{
		koordinat(0, i);
		cout << s.karakter;
	}
	for (int j = 0; j < s.genislik; j++)   //Çizilen sahnenin tavan kýsmýný hazýrlayan döngü
	{
		koordinat(j, 0);
		cout << s.karakter;
	}
	for (int k = 0; k < s.yukseklik; k++)  //Çizilen sahnenin sað kýsmýný hazýrlayan döngü
	{
		koordinat(s.genislik - 1, k);
		cout << s.karakter;
	}
	for (int l = 0; l < s.genislik; l++)  //Çizilen sahnenin taban kýsmýný hazýrlayan döngü 
	{
		koordinat(l, s.yukseklik - 1);
		cout << s.karakter;
	}


}
LSekli LSekliOlustur(LSekli)  // L Þeklini oluþturmak için kullanýlan fonksiyon
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
void LSekliCiz(LSekli) // Oluþturulan L Þeklini çizdirmek için kullanýlan fonksiyon
{
	renkVer(rand() % 15);
	for (int i = 0; i < L.boyut; i++)            //L seklinin tavan örüntüsü
	{
		koordinat(L.x + i, L.y);
		cout << L.karakterL;
	}
	for (int i = 0; i < L.boyut + 2; i++)          //L seklinin sað kýsmýnýn üst bölümünün örüntüsü
	{
		koordinat(L.x + L.boyut, L.y + i);

		cout << L.karakterL;
	}

	for (int i = 0; i < L.boyut + 2; i++)  //L seklinin orta kýsým örüntüsü
	{

		koordinat(L.boyut + L.x + i, L.boyut + L.y + 1);
		cout << L.karakterL;
	}

	for (int i = 0; i < L.boyut; i++)            //L seklinin sað kýsmýnýn alt bölümünün örüntüsü
	{

		koordinat(2 * L.boyut + 1 + L.x, L.boyut + L.y + i + 2);
		cout << L.karakterL;
	}
	for (int i = 0; i < (2 * L.boyut) + 2; i++)            //L seklinin taban örüntüsü
	{
		koordinat(L.x + i, 2 * L.boyut + L.y + 2);
		cout << L.karakterL;
	}
	for (int i = 0; i < (2 * L.boyut) + 3; i++)            //L seklinin sol kýsým örüntüsü
	{
		koordinat(L.x, L.y + i);
		cout << L.karakterL;
	}


}

LSekli LsekliAsagiÝndir(LSekli) // L þeklinin aþaðý inmesini saðlayan fonksiyon
{

	L.y = L.y++;

	return L;
}



int main()
{


	srand(time(NULL));
	sahneOlustur(s);

	while (true) // Yazýlan fonksiyonlarýn L þekli sahnenin tabanýna deðince L þeklinin deðerlerinin yeniden girilmesini için koþulu saðlayan döngü
	{
		srand(time(NULL));
		LSekliOlustur(L);

		while (L.y + (2 * L.boyut) + 3 != s.yukseklik)// Yazýlan fonksiyonlarýn sürekli olarak tekrar tekrar çalýþmasýný saðlayan koþul(L Þekli sahnenin tabanýna deðene kadar) 
		{

			system("cls");
			kursorgizle();
			sahneCiz(s);
			LSekliCiz(L);
			LsekliAsagiÝndir(L);
			Sleep(100);
		}

	}


	system("pause");
}