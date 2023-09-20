/* Esercitazione parziale 16/12/2022
 * 1) Definire una struttura 'Albergo' composta dai campi 'nome',
 * 'numeroStanze', 'prezzo', 'localita', tipologia(HOTEL, BNB, OSTELLO, AGRITURISMO)
 * 2) Permettere di acquisire i relativi dati attraverso una procedura passando
 * come parametro l'indirizzo di memoria della stessa.
 */
#include <stdio.h>
// librerie
#include <stdlib.h>
// definizioni macro
#define LEN_NOME 30 // lunghezza della stringa del nome dell'hotel
#define LEN_LOC 40 // lunghezza della stringa della località dell'hotel


// definizione enumeratori
typedef enum {
    HOTEL=1, BNB, OSTELLO, AGRITURISMO
} tipologiaHotel;

// definizione strutture
typedef struct {
    char nome[LEN_NOME+1];
    int numeroStanze;
    float prezzo;
    char localita[LEN_LOC+1];
    tipologiaHotel tipologia;
} Albergo;


// dichiarazione subroutine
void acquisisciDati(Albergo*);


// entry point
int main() {
    // dichiarazione variabili
    Albergo *albergo = NULL;

    // allocazione di memoria
    albergo = (Albergo*) malloc(sizeof(Albergo));

    // inizializzazione
    if(albergo == NULL) {
        printf("Impossibile allocare la memoria sufficiente.");
        exit(-1);
    }
    // invocazione subroutine
    acquisisciDati(albergo);

    // stampa dei dati acquisiti
    printf("\nNome dell'albergo: %s", albergo->nome);
    printf("\nNumero di stanze dell'albergo: %d.", albergo->numeroStanze);
    printf("\nPrezzo di una stanza dell'albergo: %.2f.", albergo->prezzo);
    printf("\nLocalità dell'albergo: '%s'.", albergo->localita);
    printf("\nTipologia dell'albergo: ");
    switch (albergo->tipologia) {
        case HOTEL:
            printf("Hotel.");
            break;
        case BNB:
            printf("BNB.");
            break;
        case OSTELLO:
            printf("Ostello.");
            break;
        case AGRITURISMO:
            printf("Agriturismo.");
            break;
        default:
            printf("tipologia non riconosciuta.");
            break;
    }

    // dereferenziazione della memoria
    if(albergo != NULL) {
        free(albergo);
        albergo = NULL;
    }
    // exit point
    return 0;
}


// definizione subroutine
void acquisisciDati(Albergo *albergo) {
    printf("\nInserisci il nome dell'albergo (max %d caratteri): ", LEN_NOME);
    scanf("%30[^\n]s", albergo->nome);
    printf("\nInserisci il numero di stanze dell'albergo: ");
    scanf("%d", &(albergo->numeroStanze));
    printf("\nInserisci il prezzo di una stanza: ");
    scanf("%f", &(albergo->prezzo));
    printf("Inserisci la localita' dell'albergo (max %d caratteri): ", LEN_LOC);
    scanf(" %40[^\n]s", albergo->localita);
    do {
        printf("Inserisci la tipologia dell'albergo:\n"
               "%d) Hotel\n"
               "%d) BNB\n"
               "%d) Ostello\n"
               "%d) Agriturismo\n"
               ": ", HOTEL, BNB, OSTELLO, AGRITURISMO);
        scanf("%d", &(albergo->tipologia));
    } while(albergo->tipologia < HOTEL || albergo->tipologia > AGRITURISMO);
}
