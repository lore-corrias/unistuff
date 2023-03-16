#include <stdio.h>

/* Esercizio 24/11/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che acquisisca un numero e stampi un conto alla rovescia a partire dal numero acquisito.
 * Realizzare una procedura che si occupa di stampare il conto alla rovescia."
 */

// dichiarazioni subroutine
void print_countdown(int);


// entry point
int main() {
    // variabili
    int n_input;      // numero letto da tastiera

    // lettura da tastiera
    printf("Inserisci un numero: ");
    scanf("%d", &n_input);

    // chiamata della subroutine
    print_countdown(n_input);

    // exit point
    return 0;
}


// definizioni subroutine
void print_countdown(int start) {
    for(int i = start; i >= 0; i--) {
        printf("\n%d", i);
    }
}