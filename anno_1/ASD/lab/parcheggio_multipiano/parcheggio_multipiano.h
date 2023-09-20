#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TARGA 10
#define NUM_PIANI 7

#define MAX_ORA 24
#define MAX_MINUTI 59

typedef struct
{
    char targa[MAX_TARGA];
    int ora;
    int min;
}Auto;

typedef struct nodo
{
    Auto info;
    struct nodo *link;
}Nodo;

int chiedi_piano();
char * chiedi_targa(char * targa);
Auto genera_ora_e_min(Auto a);

int hash_function(char targa[]);
Auto acquisisci_auto();
void inserisci_auto(Nodo* parcheggio[], Auto a);
void carica_auto_test(Nodo* parcheggio[]);
void stampa_parcheggio(Nodo* parcheggio[]);
void stampa_piano(Nodo* parcheggio[], int piano);
Nodo* ricerca_auto(Nodo* parcheggio[], char targa[]);
void elimina_auto(Nodo* parcheggio[], char targa[]);