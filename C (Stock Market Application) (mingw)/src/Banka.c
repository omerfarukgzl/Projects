/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 24.04.2021 - 16.05.2021 
* @course  2B
* <p>
* Borsa İşlemleri Kar Zarar Ve Maliyet Hesabı
* </p>
*/


# include "Emir.h"
# include "Banka.h"
# include "Hisse.h"
# include "Portfoy.h"
Banka BankaOlustur(Emir e)
{
  Banka this;
  this = (Banka)malloc(sizeof(struct BANKA));  
  this->B_islemSatis = "SATIS";
  this->B_islemAlis = "ALIS";
  
    this->B_sembolSatis = (char**)malloc(e->E_hisseSayi*sizeof(char*));
  for(int i=0; i< e->E_hisseSayi; i++) 
	  this->B_sembolSatis[i] = (char*)malloc(100*sizeof(char));
  
  this->B_sembolAlis = (char**)malloc(e->E_hisseSayi*sizeof(char*));
  for(int i=0; i< e->E_hisseSayi; i++) 
	  this->B_sembolAlis[i] = (char*)malloc(100*sizeof(char));
  
  
  this->B_toplamKarZarar=0;
   this->B_guncelAdet = malloc(e->E_hisseSayi*sizeof(double));
  this->B_guncelFiyat = malloc(e->E_hisseSayi*sizeof(double));
  this->B_maliyet = malloc(e->E_hisseSayi*sizeof(double));
  this->B_karZararHesap = malloc(e->E_hisseSayi*sizeof(double));

}


void EmirlerHesap(Banka b , Emir e)
{

	Hisse h = HisseOlustur();
	DosyaOku(h);
	Portfoy p = PortfoyOlustur();
	P_DosyaOku(p);
     int alisSayac=0;
	 int satisSayac=0;
	for(int i=0;i<e->E_hisseSayi;i++)
	{
	    if( ! strcmp(b->B_islemSatis,e->E_islem[i])) // Islem Satis ise
	    {
	   	    int sayacFiyat=0;
			int sayacMaliyet=0;

		    while(strcmp(e->E_sembol[i], h->sembol[sayacFiyat])) //Satilacak olan hisseyi Hisseler Dosyasında Bulma
			   sayacFiyat++;
		   
		    while(strcmp(e->E_sembol[i], p->P_sembol[sayacMaliyet])) //Satilacak olan hisseyi Portfoy Dosyasında Bulma
				sayacMaliyet++;
		  
		  
		  if(e->E_iAdet[i] <= p->P_iAdet[sayacMaliyet]) //Satilacak olan Adet Var olandan Fazlamı Kontrolu
		  {
		  
		    b->B_sembolSatis[satisSayac] = e->E_sembol[i];
		    b->B_karZararHesap[satisSayac] =((e->E_iAdet[i] * h->dFiyat[sayacFiyat] ) -  (e->E_iAdet[i] * p->P_dMaliyet[sayacMaliyet]));


            b->B_toplamKarZarar+=b->B_karZararHesap[satisSayac];
			p->P_iAdet[sayacMaliyet]= p->P_iAdet[sayacMaliyet] - e->E_iAdet[i];
            satisSayac++;	
			
		  }
          else 	
			printf(" Satmak İstediginiz Adet Portfoydeki Adetten Fazladir Lutfen Daha Dusuk Miktar Giriniz \n");  
		  
	    }
		if( ! strcmp(b->B_islemAlis,e->E_islem[i])) //Islem Alıs ise
	    {
			int sayacFiyat=0;
			int sayacMaliyet=0;

		    while(strcmp(e->E_sembol[i], h->sembol[sayacFiyat]))  //Alinacak olan hisseyi Portfoy Dosyasında Bulma
			   sayacFiyat++;
		   
		    while(strcmp(e->E_sembol[i], p->P_sembol[sayacMaliyet]))  //Alinacak olan hisseyi Portfoy Dosyasında Bulma
				sayacMaliyet++;
			
			
			b->B_sembolAlis[alisSayac] = e->E_sembol[i];
			b->B_guncelAdet[alisSayac]= (p->P_iAdet[sayacMaliyet]+ e->E_iAdet[i]);
			b->B_maliyet[alisSayac] = ( (p->P_iAdet[sayacMaliyet] * p->P_dMaliyet[sayacMaliyet]) + (e->E_iAdet[i] * h->dFiyat[sayacFiyat]) ) / b->B_guncelAdet[alisSayac] ;
            
			p->P_iAdet[sayacMaliyet]= p->P_iAdet[sayacMaliyet] + e->E_iAdet[i];
			p->P_dMaliyet[sayacMaliyet] = b->B_maliyet[alisSayac];
			 alisSayac++;
			
		}
	}
	
	//Ekrana YAzma İslemleri 
	
	printf("\n\nSatislar Kar/Zarar: \n\n");
	for(int i=0;i<satisSayac;i++)
	{
		printf("%s   :",b->B_sembolSatis[i]);
                printf(" %f ", b->B_karZararHesap[i]);	
                if(b->B_karZararHesap[i]>0)	
                 printf(" TL Kar \n");	
                if(b->B_karZararHesap[i]<0)	
                 printf(" TL Zarar \n");		
		
		
	}
	 printf("Toplam Kar/Zarar : ");
	 printf("%f ", b->B_toplamKarZarar);

        printf("\n\n\n\n Guncel Portfoy : \n\n");	 
	for(int i=0;i<p->P_hisseSayi;i++)
	{
		if(p->P_iAdet[i]!=0)
		{
		   printf(" Hisse : %s ",p->P_sembol[i]);
		   printf("\n Adet : %i ",p->P_iAdet[i]);
           printf("\n Maliyet %f   ", p->P_dMaliyet[i] );	
		   printf("\n------------\n");
		}
		
	}
	
	
	P_YokEt(p);
	E_YokEt(e);
	YokEt(h);
}
void B_YokEt(Banka b)//Yikici Fonksiyon
{
	if(b==NULL)return;
	free(b->B_sembolSatis);
	free(b->B_sembolAlis);
	free(b->B_guncelAdet);
	free(b->B_guncelFiyat);
	free(b->B_maliyet);
	free(b->B_karZararHesap);
	free(b);
	b=NULL;	
}

