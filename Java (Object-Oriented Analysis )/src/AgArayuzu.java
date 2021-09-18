import java.util.ArrayList;
import java.util.List;

public class AgArayuzu extends AkilliCihaz implements ISubject{
	
	  private final List<Kullanici> yetkili_kullanicilar = new ArrayList<Kullanici>();
	    public boolean durum_once;
	    public boolean durum_sonra;
	    Eyleyici eyleyiciModul= new Eyleyici();
	    SicaklikAlgilayiciModul sicaklikAlgilayiciModul = new SicaklikAlgilayiciModul();
	    SicaklikAlgilaCelvin sicaklikAlgilaCelvin = new SicaklikAlgilaCelvin();
	    
	    
	    protected AgArayuzu() {

	    }

	    public void islemi_yap(String islem_no, String yapan_kisi) {
	        this.durum_once = this.isDurum();
	        
		      if (null != islem_no) {
		            byte var3 = -1;
		            switch(islem_no.hashCode()) {
		                case 49:
		                    if (islem_no.equals("1")) {
		                        var3 = 0;
		                    }
		                    break;
		                case 50:
		                    if (islem_no.equals("2")) {
		                        var3 = 1;
		                    }
		                    break;
		                case 51:
		                    if (islem_no.equals("3")) {
		                        var3 = 2;
		                    }
		            }

		            switch(var3) {
		                case 0:
		                    eyleyiciModul.Sogutucu_ac();
		                    break;
		                case 1:
		                    eyleyiciModul.Sogutucu_kapat();
		                    break;
		                case 2:
		                    sicaklikAlgilayiciModul.Sicaklik_goruntule();
		                    sicaklikAlgilaCelvin.Sicaklik_goruntule();
		                    
		            }
		      }
		      
	        this.durum_sonra = this.isDurum();
	        if (this.durum_once != this.durum_sonra) {
	            this.bildirim();
	        }

	    }
	    
@Override
	    public void yetki_ver(IObserver o) {
	        this.yetkili_kullanicilar.add((Kullanici) o);
	    }
@Override
	    public void yetki_al(IObserver o) {
	        this.yetkili_kullanicilar.remove(o);
	    }
@Override
	    public void bildirim() {
	        this.yetkili_kullanicilar.forEach((k) -> {
	            k.Update(this.durum_sonra);
	        });
	    }

}
