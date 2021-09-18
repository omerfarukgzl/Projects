/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 24.04.2021 - 16.05.2021 
* @course  2B
* <p>
* Borsa İşlemleri Kar Zarar Ve Maliyet Hesabı
* </p>
*/

#include "Hisse.h"
Hisse HisseOlustur()
{
  Hisse this;
  this = (Hisse)malloc(sizeof(struct HISSE));
  this->hisseSayi=HisseSayiAl();
  
  this->id = (char**)malloc(this->hisseSayi*sizeof(char*));
  for(int i=0; i< this->hisseSayi; i++) 
	  this->id[i] = (char*)malloc(100*sizeof(char));
  
    this->sembol = (char**)malloc(this->hisseSayi*sizeof(char*));
  for(int i=0; i< this->hisseSayi; i++) 
	  this->sembol[i] = (char*)malloc(100*sizeof(char));
  
   this->ad = (char**)malloc(this->hisseSayi*sizeof(char*));
  for(int i=0; i< this->hisseSayi; i++) 
	  this->ad[i] = (char*)malloc(100*sizeof(char));
  
  
   this->fiyat = (char**)malloc(this->hisseSayi*sizeof(char*));
  for(int i=0; i< this->hisseSayi; i++) 
	  this->fiyat[i] = (char*)malloc(100*sizeof(char));
  
   this->dFiyat = malloc(this->hisseSayi*sizeof(double));
  
   this->oku=' ';
}

void DosyaOku(Hisse h)
{
FILE *dosya = fopen("hisseler.json", "r");
int parantez_sayisi=0;
int idSatir=0;
  while(! feof(dosya))
   {
       h->oku = fgetc(dosya);
	   if(h->oku=='{')
	   parantez_sayisi++;

	  int sinirSayac=0;
	  int idIDSayac=0;
	  int sembolSayac=0;
	  int adSayac=0;
	  int fiyatSayac=0;
	    while(parantez_sayisi==2) 
	    {		
			if(h->oku=='"') //" kontrolu
			{
				h->oku = fgetc(dosya);
				while(h->oku!='"' ) //" icindeysek
	            {
					if(sinirSayac==1)//id 
			        {
				        while(h->oku!='"') //id Okuma
	                    {
							h->id[idSatir][idIDSayac]=h->oku;
							idIDSayac++;
		                    h->oku = fgetc(dosya);
		                }  
						h->id[idSatir][idIDSayac]='\0';
						break;
				    }
					if(sinirSayac==3)//Sembol
			        {
				        while(h->oku!='"')//Sembol okuma
	                    {
							h->sembol[idSatir][sembolSayac]=h->oku;
							sembolSayac++;
		                    h->oku = fgetc(dosya);
		                }  
						h->sembol[idSatir][sembolSayac]='\0';
						break;
				    }
					if(sinirSayac==5)//AD
			        {
				        while(h->oku!='"')//AD okuma
	                    {
							h->ad[idSatir][adSayac]=h->oku;
							adSayac++;
		                    h->oku = fgetc(dosya);
		                }  
						h->ad[idSatir][adSayac]='\0';
						break;
				    }
		            h->oku = fgetc(dosya);					
		        }
				 h->oku = fgetc(dosya);
				 sinirSayac++;							 
			} 			
			else
			{
				  h->oku = fgetc(dosya);
			}
			if(sinirSayac==7) //Fiyat
			{
				 h->oku = fgetc(dosya);
				while(h->oku==' '|| h->oku==':') //Bosluk ve : Karakteri Kontrolu
	               h->oku = fgetc(dosya);
			   
			    while(h->oku!=' ' && h->oku!='}') //Fiyat Okuma
	            {		            
		     		h->fiyat[idSatir][fiyatSayac]=h->oku;						
					fiyatSayac++;
					h->oku = fgetc(dosya);
		        }  
				h->fiyat[idSatir][fiyatSayac]='\0';
		    }
			while(h->oku==' ')//bosluk kontrolu
				h->oku = fgetc(dosya);
			if(h->oku=='}')
			{
		        parantez_sayisi--;
		        idSatir++;			
			}
	    }	
    }	
	for(int i=0; i< h->hisseSayi; i++) //double cevirme
	{
	   h->dFiyat[i]= atof(h->fiyat[i]);
	}
 
  fclose(dosya); 
}	
int HisseSayiAl() //Hisse Sayisi Alma
{
	FILE *dosya = fopen("hisseler.json", "r");
	int hisseSayisi=-1;
	char okunan;
   while(!feof(dosya)) //Dosya Sonuna Kadar Okuma
   {
       okunan = fgetc(dosya);
	    if(okunan=='{')
          	hisseSayisi++;	
    }	
	 fclose(dosya);
	return hisseSayisi;
}
void YokEt(Hisse h) //Yikici Fonksiyon
{
	if(h==NULL)return;
	free(h->id);
	free(h->sembol);
	free(h->ad);
	free(h->fiyat);
	free(h->dFiyat);
	free(h);
	h=NULL;
}