#include <stdio.h>
#define N 4 // dimensione dell'array

/* Esercizio 28/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma in cui si dichiarino due array, A e B.
 * Inizializzare il primo array a piacere e il secondo in modo che
 * contenga gli stessi elementi di A in ordine inverso.
 * Stampare entrambi gli array come verifica della correttezza.
*/

// entry point
int main() {
    // dichiarazione array
    int a[N] = {2, 3, 4, 5}, b[N];

    // assegnazione a b dei valori di a in ordine inverso
    for(int i = N-1, l = 0; i >= 0; i--, l++) {
        b[i] = a[l];
    }

    // stampa di A e B
    printf("Stampa degli elementi di A e B:\n");
    for(int i = 0; i < N; i++) {
        printf("A%d = %d; B%d = %d\n", i+1, a[i], i+1, b[i]);
    }

    // exit point
    return 0;
}
