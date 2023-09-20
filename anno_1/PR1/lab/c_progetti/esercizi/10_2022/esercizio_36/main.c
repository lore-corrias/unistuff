#include <stdio.h>

/* Esercizio 20/10/2022 n° 6
 *
 * Testo:
 * "Scrivere un programma che riceva in input un carattere
 * e verifichi se il carattere inserito è una vocale oppure una consonante.
 * NB: gestire sia la casistica minuscola che maiuscola.
 * NB2: fornire il messaggio "carattere non consentito" nel caso in cui il carattere non sia una vocale.
*/

// entry point
int main() {
    // dichiarazione variabili
    char carattere_input;

    // lettura del carattere da terminale
    printf("Inserisci il carattere da verificare: ");
    scanf("%c", &carattere_input);

    // verifico che il carattere inserito sia una lettera (maiuscola o minuscola)
    if((carattere_input >= 'A' && carattere_input <= 'Z') || (carattere_input >= 'a' && carattere_input <= 'z')) {
        // controllo che il carattere inserito sia una vocale
        switch(carattere_input) {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u': // sia che la lettera sia maiuscola che minuscola, l'istruzione eseguita è la stessa
                printf("La lettera inserita è una vocale.");
                break;
            default:
                printf("La lettera inserita è una consonante.");
        }
    } else {
        printf("Errore: carattere invalido. Inserisci una lettera maiuscola o minuscola.");
    }

    // exit point
    return 0;
}
