#include <stdio.h>
#include <math.h> // per la funzione pow()
#include <stdlib.h>
#include <time.h> // per la generazione di numeri
#define MIN_ALTEZZA 0.30
#define MAX_ALTEZZA 2.50
#define MIN_PESO 3.0
#define MAX_PESO 120.0
#define CIFRE_DECIMALI 4 // specifica il numero di cifre decimali per i numeri generati randomicamente
/*
 * dichiarazione di una variabile COEFFICIENTE_DECIMALI che contenga una potenza di 10
 * elevata al numero di cifre decimali da ottenere nella generazione dei valori randomici
*/
#define COEFFICIENTE_DECIMALI (int)pow(10, CIFRE_DECIMALI) // cast per specificare che la potenza è un intero

/* Esercitazione 13/10/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma che, generato il peso in kg tra 3.00kg e 120.00kg, e l’altezza in metri, tra 0.30m e 2.50m,
 * calcoli e stampi l’indice di massa corporea (BMI) secondo la formula BMI = peso / altezza2."
*/

// entry point
int main() {
    // dichiarazione delle variabili
    float altezza, peso, bmi;

    srand(time(NULL)); // generazione del seed

    // generazione dei valori per l'altezza e per il peso
    /*
     * per generare dei valori con un numero di cifre decimali pari a CIFRE_DECIMALI, è necessario
     * moltiplicare il minimo e il massimo dell'intervallo della generazione per 10^CIFRE_DECIMALI,
     * ossia il valore della variabile COEFFICIENTE_DECIMALI. Dopodiché, per ottenere dei valori decimali,
     * bisogna dividere il numero generato per COEFFICIENTE_DECIMALI
    */
    // dichiarazione e assegnazione delle variabili per il minimo e il massimo del range, ma moltiplicate per COEFFICIENTE_DECIMALI
    int min_altezza_per_coefficiente = MIN_ALTEZZA * COEFFICIENTE_DECIMALI;
    int max_altezza_per_coefficiente = MAX_ALTEZZA * COEFFICIENTE_DECIMALI;
    int max_peso_per_coefficiente = MAX_PESO * COEFFICIENTE_DECIMALI;
    int min_peso_per_coefficiente = MIN_PESO * COEFFICIENTE_DECIMALI;
    altezza = (float)(min_altezza_per_coefficiente + rand() % (int)(max_altezza_per_coefficiente - min_altezza_per_coefficiente + COEFFICIENTE_DECIMALI)) / COEFFICIENTE_DECIMALI;
    peso = (float)(min_peso_per_coefficiente + rand() % (int)(max_peso_per_coefficiente - min_peso_per_coefficiente + COEFFICIENTE_DECIMALI)) / COEFFICIENTE_DECIMALI;
    printf("Altezza generata: %fm. Peso generato: %fkg.", altezza, peso);

    // calcolo bmi
    bmi = peso / pow(altezza, 2);

    // stampa del risultato
    printf("\nBMI calcolato: %f.", bmi);

    // exit point
    return 0;
}