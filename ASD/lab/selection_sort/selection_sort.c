//
// Created by just on 16/03/23.
//
#include "selection_sort.h"


int main() {


    clock_t start, end;
    double t;

    int dimensioni[] = {100, 1000, 10000, 100000};// 200000, 500000};
    arrayType modalitaGenerazione;
    int* array;

    printf("\n-------------------- SELECTION SORT --------------------");
    for(int i = 0; i <= CASUALE; i++) {
        modalitaGenerazione = i;
        printf("\n-- Modalità di generazione: ");
        switch (modalitaGenerazione) {
            case ORDINATO:
                printf("ordinato.");
                break;
            case INV_ORDINATO:
                printf("ordinato al contrario.");
                break;
            case QUASI_ORDINATO:
                printf("quasi ordinato.");
                break;
            case CASUALE:
                printf("casuale.");
                break;
        }
        for(int j = 0; j < 4; j++) {
            printf("\n- Numero di input: %d.", dimensioni[j]);
            array = generaArray(dimensioni[j], modalitaGenerazione);

            cont_conf_ric = 0;
            cont_scambi_ric = 0;

            start = clock();
            selectionSortRicorsivo(array, dimensioni[j], 0);
            end = clock();

            t = ((double) (end-start)) / CLOCKS_PER_SEC;
            printf(
                    " \nRicorsivo: tempo di esecuzione: %lf secondi. "
                    "Numero di confronti: %d. "
                    "Numero di scambi: %d", t, cont_conf_ric, cont_scambi_ric
            );

            cont_conf_iter = 0;
            cont_scambi_iter = 0;

            start = clock();
            selectionSortIterativo(array, dimensioni[j]);
            end = clock();

            t = ((double) (end-start)) / CLOCKS_PER_SEC;
            printf(
                    " \nIterativo: tempo di esecuzione: %lf secondi. "
                    "Numero di confronti: %d. "
                    "Numero di scambi: %d", t, cont_conf_ric, cont_scambi_ric
            );
        }
    }
}