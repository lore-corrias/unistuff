#include <stdio.h>
#include <stdlib.h>
#include <time.h> // librerie per la generazione casuale del numero
#define RAND_MIN 0
#define RAND_MAX 10 // intervalli per la generazione del numero casuale

/* Esercizio 20/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che generi un numero casuale tra 0 e 10 e chieda poi all’utente di inserire un valore tra 0 e 10.
 * Se il numero inserito è maggiore di 10 o minore di 0 il programma deve stampare un messaggio di errore.
 * Altrimenti, deve stampare "Numero uguale" se il valore inserito dall’utente è lo stesso generato casualmente o,
 * in caso contrario, deve stampare la differenza in valore assoluto tra i due numeri."
*/

// entry point
int main() {
    // dichiarazione variabili
    int numero_random, numero_input, differenza;

    // generazione numero randomico
    srand(time(NULL)); // generazione del seme
    numero_random = RAND_MIN + rand() % (RAND_MAX - RAND_MIN + 1);

    // lettura da tastiera del numero scelto dall'utente
    printf("Inserisci un numero tra 0 e 10: ");
    scanf("%d", &numero_input);
    // controllo sul numero scelto
    if(numero_input >= 0 && numero_input <= 10) {
        // controllo che il numero scelto sia uguale a quello generato casualmente e stampo il risultato
        if(numero_input != numero_random) {
            // calcolo la differenza tra i due numeri e stampo il risultato
            differenza = numero_input - numero_random;
            printf("La differenza in valore assoluto tra %d e %d (numero generato) è %d", numero_input, numero_random, abs(differenza));
        } else {
            printf("Numero uguale.");
        }
    } else {
        printf("Il numero inserito deve essere compreso tra 0 e 10.");
    }

    // exit point
    return 0;
}
