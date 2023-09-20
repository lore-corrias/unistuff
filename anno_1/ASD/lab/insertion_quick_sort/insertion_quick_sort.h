#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 15

#define ORDINATO 0
#define INV_ORDINATO 1
#define QUASI_ORDINATO 2
#define CASUALE 3


int *generaArray(int lunghezza, int tipo_input);

void stampa_array(int array[], int lunghezza);

void swap(int *a, int *b);

void insertionSort(int *lista, int dim);

void quickSort(int lista[], int u, int v);

void mixSort(int lista[], int u, int v, int M);