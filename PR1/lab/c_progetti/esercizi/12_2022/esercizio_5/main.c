/* Esercizio 06/11/2022 n° 2
 *
 * Testo:
 * "Scrivere una funzione che controlli se due vettori sono uguali
 * e restituisca true in caso affermativo, false altrimenti"
 */
#include <stdio.h>
#include <stdbool.h> // libreria per il tipo booleano

// macro
#define DIM 4


// dichiarazione subroutine
bool uguali(int l1, int l2, int v1[], int v2[]);


int main() {
    // dichiarazione variabili
    int v1[DIM] = {1, 2, 3, 4}, v2[DIM] = {1, 2, 3, 4}; // vettori da confrontare

    if(uguali(DIM, DIM, v1, v2)) {
        printf("Gli array sono uguali.");
    } else {
        printf("Gli array non sono uguali.");
    }

    return 0;
}


// definizione subroutine
bool uguali(int l1, int l2, int v1[], int v2[]) {
    if(l1 != l2)
        return false;
    int *p1 = v1, *p2 = v2; // puntatori agli array
    // scorrimento degli array tramite i puntatori
    for(int i = 0; i < l1; i++, p1++, p2++) {
        if(*(p1) != *(p2)) // dereferenza dei puntatori agli elementi dei due array
            return false; // se gli elementi nello stesso indice dei due array sono diversi, returna false
    }
    return true; // se non è stato returnato false, gli array sono uguali
}