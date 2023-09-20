#include <stdio.h>

/* Esercizio 20/10/2022 n° 7
 *
 * Testo:
 * "Scrivere un programma che funzioni come calcolatrice, chiedendo all'utente
 * l'operazione da svolgere ( +, -, *, / ) e due operandi.
 * Il programma deve svolgere l'operazione richiesta dall'utente e scrivere il risultato in output.
 * Usare lo switch-case."
*/

// entry point
int main() {
    // dichiarazione variabili
    char operazione;
    int operando1, operando2;
    float risultato;

    // lettura da tastiera degli elementi dell'operazione
    printf("\nInserisci il primo operando: ");
    scanf("%d", &operando1);
    printf("\nInserisci il secondo operando: ");
    scanf("%d", &operando2);
    getchar(); // consumo il carattere 'invio' in vista del prossimo getchar (si potrebbe anche mettere questa istruzione come prima, scelta estetica)
    printf("\nInserisci l'operazione da svolgere (+, -, *, /): ");
    operazione = getchar();

    // verifica dell'operazione
    switch(operazione) {
        case '+': // associo a ogni carattere la corretta operazione
            risultato = operando1 + operando2;
            break;
        case '-':
            risultato = operando1 - operando2;
            break;
        case '*':
            risultato = operando1 * operando2;
            break;
        case '/':
            if(operando2 != 0) { // verifico di non star effettuando una divisione per zero
                risultato = (float)operando1 / operando2; // cast per la divisione tra float
            } else {
                printf("\nErrore: divisione per zero.");
                return -1; // termina il programma con un errore
            }
            break;
        default:
            printf("\nErrore: operazione non riconosciuta.");
            return -1; // termina il programma con un errore
    }

    // stampa del risultato
    printf("\nL'operazione '%d %c %d' vale '%.3f'.", operando1, operazione, operando2, risultato);

    // exit point
    return 0;
}
