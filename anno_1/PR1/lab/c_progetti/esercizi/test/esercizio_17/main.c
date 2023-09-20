#include <stdio.h>
#include <stdlib.h> // libreria per la funzione rand() e srand()
#include <time.h> // libreria per la funzione time()
#include <math.h> // libreria per la funzione sqrt() e pow()
#define VALORE_CATETO_MINIMO 5
#define VALORE_CATETO_MASSIMO 20 // macro per i valori minimo e massimo per la generazione dei cateti

/* Esercizio 11/10/2022 n° 4
 *
 * Testo:
 * "Scrivere un programma che, conoscendo i valori dei cateti di un triangolo rettangolo,
 * ne calcoli l'ipotenusa."
*/

// entry point
int main() {
    // dichiarazione delle variabili contenenti i valori dei cateti e dell'ipotenusa
    int cateto1, cateto2;
    double ipotenusa;

    // generazione del seed per la funzione rand()
    srand(time(NULL));

    // generazione casuale dei cateti
    cateto1 = VALORE_CATETO_MINIMO + rand() % (VALORE_CATETO_MASSIMO - VALORE_CATETO_MINIMO + 1);
    cateto2 = VALORE_CATETO_MINIMO + rand() % (VALORE_CATETO_MASSIMO - VALORE_CATETO_MINIMO + 1);
    // calcolo ipotenusa
    ipotenusa = sqrt(pow((double) cateto1, 2) + pow((double) cateto2, 2));

    // stampa dei risultati
    printf("Valori dei cateti generati: %d e %d.\n", cateto1, cateto2);
    printf("Valore dell'ipotenusa: %.3lf.\n", ipotenusa);

    // exit point
    return 0;
}