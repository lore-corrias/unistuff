#include <stdio.h>
#include <stdlib.h>
#include <time.h> // librerie per la generazione dei numeri
#include <math.h> // libreria per PI
#define RAGGIO_MIN 2
#define RAGGIO_MAX 20 // valori minimi e massimi per la generazione del raggio

/* Esercizio 11/10/2022 n° 5
 *
 * Testo:
 * "Scrivere un programma che data la misura del raggio di un cerchio ne calcoli l'area e la circonferenza"
*/

// entry point
int main() {
    // dichirazione variabili
    int raggio;
    float area, circonferenza;

    // generazione casuale del valore del raggio
    srand(time(NULL)); // generazione del seme
    raggio = RAGGIO_MIN + rand() % (RAGGIO_MAX - RAGGIO_MIN + 1);

    // calcolo dell'area e della circonferenza
    area = M_PI * pow(raggio, 2);
    circonferenza = M_PI * 2 * raggio;

    // stampa risultati
    printf("Valore generato del raggio della circonferenza: %d", raggio);
    printf("\nValore dell'area della circonferenza: %.3f", area);
    printf("\nValore della circonferenza: %.3f", circonferenza);

    // exit point
    return 0;
}
