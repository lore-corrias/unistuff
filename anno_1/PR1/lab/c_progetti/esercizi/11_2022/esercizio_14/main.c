#include <stdio.h>
#include <stdbool.h>

// macro
#define L1 8
#define L2 4

/*
 * Esercizio 30/11/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che prenda in ingresso due stringhe, s1 ed s2,
 * e stampi se la stringa s2 è completamente contenuta in s1 o meno.
 *
 * Per "completamente contenuta" si intende che i caratteri di s2
 * devono essere presenti in s1 nella stessa sequenza in cui compaiono in s2.
 * Ad esempio, la stringa "zio" è contenuta in "funzione"."
 */

// dichiarazioni subroutine
bool isContained(int l1, int l2, char s1[l1], char s2[l2]);


// entry point
int main() {
    // dichiarazioni variabili
    char original[L1+1]; // stringa in cui è contenuta la seconda
    char contained[L2+1]; // stringa da verificare
    char tmp;

    // lettura da tastiera
    printf("Inserisci la prima stringa (max %d caratteri): ", L1);
    scanf("%8[^\n]s", original);
    printf("\nInserisci la stringa da controllare (max %d caratteri): ", L2);
    scanf(" %4[^\n]s", contained);

    // invocazione isContained
    if(isContained(L1, L2, original, contained)) {
        printf("\nLa stringa '%s' e' contenuta in '%s'.", contained, original);
    } else {
        printf("\nLa stringa '%s' non e' contenuta in '%s'.", contained, original);
    }

    return 0;
}

// definizioni subroutine
/**
 * Verifica che la stringa s2 sia contenuta in s1
 * @param l1 La lunghezza di s1.
 * @param l2 La lunghezza di s2.
 * @param s1 La stringa in cui è contenuta s2.
 * @param s2 La stringa contenuta in s1.
 * @return true se s1 contiene s2, false altrimenti
 */
bool isContained(int l1, int l2, char s1[l1], char s2[l2]) {
    // numero di lettere consecutive di s2 trovate in s1
    int counter = 0;
    // se counter == l2, vuol dire che s2 è contenuto in s1
    for(int i = 0; i < l1 && counter < l2 && s1[i] != '\0'; i++) {
        // aggiunge 1 al counter se la lettera è contenuta in s2 nello stesso ordine
        if(s2[counter] == s1[i])
            counter += 1;
        else
            counter = 0; // altrimenti, resettalo a 0
    }
    // se il ciclo è finito e counter == l2, allora s2 è contenuta in s1
    return counter == l2;
}