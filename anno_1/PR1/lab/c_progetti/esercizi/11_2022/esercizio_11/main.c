#include <stdio.h>
// librerie
#include <stdlib.h>
#include <time.h> // generazione randomica
// macro
#define MIN 1
#define MAX 100 // intervalli generazione randomica
// dimensioni matrice
#define RIGHE 6
#define COLONNE 8

/* Esercitazione 24/11/2022 n° 7
 *
 * Testo:
 * "Scrivere una procedura che riceva come parametro una matrice di interi
 * e generi casualmente i suoi elementi in un range 1 – 100.
 * Anche righe e colonne vanno generate casualmente.
 * Richiamare tale procedura dal main."
*/

// definizione subroutine
/**
 * Genera randomicamente un numero tra MIN e MAX per
 * ogni elemento di una matrice NxM data.
 *
 * @param n numero di righe della matrice
 * @param m numero di colonne della matrice
 * @param matrice la matrice
 */
void generaMatrice(int n, int m, int matrice[n][m]) {
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < m; k++)
            matrice[i][k] = MIN + rand() % (MAX - MIN + 1); // generazione randomica e assegnamento
    }
}


// entry point
int main() {
    // dichiarazioni e assegnazioni
    int matrice[RIGHE][COLONNE]; // matrice da generare

    srand(time(NULL)); // inizializzazione seed

    // chiamata subroutine
    generaMatrice(RIGHE, COLONNE, matrice);

    // stampa matrice
    printf("Matrice %dx%d generata:\n", RIGHE, COLONNE);
    for(int i = 0; i < RIGHE; i++) {
        for(int k = 0; k < COLONNE; k++) {
            printf("%d\t", matrice[i][k]);
        }
        printf("\n");
    }

    // exit point
    return 0;
}