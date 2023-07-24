#include "pronto_soccorso.h"


int priorita(Paziente p1, Paziente p2) {
    if (p1.codice > p2.codice) return 1;
    if (p2.codice > p1.codice) return 2;

    //se ora i codici sono uguali controllo il numero
    //do per scontato che non possano avere lo stesso numero
    if (p1.ordine < p2.ordine) return 1;
    else return 2;

}

void insertHeap(Paziente coda[], Paziente p, int *n_el) {
    int i;
    // inserisce un nuovo item in un heap di n elementi
    if (*n_el == DIM_HEAP - 1) {
        printf("\nHeap pieno!");
    } else {
        //aggiungo uno al contatore degli elementi
        (*n_el)++;
        i = *n_el; //inizializzo i per scorrere l'array
        while (i != 1 && priorita(p, coda[i / 2]) == 1) {
            //partendo dall'ultimo elemento risalgo finche ho raggiunto il top oppure ha priorita minore del padre
            coda[i] = coda[i / 2]; //se è maggiore metto il padre nel figlio
            i = i / 2;
        }
        coda[i] = p; //a fine ciclo inserisco nella posizione corretta
    }
}

Paziente deleteHeap(Paziente heap[], int *n_el) {
    Paziente item = {}, temp;
    int padre, figlio;
    // cancella e restituisce l’elemento radice in un heap di n elementi

    item = heap[1];
    temp = heap[*n_el];

    if ((*n_el) > 0)
        (*n_el)--;
    else return item;


    padre = 1;
    figlio = 2;

    while (figlio <= *n_el) {
        if (figlio < *n_el &&
            priorita(heap[figlio], heap[figlio + 1]) == 2) //se il figlio destro ha priorita avanzo di 1
            figlio++;

        if (priorita(temp, heap[figlio]) == 1)
            break;

        //metto il figlio nella posizione del padre e continuo a scendere con il figlio *=2
        heap[padre] = heap[figlio];
        padre = figlio;
        figlio *= 2;
    }

    heap[padre] = temp; //piazzo temp nella posizione corretta solo alla fine
    return item;
}

void confrontaPazienti(Paziente coda[], int n_pazienti) {
    int a, b;
    int prioritario, nonPrioritario;

    do {
        printf("\nDevi selezionare due pazienti!");
        printHeap(coda, n_pazienti);

        printf("\nPaziente A: ");
        scanf("%d", &a);
        getchar();

        printf("\nPaziente B: ");
        scanf("%d", &b);
        getchar();

        if(a < 1 || b < 1 || a > n_pazienti || b > n_pazienti || a == b)
            printf("\nInserisci un valore valido!");
    } while (a < 1 || b < 1 || a > n_pazienti || b > n_pazienti || a == b);


    if(priorita(coda[a], coda[b]) == 1) {
        prioritario = a;
        nonPrioritario = b;
    } else {
        prioritario = b;
        nonPrioritario = a;
    }
    printf("\nLa priorità di %s è maggiore di quella di %s", coda[prioritario].nome, coda[nonPrioritario].nome);
}

void printHeap(Paziente coda[], int n_pazienti) {
    int j = 0;

    printf("\nHEAP:");
    for (int i = 1; j < n_pazienti && i < DIM_HEAP; i++) {
        if (coda[i].nome[0] != '\0') {
            j++;
            printf("\n\nPaziente n° %d : ", j);
            printf("\n\tNome paziente: %s", coda[i].nome);

            printf("\n\tCodice paziente: ");
            switch (coda[i].codice) {
                case ROSSO:
                    printf("ROSSO");
                    break;
                case GIALLO:
                    printf("GIALLO");
                    break;
                case VERDE:
                    printf("VERDE");
                    break;
                case BIANCO:
                    printf("BIANCO");
                    break;
            }
            printf("\n\tPosizione nella coda: %d", coda[i].ordine);
        }
    }
}

Paziente nuovoPaziente(ProntoSoccorso *ps) {
    Paziente p;

    printf("\nNome paziente -> ");
    scanf("%[^\n]s", p.nome);
    getchar();

    do {
        printf("\nCodice paziente (0 = bianco, 1 = verde, 2 = giallo, 3 = rosso)-> ");
        scanf("%u", &p.codice);
        getchar();

        if (p.codice < BIANCO || p.codice > ROSSO)
            printf("\nCodice non valido");
    } while (p.codice < BIANCO || p.codice > ROSSO);

    if (p.codice == BIANCO) {
        ps->numeroB++;
        p.ordine = ps->numeroB;
    } else if (p.codice == GIALLO) {
        ps->numeroG++;
        p.ordine = ps->numeroG;

    } else if (p.codice == VERDE) {
        ps->numeroV++;
        p.ordine = ps->numeroV;
    } else {
        ps->numeroR++;
        p.ordine = ps->numeroR;
    }

    return p;
}