#include <stdio.h>
#define TOTALE_VOTI 3 // macro con il numero totale di voti dello studente

/* Esercizio 11/10/2022 n° 2
 *
 * Testo:
 * "Calcolare la media aritmetica di tre voti di uno studente e stampare il risultato a schermo
 * Specifiche: i tre voti devono essere interi, mentre la media è un numero reale
 * Suggerimento: utilizzare opportunamente il cast esplicito per risolvere eventuali anomalie"
 */

// entry point
int main() {
    // dichiarazione e assegnazione delle variabili contenenti i voti
    int voto1 = 27, voto2 = 22, voto3 = 19;
    // calcolo della media
    float media = (float)(voto1 + voto2 + voto3) / TOTALE_VOTI;

    // stampa il risultato
    printf("La media dei voti è: %.2f", media);

    // exit point
    return 0;
}
