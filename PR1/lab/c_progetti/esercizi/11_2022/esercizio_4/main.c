#include <stdio.h>
// librerie utente
// generazione randomica
#include <stdlib.h>
#include <time.h>
#include <math.h> // per pow()
// macro
// intervalli di generazione
#define MIN 10
#define MAX 300
// cifre decimali
#define DECIMALI 2
// numero di cifre decimali di un float
#define MIN_FLOAT 0
#define MAX_FLOAT 6

/* Esercizio 22/11/2022 n° 1
 *
 * Testo:
 * "Scrivere la funzione randRange che riceva in ingresso due numeri interi (min e max), acquisiti nel main,
 * e restituisca un valore generato casualmente all’interno del range i cui gli estremi sono i due valori passati in ingresso (estremi inclusi).
 * Invocare tale funzione nel main passando i valori necessari, poi stampare il valore restituito dalla funzione.
 * NB: l'inizializzazione del seed va fatta nel main.
 *
 * VARIANTE: scrivere una funzione randRangeFloat per generare numeri con la virgola.
 * La funzione riceverà un ulteriore parametro che rappresenta il numero di cifre decimali richiesto."
 */

/* funzione per la generazione randomica di un intero
 * accetta due parametri: il minimo dell'intervallo
 * della generazione e il massimo
 */
int randRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

/* funzione per la generazione randomica di un float
 * accetta tre parametri: il minimo dell'intervallo
 * della generazione, il massimo e il numero di cifre decimali
 */
float randRangeFloat(int min, int max, int decimali) {
    if(decimali <= MIN_FLOAT || decimali > MAX_FLOAT) {
        printf("\nErrore: inserisci un numero di cifre decimali valido.");
        return -1;
    }
    int coefficienteDecimali = pow(10, decimali);
    return (float)(min * coefficienteDecimali + rand() % (max * coefficienteDecimali - min * coefficienteDecimali + 1)) / coefficienteDecimali;
}


int main() {
    // dichiarazione variabili
    // numeri generati randomicamente
    int randInt;
    float randFloat;

    // inizializzazione del seed
    srand(time(NULL));

    // calcolo e stampa
    // intero
    randInt = randRange(MIN, MAX);
    printf("Numero intero generato nel range %d - %d: %d", MIN, MAX, randInt);
    // float
    randFloat = randRangeFloat(MIN, MAX, DECIMALI);
    // verifica della validità dei parametri inseriti
    if(randFloat != -1) {
        printf("\nNumero float generato nel range %d - %d con %d cifre decimali: %f", MIN, MAX, DECIMALI, randFloat);
    }

    return 0;
}
