/* Esercizio 13/12/2022 n° 1
 *
 * Testo:
 * "Scrivere una funzione che, ricevuto come parametro un numero di gradi Celsius,
 * lo trasformi in Fahrenheit secondo la formula F=(C*1.8) + 32.
 * Utilizzare solamente variabili allocate dinamicamente.
*/
#include <stdio.h>
#include <stdlib.h>

// dichiarazioni subroutine
void fahrenheit(float *);

// entry point
int main() {
    // dichiarazione variabili
    float *gradi = NULL; // puntatore a una variabile float contenente i gradi in celsius+

    // allocazione dinamica
    gradi = (float *) malloc(sizeof(float));

    // lettura dell'input
    if(gradi != NULL) { // controllo che la memoria sia stata riservata
        printf("Inserisci il numero di gradi celsius: ");
        scanf("%f", gradi);

        // conversione
        fahrenheit(gradi);

        // stampa
        printf("\nGradi in Fahrenheit: %.2f", (*gradi));
    } else {
        printf("Impossibile allocare lo spazio per le variabili.");
        exit(-1);
    }

    // liberazione dello spazio in memoria
    free(gradi);

    // exit point
    return 0;
}


// definizioni subroutine
/**
 * Dato un puntatore a un numero di gradi in Celsius, lo converte in Fahrenheit.
 * La funzione non restituisce nessun valore in quanto opera direttamente sul puntatore fornito.
 * @param celsius Il puntatore alla variabile contenente il numero di gradi in celsius, da convertire.
 */
void fahrenheit(float *celsius) {
    (*celsius) = (*celsius) * 1.8 + 32;
}