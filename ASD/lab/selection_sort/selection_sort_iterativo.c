//
// Created by just on 16/03/23.
//
#include "selection_sort.h"

int cont_scambi_iter = 0;
int cont_conf_iter = 0;


/**
 * Versione iterativa del selection sort.
 *
 * @param array L'array da ordinare.
 * @param dim La dimensione dell'array da ordinare.
 */
void selectionSortIterativo(int *array, int dim) {
    int i, j, min;
    // scorri tutti gli elementi fino al penultimo
    for(i = 0; i <= dim-2; i++) {
        // assumi che l'elemento minore sia quello corrente
        min = i;
        for(j = i+1; j <= dim-1; j++) {
            // trova l'elemento minore tra quelli successivi a i
            if (array[j] < array[min]) {
                min = j;
            }
            cont_conf_iter++;
        }
        // scambiaInteri le posizioni di i e dell'elemento minore
        scambiaInteri(array, min, i);
        cont_scambi_iter++;
    }
}