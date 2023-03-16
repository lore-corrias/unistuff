#include <stdio.h>

/* Esercizio 14/10/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma in cui vengono acquisiti due numeri dall'utente.
 * Il programma deve dire se il primo numero è multiplo del secondo, oppure stampare
 * un messaggio per comunicare che il primo numero non è multiplo del secondo"
*/

// entry point
int main() {
    // dichiarazione variabili dei due numeri
    int a, b;

    // leggo il valore dei numeri da terminale
    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);

    // verifico che a sia multiplo di b e stampo il risultato
    (b != 0 && a % b == 0) ? printf("%d è multiplo di %d", a, b) : printf("%d non è multiplo di %d", a, b);

    // exit point
    return 0;
}
