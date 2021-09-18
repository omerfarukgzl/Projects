
public class SicaklikAlgilaCelvin extends AkilliCihaz implements ISıcaklikAlgila {
	
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
            int sicaklik = this.getSicaklik()+273;
            
            System.out.println("Sıcaklık: " + sicaklik+ " Kelvin ");
        } else {
            System.out.println("Soğutucu kapalı olduğu için bu işlem gerçekleşemiyor.\n");
        }
	}

}
