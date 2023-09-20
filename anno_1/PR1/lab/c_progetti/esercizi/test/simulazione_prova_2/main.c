#include <stdio.h>
#include <stdlib.h>
#include <time.h> // librerie per la generazione del numero random
#include <stdbool.h> // libreria per il tipo booleano, utile per riassumere condizioni booleane da riutilizzare
#define PRIMO_CARATTERE_ASCII 1
#define ULTIMO_CARATTERE_ASCII 255 // primo e ultimo carattere ascii da usare nella generazione casuale
#define PRIMA_LETTERA_MAIUSCOLA 'A'
#define ULTIMA_LETTERA_MAIUSCOLA 'Z'
#define PRIMA_LETTERA_MINUSCOLA 'a'
#define ULTIMA_LETTERA_MINUSCOLA 'z' // prime e ultime lettere maiuscole/minuscole dell'alfabeto
#define INSERIMENTO_CARATTERE_MANUALE 'm'
#define INSERIMENTO_CARATTERE_RANDOMICO 'r' // keyword inseribili dall'utente che determinano l'inserimento manuale o randomico del carattere

/* Esercizio 22/10/2022 n° 1
 *
 * Testo:
 * "1) Generare un carattere ASCII casuale (tra 1 e 255 estremi inclusi), stamparlo a video e
 * verificare se esso rappresenti una lettera mediante un costrutto IF.
 * 2) Nel caso lo sia, utilizzare un costrutto SWITCH per determinare se essa sia una vocale o una consonante stampando
 * poi un messaggio per comunicarlo all'utente. In caso contrario stampare un messaggio relativo.
 * 3) Tramite un costrutto IF verificare se la lettera sia maiuscola o minuscola, stampando
 * un messaggio per comunicarlo all’utente. In caso contrario stampare un messaggio relativo.
 * 4) Modificare il programma per chiedere all’utente se vuole generare casualmente il carattere
 * oppure inserirlo in input. Commentare opportunatamente tutto il codice."
*/

// entry point
int main() {
    // dichiarazione variabili
    char modalita_inserimento_carattere, carattere;
    // variabili contenenti le condizioni booleane che indicano il fatto che la lettera sia maiuscola/minuscola
    bool is_lettera_maiuscola, is_lettera_minuscola;
    // condizione per verificare che modalita_inserimento_carattere sia un carattere accettabile
    bool modalita_inserimento_carattere_accettabile;

    // richiedo all'utente se preferisce generare o inserire un carattere
    printf("Preferisci inserire un carattere ('%c') o generarlo randomicamente ('%c')? ", INSERIMENTO_CARATTERE_MANUALE, INSERIMENTO_CARATTERE_RANDOMICO);
    scanf("%c", &modalita_inserimento_carattere);
    // controllo che il carattere inserito sia accettabile
    switch (modalita_inserimento_carattere) {
        case INSERIMENTO_CARATTERE_RANDOMICO:
            modalita_inserimento_carattere_accettabile = true; // carattere accettabile
            srand(time(NULL)); // inizializzazione del seed
            // viene generato un numero, ma durante l'assegnazione alla variabile char viene castato implicitamente
            carattere = PRIMO_CARATTERE_ASCII + rand() % (ULTIMO_CARATTERE_ASCII - PRIMO_CARATTERE_ASCII + 1); // formula per la generazione randomica tra 1 e 355
            break;
        case INSERIMENTO_CARATTERE_MANUALE:
            modalita_inserimento_carattere_accettabile = true; // carattere accettabile
            printf("\nInserisci il carattere da verificare: ");
            getchar(); // consumo l'ultimo carattere invio
            scanf("%c", &carattere);
            break;
        default:
            modalita_inserimento_carattere_accettabile = false;
            break;
    }

    // continua l'esecuzione del programma solo se l'utente ha inserito un carattere valido per la modalità di inserimento
    if(modalita_inserimento_carattere_accettabile) {
        // verificare che il carattere sia una lettera mediante if
        is_lettera_minuscola = (carattere >= PRIMA_LETTERA_MINUSCOLA && carattere <= ULTIMA_LETTERA_MINUSCOLA);
        is_lettera_maiuscola = (carattere >= PRIMA_LETTERA_MAIUSCOLA && carattere <= ULTIMA_LETTERA_MAIUSCOLA);
        if(is_lettera_maiuscola || is_lettera_minuscola) { // se il carattere è una lettera (maiuscola o minuscola)
            printf("\nIl carattere '%c' e' una lettera.", carattere);

            // controllo che la lettera sia un consonante o una vocale
                switch(carattere) {
                case 'A':
                case 'a':
                case 'E':
                case 'e':
                case 'I':
                case 'i':
                case 'O':
                case 'o':
                case 'U':
                case 'u': // che il carattere sia una vocale maiuscola o minuscola, viene eseguito il case di sotto
                    printf("\nIl carattere '%c' e' una vocale.", carattere);
                    break;
                default: // altrimenti, dato che il carattere è una lettera e non una vocale, è una consonante
                    printf("\nIl carattere '%c' e' una consonante.", carattere);
                    break;
            }

            // controllo che la lettera sia maiuscola o minuscola riutilizzando la condizione booleana specificata prima
            if(is_lettera_minuscola) {
                // il carattere è compreso tra la prima e ultima lettera minuscola, quindi è una lettera minuscola
                printf("\nIl carattere '%c' e' una lettera minuscola.", carattere);
            } else { // se non è minuscola, è maiuscola
                printf("\nIl carattere '%c' e' una lettera maiuscola.", carattere);
            }
        } else {
            printf("\nIl carattere '%c' non e' una lettera.", carattere);
        }
    } else { // il carattere inserito per rispondere alla domanda non e' accettabile e il programma non puo' eseguire.
        printf("\nErrore: inserisci un carattere valido.");
    }

    // exit point
    return 0;
}
