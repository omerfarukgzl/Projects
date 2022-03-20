/**
* @file			Veri yapilari 2. odev
* @description	AVL Agaci
* @course		2A
* @date			27/12/2020
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Kontrol.h"
using namespace std;
Kontrol::Kontrol()
{
	listsayisi=ListSayisi();//olusacak olan avl ağaçarı sayisi satir sayisi kadar olussun
	avl_ic=new AVL*[listsayisi];//iç avl ağaçları
	avl_dis=new AVL*[listsayisi];//dış avl ağaçları
	for (int i = 0; i < listsayisi; i++)
	{
		avl_ic[i] = new AVL[listsayisi];
		avl_dis[i] = new AVL[listsayisi];
		avl_ic[i]=NULL;
		avl_dis[i]=NULL;
	}
}
int Kontrol::ListSayisi()//olusacak list sayısını (satir sayisi) getiren fonksiyon
{
	int listSayisi=0;
	string satir;
	ifstream dosya1;
	dosya1.open("Veriler.txt", ios::in);
	while(getline(dosya1,satir))
	{	
		listSayisi++;
	}
	dosya1.close();
	return listSayisi;
} 
int Kontrol::Yukseklik(AVL * node)  
{  
    if (node == NULL)  
        return 0;  
    return node->yukseklik;  
}  
int Kontrol::Max(int x, int y)  
{ 
if(x>y)
	return x;
else
	return y;
}  
AVL* Kontrol::SagDonus(AVL *a)  
{  
//denge şartı için sağa döndürme
//düğümlerin bağlantıkarını yedekleyerek yapılır
    AVL *b = a->sol;  
    AVL *c = b->sag;  
    b->sag = a;  
    a->sol = c;   
    a->yukseklik = Max(Yukseklik(a->sol),Yukseklik(a->sag)) + 1;  
    b->yukseklik = Max(Yukseklik(b->sol),Yukseklik(b->sag)) + 1;   
	delete c;
    return b;  
} 
AVL* Kontrol::SolDonus(AVL *b)   
{  
//denge şartı için sola döndürme
//düğümlerin bağlantıkarını yedekleyerek yapılır
    AVL *a = b->sag;  
    AVL *c = a->sol;    
    a->sol = b;  
    b->sag = c;  
    b->yukseklik = Max(Yukseklik(b->sol),Yukseklik(b->sag)) + 1;  
    a->yukseklik = Max(Yukseklik(a->sol),Yukseklik(a->sag)) + 1;  
	delete c;
    return a;  
}  
int Kontrol::Denge(AVL *Node)  
{  
    if (Node == NULL)  
        return 0;  
    return Yukseklik(Node->sol) - Yukseklik(Node->sag);  
}  
AVL* Kontrol::YeniNodeIc(int yil ,string adsoyad)
{
	//yeni iç avl oluşturma 
	AVL* dugum = new AVL(); 
   	 dugum->adSoyad = adsoyad;  
	 dugum->yilDeger = yil;  
     dugum->sol = NULL;  
     dugum->sag = NULL;
     dugum->yukseklik = 1;
	 return dugum; 
}
AVL* Kontrol::YeniNodeDis(int kisiSayi,string work,int sayac,int yil ,string adsoyad)
{
	//yeni dış avl oluşturma 
	AVL* dugum = new AVL(); 
   	 dugum->isYeri = work;  
	 dugum->kisiSayisi = kisiSayi;  
     dugum->sol = NULL;  
     dugum->sag = NULL;
	 dugum->baglanti = YeniNodeIc(yil,adsoyad);
     dugum->yukseklik = 1;
	 avl_dis[sayac]=dugum;
	 return dugum; 
}
AVL* Kontrol::NodeUpdate(AVL* node,AVL* node2)
{
	if(node==NULL)
	{
		return node2;
	}
	if (node2->kisiSayisi < node->kisiSayisi) //ebeveyn düğümün değeri çocuk düğümün değerinden küçükse 
	{
        node->sol = NodeUpdate(node->sol,node2);  
    }
    else if (node2->kisiSayisi > node->kisiSayisi)  //ebeveyn düğümün değeri çocuk düğümün değerinden büyükse 
	{
        node->sag = NodeUpdate(node->sag,node2); 
	}
    else //ebeveyn düğümün değeri çocuk düğümün değerine eşitse 
	{
       node->sol = NodeUpdate(node->sol,node2); 
	}
	 node->yukseklik = 1 + Max(Yukseklik(node->sol),Yukseklik(node->sag));	   
    int denge = Denge(node);  
	//avl dengesini oluşturma
    if (denge > 1 && node2->kisiSayisi < node->sol->kisiSayisi)  
        return SagDonus(node);  

    if (denge < -1 && node2->kisiSayisi > node->sag->kisiSayisi)  
        return SolDonus(node);  
  
    if (denge > 1 && node2->kisiSayisi > node->sol->kisiSayisi)  
    {  
        node->sol = SolDonus(node->sol);  
        return SagDonus(node);  
    }  
    if (denge < -1 && node2->kisiSayisi < node->sag->kisiSayisi)  
    {  
        node->sag = SagDonus(node->sag);  
        return SolDonus(node);  
    }
	return node;
}

AVL* Kontrol::AvlEkleDis(AVL* node, int kisiSayi,string work,int sayac,int yil ,string adsoyad)  
{ 
    if (node == NULL)  
	{
	 return YeniNodeDis(kisiSayi,work,sayac,yil , adsoyad );
	}	
    if (kisiSayi < node->kisiSayisi) //eklenecek değer ebeveyn düğümün değerinden küçükse  
        node->sol = AvlEkleDis(node->sol, kisiSayi,work,sayac,yil,adsoyad);  
    else if (kisiSayi > node->kisiSayisi) //eklenecek değer ebeveyn düğümün değerinden büyükse 
        node->sag = AvlEkleDis(node->sag,kisiSayi,work,sayac,yil,adsoyad); 
    else if (kisiSayi == node->kisiSayisi)   //eklenecek değer ebeveyn düğümün değerine eşitse
        node->sol = AvlEkleDis(node->sol, kisiSayi,work,sayac,yil,adsoyad);  
 	
	   node->yukseklik = 1 + Max(Yukseklik(node->sol),Yukseklik(node->sag));//avl nin yüksekliğini güncelleme ve tanımlama	   
    int denge = Denge(node);  
	//avl dengesini oluşturma
    if (denge > 1 && kisiSayi < node->sol->kisiSayisi)  
        return SagDonus(node);

    if (denge > 1 && kisiSayi == node->sol->kisiSayisi)  
        return SagDonus(node);	

    if (denge < -1 && kisiSayi > node->sag->kisiSayisi)  
        return SolDonus(node);  
  
    if (denge > 1 && kisiSayi > node->sol->kisiSayisi)  
    {  
        node->sol = SolDonus(node->sol);  
        return SagDonus(node);  
    }  
    if (denge < -1 && kisiSayi < node->sag->kisiSayisi)  
    {  
        node->sag = SagDonus(node->sag);  
        return SolDonus(node);  
    }

    return node; 
}  
AVL* Kontrol::AvlEkleIc(AVL* node,int yil ,string adsoyad) //iç avl ekleme 
{  
    if (node == NULL)  //eklenecek olan avl boşsa
	{
	 return YeniNodeIc(yil,adsoyad);
	}	
         if (yil < node->yilDeger)  //eklenecek değer ebeveyn düğümün değerinden küçükse
        node->sag = AvlEkleIc(node->sag,yil,adsoyad);  
    else if (yil > node->yilDeger)   //eklenecek değer ebeveyn düğümün değerinden büyükse
        node->sol = AvlEkleIc(node->sol,yil,adsoyad);
    else if (yil == node->yilDeger)   //eklenecek değer ebeveyn düğümün değerine eşitse
        node->sol = AvlEkleIc(node->sol,yil,adsoyad); 
		
	 node->yukseklik = 1 + Max(Yukseklik(node->sol),Yukseklik(node->sag));  //avl nin yüksekliğini güncelleme ve tanımlama
     
    int denge = Denge(node);  
	//avl dengesini oluşturma
    if (denge > 1 && yil > node->sol->yilDeger)  
        return SagDonus(node);  
	
	if (denge > 1 && yil == node->sol->yilDeger)  
        return SagDonus(node);  

    if (denge < -1 && yil < node->sag->yilDeger)  
        return SolDonus(node);  
  
    if (denge > 1 && yil < node->sol->yilDeger)  
    {  
        node->sol = SolDonus(node->sol);  
        return SagDonus(node);  
    }  
    if (denge < -1 && yil > node->sag->yilDeger)  
    {  
        node->sag = SagDonus(node->sag);  
        return SolDonus(node);  
    }  
    return node;  
}  
void Kontrol::PostorderDis(AVL *t)//dış avl ile birlikte iç avl yazdırma
 {
   if (t != NULL)
   {
      PostorderDis(t ->sol);
      PostorderDis(t ->sag);
	  cout << t->isYeri<< " ";
      cout << t->kisiSayisi<< " ";
	  cout<<endl;
	  PostorderIc(t->baglanti);
	   cout<<endl;
   }
 }
void Kontrol::PostorderIc(AVL *t)//iç avl yazdırma
 {
   if (t != NULL)
   {
      PostorderIc(t ->sol);
      PostorderIc(t ->sag);
      cout << t->adSoyad<< " ";
	  cout << t->yilDeger<< " ";
   }
 }
void Kontrol::DosyaIslemleri()
{
	int satirSayac=0;
	int listSayi=ListSayisi();
	string isYeriDizi[listSayi];
	bool isYeriVarmi=false;
     AVL *root2 = NULL;	 
	int m=0;
	string satir;
	char karakter;
	string isYeri;
	string adSoyad;
	string yil;
	int Yil;
	ifstream dosya1;
	dosya1.open("Veriler.txt", ios::in);
	ifstream dosya2;
	dosya2.open("Veriler.txt", ios::in);
	while(!dosya1.eof())//dosya sonuna gelene kadar okunan döngü
	{
		int kontrolSayac=0;
		getline(dosya1,satir);
		for(int i=0;i<satir.length();i++)//satirdaki veri sayisini bulmak icin hazırlanan dongu
		{
		   dosya2.get(karakter);
		    if(satir[i]=='#')//# kontrolu yaparak verileri ayiriyoruz 
			{
			 kontrolSayac++;
			}
			else 
			{
		        if(kontrolSayac==0)//# kontrolu yaparak verileri ayiriyoruz 
			    {
			     isYeri+=karakter;
			    }
			    if(kontrolSayac==1)//# kontrolu yaparak verileri ayiriyoruz 
			    {
			     adSoyad+=karakter;
			    }
			    if(kontrolSayac==2)//# kontrolu yaparak verileri ayiriyoruz 
			    {
			     yil+=karakter;
			    }
			}
		}
		dosya2.get(karakter);
		stringstream geek(yil); 
		geek >> Yil; 
		satirSayac++;
		
		
		//*******************************************************************
		//*******    AVL ağaçarı satır okundukça oluşturulur      ***********
		//*******************************************************************
		
		
		for(int i=0;i<satirSayac;i++)
		{
			if(isYeriDizi[i]==isYeri)//okunan değer daha once okunmuş ise dış avlnin sahip olduğu iş yerinin elemanımı kontrolü
			{
				for(int j=0;j<m;j++)//dış avl sayısı kadar doner ve avl ağaçarının bağlantılarını koparır
				{
					avl_dis[j]->sag=NULL;
					avl_dis[j]->sol=NULL;
                    avl_dis[j]->yukseklik=1;					
				}
				isYeriVarmi=true;
				avl_dis[i]->kisiSayisi++;
				for(int k=0;k<m;k++)//dış avl sayısı kadar donen dongu
				{
					if(root2!=avl_dis[k])//kök düğüm zaten var olduğu için ekleme olmaz
                   root2=NodeUpdate(root2,avl_dis[k]);//avl ağaçlarının update edilmesi ve diziliminin dengeli ve kurallı oluşturulması
				}
				avl_ic[i]=AvlEkleIc(avl_ic[i],Yil,adSoyad);
				avl_dis[i]->baglanti=avl_ic[i];
			}
		}
		if(!isYeriVarmi)//okunan değer daha once okunmamış ise yeni  dış avl oluşturulur
		{
		  isYeriDizi[m]=isYeri;
		  root2=AvlEkleDis(root2,1,isYeri,m,Yil,adSoyad);
		  avl_ic[m]=avl_dis[m]->baglanti;
		  m++;
	    }
		isYeriVarmi=false;
		isYeri.clear();
		adSoyad.clear();
		yil.clear();
	}
	PostorderDis(root2);//ekrana yazırma
    delete []avl_ic;
	delete []avl_dis;
	dosya1.close();
	dosya2.close();
}