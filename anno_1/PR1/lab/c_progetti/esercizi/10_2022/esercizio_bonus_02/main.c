#include <stdio.h>
#define TOTALE_NUMERI 2.0 // magic number float per il calcolo della media

/* Esercizio 07/10/2022 n° 2
 *
 * Testo:
 * "Scrivere un programma C in cui verranno dichiarati due interi.
 * Assegnare un valore a entrambi gli interi.
 * Stampare, quindi:
 * •La loro somma
 * •Il precedente e il successivo di entrambi
 * •La loro media
 * Non devono essere presenti magic numbers e si deve commentare opportunatamente tutto il codice."
 */

// entry point
int main() {
    // dichiarazione e assegnazione delle variabili
    int a = 3, b = 6;

    // stampo la somma
    printf("La somma di %d e %d è %d.\n", a, b, a + b);
    // stampo il precedente e il successivo
    printf("Il precedente e successivo di a sono rispettivamente %d e %d. Quelli di b, invece, sono %d e %d.\n", a-1, a+1, b-1, b+1);
    // stampo la media
    printf("La media di %d e %d è %f", a, b, (a + b) / TOTALE_NUMERI);

    // exit point
    return 0;
}
