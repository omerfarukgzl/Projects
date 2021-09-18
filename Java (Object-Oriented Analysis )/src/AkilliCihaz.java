import java.util.Random;

public class AkilliCihaz {
	
	   private int sicaklik;
	    private static boolean durum;
	    private Random rnd;

	    public AkilliCihaz() {
	        this.setSicaklik();
	        durum = false;
	    }

	    public int getSicaklik() {
	        return this.sicaklik;
	    }

	    public void setSicaklik() {
	        this.rnd = new Random();
	        this.sicaklik = -10 + this.rnd.nextInt(20);
	    }

	    public boolean isDurum() {
	        return durum;
	    }

	    public void setDurum(boolean durum) {
	        AkilliCihaz.durum = durum;
	    }

}
