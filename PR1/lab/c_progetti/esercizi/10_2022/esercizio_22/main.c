#include <stdio.h>

/* Esercizio 14/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che acquisisca due valori interi in input ed esegua la divisione tra essi.
 * Nel caso in cui il secondo valore sia 0, il programma deve restituire un messaggio di errore."
*/

// entry point
int main() {
    // dichiarazione variabili
    int a, b;

    // lettura dei valori di a e b da terminale
    printf("Inserisci il valore di a: ");
    scanf("%d", &a);
    printf("Inserisci il valore di b: ");
    scanf("%d", &b);

    // verifica che b =/= 0
    if (b == 0) {
        printf("Attenzione, il valore di b non può essere 0.");
    } else {
        // stampa il valore della divisione
        printf("a/b vale: %.2f", (float)a/b); // cast esplicito per la divisione con la virgola
    }

    // exit point
    return 0;
}
