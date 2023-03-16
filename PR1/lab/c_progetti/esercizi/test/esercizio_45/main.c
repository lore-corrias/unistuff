#include <stdio.h>
#define MAX 1
#define MIN 20 // massimo e minimo dell'intervallo
#define DIMENSIONE 7 // dimensione dell'array

/* Esercizio 31/10/2022 n° 2
 *
 * Testo:
 * Scrivere un programma in cui si dichiari e inizializzi a piacimento un array A, quindi normalizzarlo.
 * Stampare l'array prima e dopo la normalizzazione.
 *
 * Hint: normalizzare un intervallo vuol dire portare tutti gli elementi dell’intervallo ad avere valori
 * compresi tra 0 e 1, secondo la formula x_norm = (x − min)/(max − min).
*/

// entry point
int main() {
    // dichiarazione e inizializzazione array
    int intervallo[DIMENSIONE] = {4, 6, 19, 12, 15, 18, 7};
    float intervalloNormalizzato[DIMENSIONE];

    // stampa dell'array
    printf("Elementi dell'array originale:\n");
    for(int i = 0; i < DIMENSIONE; i++) {
        printf("%d\n", intervallo[i]);
    }

    // normalizzazione e stampa
    printf("Elementi dell'array normalizzato tra i numeri %d e %d:\n", MAX, MIN);
    for(int i = 0; i < DIMENSIONE; i++) {
        intervalloNormalizzato[i] = (float)(intervallo[i] - MIN) / (MAX - MIN); // formula per la normalizzazione
        printf("%.2f\n", intervalloNormalizzato[i]);
    }

    // exit point
    return 0;
}
