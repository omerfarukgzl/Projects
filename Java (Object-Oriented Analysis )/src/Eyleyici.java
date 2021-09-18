
public class Eyleyici extends AkilliCihaz {

	
	public void Sogutucu_kapat() {
		 if (this.isDurum()) {
	            this.setDurum(false);
	            try {
					 System.out.println("Bekelyin..\n");
					Thread.sleep(3000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
	            System.out.println("Soğutucuyu kapandı.\n");
	        } else {
	            System.out.println("Soğutucu zaten kapalı.\n");
	        }
	}

	public void Sogutucu_ac() {
		 if (this.isDurum()) {
	            System.out.println("Soğutucu zaten açık.\n");
	        } else {
	            this.setDurum(true);
	            try {
					 System.out.println("Bekelyin..\n");
					Thread.sleep(3000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
	            System.out.println("Soğutucuyu açıldı.\n");
	        }
	}


	

}
