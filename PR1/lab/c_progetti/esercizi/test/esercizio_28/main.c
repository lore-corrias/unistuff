#include <stdio.h>
#include <stdbool.h> // libreria per il tipo bool

/* Esercizio 18/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che acquisisca in input un valore booleano, lo memorizzi
 * in un'apposita variabile booleana e stampi a video se il suo valore è true o false
 *
 * Risolvere l'esercizio usando:
 *  1) if - else
 *  2) Switch - case
 *  3) Operatore ternario"
 */

// entry point
int main() {
    // dichiarazione della variabile di input
    int input;
    // dichiarazione della variabile booleana
    bool variabile_booleana;

    // lettura in input
    printf("Inserisci 0 come 'false', 1 o un numero maggiore come 'true': ");
    scanf("%d", &input);
    variabile_booleana = (input >= 1); // conversione dell'input in un valore boolean

    // primo metodo: if - else
    if(variabile_booleana) {
        printf("Hai inserito 'true'.");
    } else {
        printf("Hai inserito 'false'.");
    }

    // secondo metodo: switch - case
    /*
    switch(variabile_booleana) {
        case true:
            printf("Hai inserito 'true'.");
            break;
        default: // se non è true è false
            printf("Hai inserito 'false'.");
    }
    */

    // terzo metodo: operatore ternario
    //variabile_booleana ? printf("Hai inserito 'true'.") : printf("Hai inserito 'false'.");

    // exit point
    return 0;
}
