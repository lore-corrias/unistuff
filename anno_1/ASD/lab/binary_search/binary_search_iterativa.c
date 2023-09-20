#include "binary_search.h"


/**
 * Versione iterativa dell'algoritmo di ricerca binaria.
 *
 * @param array L'array in cui cercare l'elemento.
 * @param numric L'elemento ricercato.
 * @param dimension La dimensione dell'array.
 * @return Un intero corrispondente all'indice dell'elemento, o -1 se esso non è presente
 */
int binarySearchIter(int array[], int numric, int dimension) {
    // inizializzazione delle variabili che indicano gli estremi della ricerca
    int primo = 0, ultimo = dimension-1, mezzo;

    // il ciclo itera finché tutte le metà necessarie non sono state analizzate
    while(primo <= ultimo) {
        // calcolo dell'elemento di mezzo del range
        mezzo = (primo + ultimo) / 2;
        if(numric < array[mezzo]) {
            // l'elemento si trova nella metà precedente
            ultimo = mezzo - 1;
        } else if(numric == array[mezzo]) {
            // elemento trovato
            return mezzo;
        } else {
            // l'elemento si trova nella metà successiva
            primo = mezzo + 1;
        }
    }

    // se il codice è raggiunto, l'elemento non è stato trovato
    return -1;
}