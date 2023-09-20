#include <stdio.h>

/* Esercizio 04/10/2022 n° 4
 *
 * Equivalente dell'esercizio 2, ma con variabili di tipo "char",
 * ottenute con la funzione "scanf()"
 */

// entry point
int main() {
    // dichiarazione di A, B e tmp.
    char a, b, tmp;

    // leggo il valore di A e B dall'utente
    printf("Inserisci il valore di A: ");
    // l'operatore "&" restituisce l'indirizzo di memoria della variabile
    scanf(" %c", &a); // lo spazio iniziale cancella tutti i valori speciali (tipo l'invio), è un alternativa al getchat
    //getchar(); // senza questa istruzione, il valore del carattere "invio" per confermare il valore di A viene assegnato a B.
    printf("\nInserisci il valore di B: ");
    scanf(" %c", &b); // tuttavia, inserendo più caratteri, a B viene assegnato il secondo dei caratteri inseriti

    // stampa risultati
    printf("I valori inseriti sono: \n a: %c \n b: %c\n", a, b);
    // printf("I valori inseriti sono: \n a: %d \n b: %d", a, b); stampa i valori ASCII dei caratteri (a=99, b=100)

    // scambio A e B
    tmp = a;
    a = b;
    b = tmp;

    // stampo i valori scambiati
    printf("I valori scambiati sono: \n a: %c \n b: %c", a, b);

    // exit point
    return 0;
}