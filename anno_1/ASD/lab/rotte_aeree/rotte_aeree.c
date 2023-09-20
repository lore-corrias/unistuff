#include "rotte_aeree.h"


void carica_citta_test(Citta grafo[])
{
    //Cagliari
    strcpy(grafo[0].nome, "Cagliari");
    strcpy(grafo[0].nazione, "Italia");
    grafo[0].abitanti = 300000;
    grafo[0].lista_adj = NULL;

    //Zurigo
    strcpy(grafo[1].nome, "Zurigo");
    strcpy(grafo[1].nazione, "Svizzera");
    grafo[1].abitanti = 400000;
    grafo[1].lista_adj = NULL;

    //Lione;
    strcpy(grafo[2].nome, "Lione");
    strcpy(grafo[2].nazione, "Francia");
    grafo[2].abitanti = 500000;
    grafo[2].lista_adj = NULL;

    //Genova
    strcpy(grafo[3].nome, "Genova");
    strcpy(grafo[3].nazione, "Italia");
    grafo[3].abitanti = 800000;
    grafo[3].lista_adj = NULL;

    //Roma
    strcpy(grafo[4].nome, "Roma");
    strcpy(grafo[4].nazione, "Italia");
    grafo[4].abitanti = 4000000;
    grafo[4].lista_adj = NULL;

    //New York
    strcpy(grafo[5].nome, "New York");
    strcpy(grafo[5].nazione, "USA");
    grafo[5].abitanti = 8500000;
    grafo[5].lista_adj = NULL;

    //Bilbao
    strcpy(grafo[6].nome, "Bilbao");
    strcpy(grafo[6].nazione, "Spagna");
    grafo[6].abitanti = 350000;
    grafo[6].lista_adj = NULL;

    //Berlino
    strcpy(grafo[7].nome, "Berlino");
    strcpy(grafo[7].nazione, "Germania");
    grafo[7].abitanti = 3500000;
    grafo[7].lista_adj = NULL;

    //Londra
    strcpy(grafo[8].nome, "Londra");
    strcpy(grafo[8].nazione, "Gran Bretagna");
    grafo[8].abitanti = 8700000;
    grafo[8].lista_adj = NULL;

    //Miami
    strcpy(grafo[9].nome, "Miami");
    strcpy(grafo[9].nazione, "USA");
    grafo[9].abitanti = 450000;
    grafo[9].lista_adj = NULL;

    //Tokyo
    strcpy(grafo[10].nome, "Tokyo");
    strcpy(grafo[10].nazione, "Giappone");
    grafo[10].abitanti = 13700000;
    grafo[10].lista_adj = NULL;
}

void carica_grafo_test_orientato(Citta grafo[], int num_nodi){
    carica_citta_test(grafo);

    //Creazione archi
    crea_arco(grafo, 0, 1, num_nodi);
    crea_arco(grafo, 0, 4, num_nodi);

    crea_arco(grafo, 1, 0, num_nodi);
    crea_arco(grafo, 1, 2, num_nodi);

    crea_arco(grafo, 2, 1, num_nodi);
    crea_arco(grafo, 2, 3, num_nodi);

    crea_arco(grafo, 4, 0, num_nodi);
    crea_arco(grafo, 4, 1, num_nodi);
    crea_arco(grafo, 4, 5, num_nodi);
    crea_arco(grafo, 4, 6, num_nodi);

    crea_arco(grafo, 5, 1, num_nodi);

    crea_arco(grafo, 6, 7, num_nodi);

    crea_arco(grafo, 8, 9, num_nodi);

    crea_arco(grafo, 9, 8, num_nodi);
    crea_arco(grafo, 9, 10, num_nodi);
}

void carica_grafo_test_non_orientato(Citta grafo [], int num_nodi){
    carica_citta_test(grafo);

    //Creazione archi
    crea_arco(grafo, 0, 1, num_nodi);
    crea_arco(grafo, 1, 0, num_nodi);

    crea_arco(grafo, 0, 4, num_nodi);
    crea_arco(grafo, 4, 0, num_nodi);

    crea_arco(grafo, 1, 2, num_nodi);
    crea_arco(grafo, 2, 1, num_nodi);

    crea_arco(grafo, 2, 3, num_nodi);
    crea_arco(grafo, 3, 2, num_nodi);

    crea_arco(grafo, 4, 1, num_nodi);
    crea_arco(grafo, 1, 4, num_nodi);

    crea_arco(grafo, 4, 5, num_nodi);
    crea_arco(grafo, 5, 4, num_nodi);

    crea_arco(grafo, 4, 6, num_nodi);
    crea_arco(grafo, 6, 4, num_nodi);

    crea_arco(grafo, 5, 1, num_nodi);
    crea_arco(grafo, 1, 5, num_nodi);

    crea_arco(grafo, 6, 7, num_nodi);
    crea_arco(grafo, 7, 6, num_nodi);

    crea_arco(grafo, 8, 9, num_nodi);
    crea_arco(grafo, 9, 8, num_nodi);

    crea_arco(grafo, 9, 10, num_nodi);
    crea_arco(grafo, 10, 9, num_nodi);
}

void aggiungi_nodo(Citta grafo[], int *num_nodi){
    if(*num_nodi == MAX_VERTICI){
        printf("E\' stato raggiunto il numero massimo di nodi\n");
        return;
    }
    else{
        (*num_nodi)++;
        printf("Inserisci il nome della citta\'\n");
        scanf("%[^\n]s", grafo[*num_nodi - 1].nome);
        svuotaBuffer();
        printf("Inserisci il nome della nazione\n");
        scanf("%[^\n]s", grafo[*num_nodi - 1].nazione);
        svuotaBuffer();
        printf("Inserisci il numero di abitanti\n");
        scanf("%d", &grafo[*num_nodi - 1].abitanti);
        svuotaBuffer();

        grafo[*num_nodi - 1].lista_adj = NULL;
    }

}

