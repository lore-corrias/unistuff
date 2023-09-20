#include <stdio.h>

/* Esercizio 14/10/2022 n° 4
 *
 * Testo:
 * "Scrivere un programma che acquisisca un valore intero n. Il programma deve poi:
 * •Stampare il numero inserito in minuscolo se 1 ≤ n ≤ 9
 * •Stampare "Maggiore di 9" se n > 9
 * •Stampare "Errore" in tutti gli altri casi.
 *
 * Esempio:
 * •n = 8-> "otto"
 * n = 11-> "Maggiore di 9"
 * n = -5-> "Errore""
*/

// entry point
int main() {
    // dichiarazione variabile
    int numero;

    // prendi il numero da terminale
    printf("Inserisci il numero: ");
    scanf("%d", &numero);

    switch(numero) { // switch per il caso in cui 1 <= n <= 9
        case 1:
            printf("uno");
            break;
        case 2:
            printf("due");
            break;
        case 3:
            printf("tre");
            break;
        case 4:
            printf("quattro");
            break;
        case 5:
            printf("cinque");
            break;
        case 6:
            printf("sei");
            break;
        case 7:
            printf("sette");
            break;
        case 8:
            printf("otto");
            break;
        case 9:
            printf("nove");
            break;
        default: // altrimenti
            if(numero > 9) { // se n > 9, stampa "maggiore di nove"
                printf("Maggiore di nove.");
            } else { // altrimenti, stampa "errore".
                printf("Errore.");
            }
    }

    // exit point
    return 0;
}
