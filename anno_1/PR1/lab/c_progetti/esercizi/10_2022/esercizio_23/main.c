#include <stdio.h>

/* Esercizio 14/10/2022
 *
 * Testo:
 * "Scrivere un programma che chieda all'utente un valore intero e lo memorizzi in una variabile numero.
 * Il programma deve stampare un messaggio che indichi se numero è pari o dispari.
 *
 * Suggerimento: matematicamente, come verificare se un numero è pari o dispari?"
*/

// entry point
int main() {
    // dichiarazione variabile numero
    int numero;

    // leggo il numero dal terminale
    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    // verifica che un numero sia pari o dispari e stampa il risultato
    // (un numero è pari se è divisibile per 2, quindi se numero % 2 == 0)
    numero % 2 == 0 ? printf("Il numero %d è pari.", numero) : printf("Il numero %d è dispari.", numero);

    // exit point
    return 0;
}
