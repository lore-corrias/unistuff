#include <stdio.h>

/* Esercizio 06/10/2022 n°3
 *
 * Testo:
 * "Scrivere un programma che permetta di calcolare il costo finale
 * di un certo prodotto. Leggere in input il prezzo del prodotto e inserirlo in una
 * variabile float prezzoProdotto e associare a una macro IVA una valore ricevuto in input.
 * Stampare poi in output il seguente messaggio:
 * Importo iniziale: ___.__ EUR
 * IVA applicata(__ %): __.__ EUR
 * Importo finale: __.__ EUR
 * Utilizzare due cifre decimali per ogni prezzo.
 * No magic numbers, commenta"
 */

// entry point
int main() {
    // dichiarazione delle variabili
    float prezzoProdotto, iva; // iva è un float per permettere una divisione con cifre decimali

    // lettura dei valori di prezzoProdotto e iva
    printf("Inserisci il prezzo del prodotto: ");
    scanf("%f", &prezzoProdotto);
    printf("\nInserisci il valore dell'IVA (in percentuale): ");
    scanf("%f", &iva);

    // dichiarazione e assegnazione della variabile costoAggiuntivoIVA, che definisce il costo aggiuntivo dopo l'applicazione dell'IVA
    float costoAggiuntivoIVA = prezzoProdotto * (iva / 100);

    // stampa dei messaggi
    printf("Importo iniziale: %.2f EUR\n", prezzoProdotto);
    // il prezzo aggiuntivo per l'applicazione dell'IVA è dato dalla differenza tra il prezzo iniziale e quello dopo l'applicazione
    printf("IVA applicata (%.0f %%): %.2f EUR\n", iva, costoAggiuntivoIVA); // %.0f rimuove le cifre decimali dal float dell'IVA
    printf("Importo finale: %.2f EUR", prezzoProdotto + costoAggiuntivoIVA);

    // exit point
    return 0;
}