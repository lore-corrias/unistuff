/* Esercizio 18/12/2022 N° 7
 *
 * Testo:
 * "Scrivere un programma che permetta di visualizzare la k-esima stringa tra le n
 * inserite dall'utente in un array di stringhe. Chiedere inizialmente all'utente
 * quante stringhe vuole inserire, dopodiché acquisirle una alla volta.
 * L'array deve essere allocato dinamicamente.
 *
 * Scrivere una funzione che concateni tutte le stringhe presenti nell'array dell'esercizio precedente.
 * La stringa risultante deve essere allocata dinamicamente, e la sua lunghezza deve essere
 * esattamente pari al numero di caratteri che contiene (più il carattere \0).
 * La funzione deve restituire poi il puntatore al primo carattere della stringa."
 */
#include <stdio.h>
// librerie
#include <stdlib.h>
#include <string.h>
// macro
#define STR_LEN 50

// dichiarazioni subroutine
char * concatenaStringhe(int, char**);

// entry point
int main() {
    // dichiarazione variabili
    int n, k; // numero di stringhe da inserire e dell'indice di quella da stampare
    char **array; // array di stringhe
    char tmpString[STR_LEN+1]; // variabile temporanea in cui inserire la stringa da poi mantenere nell'array

    // lettura in input
    printf("\nInserisci il numero di righe da inserire: ");
    do {
        scanf("%d", &n);
        if(n < 0)
            printf("\nErrore, inserisci un numero positivo: ");
    } while (n < 0);

    // allocazione memoria
    array = (char **) calloc(n, sizeof(char *));
    if(array == NULL) {
        printf("\nImpossibile allocare sufficiente memoria.");
        exit(-1);
    }


    // acquisizione di stringhe in input
    for(int i = 0; i < n; i++) {
        printf("\nInserisci una stringa (max %d caratteri): ", STR_LEN);
        scanf(" %50[^\n]s", tmpString); // inserimento nella variabile temporanea

        // allocazione della giusta quantità di memoria per la stringa
        array[i] = calloc(strlen(tmpString)+1, sizeof(char));

        if(array[i] == NULL) {
            printf("\nImpossibile allocare sufficiente memoria.");
            exit(-1);
        }

        strcpy(array[i], tmpString);
    }

    // inserimento della stringa da stampare
    printf("\nInserisci l'indice della stringa da stampare (tra 0 e %d): ", n-1);
    do {
        scanf("%d", &k);
        if(k < 0 || k > n-1)
            printf("\nErrore, inserisci un indice valido: ");
    } while(k < 0 || k > n-1);

    // stampa della stringa k-esima
    printf("\n%d° stringa: '%s'", k, array[k]);

    // stampa della stringa concatenata
    printf("\nStringhe concatenate: %s.", concatenaStringhe(n, array));

    // deallocazione memoria
    free(array);

    // exit point
    return 0;
}

// definizioni subroutine
char * concatenaStringhe(int n, char **stringhe) {
    char *concatenata = NULL;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            // allocazione della memoria per il primo elemento
            concatenata = (char *) malloc(strlen(stringhe[i]) * sizeof(char));
            if(concatenata == NULL) {
                printf("\nImpossibile allocare sufficiente memoria.");
                exit(-1);
            }
        } else {
            // riallocazione della memoria per aggiungere lo spazio necessario per la stringa successiva
            concatenata = (char *) realloc(concatenata,
                                           strlen(concatenata) * sizeof(char) +
                                           strlen(stringhe[i]) * sizeof(char)
                                           );
            if (concatenata == NULL) {
                printf("\nImpossibile allocare sufficiente memoria.");
                exit(-1);
            }
            // aggiunta della stringa a quella concatenata
        }
        strcat(concatenata, stringhe[i]);
    }
    // aggiunta del carattere di termine (1 spazio in memoria)
    concatenata = realloc(concatenata, strlen(concatenata) * sizeof(char) + sizeof(char));
    strcat(concatenata, "\0");
    return concatenata;
}