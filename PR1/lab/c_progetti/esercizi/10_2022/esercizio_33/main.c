#include <stdio.h>

/* Esercizio 20/10/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma per calcolare se un anno è bisestile oppure no.
 * In particolare, il programma deve:
 * •Richiedere all'utente l'anno
 * •Verificare che l'anno sia maggiore di zero
 * •Nel caso in cui non lo sia, stampare un messaggio d'errore
 * •Diversamente, effettuare la verifica secondo il seguente schema: un anno è bisestile se è divisibile per 400, oppure se è divisibile per 4 ma non per 100
 * In output, dire se l'anno è bisestile oppure no.
*/

// entry point
int main() {
    // dichiarazione variabili
    int anno;

    // lettura dell'anno da tastiera
    printf("Inserisci un anno (maggiore di 0): ");
    scanf("%d", &anno);
    // verifica sull'anno
    if(anno < 0) {
        printf("Errore: l'anno scelto deve essere > 0.");
    } else {
        // per essere bisestile, l'anno deve essere divisibile per 400 (anno % 400 == 0) oppure (||) per 4 (anno % 4 == 0) e non per 100 (&& anno % 100 != 0)
        if(anno % 400 == 0 || (anno % 4 == 0 && anno % 100 != 0)) {
            printf("%d e' un anno bisestile.", anno);
        } else {
            printf("%d non e' un anno bisestile.", anno);
        }
    }

    // exit point
    return 0;
}
