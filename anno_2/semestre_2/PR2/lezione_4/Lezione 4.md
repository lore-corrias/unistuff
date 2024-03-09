## I Tipi
In Java i tipi sono divisi in **primitivi** e **non primitivi**: se iniziano in maiuscolo, come String, sono **non primitivi**.

Ogni tipo ha delle operazioni associate: per esempio, `int` ha quelle aritmetiche, `String` quella di concatenazione, eccetera.
```java
// tipi non primitivi
String greeting = "Hello, World!";
PrintStream printer = System.out;

// tipo primitivo
int width = 25;
```

I tipi primitivi di Java sono:

| Nome      | Dimensione       | Esempio/Range         | Categoria                  |
| --------- | ---------------- | --------------------- | -------------------------- |
| `Boolean` | $1 \text{ bit}$  | $false$               | _booleani_                 |
| `Char`    | $16 \text{ bit}$ | `'a'`                 | _char_                     |
| `Byte`    | $8 \text{ bit}$  | $[-128, 127]$         | _tipi aritmetici interi_   |
| `Short`   | $16 \text{ bit}$ | $[-32.768, 32.767]$   | _tipi aritmetici interi_   |
| `Int`     | $32 \text{ bit}$ | $[2^{-31},2^{-31}-1]$ | _tipi aritmetici interi_   |
| `Long`    | $64 \text{ bit}$ | $[2^{-63},2^{-63}-1]$ | _tipi aritmetici interi_   |
| `Float`   | $32 \text{ bit}$ | $0.0f$                | _tipi aritmetici decimali_ |
| `Double`  | $64 \text{ bit}$ | $0.0d$                | _tipi aritmetici decimali_ |
_Nota: la differenza tra `float` e `double` sta nella precisione delle cifre decimali, e quindi nel numero totale di cifre significative che la variabile può contenere, che per `double` è doppio rispetto a quello di float_

## Variabili
In Java, le variabili devono essere definite specificandone il **tipo** obbligatoriamente:
```
[tipo] [identificatore] (= valore);
```
La definizione di una variabile può avvenire contemporaneamente o meno alla sua definizione. Per l'assegnazione, si usa l`=`:
```java
int i; // dichiarazione
i = 5; // definizione
int i = 5; // definizione e dichiarazione
```
Le regole per il nome dell'identificatore di una variabile sono:
* Non iniziare con un numero
* Non contenere caratteri speciali o spazi (eccetto il \_)
* Non possono essere parole riservate (e.s.: `class`)
Generalmente si usa lo stile **camelCase**, niente $\$$.
## Oggetti
Gli oggetti sono le istanze delle classi. Per fare un paragone con il mondo reale, considerando la classe di animali "_Cane_", l'oggetto della classe cane è un cane specifico, con tutte le sue caratteristiche individuali (tipo colore del pelo, età, ecc.)
Ogni classe possiede delle _proprietà_, che sono anche dette attributi (per mantenere l'analogia, sono il colore del pelo e le caratteristiche elencate sopra). Sono come delle variabili, ma sono specifici all'istanza di un classe, quindi di un oggetto.
Un oggetto è istanziato attraverso la keyword `new`:
```java
Rectangle rettangoloPiccolo = new Rectangle(0,0,10,20);

rettangoloPiccolo.calcolaArea();
```
### Metodi
I metodi sono come delle funzioni, ma sono specifiche di una classe.
```java
String greeting = "Hello"
greeting.length(); // metodo della classe string
greeting.println(); // errore: la classe string non ha un metodo println
```
Java permette l'**overloading di un metodo**, ossia di avere due metodi con lo stesso nome, ma con diversi parametri:
```java
public class Cane {
	public void mangiaCrocchette() {
		// corpo del metodo
	}
	
	public void mangiaCrocchette(int numeroCrocchette) {
		// corpo del metodo
	}
}
```
Il **costruttore** è un metodo particolare di una classe. Esso viene chiamato quando l'oggetto viene istanziato, e il suo scopo è quello di effettuare delle azioni alla sua creazione, solitamente impostare degli attributi. La sintassi per chiamare un costruttore fa uso di `new`:
```java
Rettangolo r = new Rettangolo(0, 0, 10, 20);
```
Mentre viene definito all'interno della classe come un metodo normale, ma che ha **lo stesso nome della classe stessa**:
```java
public class Rettangolo {
	int x;
	int y;
	int base;
	int altezza;
	
	Rettangolo(int x, int y, int base, int altezza) {
		// x = x genera un errore, dobbiamo usare la keyword
		// "this" per dire che ci stiamo riferendo
		// all'attributo dell'oggetto e non al parametro
		this.x = x;
		this.y = y;
		this.base = base;
		this.altezza = altezza;
	}
}
```
In questo modo, usiamo il costruttore per fornire al nostro oggetto `r` della classe `Rettangolo` dei valori per la base, l'altezza e la sua posizione.
_Nota: esiste sempre un costruttore di default che viene aggiunto dal compilatore in automatico, che non prende nessun parametro e non esegue alcuna azione. Quindi, quando assegniamo un oggetto a una variabile, stiamo sempre chiamando un costruttore. Senza aver prima eseguito il costruttore, infatti, è impossibile accedere agli attributi o ai metodi di una variabile:_
```java
Rettangolo r;
System.out.println(r.x); // genera una NullPointerException, r vale "Null"
```
### Garbage Collector
Nell'esempio seguente:
```java
Rectangle r1 = new Rectangle(0,0,10,20);
Rectangle r2 = new Rectangle(0,0,100,400);
r2 = r1;
r2.calcolaArea(); //calcola area di r1
```
stiamo istanziando $2$ oggetti della classe `Rectangle`, tuttavia tramite l'assegnamento `r2=r1` il riferimento all'oggetto `Rectangle(0,0,100,400)` è perso, quindi non possiamo più accedervi. Quando ciò succede, per evitare che l'oggetto resti inutilmente in memoria, Java attiva il suo **Garbage Collector**, che elimina dalla memoria i riferimenti agli oggetti che non sono più utilizzabili.