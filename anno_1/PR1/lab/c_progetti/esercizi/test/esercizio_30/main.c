#include <stdio.h>
#define SPESA_PRIMO_SCONTO 120
#define SPESA_SECONDO_SCONTO 350 // definizioni delle macro contenenti i valori entro cui applicare lo sconto
#define PRIMO_SCONTO 0.05
#define SECONDO_SCONTO 0.1 // definizione delle macro contenente gli sconti sulle spese

/* Esercizio 18/10/2022 n° 3
 *
 * Testo:
 * "Scrivere un programma che chieda all'utente l'ammontare della spesa fatta in un negozio.
 * In particolare, il negoziante effettua uno sconto del 5% per ogni spesa superiore a 120€ e del 10%
 * per ogni spesa superiore a 350€.
 *
 * Visualizzare in output l'importo effettivo da pagare.•
 * Risolvere l'esercizio in due versioni:
 * •con if-else
 * •con soli switch-case (trappola)
*/

// entry point
int main() {
    // dichiarazione delle variabili
    float spesa, sconto = 0; // se la spesa è < 120 euro, lo sconto non c'è

    // lettura in input del valore spesa
    printf("Inserisci la spesa totale: ");
    scanf("%f", &spesa);

    // calcolo dello sconto con if else
    if(spesa > SPESA_PRIMO_SCONTO && spesa <= SPESA_SECONDO_SCONTO) { // applicazione dello sconto per spese > 120 euro e < 350 euro
        sconto = spesa * PRIMO_SCONTO;
    } else if (spesa > SPESA_SECONDO_SCONTO) { // applicazione dello sconto per spese > 350 euro
        sconto = spesa * SECONDO_SCONTO;
    }

    // stampa della spesa
    printf("La spesa totale ammonta a: %.2f", spesa - sconto); // applico lo sconto, se presente

    // exit point
    return 0;
}
