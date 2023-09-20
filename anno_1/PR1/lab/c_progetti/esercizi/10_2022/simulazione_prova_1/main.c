#include <stdio.h>
#include <math.h> // libreria per la funzione pow()
#include <stdlib.h>
#include <time.h> // librerie per la generazione randomica
#define SOMMA '+'
#define DIFFERENZA '-'
#define PRODOTTO '*'
#define DIVISIONE '/'
#define MODULO '%'
#define POTENZA '^'
#define MEDIA 'm' // macro contenenti i caratteri relativi alle operazioni da effettuare
#define NUMERO_OPERANDI 2 // macro da usare nel calcolo della media contenente il numero totale di operandi
#define MIN_GENERAZIONE 1
#define MAX_GENERAZIONE 100 // range di generazione dei numeri casuali
#define CIFRE_DECIMALI_NUMERI_RANDOM 2 // macro che contiene il numero di cifre decimali dei numeri randomici generati
#define POTENZA_DIECI_CIFRE_DECIMALI (float)pow(10, CIFRE_DECIMALI_NUMERI_RANDOM) // macro usata per la generazione di numeri random float con x cifre decimali
#define D_FLOAT 'F'
#define D_INTERI 'I'
#define INSERIMENTO_MANUALE 'M'
#define INSERIMENTO_RANDOMICO 'R'

/* Esercitazione prova d'esame 21/10/2022
 *
 * Testo:
 * ""
*/

