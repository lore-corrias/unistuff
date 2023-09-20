#include <stdio.h>
#define TOTALE_NUMERI 5.0 // definisco una macro che contenga il numero di elementi presi in input (float per il risultato della divisione)

/* Esercizio 06/10/2022 n° 5
 *
 * Testo:
 * "Scrivere un programma che chieda cinque numeri in input e
 * ne visualizzi somma e media.
 * N.B.: gestire eventuali problematiche legate ai tipi."
 */

// entry point
int main() {
    // dichiaro le variabili con i numeri
    int a, b, c, d, e;
    float media;

    // ricevo i numeri in input
    printf("Numero a: ");
    scanf("%d", &a);
    printf("\nNumero b: ");
    scanf("%d", &b);
    printf("\nNumero c: ");
    scanf("%d", &c);
    printf("\nNumero d: ");
    scanf("%d", &d);
    printf("\nNumero e: ");
    scanf("%d", &e);

    // calcolo e stampo la media
    media = (a + b + c + d + e) / TOTALE_NUMERI;
    printf("La media dei numeri %d, %d, %d, %d e %d vale %f", a, b, c, d, e, media);

    // exit point
    return 0;
}