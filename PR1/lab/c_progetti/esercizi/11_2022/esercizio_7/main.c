#include <stdio.h>
// macro
// mesi che non hanno 31 giorni
#define APRILE 4
#define GIUGNO 6
#define SETTEMBRE 9
#define NOVEMBRE 11
#define FEBBRAIO 2

/* Esercizio 24/11/2022 n° 3
 *
 * Testo:
 * "Scrivere una funzione calcolaGiorno(giorno, mese, anno)
 * che restituisca il giorno dell'anno (un numero compreso tra 1 e 366) specificato dai tre argomenti.
 * La funzione deve verificare se l'anno è bisestile o meno, ed effettuare il calcolo di conseguenza.
 * Nel main, impostare una data e stampare in output il giorno dell'anno.
 *
 * •NB: un anno è bisestile se è divisibile per 400; altrimenti se è divisibile per 4 ma non per 100.
 * •Modificare, poi, l'esercizio per rendere il calcolo dell'anno bisestile una funzione."
 */

// dichiarazione subroutine
int isBisestile(int);
int calcolaGiorno(int, int, int);

int main() {
    // chiamata della subroutine e stampa
    printf("%d", calcolaGiorno(3, 3, 2000));

    return 0;
}

// definizione subroutine
/**
 * Funzione per determinare se un anno è bisestile.
 *
 * @param anno l'anno da verificare
 * @return 1 se l'anno è bisestile, 0 altrimenti
 */
int isBisestile(int anno) {
    // condizione per l'anno bisestile
    return anno % 400 == 0 || (anno % 4 == 0 && anno % 100 != 0);
}

/**
 * Funzione per calcolare il numero del giorno dell'anno
 * di cui è fornito il giorno, mese e anno.
 *
 * @param giorno giorno del mese
 * @param mese mese dell'anno
 * @param anno anno
 * @return il numero del giorno dell'anno
 */
int calcolaGiorno(int giorno, int mese, int anno) {
    int giorni_counter = 0; // contatore dei giorni per il ciclo
    // iterazione per i mesi dell'anno
    for(int i = 1; i <= mese; i++) {
        // se ho raggiunto il mese richiesto, aggiungo i giorni inseriti
        if(mese == i) {
            giorni_counter += giorno;
        } else {
            // altrimenti, aggiungo i giorni del mese iterato
            switch(i) {
                case FEBBRAIO:
                    giorni_counter += (isBisestile(anno) ? 29 : 28); // controllo per l'anno bisestile
                    break;
                case APRILE:
                case GIUGNO:
                case SETTEMBRE:
                case NOVEMBRE:
                    giorni_counter += 30;
                    break;
                default:
                    giorni_counter += 31;
                    break;
            }
        }
    }
    // restituisco il numero del giorno
    return giorni_counter;
}