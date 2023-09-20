/* Esercizio 13/12/2022 n° 2
 *
 * Testo:
 * "Scrivere una funzione "createArray(int n, int initialValue)" che allochi dinamicamente un array di n elementi
 * inizializzati a initialValue, e restituisca il puntatore al primo elemento dell'array."
 */
#include <stdio.h>
#include <stdlib.h>


// dichiarazioni subroutine
int * createArray(int, int);


int main() {
    // dichiarazione variabili
    int *array = NULL;

    // invocazione subroutine
    array = createArray(5, 9);

    // stampa dell'array
    for(int i = 0; i < 5; i++)
        printf("%d", *(array + i));

    return 0;
}


// definizioni subroutine
int * createArray(int n, int initialValue) {
    int *arr = NULL;
    arr = (int *) calloc(n, sizeof(int)); // allocazione dinamica

    if(arr != NULL) {
        for(int i = 0; i < n; i++) // inizializzazione degli elementi dell'array
            *(arr+i) = initialValue;
    } else {
        printf("Impossibile allocare memoria.");
        exit(-1);
    }

    return arr;
}