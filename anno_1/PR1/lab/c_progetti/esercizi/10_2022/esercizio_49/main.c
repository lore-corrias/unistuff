#include <stdio.h>
#include <stdlib.h>
#include <time.h> // per la generazione
#include <stdbool.h> // per il valore booleano

#define MIN 1
#define MAX 90 // intervallo generazione randomica
#define DIMENSIONE 5 // dimensione vettore
#define ESTRATTO 1
#define AMBO 2
#define TERNA 3
#define QUATERNA 4
#define CINQUINA 5 // possibili casi di vincita

/* Esercizio 31/10/2022 n° 5
 *
 * Testo:
 * "Scrivere un programma in cui si dichiara un vettore di 5 elementi.
 * Assegnare casualmente 5 valori da 1 a 90 senza ripetizioni.
 *
 * "Aggiungere all’esercizio precedente un’interfaccia utente che permetta all’utente
 * di effettuare una giocata del tipo: estratto, ambo, terno, quaterna, cinquina.
 * In caso di vittoria dovrà essere comunicata all’utente la vincita,
 * altrimenti dovrà essere concesso un nuovo tentativo senza una nuova estrazione."
*/

// entry point
int main() {
    // dichiarazione vettori e variabili
    int vettore[DIMENSIONE], vettoreInput[DIMENSIONE], randTmp;
    int contatoreGenerati; // contatore dei numeri che vengono generati due volte
    bool vittoria = false; // variabile booleana che verifica che l'utente abbia vinto una giocata

    // generazione randomica dei valori
    srand(time(NULL));
    for (int i = 0; i < DIMENSIONE; i++) {
        vettore[i] = MIN + rand() % (MAX - MIN + 1); // generazione di un numero
    }

    while (!vittoria) { // esegui il gioco finché il giocatore non indovina qualche numero
        // inserimento dei valori dall'utente
        printf("Inserisci %d tra %d e %d numeri da indovinare:", DIMENSIONE, MIN, MAX);
        for (int i = 0; i < DIMENSIONE; i++) {
            printf("\n%d) ", i + 1);
            scanf("%d", &vettoreInput[i]);
        }

        // verifica dei valori generati più volte
        for(int i = 0; i < DIMENSIONE; i++) {
            for(int j = 0; j < DIMENSIONE; j++) {
                if(vettore[i] == vettoreInput[j])
                    contatoreGenerati++; // scorro i due array e se trovo dei doppioni incremento la variabile
            }
        }

        // stampa del risultato
        /* printf("Numeri generati: ");
        * for(int i = 0; i < DIMENSIONE; i++)
        *    printf("%d ", vettore[i]);
        */ // debugging
        printf("\nRisultato: ");
        switch (contatoreGenerati) {
            case ESTRATTO:
                printf("estratto.");
                vittoria = true;
                break;
            case AMBO:
                printf("ambo.");
                vittoria = true;
                break;
            case TERNA:
                printf("terna.");
                vittoria = true;
                break;
            case QUATERNA:
                printf("quaterna.");
                vittoria = true;
                break;
            case CINQUINA:
                printf("cinquina.");
                vittoria = true;
                break;
            default:
                printf("nessun numero estratto.\n");
        }
    }

    // exit point
    return 0;
}