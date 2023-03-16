#include <stdio.h>
#include <stdlib.h>
#include <time.h> // librerie generazione randomica
#define N_TOT 20 // dimensione dell'array e numero totale di numeri da generare
#define MAX_RAND 50
#define MIN_RAND 0 // intervallo generazione randomica

/* Esercizio 28/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che generi una serie di N numeri casuali all'interno di un array.
 * Dopodiché stampare in output tutti gli elementi in ordine inverso."
*/

// entry point
int main() {
    // dichiarazione array, variabile contatore del for
    int numeriCasuali[N_TOT], i;

    srand(time(NULL)); // inizializzazione del seme

    // generazione dei numeri e assegnazione agli elementi
    for(i = 0; i < N_TOT; i++) { // eseguo per "N_TOT" volte
        numeriCasuali[i] = MIN_RAND + rand() % (MAX_RAND - MIN_RAND + 1); // assegnazione all'elemento "i" dell'array un numero random
    }

    // stampa degli elementi in ordine inverso
    for(i = N_TOT - 1; i >= 0; i--) { // parto da N_TOT - 1, che è l'indice dell'ultimo elemento e torno indietro
        printf("Elemento numero %d: %d.\n", i + 1, numeriCasuali[i]);
    }

    // exit point
    return 0;
}
