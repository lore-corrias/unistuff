#include <stdio.h>

/* Esercizio 07/10/2022
 * Scrivere un programma in cui, dopo aver impostato due numeri, visualizzi la loro somma, prodotto, differenza, quoziente e resto.
 * Assumete che il secondo numero sia diverso da zero.
 */

// entry point
int main() {
    // dichiarazione e assegnazione dei due numeri scelti
    int a = 2, b = 3;

    // stampa delle operazioni
    printf("a+b=%d\na-b=%d\na*b=%d\na/b=%f\na%%d=%d", a+b, a-b, a*b, ((float)a)/b, a%b); // cast di a per permettere la divisione tra float

    // exit point
    return 0;
}