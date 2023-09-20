/* Esercizio 13/12/2022 n° 3
 *
 * Testo:
 * "Definire una struttura ‘Albergo’ composta dai campi 'numeroStanze', 'prezzo', 'localita',
 * che permetta di acquisire i relativi dati attraverso una procedura
 * passando come parametro l’indirizzo di memoria della stessa.
 * Scrivere poi una seconda procedura che ne permetta la stampa.
 * La struttura va allocata dinamicamente nel main."
 */
#include <stdio.h>
#include <stdlib.h>

// definizione macro
#define LEN 50 // lunghezza della stringa località

// definizioni struct
typedef struct {
    int numeroStanze;
    float prezzo;
    char localita[LEN+1];
} Albergo;


// dichiarazioni subroutine
void acquisisciAlbergo(Albergo *);


int main() {
    // dichiarazione variabili
    Albergo *albergo = NULL;

    // allocazione memoria
    albergo = (Albergo *) malloc(sizeof(Albergo));

    if(albergo != NULL) {
        // invocazione subroutine
        acquisisciAlbergo(albergo);

        // stampa
        printf("\nNumero di stanze dell'albergo: %d", albergo->numeroStanze);
        printf("\nPrezzo di una stanza dell'albergo: %.2f", albergo->prezzo);
        printf("\nLocalita' dell'albergo: %s", albergo->localita);
    } else {
        printf("Impossibile allocare memoria.");
        exit(-1);
    }

    // liberazione memoria
    free(albergo);

    return 0;
}


// definizioni subroutine
/**
 * Acquisisce i dati di un albergo e li inserisce nella variabile
 * di cui viene fornito il puntatore come parametro.
 * @param albergo Il puntatore alla variabile contenente i dati dell'albergo.
 */
void acquisisciAlbergo(Albergo *albergo) {
    printf("\nInserisci il numero di stanze: ");
    scanf("%d", &(albergo->numeroStanze));
    printf("\nInserisci il prezzo di ogni stanza: ");
    scanf("%f", &(albergo->prezzo));
    printf("\nInserisci il nome della località [MAX %d caratteri]: ", LEN);
    scanf(" %50[^\n]s", albergo->localita);
}