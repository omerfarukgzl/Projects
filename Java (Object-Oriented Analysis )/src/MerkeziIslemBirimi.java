import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;
import java.util.Scanner;




public class MerkeziIslemBirimi {
	
	 private static ArrayList<Kullanici> kullanicilar = new ArrayList();

	    public MerkeziIslemBirimi() {
	    }

	    public static void main(String[] args) {
	        Scanner scn = new Scanner(System.in);
	        Random rnd = new Random();
	        VeriTabani SQL = new VeriTabani();
	        System.out.println("PROGRAMA HOŞGELDİNİZ.");

	        while(true) {
	            while(true) {

	                System.out.println("Kullanıcı Adı: ");
	                String k_adi = scn.nextLine();
	                System.out.println("Parola: ");
	                String parola = scn.nextLine();
	                SQL.baglanti_ac();
	                kullanicilar = SQL.kullanicilari_ata();
	                AgArayuzu arayuz = new AgArayuzu();
	                kullanicilar.forEach((kx) -> {
	                   arayuz.yetki_ver(kx);
	                });
	                
	                Iterator<Kullanici> var17 = kullanicilar.iterator();
	                boolean giris=false;
	                boolean cikis=false;
	                while(var17.hasNext()) {	                	
	                    Kullanici k = (Kullanici)var17.next();
	                    if (k.yetkili_mi(SQL, k_adi, parola)) {
	                    	giris=true;
	                        System.out.println(k.getKullaniciAdi() + " Giris Basarili.\n");
	                        String islemler = "İşlemler\n1-Soğutucuyu Aç\n2-Soğutucuyu Kapat\n3-Sıcaklık Görüntüle\nQ-Çıkış";

	                        while(true) {
	                        	 if(cikis)
	     	 	                {
	     	 	                   System.out.println("Program Devre Disi .\n"); 
	     	 	                   break;
	     	 	                }
	                            System.out.println(islemler);
	                            String islem_secim = scn.nextLine();
	                            byte var21 = -1;
	                            switch(islem_secim.hashCode()) {
	                                case 49:
	                                    if (islem_secim.equals("1")) {
	                                        var21 = 0;
	                                    }
	                                    break;
	                                case 50:
	                                    if (islem_secim.equals("2")) {
	                                        var21 = 1;
	                                    }
	                                    break;
	                                case 51:
	                                    if (islem_secim.equals("3")) {
	                                        var21 = 2;
	                                    }
	                                    break;
	                                case 81:
	                                    if (islem_secim.equals("Q")) {
	                                        var21 = 3;
	                                    }
	                            }

	                            switch(var21) {
	                                case 0:
	                                    arayuz.islemi_yap("1",k.getKullaniciAdi());
	                                    break;
	                                case 1:
	                                	arayuz.islemi_yap("2", k.getKullaniciAdi());
	                                    break;
	                                case 2:
	                                	arayuz.islemi_yap("3", k.getKullaniciAdi());
	                                    break;
	                                case 3:
	                                    System.out.println("Programdan çıkılıyor.\n");                                     
	                                    cikis=true;
	                                    break;
	                                default:
	                                    System.out.println("Tanımlanamayan işlem,Çıkılıyor...\n");
	                                    
	                            }
	                        }
	                    }
	                    if(cikis)	 	        
 	 	                   break;     
	                }	               
	                if(!giris)
	                	System.out.println("Yetkisiz Kullanici ..\n");
	                    SQL.baglanti_kapat();
	                }
	        }
	    }
}
	            
		
	


