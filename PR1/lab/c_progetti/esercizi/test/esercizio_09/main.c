#include <stdio.h>
#define SECONDI_IN_MINUTO 60
#define SECONDI_IN_ORA 3600
// definisco le macro che contengono i coefficienti per la conversione da secondi a minuti e da secondi a ore

/* Esercizio 06/10/2022 n° 4
 *
 * Testo:
 * "Scrivere un programma che, ricevuto un numero di secondi in input
 * dall'utente, determini la quantità di ore, minuti e secondi corrispondenti.
 * N.B.: i valori dovranno essere interi, tipo 4 ore, 13 minuti, 12 secondi.
 */

// entry point
int main() {
    // dichiarazione delle variabili
    int secondiInput;
    int ore, minuti, secondi;

    // lettura dei secondi come input dell'utente
    printf("Inserisci il numero di secondi: ");
    scanf("%d", &secondiInput);

    // calcolo del numero di ore
    ore = secondiInput / SECONDI_IN_ORA;
    secondi = secondiInput % SECONDI_IN_ORA; // il numero di secondi rimanenti da convertire in minuti è il resto della divisione precedente
    minuti = secondi / SECONDI_IN_MINUTO;
    secondi = secondi % SECONDI_IN_MINUTO; // ragionamento analogo a quello per le ore

    // stampa del risultato.
    printf("%d secondi corrispondono a %d ore, %d minuti e %d secondi", secondiInput, ore, minuti, secondi);

    // exit point
    return 0;
}
