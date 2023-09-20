#include <stdio.h>

/* Esercizio 07/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma per eseguire il prodotto di tre interi.
 * Dichiarare le variabili x, y, z e result di tipo int.
 * Impostare 3 valori rispettivamente uno per x, uno per y e uno per z.
 * Calcolare il prodotto delle tre variabili e assegnare il risultato alla variabile result.
 * Infine, visualizzare: "Il prodotto è __.", dove __ dovrà essere sostituito dal valore di result.
 * Non devono essere presenti magicnumberse si deve commentare opportunatamente tutto il codice."
 */

// entry point
int main() {
    // dichiarazione e assegnazione di x, y, z e result
    int x = 3, y = 6, z = 8;
    int result = x * y * z;

    // stampa del risultato
    printf("Il prodotto è %d.", result);

    // exit point
    return 0;
}
