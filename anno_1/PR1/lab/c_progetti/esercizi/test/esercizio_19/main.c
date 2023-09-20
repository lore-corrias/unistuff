#include <stdio.h>
#include <stdlib.h>
#include <time.h> // librerie per la generazione di un numero randomico
#define PESO_MIN 3.00
#define PESO_MAX 120.00 // limiti di peso massimo e minimo tra quelli generabili
/*
 * dichiarazione di una variabile COEFFICIENTE_DECIMALI che contenga una potenza di 10
 * elevata al numero di cifre decimali da ottenere nella generazione dei valori randomici (in questo caso, 10^2 = 100)
*/
#define COEFFICIENTE_DECIMALI 100

/* Esercizio 13/10/2022 n°1
 *
 * Testo:
 * "Scrivere un programma che generi il peso di una persona da 3.00 a 120.00 kg (con due cifre decimali)."
 */

// entry point
int main() {
    // dichiarazione della variabile peso
    float peso;
    srand(time(NULL)); // generazione del seme

    // generazione del peso casuale
    /*
     * per generare dei valori con un numero di cifre decimali pari a CIFRE_DECIMALI, è necessario
     * moltiplicare il minimo e il massimo dell'intervallo della generazione per 10^CIFRE_DECIMALI,
     * ossia il valore della variabile COEFFICIENTE_DECIMALI. Dopodiché, per ottenere dei valori decimali,
     * bisogna dividere il numero generato per COEFFICIENTE_DECIMALI
    */
    // dichiarazione e assegnazione delle variabili per il minimo e il massimo del range, ma moltiplicate per COEFFICIENTE_DECIMALI
    int min_peso_per_coefficiente = PESO_MIN * COEFFICIENTE_DECIMALI;
    int max_peso_per_coefficiente = PESO_MAX * COEFFICIENTE_DECIMALI;
    // cast esplicito a int per permettere l'utilizzo dell'operatore modulo, e poi a float per permettere la divisione decimale
    peso = (float)(min_peso_per_coefficiente + rand() % (int)(max_peso_per_coefficiente - min_peso_per_coefficiente + COEFFICIENTE_DECIMALI)) / COEFFICIENTE_DECIMALI;

    // stampa del numero ottenuto
    printf("Il peso generato è: %.2f.", peso);

    // exit point
    return 0;
}