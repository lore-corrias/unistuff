#include <stdio.h>
#include <stdlib.h>
///Inclusione librerie e definizione macro studente
// librerie per la generazione randomica
#include <time.h>
// libreria per il tipo booleano
#include <stdbool.h>
// numero di squadre nelle partite
#define SQUADRE 5
// punteggi possibili di ogni partita
#define NUMERO_RISULTATI 3
#define VITTORIA_CASA '1'
#define VITTORIA_TRASFERTA '2'
#define PAREGGIO 'X'
#define IMPOSSIBILE 'N' // codici ASCII dei caratteri relativi al risultato della partita
// /Fine inclusione librerie e definizione macro studente

int main() {

    int counterCasa = 0, counterTrasferta = 0;

    /// DICHIARAZIONE VARIABILI E ISTRUZIONI PRELIMINARI STUDENTE
    int campionato[SQUADRE][SQUADRE]; // matrice contenente i risultati
    int i, j; // contatori dei cicli for
    int risultato; // contenitore per il risultato della partita nel ciclo corrente
    int puntiCasa[SQUADRE] = {}, puntiTrasferta[SQUADRE] = {};
    // variabili utilizzate nell'acquisizione del valore booleano
    int generazioneRandomicaAux;
    bool generazioneRandomica;
    // squadra inserita/generata nell'esercizio 5
    int squadraScelta;
    // punteggio della squadra scelta
    int squadraSceltaVinte = 0, squadraSceltaPareggiate = 0, squadraSceltaPerse = 0;
    // variabile d'appoggio per determinare il vincitore
    int auxVincitore;


    srand(time(NULL)); // inizializzazione del seed

    // inizializzazione della matrice
    printf("Matrice campionato:\n");
    for(i = 0; i < SQUADRE; i++) { // ciclo per lo scorrimento delle righe
        for(j = 0; j < SQUADRE; j++) { // ciclo per lo scorrimento delle colonne
            if(i == j) {
                risultato = IMPOSSIBILE; // le due squadre sono uguali
            } else {
                // generazione randomica del risultato nell'intervallo 1-3 (i possibili risultati delle partite)
                risultato = rand() % NUMERO_RISULTATI;
            }
            switch(risultato) {
                case 0:
                    campionato[i][j] = VITTORIA_CASA;
                    break;
                case 1:
                    campionato[i][j] = VITTORIA_TRASFERTA;
                    break;
                case 2:
                    campionato[i][j] = PAREGGIO;
                    break;
                default:
                    campionato[i][j] = IMPOSSIBILE;
                    break;
            }
            printf("%c\t", campionato[i][j]);
        }
        printf("\n");
    }

    /// FINE CODICE STUDENTE

/** === ESERCIZIO 1 [3pt] =====================================================
 * Dichiara nello spazio apposito una matrice "campionato" che andrà a racchiudere i risultati
 * (casa e trasferta) del campionato di calcetto a 5 squadre del Palazzo delle Scienze.
 * Ogni riga i rappresenta l'andamento della squadra nel campionato di calcetto in CASA.
 * Ogni colonna j rappresenta l'andamento della squadra nel campionato di calcetto in TRASFERTA.
 * Nella matrice sarà possibile salvare i risultati:
 * - 1: vittoria squadra casa
 * - 2: vittoria squadra trasferta
 * - X: pareggio
 * - N: partita che non può avvenire (una squadra non può sfidare se stessa)
 * Inizializzare la matrice con dei risultati casuali, tenendo conto delle sfide che non possono esserci.
 *
 * Esempio di matrice:
 *   N  X  X  X  X
 *   X  N  1  2  X
 *   X  2  N  1  X
 *   X  2  1  N  1
 *   X  1  1  1  N
   ============================================================================ **/

//Codice studente...

/** FINE ESERCIZIO 1 **/




/** === ESERCIZIO 2 [2pt] =====================================================
 * Dichiarare nell'apposito spazio due array chiamati, rispettivamente, 'puntiCasa' e 'puntiTrasferta'.
   ============================================================================ **/
/** FINE ESERCIZIO 2 **/



/** === ESERCIZIO 3 [4pt] =====================================================
 * Correggere gli errori della seguente porzione di codice (anche nello stile).
 * La seguente porzione deve calcolare tutti i punti fatti in casa dalle squadre contenute nella matrice
 * campionato e stampare il numero complessivo di partite vinte dalle squadre che giocavano in casa.
 * In particolare, ogni vittoria vale 3 punti, ogni pareggio 1 punto e ogni sconfitta 0 punti.
 *
 * OPZIONALE: aggiungere il codice opportuno e svolgere insieme esercizio 3 e 4 [punteggio totale 8pt]
   ============================================================================ **/
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (campionato[i][j] == PAREGGIO) { // pareggio, entrambe le squadre ottengono un punto
                puntiCasa[i] += 1;
                puntiTrasferta[j] += 1;
            } else if(campionato[i][j] == VITTORIA_CASA) { // la squadra "i" ottiene tre punti, vittoria in più delle squadre in casa
                puntiCasa[i] += 3;
                counterCasa++;
            } else if(campionato[i][j] == VITTORIA_TRASFERTA) { // la squadra "j" ottiene tre punti, vittoria in più delle squadre in trasferta
                puntiTrasferta[j] += 3;
                counterTrasferta++;
            }
        }
        printf("Punti in casa della squadra %d: %d. Punti in trasferta: %d\n", i, puntiCasa[i], puntiTrasferta[i]);
    }

    printf("\nNumero complessivo di partite vinte dalle squadre che giocavano in casa: %d\n", counterCasa);
    printf("\nNumero complessivo di partite vinte dalle squadre che giocavano in trasferta: %d\n", counterTrasferta);

