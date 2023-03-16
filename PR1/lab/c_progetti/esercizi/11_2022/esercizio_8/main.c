#include <stdio.h>

/* Esercizio 24/11/2022 n° 4
 *
 * Testo:
 * "Scrivere una funzione che faccia il clamp tra 50 e 100 di un numero passato come parametro.
 * ES: x: 7 -> f: 50 –x: 75 -> f: 75 –x: 135 -> f: 100"
*/

// dichiarazione subroutine
int clamp(int, int, int);

// entry point
int main() {
    // esecuzione e stampa della subroutine
    printf("%d", clamp(75, 50, 100));

    // exit point
    return 0;
}

// definizione subroutine
/**
 * Effettua il Clamp di un numero.
 * n < min        -> min
 * n > max        -> max
 * min < n < max  -> n
 *
 * @param n il numero di cui effettuare il clamp
 * @param min il minimo dell'intervallo
 * @param max il massimo dell'intervallo
 * @return clamp del numero fornito
 */
int clamp(int n, int min, int max) {
    if(n < min)
        return min;
    else if(n > max)
        return max;
    else
        return n;
}