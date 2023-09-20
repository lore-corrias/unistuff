#include <stdio.h>
#include <stdlib.h>
#include <time.h> // librerie per la generazione del minuto casuale
#define PRIMO_MINUTO 1
#define ULTIMO_MINUTO 90 // primo e ultimo minuto di una partita di calcio. il numero generato sarà compreso tra i due numeri
#define DURATA_TEMPO 45 // durata di un tempo della partita
#define PORTIERE 1
#define DIFENSORE_1 2
#define DIFENSORE_2 3
#define DIFENSORE_3 4
#define CENTROCAMPISTA_1 5
#define CENTROCAMPISTA_2 6
#define CENTROCAMPISTA_3 7
#define CENTROCAMPISTA_4 8
#define ATTACCANTE_1 9
#define ATTACCANTE_2 10
#define ATTACCANTE_3 11 // numeri relativi alla posizione del giocatore

/* Esercitazione 22/10/2022 n° 2
 *
 * Testo:
 * "1) Memorizzare in una variabile un intero casuale generato nell'intervallo [1, 90] estremi inclusi
 * che rappresenti il minuto di una partita di calcio in cui è stata segnata una rete.
 * 2) Chiedere quindi all’utente il numero del giocatore che ha segnato tale
 * rete (si ipotizzi che i valori possibili siano da 1 a 11).
 * 3) Tramite un costrutto IF verificare se la rete è stata segnata al primo o al secondo tempo
 * e a seconda dei due casi stampare un messaggio relativo(ogni tempo ha durata 45 minuti).
 * 4) Mediante uno SWITCH-CASE stampare in output il messaggio:
 *  •"Portiere" se il numero del giocatore è uguale a 1
 *  •"Difensore" se il numero del giocatore è >= 2 e <=4
 *  •"Centrocampista" se numero del giocatore è >= 5 e <=8
 *  •”Attaccante" se numero del giocatore è >= 9 e <=11
 * Commentare opportunatamente tutto il codice.
*/

// entry point
int main() {
    // dichiarazione variabili
    int minuto_goal, giocatore_goal;

    // generazione di un minuto casuale della partita
    srand(time(NULL)); // inizializzazione del seed
    // generazione del minuto nell'intervallo PRIMO_MINUTO - ULTIMO_MINUTO, estremi compresi
    minuto_goal = PRIMO_MINUTO + rand() % (ULTIMO_MINUTO - PRIMO_MINUTO + 1);

    // chiedo all'utente di inserire il numero del giocatore che ha fatto il goal al minuto generato
    printf("Inserisci il numero del giocatore (tra 1 e 11) che ha fatto goal: ");
    scanf("%d", &giocatore_goal);
    // verifico che il numero inserito sia valido e nel caso proseguo con l'esecuzione
    if (giocatore_goal >= 1 && giocatore_goal <= 11) {
        // verifico se il goal è stato effettuato durante il primo o il secondo tempo
        if (minuto_goal <= DURATA_TEMPO) { // il minuto è nel primo tempo perché è compreso tra 1 e 45
            printf("\nIl goal e' stato fatto durante il 1° tempo (%d° minuto).", minuto_goal);
        } else { // altrimenti, dato che il numero è generato tra 1 e 90, è stato fatto tra il minuto 46 e 90 (secondo tempo)
            printf("\nIl goal e' stato fatto durante il 2° tempo (%d° minuto).", minuto_goal);
        }

        // verifico il ruolo del giocatore che ha fatto goal
        switch (giocatore_goal) {
            case PORTIERE:
                printf("\nIl goal e' stato fatto dal portiere.");
                break;
            case DIFENSORE_1:
            case DIFENSORE_2:
            case DIFENSORE_3:
                printf("\nIl goal e' stato fatto da un difensore.");
                break;
            case CENTROCAMPISTA_1:
            case CENTROCAMPISTA_2:
            case CENTROCAMPISTA_3:
            case CENTROCAMPISTA_4:
                printf("\nIl goal e' stato fatto da un centrocampista.");
                break;
            case ATTACCANTE_1:
            case ATTACCANTE_2:
            case ATTACCANTE_3:
                printf("\nIl goal e' stato fatto da un attaccante.");
                break;
        } // un default non e' necessario perche' il numero e' sempre tra 1 e 11
    } else { // se il numero e' invalido, il programma non puo' eseguire
        printf("\nErrore: inserisci un numero valido.");
    }

    // exit point
    return 0;
}
