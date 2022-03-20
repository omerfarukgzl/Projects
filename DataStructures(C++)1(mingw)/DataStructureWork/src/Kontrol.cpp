/**
* @file			Veri yapilari 1. odev
* @description	Txt deki sayıları düğüme atma ve ortanca değeri en büyük olan ile en küçüğü çaprazlama 
* @course		2A
* @date			29/11/2020
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#include "Kontrol.h"
Kontrol::Kontrol()
{
	listsayisi=ListSayisi();//olusacak olan list sayisi satir sayisi kadar olussun
	orta=new listeler*[listsayisi];//orta degerleri gosterecek linked list
	temp=new listeler*[listsayisi];//orta degerlerin nextlerinde gezecek linked list
	temp2=new listeler*[listsayisi];//orta degerlerin prevlerinde gezecek linked list
	for (int i = 0; i < listsayisi; i++)
	{
		orta[i] = new listeler[listsayisi];
		temp[i] = new listeler[listsayisi];
		temp2[i] = new listeler[listsayisi];
		orta[i]=NULL;
		temp[i]=NULL;
		temp2[i]=NULL;
	}
}
void Kontrol::NodeEkle(int **x, int listNum, int veriSayi)
{
	for(int i=0;i<veriSayi;i++)//linked liste eklenecek veri sayisi kadar donen dongu
	{
		listeler * dugum;//eklenecek yeni dugum
	    dugum=new listeler;
	    dugum->data=x[listNum][i];//eklenecek dugumun verisi 
		if(i==0)//orta aleman eklenmesi
		{
		 orta[listNum]=dugum;
		 orta[listNum]->next=orta[listNum];
	     orta[listNum]->prev=orta[listNum];
		}
		if(i<=(veriSayi/2))//gonderilen veri sayisi ile birlikte orta elemandan sonra sol tarafa ekleme yapması icin hazırlanan kosul
		{
			temp[listNum]=orta[listNum];
			temp[listNum]=temp[listNum]->next;
			dugum->next=temp[listNum];
			dugum->prev=orta[listNum];
			temp[listNum]->prev=dugum;
			orta[listNum]->next=dugum;
		}
		else//orta elemandan sonra sag tarafa ekleme yapması icin hazırlanan kosul 
		{
			temp[listNum] =orta[listNum];
	        temp2[listNum]=orta[listNum];
			for(int j=0;j<(veriSayi/2);j++)//sag tarfdaki son elmana ulasmasi icin hazırlanan dongu
			{
				temp2[listNum]=temp2[listNum]->prev;
			}
	        while(temp[listNum]->next!=temp2[listNum])//linked listde sag tarafdaki son elemana ve sol tarftaki son elemana ulasması icin hazırlanan dongu
	        {
		     temp[listNum]=temp[listNum]->next;
	        }
			dugum->next=temp2[listNum];
			temp[listNum]->next=dugum;
			dugum->prev=temp[listNum];
			temp2[listNum]->prev=dugum;
		}
	}
}
void Kontrol::Bastir(int listNum)//linked list içeriği için yazdırma fonksiyonu 
{
   temp[listNum] =orta[listNum];
   temp2[listNum]=orta[listNum];
    while(temp[listNum]->next!=temp2[listNum])//linked listde sag tarafdaki son elemana ve sol tarftaki son elemana ulasması icin hazırlanan dongu
    {
	  temp[listNum]=temp[listNum]->next;
	  temp2[listNum]=temp2[listNum]->prev;
    }
	while(temp2[listNum]->next!=temp[listNum]->next)//orta elemana gore sol son elemandan baslayarak sag son elemana giden dongu
	{
	 cout<<"-> "<<temp2[listNum]->data;
	 temp2[listNum]=temp2[listNum]->next;
	}
	cout<<"-> "<<temp2[listNum]->data;
}
int Kontrol::ListSayisi()//olusacak list sayısını (satir sayisi) getiren fonksiyon
{
	int listSayisi=0;
	string satir;
	ifstream dosya1;
	dosya1.open("sayilar.txt", ios::in);
	while(getline(dosya1,satir))
	{	
		listSayisi++;
	}
	dosya1.close();
	return listSayisi;
} 
void Kontrol::DosyaIslemleri()//satir satir okunan txt deki her satir icin ayrı bir linked list olusmasi icin 2 kez okunuri. ilk okunus satiri ikinci okunus sayilari okur
{
	int sayacVeri=0;
	int satirSayac=0;
	int temp=satirSayac;
	string satir;
	int sayi;
	ifstream dosya1;
	dosya1.open("sayilar.txt", ios::in);
	ifstream dosya2;
	dosya2.open("sayilar.txt", ios::in);
	while(getline(dosya1,satir)) //Dosyanin sonuna kadar okuyup rastgele bir isim getiren döngü
	{
		for(int i=0;i<satir.length();i++)//satirdaki veri sayisini bulmak icin hazırlanan dongu
		{
		    if(satir[i]==' ')//bosluk kontrolu yaparak verileri ayiriyoruz 
			{
		     sayacVeri++;	
			}	   
		}
		sayacVeri++;
		temp++;
		int **sayiDizi= new int *[sayacVeri];// ekle metoduna paramtere olarak gönderilecek olan 
        for(int i = satirSayac; i <temp; i++)
		{
          sayiDizi[i] = new int[sayacVeri];
		}
		for(int i=0;i<sayacVeri;i++)//satirdaki veri sayisi kadar donup sırayla okunan verileri SayiDizi dizisine atan dongu
		{
		 dosya2>>sayi;
		 sayiDizi[satirSayac][i]=sayi;
		}
		 NodeEkle(sayiDizi,satirSayac,sayacVeri);
		 //Bastir(satirSayac);
		 //cout<<endl;
		 sayacVeri=0;
		 satirSayac++;
	}
	dosya1.close();
	dosya2.close();
}
void Kontrol::Caprazlama()//bu fonksiyonda listlerin ortanca degerlerinden kucuk ve buyuk olani secilir ve caprazlama yapilir
{
	int kucukIndex;
	int buyukIndex;
	int tut;
	int dizi[listsayisi];//list sayisi kadar olusturulan array
	struct listeler ** iter = new listeler*[listsayisi];//buyuk ve kucuk ortanca degerlerin nextlerinde gezen linked list
	struct listeler ** iter2 = new listeler*[listsayisi];//buyuk ve kucuk ortanca degerlerin prevlerinde gezen linked list
	struct listeler ** temp3 = new listeler*[listsayisi];//ortanca degeri buyuk olan linked listde baglantı kopmadan once ortanın nextini ve previni tutan linked list
	for (int i = 0; i < listsayisi; i++)//dynamic array of linked list olusumu
	{
		iter[i] = new listeler[listsayisi];
		iter2[i] = new listeler[listsayisi];
		temp3[i] = new listeler[listsayisi];
		iter[i]=NULL;
		iter2[i]=NULL;
		temp3[i]=NULL;
	}
	for(int k=0;k<listsayisi;k++)//tanimlanan diziye listenin ortanca degerleri atanır
	{
	  dizi[k]=orta[k]->data;
	}
	for(int i=0;i<listsayisi-1;i++)//listelerin ortanca degerleri buyukten kucukluge gore sıralanır
	{
		for(int j=0;j<listsayisi-1;j++) 
		{ 
		  if(dizi[j]>dizi[j+1]) 
		  { 
		    tut=dizi[j]; 
		    dizi[j]=dizi[j+1]; 
		    dizi[j+1]=tut; 
		  } 
		}
	}
	for(int m=0;m<listsayisi;m++)//siralanan ortanca degerlerden kucuk ve buyuk olanlar hangi indexli listede oldugunu buldurma 
	{
		if(orta[m]->data==dizi[0])//dizi[0]==orta degerlerin en kucugu
		{
			kucukIndex=m;//ortanca degeri kucuk olan list in indexi
		}
		if(orta[m]->data==dizi[listsayisi-1])//dizi[listsayisi]==orta degerlerin en buyugu
		{
			buyukIndex=m;//ortanca degeri buyuk olan list in indexi
		}
	}
	  temp[buyukIndex] =orta[buyukIndex];//orta degeri buyuk olan linked listin ortanca degerinden itibaren nextinde gezecek olan linked list 
	  temp2[buyukIndex]=orta[buyukIndex];//orta degeri buyuk olan linked listin ortanca degerinden itibaren previnde gezecek olan linked list 
	  iter[buyukIndex]=orta[buyukIndex];//orta degeri buyuk olan linked listin ortanca degerinden itibaren nextinde gezecek olan linked list 
	  iter2[buyukIndex]=orta[buyukIndex];//orta degeri buyuk olan linked listin ortanca degerinden itibaren previnde gezecek olan linked list 
	  
	  temp[kucukIndex] =orta[kucukIndex];//orta degeri kucuk olan linked listin ortanca degerinden itibaren nextinde gezecek olan linked list 
	  temp2[kucukIndex]=orta[kucukIndex];//orta degeri kucuk olan linked listin ortanca degerinden itibaren previnde gezecek olan linked list 
	  iter[kucukIndex]=orta[kucukIndex];//orta degeri kucuk olan linked listin ortanca degerinden itibaren nextinde gezecek olan linked list 
	  iter2[kucukIndex]=orta[kucukIndex];//orta degeri kucuk olan linked listin ortanca degerinden itibaren previnde gezecek olan linked list 
	  
	  temp3[0]=orta[buyukIndex]->next;//ortanca degeri buyuk olan linked listin nextini tutan linked list
	  temp3[1]=orta[buyukIndex]->prev;//ortanca degeri buyuk olan linked listin previni tutan linked list
	  
	while(temp[buyukIndex]->next!=temp2[buyukIndex])//ortanca degeri buyuk olan linked listin sol son ve sag son elemanlarını bulduran dongu
	{
		temp[buyukIndex]=temp[buyukIndex]->next;
		temp2[buyukIndex]=temp2[buyukIndex]->prev;
	}
	while(temp[kucukIndex]->next!=temp2[kucukIndex])//ortanca degeri kucuk olan linked listin sol son ve sag son elemanlarını bulduruan dongu
	{
		temp[kucukIndex]=temp[kucukIndex]->next;
		temp2[kucukIndex]=temp2[kucukIndex]->prev;
	}
	iter[buyukIndex]->next=orta[kucukIndex]->prev;//caprazlama islemi baslarken ortanca degerin nextini kucuk ortanca degerin previne esitleme
	iter2[buyukIndex]->prev=orta[kucukIndex]->next;//caprazlama islemi baslarken ortanca degerin previni kucuk ortanca degerin nextine esitleme
	
	iter[kucukIndex]->next=temp3[1];//caprazlama islemi baslarken ortanca degerin nextini tutma
	iter2[kucukIndex]->prev=temp3[0];//caprazlama islemi baslarken ortanca degerin previni tutma
	
	while(iter[buyukIndex]->next!=temp2[kucukIndex])//ortanca degeri buyuk olan linked listde sol son ve sag son elamana kadar donmesini saglayan dongu
	{
	iter[buyukIndex]->next->next=iter[buyukIndex]->next->prev;
	iter[buyukIndex]->next->prev=iter[buyukIndex];
	iter[buyukIndex]=iter[buyukIndex]->next;
	
	iter2[buyukIndex]->prev->prev=iter2[buyukIndex]->prev->next;
	iter2[buyukIndex]->prev->next=iter2[buyukIndex];
	iter2[buyukIndex]=iter2[buyukIndex]->prev;
	}
	//son elemanların next ve prevlerinin degisimi
	iter[buyukIndex]->next->next=temp[kucukIndex];
	iter[buyukIndex]->next->prev=iter[buyukIndex];
	iter2[buyukIndex]->prev->prev=temp2[kucukIndex];
	iter2[buyukIndex]->prev->next=iter2[buyukIndex];

	while(iter[kucukIndex]->next!=temp2[buyukIndex])//ortanca degeri buyuk olan linked listde sol son ve sag son elamana kadar donmesini saglayan dongu
	{
	iter[kucukIndex]->next->next=iter[kucukIndex]->next->prev;
	iter[kucukIndex]->next->prev=iter[kucukIndex];
	iter[kucukIndex]=iter[kucukIndex]->next;
	
	iter2[kucukIndex]->prev->prev=iter2[kucukIndex]->prev->next;
	iter2[kucukIndex]->prev->next=iter2[kucukIndex];
	iter2[kucukIndex]=iter2[kucukIndex]->prev;
	
	}
	//son elemanların next ve prevlerinin degisimi
	iter[kucukIndex]->next->next=temp[buyukIndex];
	iter[kucukIndex]->next->prev=iter[kucukIndex];
	iter2[kucukIndex]->prev->prev=temp2[buyukIndex];
	iter2[kucukIndex]->prev->next=iter2[kucukIndex];
    cout<<"En Buyuk Liste Deger Orta Dugum Adres: "<<orta[buyukIndex]<<endl; 
    cout<<"EN BUYUK LISTE DEGERLER:"<<endl; 
	Bastir(buyukIndex);
	cout<<endl<<endl<<"En Kucuk Liste Deger Orta Dugum Adres: "<<orta[kucukIndex]<<endl; 
	cout<<"EN KUCUK LISTE DEGERLER:"<<endl; 
	Bastir(kucukIndex);
}