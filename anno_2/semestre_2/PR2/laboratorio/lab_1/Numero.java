/* Esercizio 1 - Lorenzo Corrias:

	Crea una classe Numero che ha un numero intero ‘n’ come attributo.
	
	Creare poi un metodo somma che prende un altro numero e lo
	somma al nostro attributo.
	
	Creare infine un metodo aggiungi che aggiunge al valore di ‘n’ il
	valore di un altro numero
*/


public class Numero {

	private int n;

	public static void main(String[] args) {
		// main vuoto
	}
	
	public int somma(int a) {
		return a + n;
	}
	
	public void aggiungi(int a) {
		this.n += a;
	}
}