// entry point
int main() {
    // dichiarazione variabili
    float operando1, operando2, risultato;
    char operazione_scelta;
    // variabile da usare nel caso della divisione, contiene 'F', se l'utente ha scelto la divisione tra float, o 'I'
    char divisione_interi_float;
    // variabile che contiene la scelta tra la generazione randomica dei numeri ('r') o l'inserimento manuale ('m')
    char modalita_inserimento_numeri;

    printf("Scegli se inserire i numeri manualmente (digita 'M') oppure randomicamente (digita 'R').\n"
           "P.S.: i numeri generati randomicamente saranno uno pari e uno dispari.\n"
           "(%c/%c): ", INSERIMENTO_MANUALE, INSERIMENTO_RANDOMICO);
    scanf("%c", &modalita_inserimento_numeri);

    if(modalita_inserimento_numeri == INSERIMENTO_MANUALE) {
        // lettura da tastiera dei valori delle variabili
        printf("\nInserisci il primo operando: ");
        scanf("%f", &operando1);
        printf("\nInserisci il secondo operando: ");
        scanf("%f", &operando2);
    } else if(modalita_inserimento_numeri == INSERIMENTO_RANDOMICO) {
        srand(time(NULL)); // generazione del seed
        // generazione randomica dei numeri tra 1 e 100. uno deve essere pari e l'altro dispari
        // definisco una variabile che contenga la potenza di dieci per cui moltiplicare gli estremi dell'intervallo
        /*
         * dato che i numeri devono essere generati come float, e' necessario generarli in un intervallo
         * che sia compreso tra 1*(10^NUMERO_CIFRE_DECIMALI) e 100*(10^NUMERO_CIFRE_DECIMALI) e dividere
         * poi il risultato per 10^NUMERO_CIFRE_DECIMALI.
        */
        operando1 = (MIN_GENERAZIONE * POTENZA_DIECI_CIFRE_DECIMALI + rand() % (int)(MAX_GENERAZIONE * POTENZA_DIECI_CIFRE_DECIMALI - MIN_GENERAZIONE * POTENZA_DIECI_CIFRE_DECIMALI + 1)) / POTENZA_DIECI_CIFRE_DECIMALI; // cast a int per effettuare il modulo
        operando2 = (MIN_GENERAZIONE * POTENZA_DIECI_CIFRE_DECIMALI + rand() % (int)(MAX_GENERAZIONE * POTENZA_DIECI_CIFRE_DECIMALI - MIN_GENERAZIONE * POTENZA_DIECI_CIFRE_DECIMALI + 1)) / POTENZA_DIECI_CIFRE_DECIMALI; // cast a int per effettuare il modulo
        // verifica che operando1 sia pari, in caso contrario aggiungi/rimuovi 1
        if((int)operando1 % 2 != 0) {
            // se il valore si trova al confine del range, togli uno per non uscire dall'intervallo, altrimenti aggiungi 1
            operando1 += operando1 == MAX_GENERAZIONE ? -1 : 1;
        }
        // verifica che operando2 sia dispari, in caso contrario aggiungi/rimuovi 1
        if((int)operando2 % 2 == 0) {
            // se il valore si trova al confine del range, togli uno per non uscire dall'intervallo, altrimenti aggiungi 1
            operando2 += operando2 == MAX_GENERAZIONE ? -1 : 1;
        }
        printf("\nNumeri generati: %.2f, %.2f", operando1, operando2);
    } else {
        printf("\nErrore: digita '%c' o '%c'.", INSERIMENTO_MANUALE, INSERIMENTO_RANDOMICO);
        return -1;
    }

    // scelta dell'operazione
    printf("\nInserisci un carattere che indichi l'operazione da eseguire.\n"
           "'%c': somma; '%c': differenza; '%c': prodotto; '%c': divisione (scegliere poi se tra interi o float)\n"
           "'%c': modulo; '%c': potenza; '%c': media tra i due numeri.\n"
           "Scegli l'operatore: ", SOMMA, DIFFERENZA, PRODOTTO, DIFFERENZA, MODULO, POTENZA, MEDIA);
        getchar(); // consumo il carattere dell'invio
        scanf("%c", &operazione_scelta);

    // controllo dell'operatore ed esecuzione dell'annessa operazione
    switch(operazione_scelta) {
        case SOMMA:
            risultato = operando1 + operando2;
            break;
        case DIFFERENZA:
            risultato = operando1 - operando2;
            break;
        case PRODOTTO:
            risultato = operando1 * operando2;
            break;
        case DIVISIONE:
            printf("Hai scelto l'operatore 'divisione'. Preferisci effettuare una divisione tra interi o float?\n"
                   "Inserisci '%c' per la divisione tra float, '%c' per quella tra interi: ", D_FLOAT, D_INTERI);
            getchar(); // consumo l'ultimo carattere invio
            scanf("%c", &divisione_interi_float);
            // divisione tra float (il carattere può essere sia maiuscolo che minuscolo)
            if(divisione_interi_float == D_FLOAT) {
                risultato = operando1 / operando2;
            } else if(divisione_interi_float == D_INTERI) { // divisione tra interi
                risultato = (int) operando1 / (int) operando2; // cast per la divisione tra interi
            } else {
                printf("\nErrore: inserisci 'f' o 'i'.");
                return -1;
            }
            break;
        case MODULO:
            risultato = (int)operando1 % (int)operando2; // cast perche' il modulo puo' avvenire solo tra due interi
            break;
        case POTENZA:
            risultato = pow(operando1, operando2);
            break;
        case MEDIA:
            risultato = (operando1 + operando2) / NUMERO_OPERANDI;
            break;
        default:
            printf("\nErrore: operazione non riconosciuta.");
            return -1;
    }

    // stampa a schermo del risultato
    // sono necessari due controlli: se la divisione e' tra interi o se l'operatore scelto e' il modulo, bisogna convertire le variabili in interi
    if(operazione_scelta == MODULO || (operazione_scelta == DIVISIONE && (divisione_interi_float == 'i' || divisione_interi_float == 'I'))) {
        printf("\nIl risultato dell'operazione '%d %c %d' vale '%d'.", (int)operando1, operazione_scelta, (int)operando2, (int)risultato);
    } else {
        printf("\nIl risultato dell'operazione '%.2f %c %.2f' vale '%.2f'", operando1, operazione_scelta, operando2, risultato);
    }
    // exit point
    return 0;
}
