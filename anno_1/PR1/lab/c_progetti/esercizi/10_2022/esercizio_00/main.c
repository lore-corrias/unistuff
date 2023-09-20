#include <stdio.h>

/*
 * Esercitazione 04/10/2022 n° 1.
 *
 * Testo:
 * "Date tre variabili di tipo intero, a, b e c, assegnare un
 * valore arbitrario a ognuna e valutare i risultati delle seguenti espressioni:
 * * a-b+c
 * * a-b+c*a
 * * (a/b) % c
 * e stamparli poi a schermo"
 */

// entry point
int main() {
    // dichiarazione variabili operazione
    int a, b, c;
    // dichiarazione variabili risultato
    int exp;

    // Assegnamenti
    a = 6;
    b = 4;
    c = 9;

    // Calcoli
    //exp = a-b+c;
    printf("Il risultato dell'operazione e': %d\n", a-b+c);
    //exp = a-b+c*a;
    printf("Il risultato dell'operazione e': %d\n", a-b+c*a);
    //exp = (a/b) % c;
    printf("Il risultato dell'operazione e': %d\n", a-b+c*a);

    // Stampa dei risultati

    // exit point
    return 0;
}