#include <stdio.h>

// librerie per la generazione randomica
#include <stdlib.h>
#include <time.h>

// dimensioni della matrice
#define N 5
#define M 7

// intervalli generazione randomica
#define MIN 5
#define MAX 30

/* Esercizio 08/11/2022
 *
 * Testo:
 * "Scrivere un programma in cui si genera casualmente una matrice NxM a piacere.
 * Dichiarare un array R di N elementi e un array C di M elementi.
 * Il programma deve salvare in R[i] la somma degli elementi della riga i-esima della matrice,
 * e in C[j] la somma degli elementi della colonna j-esima della matrice."
*/

// entry point
int main() {
    // dichiarazione matrice e array
    int matrice[N][M], array_r[N] = {}, array_c[M] = {};
    // contatori per i cicli for
    int i, j;

    srand(time(NULL)); // inizializzazione del seed

    // inizializzazione matrice
    printf("Matrice:\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            matrice[i][j] = MIN + rand() % (MAX - MIN + 1);
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    // calcolo e stampa degli elementi di array_r
    printf("\nArray 'R':\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            array_r[i] += matrice[i][j];
        }
        printf("%d\t", array_r[i]); // stampa
    }

    // calcolo degli elementi di array_c
    printf("\n\nArray 'C':\n");
    for(j = 0; j < M; j++) {
        for(i = 0; i < N; i++) {
            array_c[j] += matrice[i][j];
        }
        printf("%d\t", array_c[j]); // stampa
    }

    // exit point
    return 0;
}
