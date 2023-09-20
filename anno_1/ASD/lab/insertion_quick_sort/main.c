#include "insertion_quick_sort.h"


int main() {
    srand(time(NULL));

    int scelta, M;
    int *array;
    do {
        array = generaArray(LEN, CASUALE);

        printf("\nScegli il metodo di ordinamento.");
        printf("\n1) InsertionSort."
               "\n2) Quicksort."
               "\n3) Algoritmo ibrido."
               "\n0) Esci."
               "\n?) ");
        scanf(" %d", &scelta);
        getchar();

        if (scelta > 0 && scelta <= 3) {
            printf("\n-------------------------------------------------------- ARRAY GENERATO --------------------------------------------------------\n");
            stampa_array(array, LEN);
            printf("\n\n-------------------------------------------------------- ARRAY GENERATO --------------------------------------------------------");
        }

        switch (scelta) {
            case 1:
                insertionSort(array, LEN);
                break;
            case 2:
                quickSort(array, 0, LEN - 1);
                break;
            case 3:
                do {
                    printf("\nInserisci il valore di M: ");
                    scanf(" %d", &M);
                    getchar();
                } while (M < 0 || M > LEN);
                mixSort(array, 0, LEN - 1, M);
                break;
        }

        if (scelta > 0 && scelta <= 3) {
            printf("\n\n\n\n-------------------------------------------------------- ARRAY ORDINATO --------------------------------------------------------\n");
            stampa_array(array, LEN);
            printf("\n\n-------------------------------------------------------- ARRAY ORDINATO --------------------------------------------------------");
        }

        free(array);
    } while (scelta != 0);

    printf("\nA presto!");

    return 0;
}