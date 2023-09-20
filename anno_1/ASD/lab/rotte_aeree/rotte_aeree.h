#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICI 20
#define DIM 50
#define NUM_NODI_TEST 11
#define DIM_CODA 20


typedef struct node{
    int vertex_id;
    struct node* link;
}Node;

typedef struct{
    char nome[DIM];
    int  abitanti;
    char nazione[DIM];
    Node* lista_adj;
}Citta;

typedef struct{
    Node* front;
    Node* back;
    int cont;
}Queue;

typedef enum{ORIENTATO = 1, NON_ORIENTATO}tipoGrafo;

/* ==============================
 * Funzioni gia' implementate
 * ============================== */
void carica_citta_test(Citta grafo[]);
void carica_grafo_test_orientato(Citta grafo[], int num_nodi);
void carica_grafo_test_non_orientato(Citta grafo[], int num_nodi);


/* ==============================
 * Funzioni da completare
 * ============================== */
void aggiungi_nodo(Citta grafo[], int *num_nodi);
void crea_arco(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void stampa_lista_adiacenze(Citta grafo[], int num_nodi);

void DFS(Citta grafo[], int visited[], int start_id);
void BFS(Citta grafo[], int visited[], int start_id);

void cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa);
void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);

void componenti_connesse(Citta grafo[], int visited[], int num_nodi);

void stampaCitta(Citta citta);

_Bool isEmptyQueue(Queue* coda);
_Bool isFullQueue(Queue* coda);

void pushQueue(Queue* coda, int vertex);
int popQueue(Queue* coda);

void svuotaBuffer();
