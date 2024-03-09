/* Esercizio 3:
	• Crea una classe Auto con i seguenti attributi:
		• modello
		• marca
		• Costo al giorno
		• disponibilità
	• Crea i metodi per la modifica dei valori degli attributi
*/

public class Auto {
	private String modello;
	private String marca;
	private float costoAlGiorno;
	private int kilometriPercorsi;
	private boolean disponibilita;
	
	public static void main(String[] args) {
		Auto auto = new Auto();
		
		auto.setModello("500");
		auto.setMarca("Fiat");
		auto.setCostoAlGiorno(-3);
		auto.setCostoAlGiorno(10.0f);
		auto.setDisponibilita(true);
	}
	
	public void setModello(String modello) {
		this.modello = modello;
	}
	
	public void setMarca(String marca) {
		this.marca = marca;
	}
	
	public void setCostoAlGiorno(float costoAlGiorno) {
		if(costoAlGiorno >= 0) {
			this.costoAlGiorno = costoAlGiorno;
		} else {
			System.out.println("Il costo al giorno della macchina deve essere maggiore o uguale a 0!");
		}
	}
	
	public void setDisponibilita(boolean disponibilita) {
		this.disponibilita = disponibilita;
	}
	
	public void setKilometriPercorsi(int kilometriPercorsi) {
		if(kilometriPercorsi >= 0) {
			this.kilometriPercorsi = kilometriPercorsi;
		} else {
			System.out.println("Il numero di kilometri percorsi deve essere maggiore o uguale a 0!");
		}
	}
	
	public String getModello() {
		return modello;
	}
	
	public String getMarca() {
		return marca;
	}
	
	public float getCostoAlGiorno() {
		return costoAlGiorno;
	}
	
	public boolean getDisponibilita() {
		return disponibilita;
	}
	
	public int getKilometriPercorsi() {
		return kilometriPercorsi;
	}
}
