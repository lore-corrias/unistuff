#include <stdio.h>
#define T_CONV_MPH_TO_KMH 1.61 // tasso di conversione mph -> kmh

/* Esercizio 07/10/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma che permetta di gestire la conversione mph –kmh(miglia orarie in km orari) sapendo che
 * il tasso di conversione mph -kmh è pari a 1.61 (1 mph = 1,61 kmh).
 * Associare tale tasso ad una macro chiamata T_CONV_MPH_TO_KMH. Assegnare alla variabile velocitaMph un valore a piacere
 * e stampare il seguente messaggio in output:
 * Velocita in mph: ___.__ mph.Velocita in kmh: ___.__ kmh.
 * Dove ___.__ dovrà essere sostituito dal valore corrispondente e dovrà essere stampata solo una cifra decimale.
 * Non devono essere presenti magic numbers e si deve commentare opportunatamente tutto il codice."
 */

// entry point
int main() {
    // dichiarazione e assegnazione di velocitaMph e calcolo di velocitaKmh
    float velocitaMph = 32.5;
    float velocitaKmh = velocitaMph * T_CONV_MPH_TO_KMH;

    // stampa del messaggio di conversione
    printf("Velocità in mph: %.1f. Velocità in kmh: %.1f", velocitaMph, velocitaKmh);

    // exit point
    return 0;
}