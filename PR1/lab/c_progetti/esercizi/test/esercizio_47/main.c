#include <stdio.h>
#define DIMENSIONE 10

/* Esercizio 31/10/2022 n° 4
 *
 * Testo:
 * "Scrivere un programma in cui si dichiara e inizializza un array A, quindi stamparlo.
 * Senza utilizzare altri array d'appoggio, invertire l'ordine degli elementi di A e ristampare il vettore così modificato."
*/

// entry point
int main() {
    // inizializzazione array
    int vettore[DIMENSIONE] = {2, 5, 7, 10, 15, 18, 21, 25, 29, 31};
    int vettoreTmp;

    // stampa dell'array
    printf("Valori dell'array:\n");
    for(int i = 0; i < DIMENSIONE; i++) {
        printf("%d\n", vettore[i]);
    }

    // inversione dell'array
    for(int i = 0; i <= DIMENSIONE/2; i++) {
        // scorro l'array fino a metà, scambiando i valori speculari durante lo scorrimento
        vettoreTmp = vettore[(DIMENSIONE - 1) - i]; // valore speculare a quello di i (e.s. i = 0, valore = 9)
        vettore[(DIMENSIONE - 1) - i] = vettore[i]; // assegno all'ultimo valore il primo, al penultimo il secondo and so on
        vettore[i] = vettoreTmp; // assegno al primo valore l'ultimo, al secondo il penultimo and so on
    }

    // stampa dell'array invertito
    printf("Valori dell'array invertiti:\n");
    for(int i = 0; i < DIMENSIONE; i++) {
        printf("%d\n", vettore[i]);
    }

    // exit point
    return 0;
}
