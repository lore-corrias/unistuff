#include <stdio.h>
// libreria per le stringe
#include <string.h>

// macro
#define LUNGHEZZA 30 // lunghezza della stringa

/* Esercizio 18/11/2022 n° 2
 * Testo:
 * "Scrivere un programma che acquisisca una stringa
 * e conti il numero di caratteri spazio inseriti dall'utente,
 * in due versioni diverse:
 *  1.utilizzando la strlen(utilizzando un FOR),
 *  2.con un ciclo che si ferma quando incontra il carattere di escape‘\0' (utilizzando un WHILE).
 *  Quale soluzione sarebbe preferibile? Perché?"
 */

// entry point
int main() {
    // inizializzazione
    char stringa[LUNGHEZZA + 1];    // stringa
    int i, spazi = 0;               // contatori

    // lettura della stringa
    printf("Inserisci una stringa di %d caratteri: ", LUNGHEZZA);
    scanf("%30[^\n]s", stringa);

    // conteggio del numero di spazi: for
    for(i = 0; i < strlen(stringa); i++) {
        if(stringa[i] == ' ')
            spazi++;
    }
    printf("\nSpazi contati con il ciclo for: %d.", spazi);

    // conteggio del numero di spazi: while
    spazi = 0, i = 0; // reset dei contatori
    while(stringa[i] != '\0') {
        if(stringa[i] == ' ')
            spazi++;
        i++;
    }
    printf("\nSpazi contati col ciclo while: %d", spazi);

    // exit point
    return 0;
}
