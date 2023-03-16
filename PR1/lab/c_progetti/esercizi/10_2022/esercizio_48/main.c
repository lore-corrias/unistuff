#include <stdio.h>
#include <stdlib.h>
#include <time.h> // per la generazione
#include <stdbool.h> // per il valore booleano
#define MIN 1
#define MAX 90 // intervallo generazione randomica
#define DIMENSIONE 5 // dimensione vettore

/* Esercizio 31/10/2022 n° 5
 *
 * Testo:
 * "Scrivere un programma in cui si dichiara un vettore di 5 elementi.
 * Assegnare casualmente 5 valori da 1 a 90 senza ripetizioni."
*/

// entry point
int main() {
    // dichiarazione vettore
    int vettore[DIMENSIONE], randTmp;
    bool giaGenerato; // variabile booleana che viene invertita se il numero è già stato generato

    // generazione randomica dei valori
    srand(time(NULL));
    for(int i = 0; i < DIMENSIONE; i++) {
        do {
            giaGenerato = false; // ri-inverto il valore
            randTmp = MIN + rand() % (MAX - MIN + 1); // generazione di un numero e assegnazione a randTmp
            for(int j = 0; j < i; j++) { // itero con un altro ciclo tra i valori già generati
                if(vettore[j] == randTmp) { // se trovo il valore appena creato, allora la variabile è invertita e il ciclo while riesegue
                    printf("Il valore generato (%d) esiste gia': ricalcolo...\n", randTmp);
                    giaGenerato = true;
                }
            }
        } while(giaGenerato); // esegui finché il numero non è un doppione
        vettore[i] = randTmp; // assegno il valore univoco
    }

    // stampa dei valori
    printf("Valori generati:\n");
    for(int i = 0; i < DIMENSIONE; i++) {
        printf("%d\n", vettore[i]);
    }

    // exit point
    return 0;
}
