#include "rotte_aeree.h"


int main() {
    Citta grafo[MAX_VERTICI];
    int num_nodi = 0;
    int* visited = (int*) calloc(NUM_NODI_TEST, sizeof(int));

    //Inserire qui le chiamate per testare le varie funzioni e il menu
    int id_coda, id_testa;
    int scelta;

    printf("\nBenvenuto all'aeroporto!");
    do {
        printf("\nScegli un'azione.");
        printf("\n1) Aggiungi una citta'.");
        printf("\n2) Crea un collegamento tra due citta'.");
        printf("\n3) Mostra i collegamenti presenti.");
        printf("\n4) Visita tutti i collegamenti per profondita'.");
        printf("\n5) Visita tutti i collegamenti per ampiezza.");
        printf("\n6) Elimina un arco (collegamento tra due citta').");
        printf("\n7) Visualizza le citta' connesse.");
        printf("\n8) Carica le città per testare (archi orientati).");
        printf("\n9) Carica le città per testare (archi non orientati).");
        printf("\n0) Esci");
        printf("\n?) ");

        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                aggiungi_nodo(grafo, &num_nodi);
                break;
            case 2:
                printf("\nCodice della citta' di partenza: ");
                scanf("%d", &id_coda);
                getchar();
                printf("\nCodice della citta' di arrivo: ");
                scanf("%d", &id_testa);
                getchar();
                crea_arco(grafo, id_coda, id_testa, num_nodi);
                break;
            case 3:
                stampa_lista_adiacenze(grafo, num_nodi);
                break;
            case 4:
                visited = (int*) calloc(num_nodi, sizeof(int));

                printf("\nCodice della citta' da visitare: ");
                scanf(" %d", &id_testa);
                getchar();
                DFS(grafo, visited, id_testa);
                break;
            case 5:
                visited = (int*) calloc(num_nodi, sizeof(int));
                printf("\nCodice della citta' da visitare: ");
                scanf("%d", &id_testa);
                getchar();
                BFS(grafo, visited, id_testa);
                break;
            case 6:
                printf("\nChe tipo di collegamento (arco) vorresti cancellare?");
                printf("\n 1) Orientato (A -> B)");
                printf("\n 2) Non orientato (A <-> B)\n");
                printf("?) ");
                scanf("%d", &scelta);
                getchar();

                if (scelta == 1) {
                    printf("\nCodice della citta' di partenza: ");
                    scanf("%d", &id_coda);
                    getchar();
                    printf("\nCodice della citta' di arrivo: ");
                    scanf("%d", &id_testa);
                    getchar();
                    cancella_arco_orientato(grafo, id_coda, id_testa);
                } else if (scelta == 2) {
                    printf("\nCodice della citta' di partenza: ");
                    scanf("%d", &id_coda);
                    getchar();
                    printf("\nCodice della citta' di arrivo: ");
                    scanf("%d", &id_testa);
                    getchar();
                    cancella_arco_non_orientato(grafo, id_coda, id_testa, num_nodi);
                } else {
                    printf("\nInserisci un valore valido!");
                }
                break;
            case 7:
                componenti_connesse(grafo, visited, num_nodi);
                break;
            case 8:
                num_nodi = NUM_NODI_TEST;
                carica_grafo_test_orientato(grafo, num_nodi);
                break;
            case 9:
                num_nodi = NUM_NODI_TEST;
                carica_grafo_test_non_orientato(grafo, num_nodi);
                break;
        }
    } while (scelta != 0);

    printf("\nA presto!");
    free(visited);
}