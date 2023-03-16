#include <stdio.h>
#define PRIMO_MESE 1
#define ULTIMO_MESE 12 // primo e ultimo mese dell'anno
#define FEBBRAIO 2 // febbraio è l'unico mese con 28 giorni
#define APRILE 4
#define GIUGNO 6
#define SETTEMBRE 9
#define NOVEMBRE 11 // lista dei mesi con 30 giorni

/* Esercizio 20/10/2022 n° 5
 *
 * Testo:
 * "Scrivere un programma che riceva in input un valore compreso tra 1 e 12,
 * rappresentanti i mesi dell'anno, e stampi quanti giorni ha quel mese.
 *
 * NB: Nel caso in cui il mese inserito sia febbraio, chiedere se l'anno è bisestile
 * e gestire l'eventuale casistica in cui lo sia.
 *
 * NB2: in caso di inserimento di un valore non ammissibile, comunicare all'utente un messaggio d'errore."
*/

// entry point
int main() {
    // dichiarazione variabili
    int mese, giorni = 0;
    char bisestile_conferma; // variabile che contiene l'input usato per confermare l'anno bisestile

    // lettura del mese da tastiera
    printf("Inserisci il mese come un numero tra 1 e 12: ");
    scanf("%d", &mese);

    // controllo del mese inserito
    switch(mese) {
        case FEBBRAIO:
            getchar(); // consumo il carattere 'invio' in vista del prossimo getchar()
            printf("Hai inserito il mese 'febbraio'. L'hanno è bisestile? Digita 'S' per dire si', 'N' per dire no: ");
            bisestile_conferma = getchar();
            // controllo che l'utente abbia scritto 'S' o 'N' (case insensitive)
            if(bisestile_conferma == 'S' || bisestile_conferma == 's' || bisestile_conferma == 'N' || bisestile_conferma == 'n') {
                // se l'utente ha inserito 's', l'anno è bisestile e i giorni sono 29, altrimenti sono 28
                giorni = (bisestile_conferma == 'S' || bisestile_conferma == 's') ? 29 : 28;
            } else {
                // l'input inserito non è né 's' né 'n'
                printf("Errore: conferma che l'anno sia bisestile scrivendo 'S' o 'N'.");
            }
            break;
        case APRILE:
        case GIUGNO:
        case SETTEMBRE:
        case NOVEMBRE: // lista dei mesi con 30 giorni
            giorni = 30;
            break;
        default:
            if(mese >= PRIMO_MESE && mese <= ULTIMO_MESE) {
                giorni = 31; // se la data è valida, il mese non può che avere 31 giorni
            } else {
                // altrimenti, il mese selezionato è invalido
                printf("Errore: il numero da inserire deve essere compreso tra %d e %d.", PRIMO_MESE, ULTIMO_MESE);
            }
    }

    // se giorni = 0, allora significa che il mese scelto è febbraio e che l'utente non ha confermato che l'anno sia bisestile o meno
    // in alternativa, è possibile mettere un'istruzione 'return 0' sotto il messaggio di errore per terminare il programma
    if(giorni != 0) {
        // stampa a schermo il risultato
        printf("Il mese selezionato ha %d giorni.", giorni);
    }

    // exit point
    return 0;
}
