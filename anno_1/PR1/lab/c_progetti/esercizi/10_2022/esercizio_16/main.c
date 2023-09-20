#include <stdio.h>
#include <stdlib.h> // libreria per le funzioni rand() e srand()
#include <time.h> // libreria per la funzione time()

/* Esercizio 11/10/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma che chieda all'utente min e max di un intervallo.
 * Generare, poi, 3 numeri casuali in quell'intervallo.
 * Stampare, infine, i numeri generati.
*/

// entry point
int main() {
    // dichiarazione delle variabili con i valori min e max
    int min, max;
    // dichiarazione delle variabili con i numeri generati casualmente
    int random1, random2, random3;

    // generazione del seed per i numeri casuali
    srand(time(NULL));

    // lettura da terminale dei valori min e max
    printf("Inserisci il valore minimo del range di generazione dei numeri: ");
    scanf("%d", &min);
    printf("\nInserisci il valore massimo del range di generazione dei numeri: ");
    scanf("%d", &max);

    // generazione dei numeri casuali
    random1 = min + rand() % (max - min + 1);
    random2 = min + rand() % (max - min + 1);
    random3 = min + rand() % (max - min + 1);

    // stampa dei numeri casuali
    printf("Numeri casuali generati: %d, %d, %d", random1, random2, random3);

    // exit point(
    return 0;
}