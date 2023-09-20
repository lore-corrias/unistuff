#include "merge_heap_sort.h"


int main() {
    srand(time(NULL));

    int scelta;

    printf("\nBenvenuto nell'ultima esercitazione!");
    do {
        printf("\nScegli cosa fare.");
        printf("\n1) Testa un algoritmo singolarmente"
               "\n2) Testa tutti gli algoritmi in automatico"
               "\n0) Esci"
               "\n?) ");
        scanf(" %d", &scelta);
        getchar();

        switch (scelta) {
            case CASO_MANUALE:
                test_manuale();
                break;
            case CASO_AUTOMATICO:
                testa_algoritmi();
                break;
            case CHIUDI:
                printf("\n\nA presto!");
        }
    } while (scelta != CHIUDI);

    return 0;
}