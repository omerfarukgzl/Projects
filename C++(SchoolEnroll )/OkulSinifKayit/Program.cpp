#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream> 
#include<windows.h>
#include<time.h>
#include"DosyaYonetimi.h"
#include "Ogrenci.h"
#include"Okul.h"
#include "Sinif.h"
#include "Program.h"

using namespace std;

void koordinat2(int x, int y) // �mleci belirtilen koordinata g�t�ren fonksiyon.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Program::calistir()
{
	//kullan�c� men�s� ve t�m program�n �al��mas�n� sa�layan ana fonksiyon
	int secilenOzellik;
	bool cikis = true;

	while (cikis)//6. se�enek se�ilene kadar d�ner
	{
		system("cls");//ekran temizlenir ve yeni kay�tlar yeniden yazd�r�l�r
		okul.yazdir();
		cout << endl << endl;
		koordinat2(0, 45);
		cout << "1. Ogrenci Ekle" << endl;
		cout << "2. Sinif Ekle" << endl;
		cout << "3. Ogrenci Degistir" << endl;
		cout << "4. Ogrenci Sil" << endl;
		cout << "5. Sinif Sil" << endl;
		cout << "6. Cikis" << endl << endl;

		cin >> secilenOzellik;
		switch (secilenOzellik)
		{
		case 1:
			okul.ogrenciEkle();
			break;
		case 2:
			okul.sinifEkle();
			break;
		case 3:
			okul.ogrenciDegistir();
			break;
		case 4:
			okul.ogrenciSil();
			break;
		case 5:
			okul.sinifSil();
			break;
		case 6:
			cikis = false;
			break;
		default:
			break;
		}
	}
}

