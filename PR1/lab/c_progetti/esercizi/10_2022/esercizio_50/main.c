#include <stdio.h>
#include <math.h> // libreria per pow()
#define INIZIO 1 // inizio della successione di quadrati

/* Esercizio 02/11/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che chieda all'utente un numero n e stampi
 * tutti i quadrati dispari compresi tra 1 e n, al contrario.
 * Es: inserendo 10, il programma deve stampare la successione 81, 49, 25, 9, 1."
*/


// entry point
int main() {
    // dichiarazione variabili
    int n, quadrato;

    // lettura di n da tastiera
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    // controllo la validità di n
    if (n > 1) {
        // stampa della successione
        printf("Successione:");
        for(int i = 1; i < n; i++) {
            printf("\n%d", (int)pow(i, 2));
        }
    } else {
        printf("\nErrore: inserisci un numero maggiore di uno.");
    }

    // exit point
    return 0;
}
