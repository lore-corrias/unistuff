#include <stdio.h>
#include <stdlib.h>
#include <time.h> // librerie per la generazione del numero random
#define MIN 0 // macro contenente il minimo numero generabile randomicamente
#define MAX 50 // macro contenente il massimo numero generabile randomicamente

/* Esercizio 21/10/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma che chieda all'utente un numero num all'utente,
 * e generi continuamente numeri casuali compresi tra 0 e MAX finché
 * il numero generato non è maggiore di num. Stampare infine
 * il numero di valori generati casualmente e il valore maggiore di num.
 *
 * Opzionalmente, verificare che l'utente inserisca un valore consono.
*/

// entry point
int main() {
    // dichiarazione variabili
    int num, num_random, num_random_conteggio;

    // lettura del numero da tastiera
    printf("Inserisci un numero (intervallo dei numeri generabili: %d - %d): ", MIN, MAX);
    scanf("%d", &num);

    // l'iterazione si blocca solo per valori STRETTAMENTE maggiori del numero inserito, non maggiori o uguali
    // quindi, un valore inserito che sia pari al numero di MAX non è accettabile, poiché il programma continuerebbe all'infinito
    while(num == MAX) {
        printf("\nInserisci un numero che sia minore del massimo dell'intervallo: ");
        scanf("%d", &num);
    }

    // generazione dei numeri randomici
    srand(time(NULL)); // inizializzazione del seed
    do { // esegui il ciclo almeno una volta per generare il primo numero casuale
        num_random = MIN + rand() % (MAX - MIN + 1); // generazione di un numero all'interno dell'intervallo MIN - MAX
        ++num_random_conteggio; // è stato generato un numero, incremento la variabile per il conteggio
    } while(num_random <= num); // continua la generazione finché il numero generato non è strettamente maggiore di num

    // stampa dei risultati
    printf("\nNumero di valori generati: %d. Valore dell'ultimo numero generato: %d.", num_random_conteggio, num_random);

    // exit point
    return 0;
}