void crea_arco(Citta grafo[], int id_coda, int id_testa, int num_nodi){
    Node* iter = NULL;
    Node* newNode = NULL;

    if(id_testa >= num_nodi || id_coda >= num_nodi || id_testa < 0 || id_coda < 0)
        return;


    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex_id = id_testa;
    newNode->link = NULL;

    if(grafo[id_coda].lista_adj != NULL){
        iter = grafo[id_coda].lista_adj;

        while (iter->link != NULL)
            iter = iter->link;

        iter->link = newNode;
    }
    else{
        grafo[id_coda].lista_adj = newNode;
    }
}

void stampa_lista_adiacenze(Citta grafo[], int num_nodi){
    int i;
    Node* iter = NULL;

    for(i = 0; i < num_nodi; i++){
        iter = grafo[i].lista_adj;

        if(iter != NULL) {
            printf("%s -> ", grafo[i].nome);

            while (iter->link != NULL) {
                printf("%s -> ", grafo[iter->vertex_id].nome);
                iter = iter->link;
            }
            printf("%s", grafo[iter->vertex_id].nome);
        }
        else
            printf("%s", grafo[i].nome);
        printf("\n");
    }
}

void DFS(Citta grafo[], int visited[], int start_id){
    Node* tmp = NULL;
    int id_next;

    stampaCitta(grafo[start_id]);
    visited[start_id] = true;

    tmp = grafo[start_id].lista_adj;

    while(tmp != NULL){
        id_next = tmp->vertex_id;

        if(visited[id_next] == false)
            DFS(grafo, visited, id_next);
        tmp = tmp->link;
    }
}

void BFS(Citta grafo[], int visited[], int start_id){
    Queue coda;
    Node* tmp = NULL;
    int i;

    stampaCitta(grafo[start_id]);
    visited[start_id] = true;

    /* Inizializza la coda */
    coda.front = NULL;
    coda.back = NULL;
    coda.cont = 0;

    pushQueue(&coda, start_id);

    while(!isEmptyQueue(&coda)){
        i = popQueue(&coda);
        tmp = grafo[i].lista_adj;

        while(tmp != NULL){
            if(visited[tmp->vertex_id] == false){
                pushQueue(&coda, tmp->vertex_id);
                stampaCitta(grafo[tmp->vertex_id]);
                visited[tmp->vertex_id] = true;
            }
            tmp = tmp->link;
        }
    }
}

void cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa){
    Node* iter = NULL;
    Node* temp = NULL;


    if(grafo[id_coda].lista_adj != NULL){
        iter = grafo[id_coda].lista_adj;

        if(iter->vertex_id == id_testa) {
            grafo[id_coda].lista_adj = iter->link;
            free(iter);
            return;
        }
        else {
            while (iter->vertex_id != id_testa && iter != NULL) {
                temp = iter;
                iter = iter->link;
            }

            if (iter == NULL) //Se il vertice inserito non è nella lista di adiacenza
                return;
            else {
                temp->link = iter->link;
                free(iter);
            }
        }
    }
}

void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi){
    cancella_arco_orientato(grafo, id_coda, id_testa);
    cancella_arco_orientato(grafo, id_testa, id_coda);
}

void componenti_connesse(Citta grafo[], int visited[], int num_nodi){
    int i = 0, j = 0;

    while(i < num_nodi){
        if(!visited[i]) {
            printf("%da visita:\n\n", j + 1);
            DFS(grafo, visited, i);
            j++;
        }
        i++;
    }
}

void stampaCitta(Citta citta){
    printf("%s, %s\n", citta.nome, citta.nazione);
    printf("Abitanti: %d\n\n", citta.abitanti);
}

_Bool isEmptyQueue(Queue* coda){
    if(coda->cont == 0)
        return true;
    else
        return false;
}

_Bool isFullQueque(Queue* coda){
    if(coda->cont == DIM_CODA)
        return true;
    else
        return false;
}

void pushQueue(Queue* coda, int vertex){
    Node* newNode = NULL;

    if(isFullQueque(coda))
        printf("Errore Overflow\n");
    else{
        /* Creazione del nuovo nodo */
        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex_id = vertex;
        newNode->link = NULL;

        /* Se la lista è vuota viene fatto un inserimento in testa */
        if(isEmptyQueue(coda)){
            coda->front = newNode;
            coda->back = newNode;
        }
        else{
            coda->back->link = newNode;
            coda->back = newNode;
        }
    }
    coda->cont++;

}

int popQueue(Queue* coda){
    int val;
    Node* temp = NULL;

    if(isEmptyQueue(coda)){
        printf("Errore  Underflow\n");
        val = -1;
    }
    else{
        temp = coda->front;
        val = coda->front->vertex_id;

        if(coda->cont == 1) {
            coda->front = NULL;
            coda->back = NULL;
        }
        else{
            coda->front = coda->front->link;
        }

        coda->cont--;

        free(temp);
    }

    return val;
}

void svuotaBuffer(){
    _Bool inputCorretto = true;

    while (getchar() != '\n')
        inputCorretto = false;

    if (!inputCorretto)
        printf("\nErrore nell'inserimento.\n");
}