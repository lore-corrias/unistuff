#include "pronto_soccorso.h"

int main() {
    srand(time(NULL));

    //inizializzazione pronto soccorso
    ProntoSoccorso ps;
    ps.numeroB = ps.numeroG = ps.numeroV = ps.numeroR = 0;

    //inizializzazione della Coda con priorita'
    Paziente codaPrio[DIM_HEAP] = {};
    int scelta;
    Paziente p_temp = {};
    int n_pazienti = 0;

    printf("\nBenvenuto nel Pronto Soccorso!");
    do {
        printf("\n\nScegli un'azione."
               "\n%d) Aggiungi un paziente."
               "\n%d) Confronta le priorità di due pazienti."
               "\n%d) Rimuovi il paziente prioritario dalla coda."
               "\n%d) Stampa la coda in ordine di posizione."
               "\n%d) Esci."
               "\n?) ", PROMPT_AGGIUNGI_PAZIENTE, PROMPT_CONFRONTA_PAZIENTI, PROMPT_RIMUOVI_PAZIENTE, PROMPT_STAMPA_CODA, PROMPT_ESCI);
        scanf(" %d", &scelta);
        getchar();

        switch (scelta) {
            case PROMPT_AGGIUNGI_PAZIENTE:
                p_temp = nuovoPaziente(&ps);
                insertHeap(codaPrio, p_temp, &n_pazienti);
                break;
            case PROMPT_CONFRONTA_PAZIENTI:
                confrontaPazienti(codaPrio, n_pazienti);
                break;
            case PROMPT_RIMUOVI_PAZIENTE:
                deleteHeap(codaPrio, &n_pazienti);
                break;
            case PROMPT_STAMPA_CODA:
                printf("\nNUMERO PAZIENTI: %d", n_pazienti);
                printHeap(codaPrio, n_pazienti);
                break;
        }
    } while (scelta != PROMPT_ESCI);

    printf("\nA presto!");

    return 0;
}