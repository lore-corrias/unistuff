#include <stdio.h>

/** Esercizio 11/10/2022
 *
 * Testo:
 * "Scrivere 3 espressioni matematiche che all'interno utilizzino un operatore prefisso o postfisso
 * Stampare il valore di tutte le variabili implicate nell'operazione prima e dopo il calcolo dell'espressione
 * Commentare opportunamente tutto il codice."
 */

// entry point
int main() {
    // dichiarazione e assegnazione di una variabile con numeri arbitrariamente scelti
    int a = 0, b = 5;

    // espressioni
    printf("Espressione 1) a++ * b / 2: %f.\n", (float)(a++ * b)/2);
    printf("Espressione 2) 3 * a - --b: %d.\n", (3 * a) - --b);
    printf("Espressione 3) (--a + 4 * b) / 5: %f.\n", (float)((--a + 4) * b) / 5);

    /* Esempio di operazioni non definite
     * printf("%d", ++a + ++a + a++);
     * printf("%d", j++ + ++j);
    */

    // exit point
    return 0;
}