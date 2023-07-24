#include "binary_search_hotel.h"


/**
 * Permette di trovare la posizione di un hotel in una lista ordinata, a partire dal nome,
 * in ordine alfabetico.
 * L'utente inserisce tutti gli hotel all'interno di una lista e ottiene l'indice a cui corrisponde
 * l'elemento ricercato. La lista viene ordinata attraverso un algoritmo di selection sort (vedi la funzione
 * in basso), e l'elemento è ricercato tramite binary search (vedi sempre in basso)
 */
void searchHotels() {
    int nHotels, hotelCercatoIndice;
    Hotel* hotels;
    char hotelCercato[DIM_NOME] = "";

    printf("\nQuanti hotel vuoi inserire?\n"
           "?) ");
    do {
        scanf("%d", &nHotels);
        if(nHotels <= 0)
            printf("\nInserisci un numero > 0.\n"
                   "?) ");
    } while(nHotels <= 0);

    hotels = creaHotel(nHotels);

    printf("\nBene! Ora inserisci il nome dell'hotel da trovare: ");
    do {
        scanf(" %[^\n]50s", hotelCercato);
        if(strcmp(hotelCercato, "") == 0)
            printf("Inserisci un nome non vuoto.");
    } while(strcmp(hotelCercato, "") == 0);

    hotelCercatoIndice = binarySearchHotels(hotels, hotelCercato, nHotels);

    if(hotelCercatoIndice == -1) {
        printf("\nL'hotel inserito non è stato trovato.");
    } else {
        printf("\nL'hotel inserito si trova in posizione %d°", hotelCercatoIndice+1);
    }
}


/**
 * Chiede all'utente di inserire i dati di un hotel,
 * restituendo un array ordinato in ordine alfabetico
 * per il nome di ogni hotel.
 *
 * @param nHotel Il numero di hotel da inserire.
 * @return Un array ordinato in ordine alfabetico per il nome di ogni hotel
 */
Hotel* creaHotel(int nHotel) {
    Hotel* hotels = NULL;
    hotels = calloc(nHotel, sizeof(Hotel));
    if(hotels == NULL) {
        printf("Impossibile allocare memoria dinamicamente.");
        exit(-1);
    }

    // condizione per la ripetizione del ciclo do-while
    bool condizione;
    for(int i = 0; i < nHotel; i++) {
        printf("\n--------- Hotel n° %d ---------\n", i+1);
        // nome dell'hotel
        printf("Inserisci il nome dell'hotel (max %d caratteri): ", DIM_NOME);
        do {
            scanf(" %[^\n]50s", hotels[i].nome);
            condizione = strcmp(hotels[i].nome, "") == 0;
            if(condizione)
                printf("Inserisci un nome non vuoto: ");
        } while(condizione);

        // prezzo a notte dell'hotel
        printf("Inserisci il prezzo a notte dell'hotel: ");
        do {
            scanf("%lf", &hotels[i].prezzo_notte);
            condizione = hotels[i].prezzo_notte <= 0;
            if(condizione)
                printf("Inserisci un prezzo valido: ");
        } while(condizione);

        // recensioni dell'hotel
        printf("Inserisci il numero di recensioni dell'hotel (da 1 a 5): ");
        do {
            scanf("%d", &hotels[i].recensione);
            condizione = hotels[i].recensione < 1 || hotels[i].recensione > 5;
            if(condizione)
                printf("Inserisci un numero tra 1 e 5: ");
        } while(condizione);
    }

    // ordinamento della lista
    selectionSortHotels(hotels, nHotel);

    return hotels;
}

/**
 * Versione iterativa del selection sort, ma per ordinare un array di stringhe
 * (ossia i nomi degli hotel).
 *
 * @param hotels L'array che contiene gli hotel da ordinare.
 * @param dimension La dimensione dell'array da ordinare.
 */
void selectionSortHotels(Hotel hotels[], int dimension) {
    int i, j, min;
    // scorri tutti gli elementi fino al penultimo
    for(i = 0; i <= dimension-2; i++) {
        // assumi che l'elemento minore sia quello corrente
        min = i;
        for(j = i+1; j <= dimension-1; j++) {
            // trova l'elemento minore tra quelli successivi a i
            // la comparazione di stringhe avviene in ordine alfabetico
            if (strcmp(hotels[j].nome, hotels[min].nome) < 0) {
                min = j;
            }
        }

        // scambia le posizioni di i e dell'elemento minore
        Hotel tmp = hotels[i];
        hotels[i] = hotels[min];
        hotels[min] = tmp;
    }
}


/**
 * Ricerca binaria di un hotel in una lista a partire dal suo nome.
 *
 * @param hotels L'array di hotel.
 * @param hotelRic Il nome dell'hotel da cercare.
 * @param dimension La dimensione dell'array.
 * @return L'indice a cui è associato l'hotel cercato, -1 se non è trovato.
 */
int binarySearchHotels(Hotel hotels[], char* hotelRic, int dimension) {
    // inizializzazione delle variabili che indicano gli estremi della ricerca
    int primo = 0, ultimo = dimension-1, mezzo;

    // il ciclo itera finché tutte le metà necessarie non sono state analizzate
    while(primo <= ultimo) {
        // calcolo dell'elemento di mezzo del range
        mezzo = (primo + ultimo) / 2;
        // la comparazione di stringhe avviene in ordine alfabetico
        if(strcmp(hotelRic, hotels[mezzo].nome) < 0) {
            // l'elemento si trova nella metà precedente
            ultimo = mezzo - 1;
        } else if(strcmp(hotelRic, hotels[mezzo].nome) == 0) {
            // elemento trovato
            return mezzo;
        } else {
            // l'elemento si trova nella metà successiva
            primo = mezzo + 1;
        }
    }

    // se il codice è raggiunto, l'elemento non è stato trovato
    return -1;
}