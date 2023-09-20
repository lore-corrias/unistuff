#include "merge_heap_sort.h"


//variabili globali
int scambi = 0;
int confronti = 0;
int array_dimensione[ARRAY_DIMENSIONI] = {500, 1000, 2000, 5000, 10000, 20000, 50000};


void stampa_ordinamento(int tipo_ordinamento) {
    switch (tipo_ordinamento) {
        case ORDINATO:
            printf("\n ARRAY ORDINATO");
            break;
        case QUASI_ORDINATO:
            printf("\n ARRAY PARZIALMENTE ORDINATO");
            break;
        case INV_ORDINATO:
            printf("\n ARRAY INVERSAMENTE ORDINATO");
            break;
        case CASUALE:
            printf("\n ARRAY CASUALE");
            break;
    }

}

void stampa_algo(int tipo_algo) {
    switch (tipo_algo) {
        case SELECTION:
            printf("\n\nSELECTION SORT");
            break;
        case INSERTION:
            printf("\n\nINSERTION SORT");
            break;
        case HEAPSORT:
            printf("\n\nHEAP SORT");
            break;
        case QUICKSORT:
            printf("\n\nQUICK SORT");
            break;
        case MERGE:
            printf("\n\nMERGE SORT");
            break;
    }
}

void stampa_array(int array[], int lunghezza) {
    printf("\n");
    for (int i = 0; i < lunghezza; i++) {
        printf("%d\t", array[i]);
    }
}

void test_manuale() {
    double tempo;
    int ordinamento, algoritmo, dimensione;

    scambi = confronti = 0;

    ordinamento = chiedi_ordinamento();
    algoritmo = chiedi_algoritmo();
    dimensione = chiedi_dimensione();

    tempo = tempo_ordinamento_corrente_con_stampa(ordinamento, algoritmo, dimensione);

    printf("\nTempo impegato: %lf", tempo);
    printf("\nN° scambi: %d\nN° confronti: %d\n", scambi, confronti);

    scambi = confronti = 0;

}

int chiedi_algoritmo() {
    int a;

    do {
        printf("\nSeleziona l'algoritmo:"
               "\n0) Selection Sort"
               "\n1) Insertion Sort"
               "\n2) Merge Sort"
               "\n3) Heap Sort"
               "\n4) Quick Sort"
               "\n?) ");
        scanf(" %d", &a);
        getchar();
    } while (a < SELECTION || a > QUICKSORT);

    return a;
}

int chiedi_ordinamento() {
    int a;

    //typedef enum{ORDINATO, PARZIALMENTE, INVERSAMENTE, CASUALE}Schema_iniziale;
    do {
        printf("\nSeleziona l'ordinamento dell'array:"
               "\n0) Array già ordinato"
               "\n1) Array parzialmente ordinato"
               "\n2) Array ordinato inversamente"
               "\n3) Array non ordinato"
               "\n?) ");
        scanf(" %d", &a);
        getchar();
    } while (a < ORDINATO || a > CASUALE);

    return a;
}

int chiedi_dimensione() {
    int a;

    do {
        printf("\nInserisci la dimensione dell'array : ");
        scanf(" %d", &a);
        getchar();
    } while (a < 0 || a > LIMITE_ARRAY_MANUALE);

    return a;
}

void testa_algoritmi() {
    double tempo;

    for (int i = 0; i < TIPI_ORDINAMENTO; i++) {
        stampa_ordinamento(i);

        for (int j = 0; j < NUM_ALGORITMI; j++) {

            stampa_algo(j);

            for (int k = 0; k < ARRAY_DIMENSIONI; k++) {

                printf("\n\tDimensione dell'array: %8d", array_dimensione[k]);

                scambi = confronti = 0; //a ogni giro resetto i passi e i confronti per la nuova conta

                tempo = tempo_ordinamento_corrente(i, j, k);

                printf("\n\t\tTempo impegato: %lf", tempo);
                printf("\n\t\tN° scambi: %d\n\t\tN° confronti: %d", scambi, confronti);
            }
        }
    }
}

