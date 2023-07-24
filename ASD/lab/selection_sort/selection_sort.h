#include "array.h"

// variabili di conteggio per il numero di scambi e confronti ricorsivi
extern long cont_conf_ric, cont_scambi_ric;

// variabili di conteggio per il numero di scambi e confronti iterativi
extern long cont_conf_iter, cont_scambi_iter;


int findMin(int* array, int minpos, int start, int dim);
void selectionSort();
void selectionSortRicorsivo(int *array, int dim, int start);
void selectionSortIterativo(int *array, int dim);