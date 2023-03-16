/* Esercizio 05/12/2022 n° 2
 *
 * Testo:
 * "Definire una enumerazione che rappresenti il gruppo sanguigno GS (A, B, ZERO, AB).
 * Definire poi una struttura che contenga i dati di una Persona (età, peso in kg, altezza in cm)
 * e successivamente una struttura Donatore che contenga un campo Persona, un campo enumerazione GS,
 * un intero, rappresentante il numero di giorni trascorsi dall'ultima donazione, e un intero
 * rappresentante il codice identificativo del donatore di sangue.
 *
 * Realizzare un programma in cui viene dichiarato un array di donatori di lunghezza a piacere e,
 * dopo aver inserito i dati di ogni donatore, il programma deve stabilire se ognuno di essi può donare il sangue.
 * In particolare:
 * •Se il peso è inferiore a 50 kg, non è possibile
 * •Se l'ultima donazione è stata fatta prima di 90 giorni, non è possibile.
 * •Se l'età è inferiore a 18 anni o maggiore di 65, non è possibile.
 * •È possibile in tutti gli altri casi.
 * •Stampare, come output, tutti i dati dei pazienti che possono donare il sangue, precisando il perché è possibile."
 */
#include <stdio.h>
// librerie
#include <stdbool.h>
// macro
#define LEN 2 // lunghezza dell'array di donatori

// tipi definiti dall'utente
// enum contenente i gruppi sanguigni esistenti, usata nella struct Persona
typedef enum {
    A,
    B,
    ZERO,
    AB
} GruppoSanguigno;

// struct contenente i dati della persona che è donatore, nella struct Donatore
typedef struct {
    int eta;
    int pesoKg;
    int altezzaCm;
} Persona;

// struct rappresentante un donatore di sangue, con il suo gruppo sanguigno e dati anagrafici
typedef struct {
    Persona persona;
    GruppoSanguigno gruppoSanguigno;
    int ultimaDonazione;
    int identificativo;
} Donatore;


// dichiarazioni subroutine
void inserisciDonatore(int posizione, int n_donatori, Donatore donatori[n_donatori]);
bool donatoreValido(Donatore donatore);


// entry point
int main() {
    // dichiarazione variabili
    Donatore donatori[LEN];

    // inizializzazione dell'array
    for(int i = 0; i < LEN; i++) {
        printf("\n%d° donatore:\n", i+1);
        inserisciDonatore(i, LEN, donatori);
    }

    // verifica dei donatori
    for(int i = 0; i < LEN; i++) {
        if(donatoreValido(donatori[i])) {
            // stampa dei dati del donatore valido
            printf("\nIl %d° donatore e' valido:", i+1);
            printf("\nEta': %d", donatori[i].persona.eta);
            printf("\nAltezza: %dcm", donatori[i].persona.altezzaCm);
            printf("\nPeso: %dkg", donatori[i].persona.pesoKg);
            printf("\nGiorni dall'ultima donazione: %d", donatori[i].ultimaDonazione);
            printf("\nIdentificativo: %d", donatori[i].identificativo);
            printf("\nGruppo sanguigno: ");
            switch(donatori[i].gruppoSanguigno) {
                case A:
                    printf("A");
                    break;
                case B:
                    printf("B");
                    break;
                case ZERO:
                    printf("ZERO");
                    break;
                case AB:
                    printf("AB");
                    break;
            }
        }
    }

    // exit point
    return 0;
}


// definizioni subroutine
/**
 * Inserisci un donatore nell'array donatori.
 * I dati del donatore sono richiesti in input.
 * @param posizione Posizione dell'array in cui inserire il donatore.
 * @param n_donatori Numero di donatori nell'array
 * @param donatori Array di donatori
 *
 */
void inserisciDonatore(int posizione, int n_donatori, Donatore donatori[n_donatori]) {
    Donatore donatore;
    // richiesta dei dati anagrafici
    printf("Inserisci l'eta' del donatore: ");
    scanf("%d", &donatore.persona.eta);
    printf("\nInserisci il peso in kg del donatore: ");
    scanf("%d", &donatore.persona.pesoKg);
    printf("\nInserisci l'altezza in cm del donatore: ");
    scanf("%d", &donatore.persona.altezzaCm);
    // richiesta del gruppo se il valore non è riconosciuto
    GruppoSanguigno gruppoSanguigno = -1;
    do {
        printf("\nInserisci il gruppo sanguigno.\n"
               "0) A\n1) B\n2) ZERO\n3) AB\n"
               "Inserisci il numero corrispondente al gruppo: ");
        scanf("%d", &gruppoSanguigno);
    } while (gruppoSanguigno < 0 || gruppoSanguigno > 3);
    // assegnazione del gruppo al donatore
    donatore.gruppoSanguigno = gruppoSanguigno;
    // giorni dall'ultima donazione
    printf("\nInserisci i giorni trascorsi dall'ultima donazione: ");
    scanf("%d", &donatore.ultimaDonazione);
    // identificativo come posizione nell'array
    donatore.identificativo = posizione;
    donatori[posizione] = donatore; // assegnazione dell'elemento all'array
}

/**
 * Verifica che un donatore sia valido:
 * * peso < 50kg
 * * ultimaDonazione > 90gg
 * * 18 < eta < 65
 * @param donatore Il donatore da verificare
 * @return true se il donatore è valido, false altrimenti
 */
bool donatoreValido(Donatore donatore) {
    return donatore.persona.pesoKg > 50 && donatore.ultimaDonazione > 90 && donatore.persona.eta > 18 && donatore.persona.eta < 65;
}