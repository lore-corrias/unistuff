#include <stdio.h>

/* Esercizio 25/11/2022 n° 1
 *
 * Testo:
 * "Scrivere una funzione ricorsiva che sommi i numeri da 0 a n (passato in input)"
*/

// definizioni subroutine
int somma_n(int);


// entry point
int main() {
    // dichiarazioni
    int n_input; // numero letto in input

    // lettura
    printf("Inserisci un numero: ");
    scanf("%d", &n_input);

    // calcolo della somma e stampa
    printf("La somma dei primi %d numeri vale: %d", n_input, somma_n(n_input));

    // exit point
    return 0;
}

// dichiarazioni subroutine
/**
 * Funzione ricorsiva per il calcolo della somma dei primi "n" numeri naturali
 *
 * @param n i primi "n" numeri naturali di cui effettuare la somma
 * @return la somma
 */
int somma_n(int n) {
    if(n == 0) {
        return 0;
    }
    return n + somma_n(n-1);
}