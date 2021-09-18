
public class Kullanici implements IObserver{

	     private String  password;
	     private String kullaniciAdi;
	    
	    public Kullanici(KullaniciBuilder builder){
	        this.kullaniciAdi = builder.k_adi;
	        this.password = builder.sifre_;
	    }
	    
	    
		   public String getKullaniciAdi() {
		        return this.kullaniciAdi;
		    }

		    public String getPassword() {
		        return this.password;
		    }

	    public static class KullaniciBuilder{
	        private String k_adi;
	        private String sifre_;
	        
	        public KullaniciBuilder(){
	        	this.k_adi = " ";
	        	this.sifre_ = " ";
	        }

	        public KullaniciBuilder ad(String kAdi){
	            this.k_adi = kAdi;
	            return this;
	        }

	        public KullaniciBuilder sifre (String sif){
	            this.sifre_ = sif;
	            return this;
	        }

	        public Kullanici build(){
	            return new Kullanici(this);
	        }



	    }
	    public boolean yetkili_mi(VeriTabani veritabanı, String K_ADİ, String PAROLA) {
	        boolean durum = false;
	        String dönüs_isim = veritabanı.signIN_manager(K_ADİ, PAROLA);
	        if (kullaniciAdi.equals(dönüs_isim)) {
	            durum = true;
	        } else {
	            durum = false;
	        }

	        return durum;
	    }

	    public void islemi_yap(AgArayuzu agarayuzu, String islem_no) {
	        agarayuzu.islemi_yap(islem_no, kullaniciAdi);
	    }
	    
     @Override
	    public void Update(boolean durum) {
	        if (durum) {
	            System.out.println("Hey " + kullaniciAdi + " soğutucu açıldı");
	        } else {
	            System.out.println("Hey " + kullaniciAdi + " soğutucu kapandı");
	        }
	    }

}