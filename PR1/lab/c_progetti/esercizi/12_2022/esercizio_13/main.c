/* Esercizio 18/12/2022 n° 2.
 *
 * Testo:
 * "Scrivere una funzione che calcoli la media degli elementi di un array allocato dinamicamente."
 */
#include <stdio.h>
// librerie
#include <stdlib.h>

// dichiarazioni subroutine
float media(int n, float elementi[]);

int main() {
    // dichiarazione variabili
    int n; // numero di elementi di cui fare la media
    float *elementi; // puntatore all'array degli elementi
    float n_media; // media calcolata dalla subroutine

    // richiesta dei dati dall'utente
    printf("Inserisci il numero di elementi di cui fare la media: ");
    scanf("%d", &n);

    // allocazione dinamica
    elementi = (float *) calloc(n, sizeof(float));
    if(elementi == NULL) {
        printf("\nImpossibile allocare ulteriore memoria.");
        exit(-1);
    }

    // inizializzazione dell'array
    for(int i = 0; i < n; i++) {
        printf("\nInserisci il %d° elemento: ", i+1);
        scanf("%f", (elementi + i));
    }

    // invocazione subroutine e stampa
    n_media = media(n, elementi);
    printf("\nMedia degli elementi inseriti: %.2f", n_media);

    return 0;
}


// definizioni subroutine
/**
 * Calcola la media degli elementi di un array allocato dinamicamente.
 * @param n Numero degli elementi dell'array.
 * @param elementi L'array degli elementi di cui calcolare la media.
 * @return La media degli elementi
 */
float media(int n, float elementi[]) {
    float somma; // somma degli elementi dell'array
    for(int i = 0; i < n; i++) {
        somma += *(elementi + i); // scorrimento dell'array tramite puntatore
    }
    return somma / n; // restituzione della media calcolata
}