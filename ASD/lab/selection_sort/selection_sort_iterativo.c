#include "selection_sort.h"

long cont_scambi_iter = 0;
long cont_conf_iter = 0;


/**
 * Versione iterativa del selection sort.
 *
 * @param array L'array da ordinare.
 * @param dim La dimensione dell'array da ordinare.
 */
void selectionSortIterativo(int *array, int dim) {
    int i, j;
    int min;

    for (i = 0; i <= dim - 2; i++){
        min = i;
        for (j = i + 1; j <= dim - 1; j++) {
            cont_conf_iter++;
            if (array[j] < array[min])
                min = j;
        }
        scambiaInteri(array, min, i);
        cont_scambi_iter++;
    }
}