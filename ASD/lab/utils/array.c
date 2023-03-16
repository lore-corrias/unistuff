//
// Created by just on 16/03/23.
//
#include "array.h"

/**
 * Genera un array di dimensione data in quattro modalità diverse:
 * 1) Ordinato: gli elementi sono ordinati in maniera crescente, da 1 a dimensione
 * 2) Inversamente ordinato: stessa cosa del precedente, ma in ordine decrescente
 * 3) Quasi ordinato: prima metà ordinata, seconda metà casuale
 * 4) Random: ogni elemento è generato in maniera completamente randomica
 *
 * @param dimensione
 * @param tipoArray
 * @return
 */
int* generaArray(int dimensione, arrayType tipoArray) {
    srand(time(NULL));

    int i;
    int* arrayGenerato = NULL, porzioneOrdinata, porzioneCasuale;

    arrayGenerato = (int*) calloc(dimensione, sizeof(int));
    if(arrayGenerato == NULL) {
        printf("\nImpossibile allocare dinamicamente memoria.");
        exit(-1);
    }

    switch (tipoArray) {
        case ORDINATO:
            for(i = 0; i < dimensione; i++) {
                arrayGenerato[i] = i+1;
            }
            break;
        case INV_ORDINATO:
            for(i = 0; i < dimensione; i--) {
                arrayGenerato[i] = dimensione-i-1;
            }
            break;
        case QUASI_ORDINATO:
            for(i = 0; i < dimensione/2; i++) {
                arrayGenerato[i] = i+1;
            }
            for(i = dimensione/2; i < dimensione; i++) {
                arrayGenerato[i] = (rand() % dimensione) + 1;
            }
            break;
        case CASUALE:
            for(i = 0; i < dimensione; i++)
                arrayGenerato[i] = (rand() % dimensione) + 1;
            break;
    }
    return arrayGenerato;
}


void scambia(int* array, int elemento1, int elemento2) {
    int tmp = array[elemento1];
    array[elemento1] = array[elemento2];
    array[elemento2] = tmp;
}