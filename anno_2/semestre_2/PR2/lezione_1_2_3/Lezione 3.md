## Generale
La sintassi generale di Java è riassumibile nel file di esempio `Libro.java` presente in questa stessa directory.
## Compilazione
Per compilare un programma in Java, è sufficiente scrivere su linea di comando:
```bash
javac Programma.java
```
e per eseguire
```bash
java Programma
```
dove "`Libro`" è il nome della classe contenente il main.
## Visibilità: `public`, `protected` e `private`
Nel codice di esempio, dato che l'attributo `paginaCorrente` è modificabile liberamente da qualunque classe, non è possibile implementare un controllo per verificare, per esempio, che il numero di pagina corrente non sia negativo, o non sia superiore al numero di pagine del libro.
Per evitare questi problemi, possiamo limitare la visibilità dell'attributo `paginaCorrente` in `private`: in questo modo, l'attributo è modificabile solo all'interno della stessa classe in cui è definito.
## Incapsulamento
Il concetto di visibilità permette di introdurre quello di `incapsulamento`: "incapsulare" una variabile significa limitarne la visibilità per fare in modo che non sia modificabile **direttamente**, ma solo attraverso la chiamata a un altro metodo che, prima di procedere alla modifica, permette di effettuare delle verifiche sul valore fornito, per evitare bug o altri problemi. Nell'esempio di `paginaCorrente`, aggiungiamo un metodo alla classe `Libro` per evitare che la pagina corrente assuma un valore insensato:
```java
public void cambiaPaginaCorrente(int paginaCorrente) {
	// verifica che la pagina sia valida
	if(paginaCorrente < 0 || paginaCorrente > nPagine) {
		System.out.println("La pagina corrente non è valida!");
	} else {
		this.paginaCorrente = paginaCorrente;
	}
}
```
Ovviamente, dato che ora l'attributo è privato, abbiamo bisogno di un metodo anche per accedervi:
```java
// Metodo che restituisce la pagina corrente
public int prendiPaginaCorrente() {
	return this.paginaCorrente;
}
```