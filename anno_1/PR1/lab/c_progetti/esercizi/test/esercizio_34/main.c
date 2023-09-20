#include <stdio.h>
#define SCONTO_PENSIONATI 0.1
#define SCONTO_STUDENTI 0.15
#define SCONTO_DISOCCUPATI 0.25 // definizione delle macro con gli sconti da applicare alle categorie

/* Esercizio 20/10/2022 n° 4
 *
 * Testo:
 * "Scrivere un programma per la gestione dei biglietti del CTM.
 * Si supponga che, rispetto alla tariffa piena, i pensionati usufruiscano di uno sconto del 10%,
 * gli studenti del 15% e infine i disoccupati del 25%.
 *
 * Codificare lo stato dell'utente con una variabile char:
 * •pensionati con una 'P',
 * •gli studenti con una 'S' e
 * •i disoccupati con una 'D'.
 * Scrivere un programma che, richiesto il costo di un biglietto e l’eventuale condizione dell’utente,
 * visualizzi l’importo da pagare.
 *
 * •Suggerimento: potrebbe non servire l'if"
*/

// entry point
int main() {
    // dichiarazione variabili
    float costo, sconto;
    char categoria;

    // lettura delle informazioni da tastiera
    printf("Inserisci il costo del biglietto da pagare: ");
    scanf("%f", &costo);

    getchar(); // consumo l'elemento del buffer contenente l'invio

    printf("Inserisci il tuo status. 'P': pensionato; 'S': studente; 'D': disoccupato: ");
    categoria = getchar(); // lettura del carattere corrispondente alla categoria

    // verifica dello status e applicazione dello sconto
    switch(categoria) {
        case 'P':
        case 'p': // l'inserimento di P e p è trattato in modo uguale così da essere case-insensitive
            sconto = costo * SCONTO_PENSIONATI;
            break;
        case 'S':
        case 's':
            sconto = costo * SCONTO_STUDENTI;
            break;
        case 'D':
        case 'd':
            sconto = costo * SCONTO_DISOCCUPATI;
            break;
        default:
            printf("Errore: hai inserito una categoria invalida.");
    }

    // stampo a schermo il prezzo finale
    printf("Prezzo finale del biglietto per la tua categoria ('%c'): %.2f", categoria, costo - sconto);

    // exit point
    return 0;
}