double tempo_ordinamento_corrente_con_stampa(int tipo_ordinamento, int tipo_algoritmo, int dimensione_test) {

    int *array, *array_aux;
    double tempo = 0;
    clock_t start, end;

    switch (tipo_algoritmo) {
        case SELECTION:

            array = generaArray(dimensione_test, tipo_ordinamento);

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
            }

            start = clock();

            selectionSort(array, dimensione_test);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            printf("\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
            if (dimensione_test < LUNGHEZZA_MAX_STAMPA)
                stampa_array(array, dimensione_test);
            printf("\n\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");

            free(array);

            break;
        case INSERTION:

            array = generaArray(dimensione_test, tipo_ordinamento);

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
            }

            start = clock();

            insertionSort(array, dimensione_test);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
            }

            free(array);

            break;
        case HEAPSORT:

            array = generaArray(dimensione_test, tipo_ordinamento);

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
            }

            start = clock();

            heapSort(array, dimensione_test);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
            }

            free(array);

            break;
        case QUICKSORT:

            array = generaArray(dimensione_test, tipo_ordinamento);

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
            }

            start = clock();

            quickSort(array, 0, dimensione_test - 1);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
            }

            free(array);

            break;
        case MERGE:

            array = generaArray(dimensione_test, tipo_ordinamento);
            array_aux = calloc(dimensione_test, sizeof(int));

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY GENERATO -----------------------------------------------------------\n");
            }

            start = clock();

            mergeSort(array, array_aux, 0, dimensione_test - 1);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            if (dimensione_test < LUNGHEZZA_MAX_STAMPA) {
                printf("\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
                stampa_array(array, dimensione_test);
                printf("\n\n----------------------------------------------------------- ARRAY ORDINATO -----------------------------------------------------------\n");
            }

            free(array);
            free(array_aux);

            break;

    }


    return tempo;
}

double tempo_ordinamento_corrente(int tipo_ordinamento, int tipo_algoritmo, int dimensione_test) {
    int *array, *array_aux;
    double tempo = 0;
    clock_t start, end;

    switch (tipo_algoritmo) {
        case SELECTION:

            array = generaArray(array_dimensione[dimensione_test], tipo_ordinamento);

            start = clock();

            selectionSort(array, array_dimensione[dimensione_test]);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            free(array);

            break;
        case INSERTION:

            array = generaArray(array_dimensione[dimensione_test], tipo_ordinamento);

            start = clock();

            insertionSort(array, array_dimensione[dimensione_test]);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            free(array);

            break;
        case HEAPSORT:

            array = generaArray(array_dimensione[dimensione_test], tipo_ordinamento);

            start = clock();

            heapSort(array, array_dimensione[dimensione_test]);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            free(array);

            break;
        case QUICKSORT:

            array = generaArray(array_dimensione[dimensione_test], tipo_ordinamento);

            start = clock();

            quickSort(array, 0, array_dimensione[dimensione_test] - 1);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            free(array);

            break;
        case MERGE:

            array = generaArray(array_dimensione[dimensione_test], tipo_ordinamento);
            array_aux = calloc(array_dimensione[dimensione_test], sizeof(int));

            start = clock();

            mergeSort(array, array_aux, 0, array_dimensione[dimensione_test] - 1);

            end = clock();

            tempo = ((double) (end - start)) / CLOCKS_PER_SEC;

            free(array);
            free(array_aux);
            break;

    }


    return tempo;
}

int casuale_tra(int min, int max) {
    return min + rand() % (max - min + 1);
}

int * generaArray(int dimensione, int tipoArray)
{
    int *array;

    array= calloc(dimensione, sizeof(int));


    switch(tipoArray)
    {
        case ORDINATO:
            for(int i=0;i<dimensione; i++)
            {
                array[i]=i;
            }
            break;

        case QUASI_ORDINATO:
            for(int i=0;i<dimensione; i++)
            {
                if(i<dimensione/2)
                {
                    array[i]=i;
                }
                else
                {
                    array[i]= casuale_tra(MIN,MAX );
                }
            }
            break;

        case INV_ORDINATO:
            for(int i=0;i<dimensione; i++)
            {
                array[i]=dimensione-i-1;
            }
            break;

        case CASUALE:
            for(int i=0;i<dimensione; i++)
            {
                array[i]= casuale_tra(MIN, MAX);
            }
            break;

        default:
            exit(-1);
    }

    return array;
}


void swap(int *a, int *b) {
    int appoggio;
    appoggio = *a;
    *a = *b;
    *b = appoggio;
}

