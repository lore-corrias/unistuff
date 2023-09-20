#include <stdio.h>

/* Esercizio 16/10/2022 n° 2
 *
 * Testo:
 * "Scrivere un programma che permetta l’inserimento delle età di tre persone.
 *  Successivamente stampare a video l’età relativa a ogni persona e indicare l'età del più anziano."
 * Testo dell'esercizio successivo:
 * "Modificare l'esercizio per far sì che stampi anche l'età del più giovane."
*/

// entry point
int main() {
    // dichiarazione delle variabili
    int eta1, eta2, eta3, tmp; // variabile tmp da usare nell'inversione delle posizioni della classifica

    // lettura delle variabili da terminale
    printf("Inserisci la prima età: ");
    scanf("%d", &eta1);
    printf("Inserisci la seconda età: ");
    scanf("%d", &eta2);
    printf("Inserisci la terza età: ");
    scanf("%d", &eta3);

    // dichiarazioni delle variabili che contengono le posizioni delle età, in ordine crescente di età
    int primo = eta1, secondo = eta2, terzo = eta3; // l'ordine ipotizzato iniziale è che le età siano state inserite in ordine crescente dall'utente

    // calcolo delle posizioni ordinando le età
    if(primo > secondo) { // se la prima età è più grande della seconda, allora inverto l'ordine
        tmp = secondo;
        secondo = primo;
        primo = tmp;
    }
    if(secondo > terzo) { // se la seconda età è più grande della terza, allora inverto l'ordine
        tmp = terzo;
        terzo = secondo;
        secondo = tmp;
        if(primo > secondo) { // ri-verifica che le prime due età siano in ordine in seguito alle possibili inversioni precedenti
            tmp = secondo;
            secondo = primo;
            primo = tmp;
        }
    }

    // stampo a schermo i risultati
    printf("L'ordine d'eta' risulta essere: \n");
    printf("1) %d, minore dei tre.\n", primo);
    printf("2) %d.\n", secondo);
    printf("3) %d, maggiore dei tre.", terzo);

    // exit point
    return 0;
}