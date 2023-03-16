#include <stdio.h>
// macro
#define LUNGHEZZA 10
// range lettere maiuscole-minuscole
#define PRIMA_MINUSCOLA 'a'
#define ULTIMA_MINUSCOLA 'z'
#define PRIMA_MAIUSCOLA 'A'
#define ULTIMA_MAIUSCOLA 'Z'
// distanza nella tabella ascii tra una lettera maiuscola e la corrispettiva minuscola
#define DISTANZA ('a' - 'A')

/* Esercitazione 18/11/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che acquisisca una stringa e la modifichi
 * trasformando tutti i caratteri minuscoli in maiuscoli e viceversa.
 * Tutti gli altri caratteri vanno lasciati inalterati."
 */

// entry point
int main() {
    // inizializzazioni
    char stringa[LUNGHEZZA + 1];    // stringa
    int i;                          // contatore ciclo for

    // acquisizione stringa;
    printf("Inserisci una stringa di %d caratteri: ", LUNGHEZZA);
    scanf("%10[^\n]s", stringa); // leggi solo i primi 10 caratteri, spazi compresi

    // ciclo per la modifica
    for(i = 0; i <= LUNGHEZZA && stringa[i] != '\0'; i++) {
        if(stringa[i] >= PRIMA_MAIUSCOLA && stringa[i] <= ULTIMA_MAIUSCOLA) {
            // la lettera è maiuscola, trasformo in minuscola aggiungendo la distanza
            stringa[i] += DISTANZA;
        } else if(stringa[i] >= PRIMA_MINUSCOLA && stringa[i] <= ULTIMA_MINUSCOLA) {
            // la lettera è minuscola, trasformo in maiuscola sottraendo la distanza
            stringa[i] -= DISTANZA;
        } // se il carattere non è una lettera, non fare nulla
    }

    // stampa della stringa modificata
    printf("Stringa con i caratteri modificati: %s", stringa);

    // exit point
    return 0;
}
