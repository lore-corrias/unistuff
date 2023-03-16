#include <stdio.h>

/* Esercizio 25/11/2022 n° 2
 *
 * Testo:
 * "Scrivere una funzione ricorsiva che calcoli l'n-esimo numero di Fibonacci, dove:
 * f(n) = f(n-1)+f(n-2)(la serie di Fibonacci è quindi la seguente: (0) 1 1 2 3 5 8 13 21 ...)"
*/

// dichiarazioni subroutine
int fibonacci(int);


// entry point
int main() {
    // dichiarazioni
    int n_input; // numero in input

    printf("Inserisci un numero: ");
    scanf("%d", &n_input);

    // calcola e stampa il risultato
    printf("Il numero %d della serie di Fibonacci e': %d", n_input, fibonacci(n_input));

    // exit point
    return 0;
}

// definizioni subroutine
/**
 * Calcola l'n-esimo numero della serie di Fibonacci
 *
 * @param n il numero da calcolare
 * @return il numero corrispondente a n nella serie
 */
int fibonacci(int n) {
    if(n <= 2)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}