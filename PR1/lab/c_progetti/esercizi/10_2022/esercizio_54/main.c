#include <stdio.h>

// dimensioni della matrice
#define RIGHE 4
#define COLONNE 4

/* Esercizio 08/11/2022 n° 3
 *
 * Testo:
 * "Generare una matrice identità (1 sulla diagonale principale, i restanti valori a 0) utilizzando un solo ciclo for."
*/

// entry point
int main() {
    // dichiarazione matrice
    int matrice[RIGHE][COLONNE] = {};
    // contatori ciclo for
    int i, j;

    // inizializzazione della matrice
    for(i = 0; i < RIGHE; i++) {
        matrice[i][i] = 1; // sostituzione dei valori nella diagonale con "1"
    }

    // stampa della matrice
    printf("Matrice:\n");
    for(i = 0; i < RIGHE; i++) {
        for(j = 0; j < COLONNE; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    // exit point
    return 0;
}

