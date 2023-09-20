#include <stdio.h>
// macro
// intervallo
#define MIN 10
#define MAX 30

/* Esercizio 24/11/2022 n° 2
 *
 * Testo:
 * "Scrivere una funzione che esegua l'acquisizione da input di un numero e il controllo che
 * il numero si trovi all'interno di un determinato intervallo (min, max), mediante l'acquisizione ripetuta del numero.
 * La funzione deve restituire sempre un valore compreso tra min e max. Stampare tale numero nel main."
 */

// dichiarazione subroutine
int intervallo(int, int);


// entry point
int main() {
    // invocazione di intervallo() con parametri arbitrari e stampa del risultato
    printf("%d", intervallo(MIN, MAX));

    // exit point
    return 0;
}

// definizione subroutine
int intervallo(int min, int max) {
    int n_input; // dichiarazione variabile di input

    // lettura da terminale finché la variabile non è all'interno del range
    do {
        printf("Inserisci un numero: ");
        scanf("%d", &n_input);
    } while(n_input < min || n_input > max);
    return n_input; // restituzione della variabile nel range
}