#include <stdio.h>
#include <stdlib.h>
#include <time.h> // librerie per la generazione del numero

/* Esercizio 16/10/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma che:
 * •Chieda all'utente di inserire due valori reali, che rappresentano il minimo e il massimo di un certo intervallo.
 * •Generi casualmente un certo valore casuale.
 * •Stampi a video se il valore generato è all'interno dell'intervallo oppure no."
 */

// entry point
int main() {
    // dichiarazione variabili
    int minimo, massimo, random;

    srand(time(NULL)); // generazione del seed

    // lettura dei valori da terminale
    printf("Inserisci il valore minimo dell'intervallo: ");
    scanf("%d", &minimo);
    printf("Inserisci il valore massimo dell'intervallo: ");
    scanf("%d", &massimo);

    // generazione pseudocasuale del numero
    random = rand();
    // verifica che il valore si trovi all'interno dell'intervallo
    if(random >= minimo && random <= massimo) {
        printf("Il numero generato (%d) si trova all'interno dell'intervallo [%d,%d].", random, minimo, massimo);
    } else {
        printf("Il numero generato (%d) non si trova all'interno dell'intervallo [%d,%d]", random, minimo, massimo);
    }

    // exit point
    return 0;
}
