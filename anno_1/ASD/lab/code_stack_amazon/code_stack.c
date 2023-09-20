#include "code_stack.h"


bool isEmptyQueue(Queue* queue) {
    return queue->cont == 0;
}

bool isFullQueue(Queue* queue) {
    return queue->cont == MAX_CODA;
}

void pushQueue(Queue* queue, Ordine ordine) {
    Node* nodoAggiunto = NULL;

    if(!isFullQueue(queue)) {
        nodoAggiunto = (Node*) malloc(sizeof(Node));
        nodoAggiunto->data = ordine;
        nodoAggiunto->link = NULL;

        // verifico se la coda è piena o vuota per l'aggiunta
        if(isEmptyQueue(queue)) {
            queue->front = nodoAggiunto;
            queue->back = nodoAggiunto; // esiste un solo elemento
        } else {
            queue->back->link = nodoAggiunto;
            queue->back = nodoAggiunto;
        }
        queue->cont++;
    } else {
        printf("\nErrore: la coda è piena.");
    }
}

Ordine popQueue(Queue* queue) {
    Node* tmp = NULL;

    if(!isEmptyQueue(queue)) {
        tmp = queue->front; // salvo l'ultimo elemento, che è quello da restituire

        if(queue->cont == 1) {
            queue->front = NULL;
            queue->back = NULL; // la coda ora è vuota
        } else {
            queue->front = queue->front->link; // taglio un elemento dalla coda
        }
    } else {
        printf("\nErrore: la coda è vuota.");
        return (Ordine) {"", -1, ""};
    }
    queue->cont--;

    return tmp->data;
}


bool isEmptyStack(Stack* stack) {
    return stack->cont == 0;
}

bool isFullStack(Stack* stack) {
    return stack->cont == MAX_STACK;
}

void pushStack(Stack* stack, Ordine ordine) {
    Node* nodoAggiunto = NULL;

    if(!isFullStack(stack)) {
        nodoAggiunto = (Node*) malloc(sizeof(Node));
        nodoAggiunto->data = ordine;
        nodoAggiunto->link = NULL;

        // verifico se lo stack è vuoto
        if(isEmptyStack(stack)) {
            stack->top = nodoAggiunto;
        } else {
            nodoAggiunto->link = stack->top;
            stack->top = nodoAggiunto;
        }
    }
    stack->cont++;
}

Ordine popStack(Stack* stack) {
    Ordine ordine;
    Node* tmp = NULL;

    if(!isEmptyStack(stack)){
        tmp = stack->top;
        ordine = stack->top->data; // salvo l'ultimo valore da restituire

        stack->top = stack->top->link;
        stack->cont--;

        free(tmp); // libero la memoria del nodo rimosso
    } else {
        printf("\nErrore: lo stack è vuoto.");
        return (Ordine) {"", -1, ""};
    }

    return ordine;
}

Ordine creaOrdine() {
    Ordine ordine;

    printf("Inserisci il nome dell'articolo: ");
    scanf(" %50[^\n]s", ordine.articolo);

    printf("\nInserisci il prezzo dell'articolo: ");
    scanf(" %lf", &ordine.prezzo);

    printf("\nInserisci il nome del destinatario: ");
    scanf(" %50[^\n]s", ordine.destinatario);

    return ordine;
}

void printQueue(Queue coda){
    Node* current = NULL;

    if(!isEmptyQueue(&coda)) {
        current = coda.front;

        while(current != NULL) {
            printf("\tArticolo: %s\n"
                   "\tPrezzo: %.2f euro\n"
                   "\tDestinatario: %s\n", current->data.articolo, current->data.prezzo, current->data.destinatario);
            printf("\n\n");
            current = current->link;
        }
    } else {
        printf("La coda e' vuota.\n");
    }
}

void printStack(Stack stack){
    Node* current = NULL;

    if(!isEmptyStack(&stack)) {
        current = stack.top;

        while(current != NULL){
            printf("\tArticolo : %s\n"
                   "\tPrezzo: %.2f euro\n"
                   "\tDestinatario: %s\n", current->data.articolo, current->data.prezzo, current->data.destinatario);
            printf("\n\n");
            current = current->link;
        }
    } else{
        printf("Lo stack e' vuoto.\n");
        return;
    }
}

void inizializzaStrutture(Stack* stack, Queue* queue) {
    queue->front = NULL;
    queue->back = NULL;
    queue->cont = 0;

    stack->top = NULL;
    stack->cont = 0;
}

void menu(){
    int scelta;
    Ordine ordine;
    Stack stack;
    Queue queue;

    // inizializzazione strutture dati
    inizializzaStrutture(&stack, &queue);

    do {
        printf("\nInserisci un valore relativo a ciò che desideri fare:\n"
               "%d) Cancellas l'ultimo ordine\n"
               "%d) Elimina un ordine\n"
               "%d) Aggiungi un ordine allo stack\n"
               "%d) Rimuovi un ordine dallo stack\n"
               "%d) Sposta un ordine dalla coda allo stack\n"
               "%d) Visualizza gli ordini\n"
               "%d) Visualizza le consegne\n"
               "%d) Esci\n"
               "?) ", INSERISCI_PROMPT, ELIMINA_PROMPT, INSERISCI_ORDINE_PROMPT, RIMUOVI_ORDINE_PROMPT, CONSEGNA_PROMPT, ORDINI_PROMPT, CONSEGNE_PROMPT, ESCI_PROMPT);
        scanf("%d", &scelta);

        switch (scelta) {
            case ESCI_PROMPT:
                printf("A presto!\n");
                return;
            case INSERISCI_PROMPT:
                ordine = creaOrdine();

                pushQueue(&queue, ordine);
                printf("\nOrdine creato con successo.\n");
                break;
            case ELIMINA_PROMPT:
                ordine = popQueue(&queue);

                printf("Ordine eliminato!\n"
                       "\tArticolo: %s\n"
                       "\tPrezzo: %.2f euro\n"
                       "\tDestinatario: %s\n", ordine.articolo, ordine.prezzo, ordine.destinatario);
                printf("\n\n");
                break;
            case INSERISCI_ORDINE_PROMPT:
                ordine = creaOrdine();

                pushStack(&stack, ordine);
                printf("Hai inserito un ordine per il trasporto\n");
                break;
            case RIMUOVI_ORDINE_PROMPT:
                ordine = popStack(&stack);

                printf("Ordine consegnato!\n"
                       "\tArticolo : %s\n"
                       "\tPrezzo: %.2f euro\n"
                       "\tDestinatario: %s\n", ordine.articolo, ordine.prezzo, ordine.destinatario);
                printf("\n\n");

                break;
            case CONSEGNA_PROMPT:
                ordine = popQueue(&queue);

                pushStack(&stack, ordine);
                printf("Ordine pronto per la consegna!\n"
                       "\tArticolo: %s\n"
                       "\tPrezzo: %.2f euro\n"
                       "\tDestinatario: %s\n", ordine.articolo, ordine.prezzo, ordine.destinatario);
                printf("\n\n");
                break;
            case ORDINI_PROMPT:
                printf("\nLista Ordini:\n");
                printQueue(queue);
                break;
            case CONSEGNE_PROMPT:
                printf("\nLista Consegne:\n");
                printStack(stack);
                break;
            default:
                printf("Scelta non valida\n\n");
                break;
        }

        printf("\nPremi 'Invio' per continuare.");
        while (getchar() != '\n');
        getchar();

    } while (scelta != ESCI_PROMPT);
}