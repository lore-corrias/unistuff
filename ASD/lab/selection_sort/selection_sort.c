#include "selection_sort.h"


/**
 * Funzione per testare un algoritmo di selection sort su degli array ordinati
 * in maniera diversa, e di dimensioni di 100, 1000, 10000, 20000 e 50000 elementi.
 * L'otuput consiste nel numero di operazioni effettuate per l'ordinamento e
 * nel tempo di esecuzione per ogni operazione.
 */
void selectionSort() {
    clock_t start, end;
    double t;

    int dimensioni[] = {100, 1000, 10000, 20000, 50000};
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
        for(int j = 0; j < 5; j++) {
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
                    "Numero di confronti: %ld. "
                    "Numero di scambi: %ld", t, cont_conf_ric, cont_scambi_ric
            );

            cont_conf_iter = 0;
            cont_scambi_iter = 0;

            start = clock();
            selectionSortIterativo(array, dimensioni[j]);
            end = clock();

            t = ((double) (end-start)) / CLOCKS_PER_SEC;
            printf(
                    " \nIterativo: tempo di esecuzione: %lf secondi. "
                    "Numero di confronti: %ld. "
                    "Numero di scambi: %ld", t, cont_conf_iter, cont_scambi_iter
            );
        }
    }
}