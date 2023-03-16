#include <stdio.h>
// librerie
#include <stdbool.h>
#include <string.h>

// macro
#define L 15

/*
 * Esercizio 30/11/2022 n° 2
 *
 * Testo:
 * "Scrivere un programma che prenda in ingresso una stringa e stampi in output
 * se la stringa è palindroma. Una stringa è palindroma se
 * può essere letta nello stesso modo da sinistra verso destra e da destra verso sinistra.
 *
 * Esempio: "anna" è palindroma"
 */

// dichiarazione subroutine
bool isPalindrome(char s1[]);


// entry point
int main() {
    // dichiarazioni variabili
    char stringa[L];

    // lettura da tastiera
    printf("Inserisci la stringa (max. %d caratteri): ", L);
    scanf("%[^\n]15s", stringa);

    // invocazione isPalindrome()
    if(isPalindrome(stringa)) {
        printf("La stringa '%s' e' palindroma.", stringa);
    } else {
        printf("La stringa '%s' non e' palindroma.", stringa);
    }

    return 0;
}


// definizioni subroutine
/**
 * Verifica che s1 sia una stringa palindroma.
 * @param s1 La stringa da verificare.
 * @return true se s1 è palindroma, false altrimenti
 */
bool isPalindrome(char s1[]) {
    int l = strlen(s1); // calcolo lunghezza di s1 scartando i caratteri '\0'
    for(int i = 0; i < l / 2; i++) {
        // se il carattere n-esimo è diverso dal suo speculare (l-n)-esimo, allora la stringa non è palindroma
        if(s1[i] != s1[l-1-i])
            return false;
    }
    return true;
}