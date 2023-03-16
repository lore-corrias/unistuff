#include <stdio.h>
// macro
#define DIMENSIONE 10 // dimensione dell'array

/* Esercizio 24/11/2022 n° 6
 *
 * Testo:
 * "Scrivere una procedura che prenda come parametro un array di interi e ne stampi il suo contenuto.
 * Richiamare tale procedura dal main."
*/

// dichiarazione subroutine
void printArray(int, int[]);


// entry point
int main() {
    // dichiarazione variabili
    int array[DIMENSIONE] = {1,2,3,4,5,6,7,8,9,10}; // array da passare alla subroutine

    // chiamata della subroutine
    printf("Array stampato:\n");
    printArray(DIMENSIONE, array);

    // exit point
    return 0;
}

// definizione subroutine
/**
 * Stampa il contenuto di un array di interi
 *
 * @param n la dimensione dell'array
 * @param array l'array da stampare
 */
void printArray(int n, int array[]) {
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);
}