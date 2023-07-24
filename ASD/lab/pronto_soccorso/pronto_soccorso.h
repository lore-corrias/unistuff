#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define DIM_NOME 50
#define DIM_HEAP 50

#define PROMPT_AGGIUNGI_PAZIENTE 1
#define PROMPT_CONFRONTA_PAZIENTI 2
#define PROMPT_RIMUOVI_PAZIENTE 3
#define PROMPT_STAMPA_CODA 4
#define PROMPT_ESCI 0


//stuttura che rappresenta un Pronto soccorso
typedef struct {
    int numeroB;
    int numeroG;
    int numeroV;
    int numeroR;
} ProntoSoccorso;

//enumerazione che rappresenta i codici del pronto soccorso
typedef enum {
    BIANCO, VERDE, GIALLO, ROSSO
} Codice;

//struttura che rappresenta un Paziente
typedef struct {
    char nome[DIM_NOME];
    Codice codice;
    int ordine;
} Paziente;

/*funzione che chiede i dati relativi ad un nuovo paziente e lo restituisce (con il campo ordine calcolato automaticamente),
pronto per essere inserito nella coda con priorita' (heap) */
Paziente nuovoPaziente(ProntoSoccorso *ps);

int priorita(Paziente p1, Paziente p2);

void insertHeap(Paziente coda[], Paziente p, int *n_el);

Paziente deleteHeap(Paziente coda[], int *n_el);

void printHeap(Paziente coda[], int n_pazienti);

void confrontaPazienti(Paziente coda[], int n_pazienti);