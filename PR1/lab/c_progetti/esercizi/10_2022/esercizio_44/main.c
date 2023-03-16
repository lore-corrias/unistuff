#include <stdio.h>
#define DIMENSIONE 7 // dimensione dell'array

/* Esercizio 31/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma in cui, dato un insieme di valori in un array, si calcoli
 * la media dei valori e vengano stampati in output tutti i valori minori della media,
 * tutti i valori maggiori della media e la media stessa.
 * Infine, stampare quanti sono i valori minori della media e quanti i valori maggiori.
*/

// entry point
int main() {
    // dichiarazione e inizializzazione dell'array e delle variabili
    float valori[DIMENSIONE] = {6, 84, 15, 24, 33, 55, 79}, media;
    float somma = 0; // variabile da utilizzare come somma nel calcolo della media
    int valoriMinori = 0, valoriMaggiori = 0; // contatori dei valori maggiori e minori della media

    // calcolo della media
    for(int i = 0; i < DIMENSIONE; i++) {
        somma+= valori[i];
    }
    media = somma / DIMENSIONE;

    // stampa della media
    printf("Media dei valori; %.2f.\n", media);
    // stampa dei valori maggiori della media
    printf("Valori superiori alla media:\n");
    for(int i = 0; i < DIMENSIONE; i++) {
        if (valori[i] > media) {
            printf("* %.0f\n", valori[i]);
            valoriMaggiori++;
        }
    }
    printf("Numero dei valori maggiori: %d.\n", valoriMaggiori);
    // stampa dei valori minori della media
    printf("Valori inferiori alla media:\n");
    for(int i = 0; i < DIMENSIONE; i++) {
        if (valori[i] < media) {
            printf("* %.0f\n", valori[i]);
            valoriMinori++;
        }
    }
    printf("Numero dei valori minori: %d.\n", valoriMinori);

    // exit point
    return 0;
}