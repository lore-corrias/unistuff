#include <stdio.h>
#define COEFFICIENTE_GRADO_4 5
#define COEFFICIENTE_GRADO_3 (-8)
#define COEFFICIENTE_GRADO_2 4
#define COEFFICIENTE_GRADO_1 3
#define TERMINE_NOTO (-4)
// definizione delle macro con i coefficienti dell'equazione e il termine noto

/* Esercizio 06/10/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma che permetta il calcolo del polinomio 5x^4-8x^3+4x^2+3x-4.
 * Assegnare alla variabile x un valore a piacere e stampare il risultato a video.
 */

// entry point
int main() {
    // definizione della variabile polinomio, che contiene il risultato finale.
    int polinomio;
    //definizione e assegnazione della variabile x
    int x = 23;

    // calcolo del polinomio
    polinomio = COEFFICIENTE_GRADO_4 * (x*x*x*x) + COEFFICIENTE_GRADO_3 * (x*x*x) + COEFFICIENTE_GRADO_2 * (x*x) + COEFFICIENTE_GRADO_1 * x + TERMINE_NOTO;

    // stampa a schermo del risultato
    printf("Il polinomio 5x^4-8x^3+4x^2+3x-4, in funzione della variabile x=%d, vale %d", x, polinomio);

    // exit point
    return 0;
}