/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 24.04.2021 - 16.05.2021 
* @course  2B
* <p>
* Borsa İşlemleri Kar Zarar Ve Maliyet Hesabı
* </p>
*/

#include "Portfoy.h"


Portfoy PortfoyOlustur()
{
	
  Portfoy this;
  this = (Portfoy)malloc(sizeof(struct PORTFOY));
  this->P_hisseSayi=P_HisseSayiAl();
  
  this->P_id = (char**)malloc(this->P_hisseSayi*sizeof(char*));
  for(int i=0; i< this->P_hisseSayi; i++) 
	  this->P_id[i] = (char*)malloc(100*sizeof(char));
  
    this->P_sembol = (char**)malloc(this->P_hisseSayi*sizeof(char*));
  for(int i=0; i< this->P_hisseSayi; i++) 
	  this->P_sembol[i] = (char*)malloc(100*sizeof(char));
  
   this->P_maliyet = (char**)malloc(this->P_hisseSayi*sizeof(char*));
  for(int i=0; i< this->P_hisseSayi; i++) 
	  this->P_maliyet[i] = (char*)malloc(100*sizeof(char));
  
  
   this->P_adet = (char**)malloc(this->P_hisseSayi*sizeof(char*));
  for(int i=0; i< this->P_hisseSayi; i++) 
	  this->P_adet[i] = (char*)malloc(100*sizeof(char));
  
   this->P_iAdet = malloc(this->P_hisseSayi*sizeof(int));
   this->P_dMaliyet = malloc(this->P_hisseSayi*sizeof(double));
  
 
   this->oku='x';
	
}
void P_DosyaOku(Portfoy p)
{
FILE *dosya = fopen("portfoy.json", "r");
int parantez_sayisi=0;
int idSatir=0;
  while(! feof(dosya))
   {
       p->oku = fgetc(dosya);
	   if(p->oku=='{')
	   parantez_sayisi++;

	  int sinirSayac=0;
	  int idIDSayac=0;
	  int sembolSayac=0;
	  int maliyetSayac=0;
	  int adetSayac=0;
	    while(parantez_sayisi==2 /*&& h->oku!='"'*/)
	    {		
			if(p->oku=='"') //" kontrolu
			{
				p->oku = fgetc(dosya);
				while(p->oku!='"' ) //" icindeyse 
	            {
					if(sinirSayac==1)//id okuma
			        {
				        while(p->oku!='"')
	                    {
							p->P_id[idSatir][idIDSayac]=p->oku;
							idIDSayac++;
		                    p->oku = fgetc(dosya);
		                }  					
					     p->P_id[idSatir][idIDSayac]='\0';					
						break;
				    }
					if(sinirSayac==3)//Sembol
			        {
				        while(p->oku!='"')//Sembol Okuma
	                    {
							p->P_sembol[idSatir][sembolSayac]=p->oku;
							sembolSayac++;
		                    p->oku = fgetc(dosya);
		                }  
					    p->P_sembol[idSatir][sembolSayac]='\0';
						break;
				    }
		            p->oku = fgetc(dosya);					
		        }
				 p->oku = fgetc(dosya);
				 sinirSayac++;	
			} 			
			else
			{
				  p->oku = fgetc(dosya);
			}
			if(sinirSayac==5) // Maliyet
			{
				 p->oku = fgetc(dosya);
				while(p->oku==' '  ||  p->oku==':') //Bosluk ve : Karakteri Kontrolu
	               p->oku = fgetc(dosya);
			   
			    while(p->oku!=' ' && p->oku!='}' && p->oku!=',') //Maliyet okuma
	            {		            
		     		p->P_maliyet[idSatir][maliyetSayac]=p->oku;						
					maliyetSayac++;
					p->oku = fgetc(dosya);
		        }  
				p->P_maliyet[idSatir][maliyetSayac]='\0';	
                sinirSayac++;				
		    }
			if(sinirSayac==7) //Adet
			{

				 p->oku = fgetc(dosya);
				while(p->oku==' ' || p->oku==':') //Bosluk ve : Karakteri Kontrolu
	               p->oku = fgetc(dosya);
			   
			    while(p->oku!=' ' && p->oku!='}') //Adet Okuma
	            {		            
		     		p->P_adet[idSatir][adetSayac]=p->oku;						
					adetSayac++;
					p->oku = fgetc(dosya);
		        }  
				p->P_adet[idSatir][adetSayac]='\0';	
		    }	
			while(p->oku==' ')//bosluk kontrolu
				p->oku = fgetc(dosya);
			
			if(p->oku=='}') //satir sonu parantezi
			{
		        parantez_sayisi--;
		        idSatir++;			
			}
	    }	
    }	
	for(int i=0; i< p->P_hisseSayi; i++) // cevirme islemleri
	{
	   p->P_iAdet[i]= atoi(p->P_adet[i]);
	   p->P_dMaliyet[i]= atof(p->P_maliyet[i]);
	}
 
  fclose(dosya); 
	
	
}
int P_HisseSayiAl() //Hisse Sayisi Alma 
{
	FILE *dosya = fopen("portfoy.json", "r");
	int hisseSayisi=-1;
	char okunan;
   while(!feof(dosya))//Dosya Sonuna Kadar Oku
   {
       okunan = fgetc(dosya);
	    if(okunan=='{')
          	hisseSayisi++;	
    }	
	 fclose(dosya);
	return hisseSayisi;

}
void P_YokEt(Portfoy p) //Yikici Fonskiyon
{
	if(p==NULL)return;
	free(p->P_id);
	free(p->P_sembol);
	free(p->P_maliyet);
	free(p->P_adet);
	free(p->P_iAdet);
	free(p->P_dMaliyet);
	free(p);
	p=NULL;	
	
	
	
}