void selectionSort(int A[], int n) {
    int i, j;
    int min;

    for (i = 0; i <= n - 2; i++){
        min = i;
        for (j = i + 1; j <= n - 1; j++) {
            confronti++;
            if (A[j] < A[min])
                min = j;
        }
        swap(&A[min], &A[i]);
        scambi++;
    }
}


void insertionSort(int *lista, int dim) {
    int prossimo, j, i;

    for (i = 1; i < dim; i++) {

        prossimo = lista[i];

        for (j = i - 1; j >= 0; j--) {
            confronti++;
            if (prossimo < lista[j]) {
                scambi++;
                lista[j + 1] = lista[j];
            } else {
                break;
            }
        }

        scambi++;
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
            confronti++;
        } while (i <= ultimo && lista[i] <= pivot);

        do {
            j--;
            confronti++;
        } while (j >= primo && lista[j] > pivot);

        if (i < j) {
            swap(&lista[i], &lista[j]);
            scambi++;
        }
    }


    swap(&lista[primo], &lista[j]);
    scambi++;

    return j;
}

void quickSort(int lista[], int u, int v) {
    if (u == v) return;

    int q = perno(lista, u, v);

    if (u < q) quickSort(lista, u, q - 1);
    if (q < v) quickSort(lista, q + 1, v);
}

void merge(int lista[], int arr_ordinato[], int low, int mid, int up) {
    int j = mid + 1; // indice per la seconda parte di lista
    int k = low; // indice per la lista ordinata
    int pos_iniziale = low; //posizione iniziale nella lista

    while (low <= mid && j <= up) {
        confronti++;
        if (lista[low] <= lista[j]) {
            scambi++;
            arr_ordinato[k] = lista[low];
            low++;
            k++;
        } else {
            scambi++;
            arr_ordinato[k] = lista[j];
            j++;
            k++;
        }

    }

    if (low > mid) {
        // ordinata[k],..., ordinata[n] ← lista[j],..., lista[n]
        for (int t = j; t <= up; t++) {
            arr_ordinato[k + t - j] = lista[t];
            scambi++;
        }

    } else {
        // ordinata[k],..., ordinata[n] ← lista[i],..., lista[m]
        for (int t = low; t <= mid; t++) {
            arr_ordinato[k + t - low] = lista[t];
            scambi++;
        }
    }

    //copio la lista ordinata dall'array di appoggio alla lista iniziale
    for (int t = pos_iniziale; t <= up; t++) {
        lista[t] = arr_ordinato[t];
        scambi++;
    }

}

void mergeSort(int lista[], int ordinata[], int lower, int upper) {
    if (lower >= upper) return;

    int medium = (lower + upper) / 2;
    mergeSort(lista, ordinata, lower, medium);
    mergeSort(lista, ordinata, medium + 1, upper);
    merge(lista, ordinata, lower, medium, upper);
}

void adatta(int lista[], int padre, int ultimo) {

    //ricerco il maggiore tra figlio sinistro e destro
    int maggiore = padre;

    //inizializzo figlio destro e sinistro
    int sx = 2 * padre + 1;
    int dx = 2 * padre + 2;

    //se l'indice rappresenta un elemento dell'array, ed è maggiore..
    confronti++;
    if (sx < ultimo && lista[sx] > lista[maggiore])
        maggiore = sx;

    confronti++;
    if (dx < ultimo && lista[dx] > lista[maggiore])
        maggiore = dx;


    //se la radice non è piu il maggiore, la scambio con il maggiore e faccio la chiamata ricorsiva
    if (maggiore != padre) {
        swap(&lista[padre], &lista[maggiore]), scambi++;
        adatta(lista, maggiore, ultimo);
    }
}

void heapSort(int lista[], int dim) {
    //primo giro di adattamenti che parte dal primo elemento con un figlio
    for (int i = dim / 2 - 1; i >= 0; i--)
        adatta(lista, i, dim);

    //loop dove scorro la lista e pian piano rimuovo un elemento e riadatto
    for (int i = dim - 1; i >= 0; i--) {
        //scambio il maggiore e lo metto in fondo, nella sua posizione finale
        swap(&lista[0], &lista[i]);
        scambi++;

        //adatto dopo lo scambio
        adatta(lista, 0, i);
    }
}