/** FINE ESERCIZIO 3 **/




/** === ESERCIZIO 4 [3pt] =====================================================
 * Scrivere una porzione di codice per calcolare, per ogni squadra, i punti fatti in trasferta.
 * Inoltre, stampare il numero complessivo di partite vinte dalle squadre che giocavano in trasferta.
 * HINT: se hai già svolto l'ESERCIZIO 4 insieme all'ESERCIZIO 3, non rifarlo!
   ============================================================================ **/

//Codice studente...

/** FINE ESERCIZIO 4**/




/** === ESERCIZIO 5 [6pt] =====================================================
 * Scrivere una porzione di codice che acquisisca un valore booleano. Nel caso in cui sia true, deve
 * essere generato casualmente un numero compreso tra 0 e N-1 (estremi inclusi). Altrimenti, deve essere chiesto
 * all'utente un numero compreso tra 0 e N-1 (estremi inclusi). Nel caso in cui il numero inserito sia un valore non
 * compreso, richiedere un nuovo inserimento fino a quando esso non rispetti il vincolo posto.
   ============================================================================ **/

//Codice studente...

    // acquisizione di una variabile booleana
    printf("\nInserisci '0' per inserire manualmente il numero di una squadra, qualsiasi altri numero per generarlo randomicamente: ");
    scanf("%d", &generazioneRandomicaAux);
    generazioneRandomica = (generazioneRandomicaAux != 0);

    if(generazioneRandomica) {
        // generazione della squadra tra 0 e SQUADRE - 1
        squadraScelta = rand() % SQUADRE;
        printf("\nSquadra generata: %d", squadraScelta);
    } else {
        // inserimento della squadra
        do {
            printf("\nInserisci il numero di una squadra da 0 a %d: ", SQUADRE - 1);
            scanf("%d", &squadraScelta);
        } while(squadraScelta < 0 || squadraScelta >= SQUADRE); // ripetizione dell'inserimento se la squadra non rispetta il vincolo
    }

/** FINE ESERCIZIO 5**/


/** === ESERCIZIO 6 [8pt] =====================================================
 * Utilizzare il valore inserito in input dall'utente nell'ESERCIZIO 5 come identificatore della squadra e stampare in
 * output il numero di partite vinte, pareggiate e perse da tale squadra.
   ============================================================================ **/

//Codice studente...

    for(i = 0; i < SQUADRE; i++) {
        // partite della squadra in casa
        switch(campionato[squadraScelta][i]) {
            case VITTORIA_CASA:
                squadraSceltaVinte += 1;
                break;
            case VITTORIA_TRASFERTA:
                squadraSceltaPerse += 1;
                break;
            case PAREGGIO:
                squadraSceltaPareggiate += 1;
                break;
        }

        // partite della squadra in trasferta
        switch(campionato[i][squadraScelta]) {
            case VITTORIA_CASA:
                squadraSceltaPerse += 1;
                break;
            case VITTORIA_TRASFERTA:
                squadraSceltaVinte += 1;
                break;
            case PAREGGIO:
                squadraSceltaPareggiate += 1;
                break;
        }
    }

    printf("\nPartite Vinte: %d", squadraSceltaVinte);
    printf("\nPartite Perse: %d", squadraSceltaPerse);
    printf("\nPartite Pareggiate: %d", squadraSceltaPareggiate);

/** FINE ESERCIZIO 6 **/




/** ESERCIZIO 7 [4pt]
 * Stampare in output il vincitore del campionato.
   ============================================================================ **/

//Codice studente...

    for(i = 0; i < SQUADRE; i++) {
        // confronto dei punteggi della squadra "i" e di quella che, al momento del ciclo, ha il punteggio più alto
        if(puntiCasa[i] + puntiTrasferta[i] >= puntiCasa[auxVincitore] + puntiTrasferta[auxVincitore]) {
            auxVincitore = i; // assegnazione della nuova squadra con punteggio maggiore
        }
    }

    printf("\nIl campionato è stato vinto dalla squadra %d!", auxVincitore);

/** FINE ESERCIZIO 7 **/

    return 0;
}