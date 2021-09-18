
import java.sql.*;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;


public class VeriTabani {
	
	  private Connection baglanti=null;
	  private boolean bagli_mi = false;
	  private final ArrayList<Kullanici> kullaniciDizisi = new ArrayList<Kullanici>();
	  

	public boolean baglanti_ac() {
		if (this.baglanti == null) {
            try {
                Class.forName("org.postgresql.Driver");
            } catch (ClassNotFoundException var3) {
                System.out.println("Driver bulunamadı");
            }

            try {
                this.baglanti = DriverManager.getConnection("jdbc:postgresql://localhost:5432/Nesne", "postgres", "1234");
            } catch (SQLException var2) {
                System.out.println("baglanamadi");
            }

            if (this.baglanti != null) {
                this.bagli_mi = true;
            }
        } else {
            System.out.println("DB'ye zaten bağlısınız..");
        }

        return this.bagli_mi;
	}

	public boolean baglanti_kapat() {
		  if (this.baglanti != null) {
	            try {
	                this.baglanti.close();
	                this.baglanti = null;
	                this.bagli_mi = false;
	            } catch (SQLException var2) {
	                Logger.getLogger(VeriTabani.class.getName()).log(Level.SEVERE, (String)null, var2);
	            }
	        } else {
	            System.out.println("Zaten bağlı değilsiniz.");
	        }

	        if (!this.bagli_mi) {
	            System.out.println("DB bağlantısı kesildi..");
	            return true;
	        } else {
	            return false;
	        }
	}

	public String signIN_manager(String kullanici_adi, String parola) {
		  boolean durum = false;
	        String kullanici_adi1 = "";
	        String sorgu = "SELECT kullanici_adi FROM public.\"kisiler\" where kullanici_adi='" + kullanici_adi + "' and sifre='" + parola + "';";
	        if (this.bagli_mi) {
	            try {
	                PreparedStatement ifade_yetki = this.baglanti.prepareStatement(sorgu);
	                ResultSet result_sonuc = ifade_yetki.executeQuery();
	                if (result_sonuc.next()) {
	                    kullanici_adi1 = result_sonuc.getString("kullanici_adi");
	                    durum = true;	                   
	                } else {
	                    durum = false;
	                }
	            } catch (SQLException var10) {
	            	
	            }
	        } else {
	            System.out.println("DB bağlı değil..");
	        }
      
	        return durum ? kullanici_adi1 : "Böyle bir yetkili kullanıcı yok.";
	}
	
	public ArrayList<Kullanici> kullanicilari_ata() {
        String giris = "SELECT  kullanici_adi , sifre FROM public.\"kisiler\";";

        try {
            PreparedStatement ifadegiris = this.baglanti.prepareStatement(giris);
            ResultSet result = ifadegiris.executeQuery();

            while(result.next()) {
                String password = result.getString("sifre");
                String k_ad = result.getString("kullanici_adi");
                this.kullaniciDizisi.add(new Kullanici.KullaniciBuilder().ad(k_ad).sifre(password).build());
            }
        } catch (SQLException var9) {
            Logger.getLogger(VeriTabani.class.getName()).log(Level.SEVERE, (String)null, var9);
        }

        return this.kullaniciDizisi;
    }

}
