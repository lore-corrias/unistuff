#include <stdio.h>
#define EUR_GBP 0.84 // macro che definisce il tasso di cambio euro -> sterlina

/* Esercizio 06/10/2022 n°2
 *
 * Testo:
 * "Scrivere un programma che permetta di gestire la conversione Euro - Sterlina,
 * sapendo che il tasso di cambio Euro-Sterlina è pari a 0.84 (1 euro -> 0.84 sterline).
 * Associare tale tasso ad una macro chiamata EUR_GBP. Assegnare alla variabile importoEuro un valore
 * a piacere e stampare il seguente messaggio in output: Importo in sterline pari a ____.__ GBP.
 * Dove ____.__ dovrà essere sostituito dal valore corrispondente e dovranno essere stampate solo due
 * cifre decimali.
 * Nessun magic numbers, commentare bene.
 * Suggerimento: usare i float."
 */

// entry point
int main() {
    // dichiarazione e assegnazione della variabile importoEuro
    float importoEuro = 15.63;

    // stampa del messaggio
    printf("Importo in sterline pari a %.2f GBP", importoEuro * EUR_GBP);

    // exit point
    return 0;
}
