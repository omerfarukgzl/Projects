
public class SicaklikAlgilayiciModul extends AkilliCihaz implements ISıcaklikAlgila {
	  protected SicaklikAlgilayiciModul() {
	    }
	@Override
	public void Sicaklik_goruntule() {
		if (this.isDurum()) {
            this.setSicaklik();
            try {
				 System.out.println("Algılanıyor...\n");
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
            System.out.println("Sıcaklık: " + this.getSicaklik() + " Derece ");
        } else {
            System.out.println("Soğutucu kapalı olduğu için bu işlem gerçekleşemiyor.\n");
        }
	}

}
