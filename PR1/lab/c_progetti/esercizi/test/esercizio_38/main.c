#include <stdio.h>
#define MAGGIORE 'M'
#define MINORE 'm'
#define SOMMA 's'
#define MEDIA 'a' // caratteri associati alle operazioni
#define NUMERO_VALORI 3 // numero totale dei valori usati nel calcolo della media

/* Esercizio 20/10/2022 n° 8
 *
 * Testo:
 * "Scrivere un programma che, acquisiti tre numeri, permetta di decidere all'utente
 * se determinare il maggiore, determinare il minore, calcolare la somma o la media.
 * Tale scelta dovrà avvenire inserendo uno tra i seguenti caratteri:
 * •‘M’ per il maggiore
 * •‘m’ per il minore
 * •’s’ per la somma
 * •‘a’ per la media."
*/

// entry point
int main() {
    // dichiarazione variabili
    int numero1, numero2, numero3;
    int maggiore, minore; // da usare eventualmente nel calcolo di maggiore/minore
    char operazione;

    // lettura dei dati da terminale
    printf("Inserisci il primo numero: ");
    scanf("%d", &numero1);
    printf("\nInserisci il secondo numero: ");
    scanf("%d", &numero2);
    printf("\nInserisci il terzo numero: ");
    scanf("%d", &numero3);
    getchar(); // consumo il carattere 'invio'
    printf("Inserisci l'operazione da effettuare.\n");
    printf("'%c': trova il numero maggiore; '%c': trova il numero minore; '%c': calcola la somma; '%c': calcola la media: ", MAGGIORE, MINORE, SOMMA, MEDIA);
    operazione = getchar();

    // switch per le varie operazioni
    switch(operazione) {
        case MAGGIORE: // calcolo del numero maggiore
            if(numero1 > numero2 && numero1 > numero3) {
                maggiore = numero1;
            } else if(numero2 > numero1 && numero2 > numero3) {
                maggiore = numero2;
            } else {
                maggiore = numero3;
            }
            printf("\nIl maggiore dei tre numeri è '%d'.", maggiore);
            break;
        case MINORE: // calcolo del numero minore
            if(numero1 < numero2 && numero1 < numero3) {
                minore = numero1;
            } else if(numero2 < numero1 && numero2 < numero3) {
                minore = numero2;
            } else {
                minore = numero3;
            }
            printf("\nIl minore dei tre numeri è '%d'.", minore);
            break;
        case SOMMA:
            printf("\nLa somma dei tre valori vale '%d'.", numero1 + numero2 + numero3);
            break;
        case MEDIA:
            printf("\nLa media dei tre valori vale '%.2f'.", (float)(numero1 + numero2 + numero3) / NUMERO_VALORI); // cast per la divisione tra float
            break;
        default:
            printf("\nErrore: operazione non riconosciuta.");
    }

    // exit point
    return 0;
}
