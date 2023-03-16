#include <stdio.h>
#include <stdlib.h>
#include <time.h> // per la generazione randomica
#include <stdbool.h> // per i valori booleani
#define MIN 0
#define MAX 100 // intervallo di generazione randomica

/* Esercizio 02/11/2022 n° 2
 *
 * Testo:
 * "Generare un numero casuale compreso tra 0 e 100 e chiedere all’utente
 * un numero nello stesso intervallo. Se sono uguali stampare un messaggio
 * «Numeri uguali»; in caso contrario comunicare se il numero inserito è maggiore o minore di quello generato.
 * Il programma deve terminare quando l’utente indovina il numero generato (for, while o do while?)."
*/

// entry point
int main() {
    // dichiarazione variabili
    int n_input, n_random;
    bool indovinato = false; // variabile booleana che verifica che l'utente abbia indovinato

    srand(time(NULL)); // inizializzo il seed

    while(!indovinato) {
        // lettura da tastiera di un numero
        printf("Inserisci un numero tra 0 e 100: ");
        scanf("%d", &n_input);

        // controllo del valore inserito
        if (n_input >= MIN && n_input <= MAX) {
            // generazione randomica
            n_random = MIN + rand() % (MAX - MIN + 1);

            // verifico che l'utente abbia indovinato
            indovinato = (n_input == n_random);
            if(indovinato) {
                printf("\nNumeri uguali.");
            } else {
                printf("\nRitenta.");
            }
        }
    }

    // exit point
    return 0;
}
