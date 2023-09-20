#include <stdio.h>
// librerie
#include <string.h>

// macro
#define N 40

/* Esercizio 18/11/2022 n° 3
 * Testo:
 * "Scrivere un programma in cui si dichiarano due stringhe di dimensione N,
 * definita mediante direttiva #define, e si acquisiscono entrambe in input.
 * Il programma deve copiare la seconda stringa all'interno della prima,
 * senza usare la strcpy. Stampare le stringhe prima e dopo l'operazione di copia.
 */

// entry point
int main() {
    // dichiarazioni
    char s1[N+1], s2[N+1];  // dichiarazioni stringhe
    int i;                  // contatore ciclo

    // acquisizione in input
    printf("Inserisci la prima stringa di %d caratteri: ", N);
    scanf("%40[^\n]s", s1);
    printf("\nInserisci la seconda stringa di %d caratteri: ", N);
    scanf(" %40[^\n]s", s2);

    // copia di s2 su s1
    // strlen() si assicura che il ciclo non acceda a elementi dell'array non inizializzati
    for(i = 0; i <= strlen(s1) && i <= strlen(s2); i++) {
        s1[i] = s2[i];
    }

    // stampa
    printf("\nStringa S1: %s", s1);
    printf("\nStringa S2: %s", s2);

    // exit point
    return 0;
}
