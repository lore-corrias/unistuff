#include <stdio.h>
#define IVA 16.0 // definizione della macro IVA come float, così da produrre una divisione float durante il calcolo della percentuale

/* Esercizio 06/10/2022 n°3
 *
 * Testo:
 * "Scrivere un programma che permetta di calcolare il costo finale
 * di un certo prodotto. Assegnare a piacere il prezzo del prodotto in una
 * variabile float prezzoProdotto e associare a una macro IVA una percentuale a piacere.
 * Stampare poi in output il seguente messaggio:
 * Importo iniziale: ___.__ EUR
 * IVA applicata(__ %): __.__ EUR
 * Importo finale: __.__ EUR
 * Utilizzare due cifre decimali per ogni prezzo.
 * No magic numbers, commenta"
 */

// entry point
int main() {
    // dichiarazione e assegnazione della variabile prezzoProdotto
    float prezzoProdotto = 33.47;
    // dichiarazione e assegnazione della variabile costoAggiuntivoIVA, che definisce il costo aggiuntivo dopo l'applicazione dell'IVA
    float costoAggiuntivoIVA = prezzoProdotto * (IVA / 100);

    // stampa dei messaggi
    printf("Importo iniziale: %.2f EUR\n", prezzoProdotto);
    // il prezzo aggiuntivo per l'applicazione dell'IVA è dato dalla differenza tra il prezzo iniziale e quello dopo l'applicazione
    printf("IVA applicata (%.0f %%): %.2f EUR\n", IVA, costoAggiuntivoIVA); // %.0f rimuove le cifre decimali dal float dell'IVA
    printf("Importo finale: %.2f EUR", prezzoProdotto + costoAggiuntivoIVA);

    // exit point
    return 0;
}