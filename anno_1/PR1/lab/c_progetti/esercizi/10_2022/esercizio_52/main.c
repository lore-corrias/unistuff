#include <stdio.h>

// librerie per la generazione randomica
#include <stdlib.h>
#include <time.h>

// estremi intervallo di generazione
#define MIN 0
#define MAX 100

// dimensione matrice multidimensionale
#define N_RIGHE 5
#define M_COLONNE 5

/* Eserczio 08/11/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che stampi il contenuto di una matrice di interi,
 * generati in maniera casuale nell’intervallo [0, 100]."
*/

// entry point
int main() {
    // dichiarazione matrice
    int matrice[N_RIGHE][M_COLONNE];
    // dichiarazione contatori per i cicli for
    int i = 0, j = 0;

    srand(time(NULL)); // inizializzazione seed

    // inizializzazione degli elementi della matrice
    for(i = 0; i < N_RIGHE; i++) {
        for(j = 0; j < M_COLONNE; j++) {
            matrice[i][j] = MIN + rand() % (MAX - MIN + 1); // generazione randomica e assegnamento
        }
    }

    // stampa a schermo degli elementi della matrice
    printf("Matrice generata:\n");
    for(i = 0; i < N_RIGHE; i++) {
        for(j = 0; j < M_COLONNE; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    // exit point
    return 0;
}