#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define LIMITE_ARRAY_MANUALE 1000000000

#define MIN 0
#define MAX 100

#define CASO_MANUALE 1
#define CASO_AUTOMATICO 2
#define CHIUDI 0

#define LUNGHEZZA_MAX_STAMPA 21

#define NUM_ALGORITMI 5
#define TIPI_ORDINAMENTO 4
#define ARRAY_DIMENSIONI 7

typedef enum {
    SELECTION, INSERTION, MERGE, HEAPSORT, QUICKSORT
} Algoritmi;
typedef enum {
    ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE
} Schema_iniziale;

int* generaArray(int dimensione, int tipoArray);

void stampa_array(int array[], int lunghezza);

void swap(int *a, int *b);

void stampa_ordinamento(int tipo_ordinamento);

void stampa_algo(int tipo_algo);

void stampa_algo_file(FILE *file, int tipo_algo);

void stampa_ordinamento_file(FILE *file, int tipo_ordinamento);

void stampa_algo_tabella(FILE *file, int tipo_algo);

void stampa_ordinamento_tabella(FILE *file, int tipo_ordinamento);

void selectionSort(int A[], int n);

void insertionSort(int *lista, int dim);

void quickSort(int lista[], int u, int v);

void mergeSort(int lista[], int ordinata[], int lower, int upper);

void heapSort(int lista[], int dim);


double tempo_ordinamento_corrente(int tipo_ordinamento, int tipo_algoritmo, int dimensione_test);

double tempo_ordinamento_corrente_con_stampa(int tipo_ordinamento, int tipo_algoritmo, int dimensione_test);

int chiedi_ordinamento();

int chiedi_algoritmo();

int chiedi_dimensione();

void test_manuale();

void testa_algoritmi();