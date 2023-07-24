#include "insertion_quick_sort.h"


int* generaArray(int dimensione, int tipoArray) {
    int i;
    int* arrayGenerato = NULL;

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

void stampa_array(int array[], int lunghezza) {
    printf("\n");
    for (int i = 0; i < lunghezza; i++) {
        printf("%d\t", array[i]);
    }
}

void swap(int *a, int *b) {
    int appoggio;
    appoggio = *a;
    *a = *b;
    *b = appoggio;
}

void insertionSort(int *lista, int dim) {
    int prossimo, j, i;

    for (i = 1; i < dim; i++) {

        prossimo = lista[i];

        for (j = i - 1; j >= 0; j--) {
            if (prossimo < lista[j]) {
                lista[j + 1] = lista[j];
            } else {
                break;
            }
        }

        lista[j + 1] = prossimo;
    }
}

int perno(int lista[], int primo, int ultimo) {
    int i = primo;
    int j = ultimo + 1;
    int pivot = lista[primo];

    while (i < j) {
        do {
            i++;
        } while (i <= ultimo && lista[i] <= pivot);

        do {
            j--;

        } while (j >= primo && lista[j] > pivot);

        if (i < j)
            swap(&lista[i], &lista[j]);
    }


    swap(&lista[primo], &lista[j]);

    return j;
}

void quickSort(int lista[], int u, int v) {
    if (u == v) return;

    int q = perno(lista, u, v);

    if (u < q) quickSort(lista, u, q - 1);
    if (q < v) quickSort(lista, q + 1, v);
}

void mixSort(int lista[], int u, int v, int M) {

    if (u == v) return;

    if (abs(v - u) < M) {
        insertionSort(&lista[u], (v - u) + 1);
    } else {
        int q = perno(lista, u, v);

        if (u < q) mixSort(lista, u, q - 1, M);
        if (q < v) mixSort(lista, q + 1, v, M);
    }

}