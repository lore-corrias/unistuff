/* Esercizio 18/12/2022 n° 4
 *
 * Testo:
 * "Scrivere un programma in cui viene allocato dinamicamente un vettore di dimensione scelta in input dall'utente.
 * Il vettore deve essere popolato con numeri interi, positivi e negativi, generati casualmente.
 * Scrivere poi una subroutine che riceve come parametro il vettore e inverte l'ordine degli elementi.
 * Visualizzare dal main sia il vettore originale che quello ottenuto dopo la chiamata della funzione.
 */
#include <stdio.h>
// librerie
#include <stdlib.h>
#include <time.h>
// macro
#define MIN (-30)
#define MAX 30


// dichiarazioni subroutine
int generaNumero(int, int);
void popolaVettore(int, int[], int, int);
void invertiVettore(int, int[]);
void stampaVettore(int, int[]);


// entry point
int main() {
    int n; // dimensione del vettore da generare
    int *vettore; // vettore da popolare

    srand(time(NULL)); // inizializzazione seed

    // lettura in input
    do {
        printf("Inserisci la grandezza del vettore: ");
        scanf("%d", &n);
        if(n <= 0)
            printf("\nErrore: inserisci un numero positivo.\n");
    } while(n <= 0);

    // allocazione dinamica
    vettore = (int *) calloc(n, sizeof(int));
    if(vettore == NULL) {
        printf("\nImpossibile allocare sufficiente memoria.");
        exit(-1);
    }

    // invocazione subroutine popolazione
    popolaVettore(n, vettore, MIN, MAX);
    // stampa
    printf("\nVettore popolato:\n");
    stampaVettore(n, vettore);

    // invocazione subroutine inversione
    invertiVettore(n, vettore);
    //  stampa
    printf("\nVettore invertito:\n");
    stampaVettore(n, vettore);

    // deallocazione memoria
    free(vettore);

    // exit point
    return 0;
}


// definizioni subroutine
/**
 * Genera un numero intero compreso tra min e max.
 * @param min Il minimo dell'intervallo di generazione.
 * @param max Il massimo dell'intervallo di generazione.
 * @return Il numero randomico generato
 */
int generaNumero(int min, int max) {
    // formula per la generazione randomica
    return min + rand() % (max - min + 1);
}

/**
 * Inizializza gli elementi del vettore fornito di dimensione n
 * con valori generati casualmente tra min e max dalla funzione generaNumero()
 * @param n Il numero di elementi del vettore.
 * @param vettore Il vettore di cui generare gli elementi.
 * @param min Il minimo dell'intervallo di generazione degli elementi.
 * @param max Il massimo dell'intervallo di generazione degli elementi.
 */
void popolaVettore(int n, int vettore[], int min, int max) {
    for(int i = 0; i < n; i++)
        *(vettore + i) = generaNumero(min, max);
}

/**
 * Dato un vettore, inverte il suo ordine
 * @param n Il numero di elementi.
 * @param vettore Il vettore da invertire.
 */
void invertiVettore(int n, int vettore[]) {
    int tmp; // variabile temporanea usata per invertire i due valori speculari
    for(int i = n-1; i > (n-1)/2; i--) {
        // swap dei valori inversi
        tmp = *(vettore + i);
        *(vettore + i) = *(vettore + (n-1) - i);
        *(vettore + (n-1) - i) = tmp;
    }
}

/**
 * Stampa un vettore di n elementi.
 * @param n Il numero di elementi del vettore.
 * @param vettore Il vettore da stampare.
 */
void stampaVettore(int n, int vettore[]) {
    for(int i = 0; i < n; i++)
        printf("%d ", vettore[i]);
}