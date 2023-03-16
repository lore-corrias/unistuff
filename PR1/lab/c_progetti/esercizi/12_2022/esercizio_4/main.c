#include <stdio.h>

/* Esercizio 06/12/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma per lo scambio di due variabili. In particolare,
 * le due variabili vanno dichiarate nel maine lo scambio deve essere effettuato da una procedura.
 * Stampare il valore delle variabili prima e dopo lo scambio."
 */



// dichiarazione subroutine
void scambia(int *a, int *b);


int main() {
    // dichiarazione variabili
    int a = 2, b = 3;           // variabili contenenti i numeri da scambiare
    int *p1 = &a, *p2 = &b;     // puntatori passati alla subroutine

    // stampa delle variabili
    printf("A prima dello scambio: %d. B prima dello scambio: %d.", a, b);

    // invocazione della subroutine e stampa
    scambia(p1, p2);
    printf("\nA dopo lo scambio: %d. B dopo lo scambio: %d.", a, b);

    return 0;
}


// definizione subroutine
void scambia(int *p1, int *p2) {
    int tmp; // variabile temporanea per lo scambio
    tmp = *(p1);
    *(p1) = *(p2);
    *(p2) = tmp; // inversione delle variabili
}
