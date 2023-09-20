/* Esercizio 18/12/2022 n° 6
 *
 * Testo:
 * "Scrivere una funziona creaMatriceDinamica che riceva due interi R, C,
 * in ingresso rappresentanti il numero di righe e il numero di colonne,
 * e restituisca una matrice RxC allocata dinamicamente.
 *
 * Scrivere un programma che crei dinamicamente una matrice usando la funzione dell'esercizio 9,
 * la popoli casualmente e la stampi in output"
 */
#include <stdio.h>
// librerie
#include <stdlib.h>
#include <time.h>
// macro
#define MIN 10
#define MAX 40

// dichiarazioni subroutine
int ** creaMatriceDinamica(int, int);
int generaNumeroCasuale(int, int);
void popolaMatrice(int r, int c, int**, int, int);

int main() {
    int r, c; // dimensioni matrice
    int **matrice; // matrice da popolare

    srand(time(NULL)); // generazione seed

    // lettura da terminale
    printf("Inserisci il numero di righe della matrice: ");
    scanf("%d", &r);
    printf("\nInserisci il numero di colonne della matrice: ");
    scanf("%d", &c);

    // invoca subroutine
    matrice = creaMatriceDinamica(r, c);
    popolaMatrice(r, c, matrice, MIN, MAX);

    // stampa
    for(int i = 0; i < r; i++) {
        for(int k = 0; k < c; k++)
            printf("%d ", matrice[i][k]);
        printf("\n");
    }

    // deallocazione memoria
    free(matrice);

    return 0;
}


// definizione subroutine

void popolaMatrice(int r, int c, int **matrice, int min, int max) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            matrice[i][j] = generaNumeroCasuale(min, max);
}

int generaNumeroCasuale(int min, int max) {
    return min + rand() % (max - min + 1);
}

/**
 * Restituisce una matrice di interi allocata
 * dinamicamente, di dimensione RxC.
 * @param r Il numero di righe della matrice.
 * @param c Il numero di colonne della matrice.
 * @return Un puntatore alla prima riga della matrice.
 */
int ** creaMatriceDinamica(int r, int c) {
    int **matrice = NULL;
    matrice = (int **) calloc(r, sizeof(int *));

    if(matrice == NULL) {
        printf("Impossibile allocare sufficiente memoria.");
        exit(-1);
    }

    for(int i = 0; i < c; i++)
        matrice[i] = (int *) malloc(sizeof(int));
    return matrice;
}