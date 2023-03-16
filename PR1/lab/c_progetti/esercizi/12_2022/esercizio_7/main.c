/* Esercizio 06/12/2022 n° 4
 *
 * Testo:
 * "Scrivere una procedura che stampi il contenuto di un vettore senza usare indici."
 */
#include <stdio.h>

// macro
#define DIM 4

// dichiarazione subroutine
void stampa(int l1, int v1[l1]);


// entry point
int main() {
    // dichiarazione variabili
    int v1[DIM] = {1, 2, 3, 4};

    // invocazione subroutine
    stampa(DIM, v1);

    // exit point
    return 0;
}


// definizione subroutine
/**
 * Stampa gli elementi di v1 usando i puntatori.
 * @param l1 La lunghezza di v1.
 * @param v1 Il vettore v1.
 */
void stampa(int l1, int v1[l1]) {
    for(int i = 0; i < l1; i++, v1++)
        printf("%d ", *v1);
}