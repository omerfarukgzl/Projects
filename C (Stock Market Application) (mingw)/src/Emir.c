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


Emir EmirOlustur() //Yapıcı Fonk
{
	  
  Emir this;
  this = (Emir)malloc(sizeof(struct EMIR));
  this->E_hisseSayi=E_HisseSayiAl();
  
  this->E_id = (char**)malloc(this->E_hisseSayi*sizeof(char*));
  for(int i=0; i< this->E_hisseSayi; i++) 
	  this->E_id[i] = (char*)malloc(100*sizeof(char));
  
    this->E_sembol = (char**)malloc(this->E_hisseSayi*sizeof(char*));
  for(int i=0; i< this->E_hisseSayi; i++) 
	  this->E_sembol[i] = (char*)malloc(100*sizeof(char));
  
   this->E_islem = (char**)malloc(this->E_hisseSayi*sizeof(char*));
  for(int i=0; i< this->E_hisseSayi; i++) 
	  this->E_islem[i] = (char*)malloc(100*sizeof(char));
  
  
   this->E_adet = (char**)malloc(this->E_hisseSayi*sizeof(char*));
  for(int i=0; i< this->E_hisseSayi; i++) 
	  this->E_adet[i] = (char*)malloc(100*sizeof(char));
  
   this->E_iAdet = malloc(this->E_hisseSayi*sizeof(int));

   this->oku=' ';	
}
void E_DosyaOku(Emir e)
{

  FILE *dosya = fopen("emirler.json", "r");
  int parantez_sayisi=0;
  int idSatir=0;
  while(!feof(dosya)) //Dosya Sonuna Kadar Okuma
   {
       e->oku = fgetc(dosya);
	   if(e->oku=='{')
	   parantez_sayisi++;

	  int sinirSayac=0;
	  int idIDSayac=0;
	  int sembolSayac=0;
	  int islemSayac=0;
	  int adetSayac=0;
	    while(parantez_sayisi==2)
	    {		
			if(e->oku=='"')
			{
				e->oku = fgetc(dosya);
				while(e->oku!='"' )
	            {
					if(sinirSayac==1)//id 
			        {
				        while(e->oku!='"')//id okuma
	                    {
							e->E_id[idSatir][idIDSayac]=e->oku;
							idIDSayac++;
		                    e->oku = fgetc(dosya);
		                }  
						e->E_id[idSatir][idIDSayac]='\0';
						break;
				    }
					if(sinirSayac==3)//Sembol
			        {
				        while(e->oku!='"') //Sembol okuma
	                    {
							e->E_sembol[idSatir][sembolSayac]=e->oku;
							sembolSayac++;
		                    e->oku = fgetc(dosya);
		                }  
						e->E_sembol[idSatir][sembolSayac]='\0';
						break;
				    }
					if(sinirSayac==5)//Islem 
			        {
				        while(e->oku!='"') //Islem okuma
	                    {
							e->E_islem[idSatir][islemSayac]=e->oku;
							islemSayac++;
		                    e->oku = fgetc(dosya);
		                }  
						e->E_islem[idSatir][islemSayac]='\0';
						break;
				    }
		            e->oku = fgetc(dosya);					
		        }
				 e->oku = fgetc(dosya);
				 sinirSayac++;							 
			} 			
			else
			{
				  e->oku = fgetc(dosya);
			}
			if(sinirSayac==7) //Adet 
			{
				 e->oku = fgetc(dosya);
				while(e->oku==' ' || e->oku==':') //Bolsuk ve : Karakteri Kontrolu
	               e->oku = fgetc(dosya);
			   
			    while(e->oku!=' ' && e->oku!='}') //Adet Okuma
	            {		            
		     		e->E_adet[idSatir][adetSayac]=e->oku;						
					//   printf("%c",e->E_adet[idSatir][adetSayac]);
					adetSayac++;
  				    e->oku = fgetc(dosya);
		        }  
				e->E_adet[idSatir][adetSayac]='\0';
		    }
			while(e->oku==' ')//bosluk kontrolu
				e->oku = fgetc(dosya);
			if(e->oku=='}') //Satir sonu parantezi
			{
		        parantez_sayisi--;
		        idSatir++;			
			}
	    }	
		
    }
		
	for(int i=0; i< e->E_hisseSayi; i++) //double cevirme
	{
	   e->E_iAdet[i]= atoi(e->E_adet[i]);
	}
 
  fclose(dosya); 
}

int E_HisseSayiAl() //Hisse Sayisi Alma
{
	FILE *dosya = fopen("emirler.json", "r");
	int hisseSayisi=-1;
	char okunan;
    while(!feof(dosya)) //Dosya Sonuna kadar okuma
    {
       okunan = fgetc(dosya);
	    if(okunan=='{')
          	hisseSayisi++;	
    }	
	 fclose(dosya);
	return hisseSayisi;
}
void E_YokEt(Emir e)//Yikici Fonksiyon
{
	if(e==NULL)return;
	free(e->E_id);
	free(e->E_sembol);
	free(e->E_islem);
	free(e->E_adet);
	free(e->E_iAdet);
	free(e);
	e=NULL;	
}