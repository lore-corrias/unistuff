/* Esercitazione 4
	Crea una classe Autonoleggio per gestire il noleggio delle auto create precedentemente.
	Tramite questa classe deve essere possibile aggiungere nuove auto se queste sono disponibili.
	Deve essere inoltre presente un metodo per la visualizzazione dei valori degli attributi di tutte le Auto presenti nell’Autonoleggio in quel momento
*/

public class Autonoleggio {
	private Auto[] auto = new Auto[100];
	private int numeroAuto;
	
	public void aggiungiAuto(Auto auto) {
		if(auto.getDisponibilita()) {
			this.auto[numeroAuto] = auto;
			numeroAuto++;
		} else {
			System.out.println("La " + auto.getMarca() + " " + auto.getModello() + " non è disponibile!");
		}
	}
	
	public void noleggiaAuto(int numeroAuto) {
		if(numeroAuto < 0 || numeroAuto >= this.numeroAuto) {
			System.out.println("L'auto " + numeroAuto + " non esiste!");
		} else if(!auto[numeroAuto].getDisponibilita()) {
			System.out.println("L'auto " + numeroAuto + " non è disponibile!");
		} else {
			auto[numeroAuto].setDisponibilita(false);
			System.out.println("Hai noleggiato una " + auto[numeroAuto].getMarca() + " " + auto[numeroAuto].getModello() + "!");
		}
	}
	
	public void restituisciAuto(int numeroAuto, int kilometriPercorsi) {
		if(numeroAuto < 0 || numeroAuto >= this.numeroAuto) {
			System.out.println("L'auto " + numeroAuto + " non esiste!");
		} else if(auto[numeroAuto].getDisponibilita()) {
			System.out.println("L'auto " + numeroAuto + " non è stata noleggiata!");
		} else {
			auto[numeroAuto].setDisponibilita(true);
			auto[numeroAuto].setKilometriPercorsi(auto[numeroAuto].getKilometriPercorsi() + kilometriPercorsi);
			System.out.println("Hai restituito una " + auto[numeroAuto].getMarca() + " " + auto[numeroAuto].getModello()
			+ "! Kilometri percorsi attuali: " + auto[numeroAuto].getKilometriPercorsi());
		}
	}
	
	public void stampaAutoKilometriMaggiori() {
		int autoMaggiore = 0;
		
		if(numeroAuto == 0) {
			System.out.println("Nessuna auto con il maggior numero di kilometri percorsi, l'autonoleggio è vuoto.");
		} else {
			for(int i = 0; i < numeroAuto; i++) {
				if(auto[i].getKilometriPercorsi() > auto[autoMaggiore].getKilometriPercorsi()) {
					autoMaggiore = i;
				}
			}
		}
		
		System.out.println("L'auto con il numero maggiore di kilometri percorsi è:");
		visualizzaAuto(auto[autoMaggiore]);
	}
	
	public void stampaAutoKilometriMinori() {
		int autoMinore = 0;
		
		if(numeroAuto == 0) {
			System.out.println("Nessuna auto con il minor numero di kilometri percorsi, l'autonoleggio è vuoto.");
		} else {
			for(int i = 0; i < numeroAuto; i++) {
				if(auto[i].getKilometriPercorsi() < auto[autoMinore].getKilometriPercorsi()) {
					autoMinore = i;
				}
			}
		}
		
		System.out.println("L'auto con il numero minore di kilometri percorsi è:");
		visualizzaAuto(auto[autoMinore]);
	}
	
	public void stampaMediaKilometri() {
		int sommaKilometri = 0;
		int media = 0;
		
		for(int i = 0; i < numeroAuto; i++) {
			sommaKilometri += auto[i].getKilometriPercorsi();
		}
		media = sommaKilometri / numeroAuto;
		
		System.out.println("La media di kilometri percorsi è: " + media);
	}
	
	public void visualizzaAuto(Auto auto) {
		System.out.println("\tModello: " + auto.getModello());
		System.out.println("\tMarca: " + auto.getMarca());
		System.out.println("\tCosto al giorno: " + auto.getCostoAlGiorno());
		System.out.println("\tKilometri percorsi: " + auto.getKilometriPercorsi());
	}
	
	public void visualizzaListaAuto() {
		if(numeroAuto == 0) {
			System.out.println("Nessuna auto presente!");
		} else {
			for(int i = 0; i < numeroAuto; i++) {
				System.out.println("Auto n° " + (i+1) + ":");
				visualizzaAuto(auto[i]);			
			}
		}
	}
	
	public static void main(String[] args) {
		Auto auto1 = new Auto();
		Auto auto2 = new Auto();
		Auto auto3 = new Auto();
		Auto auto4 = new Auto();
		
		Autonoleggio autonoleggio = new Autonoleggio();
		
		auto1.setModello("Alfa Romeo");
		auto1.setMarca("Fiat");
		auto1.setCostoAlGiorno(50f);
		auto1.setDisponibilita(true);
		
		auto2.setModello("C4");
		auto2.setMarca("Citroen");
		auto2.setCostoAlGiorno(20f);
		auto2.setDisponibilita(false);
		
      auto3.setModello("911");
      auto3.setMarca("Porsche");
      auto3.setCostoAlGiorno(30f);
      auto3.setDisponibilita(true);

      auto4.setModello("Civic");
      auto4.setMarca("Honda");
      auto4.setCostoAlGiorno(40f);
      auto4.setDisponibilita(true);
      
		autonoleggio.aggiungiAuto(auto1);
		autonoleggio.aggiungiAuto(auto2);
      autonoleggio.aggiungiAuto(auto3);
		autonoleggio.aggiungiAuto(auto4);
		
		autonoleggio.noleggiaAuto(-1);
		autonoleggio.noleggiaAuto(0);
		autonoleggio.restituisciAuto(0, 100);
		autonoleggio.restituisciAuto(1, 100);
		
		autonoleggio.noleggiaAuto(1);
		autonoleggio.restituisciAuto(1, 200);
		autonoleggio.noleggiaAuto(1);
		autonoleggio.restituisciAuto(1, 300);
		
		autonoleggio.noleggiaAuto(2);
		autonoleggio.restituisciAuto(2, 500);
		
		autonoleggio.visualizzaListaAuto();
		autonoleggio.stampaAutoKilometriMaggiori();
		autonoleggio.stampaAutoKilometriMinori();
		autonoleggio.stampaMediaKilometri();
	}
}
