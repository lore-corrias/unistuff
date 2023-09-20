#include <stdio.h>

/* Esercizio 21/20/2022 n° 2
 *
 * Testo:
 * "Calcolare il numero di cifre che compongono un numero intero inserito dall'utente."
*/

// entry point
int main() {
    // dichiarazione variabili
    int numero, cifre = 0;

    // lettura del numero da tastiera
    printf("Inserisci un numero intero: ");
    scanf("%d", &numero);

    // conteggio del numero di cifre
    do { // il do serve per includere l'eventualità in cui il numero inserito sia == 0 (che ha comunque 1 cifra)
        // a ogni ciclo, dividi il numero per 10 e aumenta il numero di cifre. Quando il numero è == 0, non è più possibile dividere il numero e quindi le cifre sono terminate
        ++cifre;
        numero /= 10;
    }
    while(numero != 0);

    // stampa il risultato
    printf("Il numero inserito ha %d cifre.", cifre);

    // exit point
    return 0;
}
