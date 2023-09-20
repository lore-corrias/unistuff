#include <stdio.h>
#include <math.h>
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
 * Assegnare alla variabile x un valore letto in input e stampare il risultato a video.
 * N.B.: usare la libreria math.h per il calcolo della potenza.
 */

// entry point
int main() {
    // definizione della variabile polinomio, che contiene il risultato finale.
    double polinomio;
    // definizione della variabile gradoTotale, che contiene il grado totale del polinomio
    double gradoTotale = 4;
    //definizione della variabile x
    double x;

    // lettura in input della variabile x:
    printf("Inserisci il valore di x: ");
    scanf("%lf", &x);

    // calcolo dei valori di x
    double x_4 = pow(x, gradoTotale--); // diminuisco sempre di uno il grado totale per farlo corrispondere all'esponente attuale di x
    double x_3 = pow(x, gradoTotale--);
    double x_2 = pow(x, gradoTotale--);
    double x_1 = pow(x, gradoTotale);

    // calcolo del polinomio
    polinomio = COEFFICIENTE_GRADO_4 * x_4 + COEFFICIENTE_GRADO_3 * x_3 + COEFFICIENTE_GRADO_2 * x_2 + COEFFICIENTE_GRADO_1 * x + TERMINE_NOTO;

    // stampa a schermo del risultato
    printf("Il polinomio 5x^4-8x^3+4x^2+3x-4, in funzione della variabile x=%lf, vale %lf", x, polinomio);

    // exit point
    return 0;
}