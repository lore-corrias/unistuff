#include <stdio.h>
// librerie
#include <string.h> // per la funzione strlen()

/* Esercitazione 24/11/2022 n° 5
 *
 * Testo:
 * "Scrivere una funzione che prenda come parametro un carattere e:
 * •se è una lettera minuscola, restituisce una lettera maiuscola;
 * •se è una lettera maiuscola, restituisce una lettera minuscola;
 * •lascia invariati tutti gli altri caratteri.
 *
 * Modificare successivamente una stringa dichiarata nel main modificando
 * ogni carattere utilizzando la funzione appena descritta."
*/

// dichiarazione subroutine
char charLowUp(char);

// entry point
int main() {
    // dichiarazione variabili
    char stringa[] = "CiAooO MooNdO"; // stringa su cui applicare la subroutine

    // stampa stringa attuale
    printf("Stringa originale: %s", stringa);

    // iterazione sui caratteri della stringa
    for(int i = 0; i < strlen(stringa) && stringa[i] != '\0'; i++) {
        stringa[i] = charLowUp(stringa[i]); // applicazione della subroutine a ogni carattere
    }

    // stampa del risultato
    printf("\nNuova stringa: %s", stringa);

    return 0;
}

// definizione subroutine
/**
 * Restituisce lo stesso carattere se non è una lettera.
 * Restituisce la lettera in maiuscolo se è minuscola, e viceversa.
 *
 * @param carattere il carattere su cui applicare la funzione
 * @return il carattere modificato
 */
char charLowUp(char carattere) {
    // estremi dei range delle lettere maiuscole-minuscole
    char minLow = 'a', maxLow = 'z', minUp = 'A', maxUp = 'Z';
    // distanza tra una lettera maiuscola e una minuscola
    int distance = 'a'-'A';

    // controllo sul carattere fornito
    if(carattere >= minLow && carattere <= maxLow)
        return carattere-distance;                      // minuscolo -> maiuscolo
    else if(carattere >= minUp && carattere <= maxUp)
        return carattere+distance;                      // maiuscolo -> minuscolo
    else
        return carattere;
}