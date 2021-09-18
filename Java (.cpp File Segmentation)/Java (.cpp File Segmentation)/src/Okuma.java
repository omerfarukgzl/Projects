/**
*
* @author Omer Faruk Guzel - faruk.guzel@ogr.sakarya.edu.tr
* @since 19.03.2021-11.04.2021 
* @course  2B
* <p>
*  program.cpp dosyasini class'lara bolup class'lardaki public metodlari ve 
*  bu metodlarin parametrelerini,geri donus tipini ve kalitim alinan class lari listelemek
* </p>
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Okuma 
{          
	 static String Istenilen_kod="";
	 static String kod_isim="";
	 
	 
	 static int data = 0;    
	 static String kontolEdilenKod="";
	 static String classIsmi ="";
	 static String metodIsmi="";
	 static String metodParametre="";
	 static String metodDonusTipi="";
	 static String kalitimAlinanClass="";
	 
	 
	 static int parametreSayac=0;
	 static boolean kalitimBulundu=false;
	 static boolean kalitimOkundu=false;
	 static boolean parametreOkundu=false;
	 static boolean classOkundu=false;
	 static boolean publicMetodOkundu=false;
	 
	 static  List<String> Metodparametre=new ArrayList<String>();//metodlardaki parametreler tutulur
	 static  Map<String, Integer> KalitimClass = new HashMap<String, Integer>();//kalitim alinan sinif ve sayilarin sozlugu
	 
	 
	    public static char KodOku(char character,int data,BufferedReader br) throws IOException //istenilen kod okuma
	    {
		 Istenilen_kod="";
		
      	   while(character!=' ' && character!='\n' && character!='\r')  //karakter boşluk , satır sonu ve satır başı karakteri olmayana kadar oku
      	   {
      		 Istenilen_kod+=character;
      	    data = br.read();
      	    character = (char) data;
      	   }

	      return character;
         
	    }
	 
		public static char BoslukOku (char character,int data, BufferedReader br) throws IOException //bosluk satir basi ve satir sonu okuma 
	    {
			   while(character==' ' || character=='\n' || character=='\r') //karakter boşluk , satır sonu ve satır başı karakteri ise oku
	    	   {
	    	    data = br.read();
	    	    character = (char) data;
	    	   }
			   return character;
		}
		public static char SinirlayiciKarektereKadarOku (char character,int data, BufferedReader br,char sinirlayici1,char sinirlayici2) throws IOException //istenilen karaktere kadar sinirlamalar dahilinde okuma
		{

			   while(character!=sinirlayici1 ) //karakter istenilen sinirlayici karakter olana kadar oku
	    	   {
	    	    data = br.read();
	    	    character = (char) data;
	    	    if(data==-1)//karakter okunmuyorsa( dosya okumayapılamıyorsa) donguden cik
	    	    {
	    	    	character='0';
	    	    	break;
	    	    }
	    	    character = (char) data;
	    	    if(character==sinirlayici2)//karakter istenilen sinirlayici karakter olana kadar oku
	    	    	break;

	    	   }
			   return character;
		}

		public static char KodIsimOku(char character,int data,BufferedReader br,char okumaKontrolKarakteri1,char okumaKontrolKarakteri2) throws IOException // cpp dosyasindaki kod ismini okuma
		{
			kod_isim="";
			while(character!=okumaKontrolKarakteri1 )//karakter istenilen sinirlayici karakter olana kadar oku
     	    {	   
     		   if(character==' ' || character=='\n' || character=='\r'|| character==okumaKontrolKarakteri2)//son karaktere kadar yapilan bosluk kontrolu
     		   {
     			   break;
     		   }
     		   
     	    data = br.read();
     	    kod_isim+=character;
     	    character = (char) data;
     	    }
			return character;
		}
		

		public static void ClassOkuma(char character , BufferedReader br) throws IOException //sinif okuma 
		{
			  while(!classOkundu) //class okunmadiysa gir ve class sonuna gelene kadar oku
              {
	               character=SinirlayiciKarektereKadarOku(character, data, br, 'c','c');//class okutma 
	               if(character=='0')//dosya sonuna gelindiyse kontrolu
	               	break;
	               character=KodOku(character, data, br);
	               kontolEdilenKod=Okuma.Istenilen_kod;
	           	   if(kontolEdilenKod.equals("class")) //classin icine girip class ismini bulma 
	           	   {
	           		   classOkundu=true;
	           		   character=BoslukOku(character, data, br);
	           		   character=KodIsimOku(character, data, br,'{',':'); //okunacak olan class isminin { veya : karakterlerine gelirse sonlanmasi gereken ve bosluk kontroluyle birlikte okuyan fonksiyon tanimi
	           		   classIsmi=kod_isim;
	           		   character=BoslukOku(character, data, br);
	           		   if (character==':') //kalitim alinan class varsa kontrolu
	           		   {
	           		   	   while(!kalitimOkundu)//kalitim okunmadiysa gir ve kalitim sonuna gelene kadar oku
	           		   	   { 
	           		   		   data=br.read();
	           		           character = (char) data; 
	           		   		   character=BoslukOku(character, data, br);
	           		           character=KodIsimOku(character, character, br, '{', ',');
	           		           kalitimOkundu=true;
	           		           if(kod_isim.equals("public") || kod_isim.equals("private") || kod_isim.equals("protected"))//tipi belirtilmis kalitim alinan sinif
	           		           {
	           		        	   kalitimOkundu=true;
	           		        	   character=BoslukOku(character, data, br);
	           		        	   character=KodIsimOku(character, data, br, '{', ',');
	           		        	   kalitimAlinanClass=Okuma.kod_isim;

	           		        	   character=BoslukOku(character, data, br);
	           		        	   if(character==',')//kalitim alinan class birden fazla ise
	           		        		   kalitimOkundu=false;
	           		           }
	           		           else//tipi belirtilmemis kalitim alinan sinif 
	           		           {
	           		        	   kalitimOkundu=true;
	           		        	   kalitimAlinanClass=Okuma.kod_isim; 
	           		        	  if(character!='{')//class açma suslu parantezine gelindiyse
	           		        		kalitimOkundu=false;
	           		           }
	           		          
	           		        	  
	       		        	   for(String kalitimAlinanlar:KalitimClass.keySet())//onceki kalitim alinan siniflari bulup sayisini guncellemek icin kurulan dongu  
	       		        	   {       		        	   	  
	       		        	   		if(kalitimAlinanClass.equals(kalitimAlinanlar))//kalitim alinan sinif daha once varsa
	       		        	   	    {
	       		        	   			 KalitimClass.put(kalitimAlinanClass, KalitimClass.get(kalitimAlinanlar)+1);
	       		        	   			 kalitimBulundu=true;
	       		        	   		 }		  
	       		        	   }
	       		        	   if(!kalitimBulundu)//kalitim alinan sınıf daha once yoksa 
	           		    	   {
	           		    	      KalitimClass.put(kalitimAlinanClass, 1);
	           		    	   }	           		    	  
	           		   	    }           		   	   
	           		   }
	           		  System.out.println(" \nSinif: "+classIsmi + " \n");
	           	      PublicOkuma(character,br); //sinifin icine girildikten sonra kapsullenen public metdolari okuma
	           	   }
              }			  
       }
		
		public static char PublicOkuma(char character , BufferedReader br) throws IOException //public kapsulunu okuma
		{
		     while(classOkundu) //class icinden public okuma 
  		     {
		    	    character= SinirlayiciKarektereKadarOku(character, data, br,'p','}');
		    	    if(character=='}')//sinifin icinde public kapsülleme yoksa
		    	    {
		    	    	  data=br.read();
	            		  character=(char)data;
		    	    	  character=BoslukOku(character, data, br);
            			  if(character=='}')
            			  {
            				  data=br.read();
    	            		  character=(char)data;
    		    	    	  character=BoslukOku(character, data, br);
            				  if(character==';')//class sonuna gelindiyse
    	            		  {          					  
    	               	         classOkundu=false; 
    	               			 kalitimOkundu=false;
    	            			  break; 
    	            		  }           				  
            			  }	            		  
		    	    }
		  	        character=KodIsimOku(character, data, br, ':', ':');
		  	        kontolEdilenKod=Okuma.kod_isim;
		  	        		  	        
		  	            if(kontolEdilenKod.equals("public"))//public den sonra : karekteri bosluktan sonra gelirse 
		  	            {
		  	        	  character=BoslukOku(character, data, br);
		  	        	      if(character==':')
		  	        	      {
		  	        		      kontolEdilenKod="public:";
		  	        		      data=br.read();
			            		  character=(char)data;
		  	        	      }		  	        	
		  	             }
		  	     PublicMetodOkuma(character,br); // public kapsulleme altinda metodlari okuma
  		     }
			
			return character;
		}		
		public static char PublicMetodOkuma(char character , BufferedReader br) throws IOException //public olan metodlari okuma
		{
			 while(kontolEdilenKod.equals("public:"))//Metod Okuma
 	         {
				 if(!publicMetodOkundu)//metod okunmadiysa gir ve metod sonuna kadar oku
	 	         {						 
						Metodparametre.clear();
						metodDonusTipi="";
	 	        		parametreSayac=0;
	 	        		
	         		  character=BoslukOku(character, data, br);
	         		  if(character=='~') //yikici fonksiyonun donus tipini void olarak ayarlama
	         			  metodDonusTipi="void";
	         		
	         		  character=KodIsimOku(character, data, br, '(','(');//Metod Oku
	         		  character=BoslukOku(character, data, br);
	         		  if(kod_isim.equals("private") || kod_isim.equals("private:") || kod_isim.equals("protected") || kod_isim.equals("protected:"))//public kapsulunden sonra private veya protected kapsulunun gelmnesi kontrolu
	         		  {
	            	     classOkundu=false; 
	               		 kalitimOkundu=false;
	         			 break;
	         		  }
	         		 while(character!='(' && character!=';')//metod tipini anlama
         		     {
         		  	     metodDonusTipi=Okuma.kod_isim; //donus tipi alindi 
	
         			     character=KodIsimOku(character, data, br, '(',';');  // metod ismini oku
         			     character=BoslukOku(character, data, br);
         		     }
         		     metodIsmi=Okuma.kod_isim; //metod ismi atama
         			     
         		     if(metodDonusTipi.equals(""))//metod donus tipi yoksa 
         		    	 metodDonusTipi="Nesne Adresi";
         		     
         		     if(metodDonusTipi.equals("~"))//yikici fonksiyon ise
         		     {
         		    	 metodIsmi="~"+metodIsmi;
         		    	 metodDonusTipi="void";
         		     }
    				 if(character!=';')//degisken tanimlanirsa kontrolu
    				 {   					 
         		     data=br.read();
         		     character=(char)data;
         		     publicMetodOkundu=true;
         		     System.out.println("   "+metodIsmi);	
    				 }
 	             }				 
				 if(character!=';')//degisken tanimlanirsa kontrolu
				 {
	 	        	 ParametreOkuma(character, br); // Metod parametrelerini okuma
					 
				 }
 	        	 data=br.read();
       		     character=(char)data;
       		     character=BoslukOku(character, data, br);

       		      //parantez blogu bittikten sonra bir karakter okunur . Okunan karaktere gore kosul bloklari calisir      		  
	        	 if(character=='}') //sinif parantezinin parantez kapama bloguna gelindiyse
	        	 {
           		     character=SinirlayiciKarektereKadarOku(character, data, br,';',';');//klas kapama parantezinden sonra virgulu oku ve klası kapat
           	         classOkundu=false; 
           			 kalitimOkundu=false;
           			 break;
	        	 }
 	         }
		return character;
		}		
		public static char ParametreOkuma(char character , BufferedReader br) throws IOException //public metodlarin parametrelerini okuma
		{
			if(!parametreOkundu) //parametre okunmadiysa gir ve parametreleri oku
        	{
  			     character=Okuma.BoslukOku(character, data, br);
    		      if(character!=')')//parantez icindeysek
    		      {
    			     character=Okuma.BoslukOku(character, data, br);
        		     character=Okuma.KodIsimOku(character, data, br, ')',','); //parametre turu
        		     metodParametre=Okuma.kod_isim;
        		        		  
        		     Metodparametre.add(metodParametre);
        		  
    			     character=Okuma.SinirlayiciKarektereKadarOku(character, data, br, ',',')');//virgule kadar oku virgul yoksa kapama parenteze kadar
            		 parametreSayac++;
    		      }
    		  
    		      if(character==')')//parantez sonu kontrolu
    		      {
    			     parametreOkundu=true;
    		      }
        	}
    		  metodParametre="";
    		  ParametreSonuFonksiyonu(character,br);
    		  
			return character;
		}						
		public static char ParametreSonuFonksiyonu(char character , BufferedReader br) throws IOException //metodun parametre sonu islemleri ve kontrolleri
		{
			if(parametreOkundu)//parametreler okunup sona gelindiyse
        	{
        		character=SinirlayiciKarektereKadarOku(character, data, br, '{','{'); //Metod suslu parantez blogundaki acma parantezini okuma
        		character=SinirlayiciKarektereKadarOku(character, data, br, '}','{'); //Metod suslu parantez blogunda kapama parantezini oku eger icerde baska suslu parantez bloklari varsa onlarin okunmasi icin karakterin okunmasini acma parantezinde durdur 
        		
        		int susluParantezSayisi=1;
        		if(character=='{') //Metod blogunun icinde baska parantez blogu varsa okumasini gerceklestir
        		{
        			susluParantezSayisi++;
        			while(susluParantezSayisi>0)//metod icinde baska suslu parantez bloklari varsa
	        		{
        				 data=br.read();
        				 character=(char)data;
	        			character=SinirlayiciKarektereKadarOku(character, data, br, '}','{');
	        			  if(character=='{')
	        				  susluParantezSayisi++;
    	        		 
	        			  else if(character=='}')
	        			      susluParantezSayisi--;
	        		}
        		}
        		MetodSonuYazdir(character,br);        		
        	}		
			return character;
		}		
		public static char MetodSonuYazdir(char character , BufferedReader br) //metod sonu metod ve parametreleri yazdirma
		{
			if(character=='}') //Metod parantezi blogunun sonuna gelince
       	    {
				 parametreOkundu=false;
	        	 publicMetodOkundu=false;
	        	 
	        	 //Ekrana yazdirma bolumu
	        	 System.out.print("        parametre : "+parametreSayac); //yazdirmaa
	        	 if(parametreSayac>0)
	        	 {
	        		 System.out.print(" ( ");
	        	 }
	        	 int parametresayacvirgul=parametreSayac;//virgul sayisini paraemtre sayisindan bir eksik koymak icin
	        	 for(String parametre:Metodparametre)  // parametre yazimi
	        	 {
	        		  System.out.print(parametre);
	        		  parametresayacvirgul--;
	        		  if(parametresayacvirgul>0)
	        			  System.out.print(", "); 
	        	 }
	        	 if(parametreSayac>0)
	        	       System.out.print(" )");
	        	 
	        	 System.out.print("\n        Donus Turu : "+metodDonusTipi+ " \n");
      		    metodDonusTipi="";
       	    }
			return character;
		}	
}