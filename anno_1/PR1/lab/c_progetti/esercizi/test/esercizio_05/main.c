#include <stdio.h>
#define GRADI_FAHRENHEIT (celsius*1.8 + 32) // formula di conversione da celsius a fahrenheit
#define GRADI_CELSIUS ((fahrenheit-32) / 1.8) // formula di conversione da fahrenheit a celsius

/*
 * Esercizio 06/10/2022
 *
 * Testo:
 * "scrivere un programma che, ricevuto in input un numero di gradi Celsius,
 * lo trasformi in Fahrenheit secondo la formula F=(C*1.8) + 32. Effettuare poi la
 * conversione inversa, secondo la formula C=(F-32)/1.8 e controllare mediante stampa a video
 * la correttezza del risultato."
 */

// entry point
int main() {
    // dichiarazione delle variabili
    float celsius, fahrenheit;

    // lettura del dato in input
    printf("Inserisci il valore dei gradi in Celsius: ");
    scanf("%f", &celsius);

    // assegnazione alla variabile fahrenheit del valore convertito
    fahrenheit = GRADI_FAHRENHEIT;
    // stampa della conversione a fahrenheit
    printf("%f° Celisus valgono %f° Fahrenheit", celsius, fahrenheit);

    // ricalcolo da gradi fahrenheit a celsius
    celsius = GRADI_CELSIUS;
    // stampa della conversione da celsius a fahrenheit
    printf("\n%f° Fahrenheit valgono %f° Celsius", fahrenheit, celsius);

    // exit point
    return 0;
}
