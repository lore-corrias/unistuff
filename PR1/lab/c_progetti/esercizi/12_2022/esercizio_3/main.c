/* Esercizio 05/12/2022 n° 3
 *
 * Testo:
 * "1. Scrivere un'enumerazione GiornoSettimana che rappresenti i 7 giorni della settimana (da LUN a DOM)
 * e un'enumerazione Mese che rappresenti i 12 mesi dell'anno (da GEN a DIC)
 * 2. Scrivere un tipo di dato struttura Data composto dai seguenti quattro campi: giorno, giornoSettimana, mese e anno.
 * Giorno è di tipo intero, giornoSettimana è di tipo enumerazione GiornoSettimana,
 * mese è di tipo enumerazione Mese, mentre anno è un intero.
 * 3. Scrivere un tipo di dato struttura Persona, costituito dai campi nome, cognome, luogo di nascita, data di nascita.
 * I primi tre campi sono stringhe, mentre l'ultimo è di tipo Data.
 * 4. Scrivere una funzione acquisisciPersona, che dichiari una struttura Persona e richieda in input all'utente i dati d’interesse.
 * Effettuare i controlli ritenuti opportuni per acquisire date valide.
 * Tale funzione deve restituire la struttura appena acquisita.
 * 5. Scrivere una procedura stampaDatiPersona che, ricevuta una Persona come parametro, stampi tutti i suoi dati d’interesse.
 * 6. Nel main, dichiarare una struttura Persona, a cui assegnare l'output di acquisisciPersona;
 * dopodiché stampare i suoi dati di interesse mediante la procedura stampaDatiPersona."
 */
#include <stdio.h>
/// librerie
#include <stdbool.h>
/// macro
// lunghezze dei field stringhe della struct Persona
#define L_NOME 16
#define L_COGNOME 16
#define L_LUOGO_NASCITA 40
// informazioni sugli enum
#define MESI 12

// tipi definiti dall'utente
/**
 * Giorni della settimana, da lunedì (0) a domenica (6)
 */
typedef enum {
    LUN, MAR, MER, GIO, VEN, SAB, DOM
} GiornoSettimana;
/**
 * Mesi della settimana, da gennaio (0) a dicembre (11)
 */
typedef enum {
    GEN, FEB, MARZ, APR, MAG, GIU, LUG, AGO, SET, OTT, NOV, DIC
} Mese;

/**
 * Struct rappresentante una data. Il giorno è un elemento dell'enum GiornoSettimana,
 * il mese dell'enum Mese e l'anno è un intero.
 */
typedef struct {
    GiornoSettimana giorno;
    Mese mese;
    int anno;
} Data;

/**
 * Struct contenente le informazioni principali di una persona. Nome, Cognome e
 * luogo di nascita sono stringhe, la data è una struct di tipo "Data"
 */
typedef struct {
    char nome[L_NOME];
    char cognome[L_COGNOME];
    char luogoNascita[L_LUOGO_NASCITA];
    Data dataNascita;
} Persona;


// dichiarazioni subroutine
Persona acquisisciPersona();
void stampaDatiPersona(Persona persona);


// entry point
int main() {
    // dichiarazione variabili
    Persona persona;

    // invocazione acquisisciPersona
    persona = acquisisciPersona();

    // stampa della persona
    stampaDatiPersona(persona);

    // exit point
    return 0;
}


// definizioni subroutine
Persona acquisisciPersona() {
    Persona persona; // la struct da restituire
    Data dataDiNascita; // data di nascita di persona
    int giorniMese; // numero di giorni del mese scelto, viene modificato dopo
    bool annoBisestile; // booleano che verifica che l'anno sia bisestile
    printf("\nInserisci il nome della persona (max %d caratteri): ", L_NOME);
    scanf(" %16[^\n]s", persona.nome);
    printf("\nInserisci il cognome della persona (max %d caratteri): ", L_COGNOME);
    scanf(" %16[^\n]s", persona.cognome);
    printf("\nInserisci il luogo di nascita della persona (max %d caratteri): ", L_LUOGO_NASCITA);
    scanf(" %40[^\n]s", persona.luogoNascita);
    printf("\nInserisci l'anno di nascita: ");
    scanf("%d", &dataDiNascita.anno);
    // requisito di bisestilità dell'anno: divisibile per 400 o per 4 ma non per 100
    annoBisestile = (dataDiNascita.anno % 4 == 0 && dataDiNascita.anno % 100 != 0) || dataDiNascita.anno % 400 == 0;
    // richiesta del mese finché non rientra nel range giusto (da 0 a MESI-1)
    dataDiNascita.mese = -1;
    do {
        printf("\nInserisci il mese di nascita (da 1 a %d): ", MESI);
        scanf("%d", &dataDiNascita.mese);
    } while(dataDiNascita.mese <= 0 || dataDiNascita.mese > MESI);
    // calcolo dei giorni nel mese inserito (l'enumeratore parte da 0, i mesi da 1, quindi bisogna togliere 1)x
    switch (dataDiNascita.mese-1) {
        case APR:
        case GIU:
        case SET:
        case NOV:
            giorniMese = 30; // il numero di giorni in questi mesi è 30
            break;
        case FEB:
            giorniMese = annoBisestile ? 29 : 28; // se l'anno è bisestile, febbraio ha 29 giorni
            break;
        default:
            giorniMese = 31; // gli altri mesi hanno 31 giorni
            break;
    }
    // richiesta del giorno finché non rientra nel range giusto (da 1 a giorniMese)
    dataDiNascita.giorno = 0;
    do {
        printf("\nInserisci il giorno di nascita: ");
        scanf("%d", &dataDiNascita.giorno);
    } while (dataDiNascita.giorno <= 0 || dataDiNascita.giorno > giorniMese);
    // assegnazione della data di nascita
    persona.dataNascita = dataDiNascita;
    return persona;
}

/**
 * Stampa i dati di una persona (nome, cognome, luogo di nascita e data di nascita)
 * @param persona
 */
void stampaDatiPersona(Persona persona) {
    printf("\nNome: %s\nCognome: %s\nLuogo di nascita: %s\nData di nascita: %d/%d/%d",
           persona.nome, persona.cognome, persona.luogoNascita,
           persona.dataNascita.giorno, persona.dataNascita.mese, persona.dataNascita.anno);
}