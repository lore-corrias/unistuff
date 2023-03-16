/* Esercizio 18/12/2022 n° 1
 *
 * Testo:
 * "Scrivere una funzione "duplicate" che utilizzi l'allocazione dinamica per creare una copia di una stringa."
 */
#include <stdio.h>
// librerie
#include <string.h>
#include <stdlib.h>

// dichiarazioni subroutine
char * duplicate(char stringa[]);

int main() {
    // dichiarazioni variabili
    char stringa[40] = "Ciao bello! Come butta?"; // stringa da duplicare
    char *duplicato; // puntatore alla stringa duplicata

    // invocazione subroutine
    duplicato = duplicate(stringa);

    // stampa del risultato
    printf("\nStringa originale: '%s'\n"
           "Stringa duplicata: '%s'", stringa, duplicato);

    return 0;
}


// definizioni subroutine
/**
 * Restituisce il duplicato di una stringa.
 * @param stringa La stringa da duplicare.
 * @return Un puntatore al primo carattere della stringa duplicata.
 */
char * duplicate(char stringa[]) {
    char *duplicato = NULL;
    // allocazione di uno spazio pari alla lunghezza della stringa + 1 (carattere terminale)
    duplicato = (char *) calloc(strlen(stringa)+1, sizeof(char));

    if(duplicato == NULL) {
        printf("\nImpossibile allocare uno spazio di memoria sufficiente.");
        exit(-1);
    }
    strcpy(duplicato, stringa); // copia del contenuto da stringa a duplicato
    return duplicato;
}