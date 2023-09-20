#include <stdio.h>

/* Esercizio 20/10/2022 n° 2
 *
 * Testo:
 * "Scrivere un programma che, inserito un valore numerico intero compreso tra 1 e 7 in input, stampi
 * il corrispondente nome del giorno della settimana. Per esempio:
 * •1 →"Lunedi"
 * •6 →"Sabato
 * Realizzare, inoltre, un controllo sull'input utente e, se il valore
 * non è tra quelli ammissibili, stampare un messaggio d'errore."
*/

// entry point
int main() {
    // dichiarazione variabili
    int numero_scelto;

    // lettura da tastiera del numero scelto dall'utente
    printf("Inserisci un numero tra 1 e 7: ");
    scanf("%d", &numero_scelto);
    // controllo sul numero inserito
    switch(numero_scelto) {
        case 1:
            printf("Lunedì"); // stampo il corrispondente numero in lettere
            break;
        case 2:
            printf("Martedì");
            break;
        case 3:
            printf("Mercoledì");
            break;
        case 4:
            printf("Giovedì");
            break;
        case 5:
            printf("Venerdì");
            break;
        case 6:
            printf("Sabato");
            break;
        case 7:
            printf("Domenica");
            break;
        default:
            printf("Errore: il numero scelto deve essere compreso tra 1 e 7.");
    }

    // exit point
    return 0;
}
