#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STRINGA_LEN 50
#define MAX_CODA 10
#define MAX_STACK 10

#define INSERISCI_PROMPT 1
#define ELIMINA_PROMPT 2
#define INSERISCI_ORDINE_PROMPT 3
#define RIMUOVI_ORDINE_PROMPT 4
#define CONSEGNA_PROMPT 5
#define ORDINI_PROMPT 6
#define CONSEGNE_PROMPT 7
#define ESCI_PROMPT 0

// Dichiarazione strutture
typedef struct {
    char articolo[STRINGA_LEN + 1];
    double prezzo;
    char destinatario[STRINGA_LEN + 1];
} Ordine;

struct node {
    Ordine data;
    struct Node* link;
};
typedef struct node Node;

typedef struct {
    int cont;
    Node* front;
    Node* back;
} Queue;

typedef struct{
    Node* top;
    int cont;
} Stack;


// Dichiarazione funzioni
bool isEmptyQueue(Queue* queue);
bool isFullQueue(Queue* queue);
void pushQueue(Queue* queue, Ordine ordine);
Ordine popQueue(Queue* queue);
void printQueue(Queue queue);

bool isEmptyStack(Stack* stack);
bool isFullStack(Stack* stack);
void pushStack(Stack* stack, Ordine ordine);
Ordine popStack(Stack* stack);
void printStack(Stack stack);

void inizializzaStrutture(Stack* stack, Queue* queue);

Ordine creaOrdine();

void menu();