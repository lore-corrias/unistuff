#include <stdio.h>

/* Esercizio 21/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che esegua la divisione tra due numeri,
 * chiedendo di inserire nuovamente il divisore finché questo
 * non è diverso (non è diverso == uguale) da 0.
 * Nel caso sia 0, stampare un messaggio di errore e fare gli auguri al prof. Loddo"
*/

// entry point
int main() {
    // dichiarazione variabili
    float dividendo, divisore, divisione;

    // lettura dei dati da tastiera
    printf("Inserisci il dividendo: ");
    scanf("%f", &dividendo); // dividendo
    printf("\nInserisci il divisore: ");
    scanf("%f", &divisore); // divisore

    // controllo che il divisore sia != 0
    while(divisore == 0) { // il programma chiede il numero finché divisore != 0
        printf("\nErrore: inserisci un divisore che sia diverso da 0: ");
        scanf("%f", &divisore);
        printf("\nP.S.: auguri prof. Loddo!");
    }

    // calcola e stampa il risultato
    divisione = dividendo / divisore;
    printf("Il risultato della divisione tra %.3f e %.3f è %.3f.", dividendo, divisore, divisione);

    // exit point
    return 0;
}
