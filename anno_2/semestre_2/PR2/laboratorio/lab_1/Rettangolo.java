/* Esercizio 2
	Crea la classe Rettangolo le cui istanze (oggetti) abbiano le seguenti caratteristiche e possano eseguire le seguenti azioni:
		• base uguale a 30
		• altezza uguale a 10
		• siano scalabili (ricevuto un fattore di scala)
		• possano stampare a video il proprio stato
*/

public class Rettangolo {
	private int base    = 30;
	private int altezza = 10;
	
	// per testare la classe creata
	public static void main(String[] args) {
		double fattore = 0.5;
		Rettangolo rettangolo = new Rettangolo();
		
		rettangolo.stampaStato();
		System.out.println("Scalo il rettangolo di " + fattore);
		rettangolo.scala(fattore);
		rettangolo.stampaStato();
	}
	
	public void scala(double fattore) {
		base 	  *= fattore;
		altezza *= fattore;
	}

	public void stampaStato() {
		System.out.println("Base del rettangolo: " + base);
		System.out.println("Altezza del rettengolo: " + altezza);
	}
}
