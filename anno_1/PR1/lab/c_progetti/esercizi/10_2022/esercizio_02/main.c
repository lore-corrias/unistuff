#include <stdio.h>
#define NUMERO_VARIABILI 3.0 // definisco una macro che contiene il numero totale di variabili

/* Esercizio 04/10/2022, n° 3.
 *
 * Testo:
 * "Dichiarare tre variabili intere, A, B e C, e assegnare dei valori arbitrari.
 * Calcolare la media dei 3 valori, assegnarla a una variabile di tipo float e visualizzarla
 * con 2 cifre decimali.
 * Ripetere l'esercizio dichiarando le variabili iniziali come float."
 */

// entry point
int main() {
    // assegnazione di A, B e C.
    int a = 7, b = 5, c = 16;
    // dichiarazione della variabile "m" per la media
    float m;

    // calcolo della media
    /* il tipo più preciso ha la priorità: se NUMERO_VARIABILI è float,
     * il risultato sarà un float. altrimenti, se tutti gli elementi sono un intero, il risultato sarà intero.
     * Questo è un esempio di "cast implicito", ossia un cambio di tipo dei dati non specificato esplicitamente dall'utente.
     * Un cast esplicito, invece, si effettua in questo modo:
     * m = (float)(a + b + c) / NUMERO_VARIABILI
    */
    m = (a + b + c) / NUMERO_VARIABILI;

    // stampo il valore della media con 2 cifre decimali
    printf("Media di %d, %d e %d: %.2f\n", a, b, c, m);

    // ripeto l'esercizio, ma con le variabili iniziali di tipo float
    float a2 = 7, b2 = 5, c2 = 16;

    // calcolo della media
    m = (a2 + b2 + c2) / NUMERO_VARIABILI;

    // stampo la media
    printf("Media di %f, %f e %f: %.2f", a2, b2, c2, m);

    // exit point
    return 0;
}