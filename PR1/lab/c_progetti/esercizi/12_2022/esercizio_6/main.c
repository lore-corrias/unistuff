/* Esercizio 06/12/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma che invochi una procedura che, ricevuti in ingresso tre valori
 * e l’indirizzo di memoria di due variabili (min e max) definite nel main,
 * memorizzi i valori minimo e massimo all’interno delle relative variabili.
 * Effettuare la stampa poi direttamente nel main."
 */
#include <stdio.h>


// dichiarazione subroutine
void minimoMassimo(int a, int b, int c, int *max, int *min);


int main() {
    // dichiarazione variabili
    int a = 2, b = 3, c = 4, *max, *min;

    // invocazione subroutine
    minimoMassimo(a, b, c, max, min);

    // stampa
    printf("Il maggiore tra %d, %d e %d e' %d, il minore e' %d.", a, b, c, *max, *min);

    return 0;
}


// definizione subroutine
/**
 * Determina il minore e il maggiore tra a, b e c e li memorizza
 * negli indirizzi di memoria min e max.
 * @param a Il primo numero.
 * @param b Il secondo numero.
 * @param c Il terzo numero.
 * @param max Puntatore alla variabile contenente il massimo dei tre numeri.
 * @param min Puntatore alla variabile contenente il minimo dei tre numeri.
 */
void minimoMassimo(int a, int b, int c, int *max, int *min) {
    if(a < b && a < c) {
        (*min) = a;
        if(b < c)
            (*max) = c;
        else
            (*max) = b;
    } else if(b < a && b < c) {
        (*min) = b;
        if (a < c)
            (*max) = c;
        else
            (*max) = a;
    } else {
        (*min) = c;
        if(a < b)
            (*max) = b;
        else
            (*max) = a;
    }
}