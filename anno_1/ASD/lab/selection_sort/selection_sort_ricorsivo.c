#include "selection_sort.h"

long cont_scambi_ric = 0;
long cont_conf_ric = 0;


/**
 * Versione ricorsiva del selection sort.
 *
 * @param array Array da ordinare.
 * @param dim Dimensione dell'array da ordinare.
 * @param start Indice dell'array da cui far partire l'ordinamento.
 */
void selectionSortRicorsivo(int *array, int dim, int start) {
    int minIndex;


    if(start >= dim - 1)
        return;


    minIndex = findMin(array, start, start, dim);

    scambiaInteri(array, minIndex, start);
    cont_scambi_ric++;

    selectionSortRicorsivo(array, dim, start + 1);
}


/**
 * Algoritmo per ricercare il numero più piccolo all'interno di un array.
 *
 * @param array L'array in cui ricercare l'elemento minore.
 * @param minpos La posizione in cui si trova quello che attualmente è l'elemento minimo.
 * @param start La posizione da cui far partire la ricerca dell'elemento minimo
 * @param dim La dimensione dell'array.
 * @return L'elemento più piccolo dell'array
 */
int findMin(int* array, int minpos, int start, int dim) {
    // la ricerca è finita, e quindi array[minpos] contiene l'elemento più piccolo
    cont_conf_ric++;
    if(start == dim)
        return minpos;
    // verifico che l'elemento da cui far partire la ricerca sia < di minpos
    // se sì, allora minpos ora è l'indice start
    if(array[start] < array[minpos])
        minpos = start;
    cont_conf_ric++;
    // itero la ricerca sull'elemento successivo, fino alla fine dell'array
    return findMin(array, minpos, start+1, dim);
}