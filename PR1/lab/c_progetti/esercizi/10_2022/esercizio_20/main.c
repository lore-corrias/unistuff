#include <stdio.h>
#include <math.h> // libreria per la funzione pow()

/* Esercitazione 13/10/2022 n° 2
 * Testo:
 *
 * "Scrivere un programma che, acquisito il peso in kg e l’altezza in metri,
 * calcoli e stampi l’indice di massa corporea (BMI) secondo la formula BMI = peso / altezza2."
*/

// entry point
int main() {
    // dichiarazione delle variabili
    float peso, altezza, bmi;

    // lettura da terminale di peso e altezza
    printf("Inserisci il tuo peso: ");
    scanf("%f", &peso);
    printf("\nInserisci la tua altezza: ");
    scanf("%f", &altezza);

    // calcolo del BMI
    bmi = peso / pow(altezza, 2);

    // stampa del risultato
    printf("\nIl tuo BMI è: %.2f", bmi);

    // exit point
    return 0;
}
