/* Esercizio 18/12/2022 n° 5
 *
 * Testo:
 * "Definire una struttura per la modellazione dei dati anagrafici di uno studente
 * (nome, cognome, data di nascita ecc), quindi creare e popolare un array di studenti.
 * Aggiungere una seconda struttura per la modellazione dei risultati di una sessione d’esame,
 * che contiene, oltre alla data, al luogo e al nominativo del professore,
 * un elenco di voti abbinati agli studenti
 * (suggerimento: utilizzare gli indici degli studenti nel primo array per recuperare le informazioni).
 *
 * Scrivere una funzione che verifica che lo stesso studente non compaia due volte nell’elenco,
 * un’altra funzione che conta quanti studenti hanno sostenuto l’esame con esito positivo,
 * ed un’altra funzione che visualizza i nomi e i voti degli studenti che hanno ottenuto voto maggiore o uguale a 28.
 *
 * Inserire gli Studenti in un array dichiarato dinamicamente.
 * La dimensione dell'array deve crescere ad ogni inserimento di un nuovo studente.
*/
#include <stdio.h>
// librerie
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// macro
#define NAME_LEN 20
#define SURN_LEN 30
#define LOC_LEN 50
#define STOP_INSERT (-1)
#define CURRENT_YEAR 2022
#define YES 'Y'
#define NO 'N'
#define VOTO_MINIMO 0
#define VOTO_MASSIMO 30


// definizione enumerazioni
typedef enum {
    GEN=1, FEB, MAR, APR, MAG, GIU, LUG, AGO, SET, OTT, NOV, DIC
} Mese;

// definizione strutture
typedef struct {
    int giorno;
    Mese mese;
    int anno;
} Data;

typedef struct {
    char nome[NAME_LEN+1];
    char cognome[SURN_LEN+1];
    Data dataDiNascita;
} Studente;

typedef struct {
    Data dataEsame;
    char luogo[LOC_LEN+1];
    char nomeProf[NAME_LEN+1];
    float *voti;
} Sessione;


// definizione subroutine
void aggiungiStudente(int, int, Studente[], Sessione*);
bool isInElenco(Studente, int, Studente[]);
int contaPromossi(int, Sessione);
void checkNotNullPointer(void *);
void stampaSopraVentotto(int, Studente[], Sessione);
void inserisciInformazioniSessione(Sessione*);
void inserisciData(Data*);


int main() {
    // dichiarazione variabili
    int n_studenti; // variabile contenente il numero di studenti - 1
    int n_promossi; // variabile contenente il numero di studenti promossi
    Studente *studenti = NULL; // array dinamico degli studenti
    Sessione *sessione = NULL; // puntatore alla variabile contenente la sessione
    bool repeat = true; // variabile temporanea che contiene la condizione per la ripetizione del ciclo while

    // allocazione dinamica
    studenti = (Studente *) calloc(1, sizeof(Studente));
    checkNotNullPointer(studenti);
    sessione = (Sessione *) malloc(sizeof(Sessione));
    checkNotNullPointer(sessione);
    sessione->voti = (float *) calloc(1, sizeof(float));
    checkNotNullPointer(sessione->voti);

    // inserimento informazioni sulla sessione
    inserisciInformazioniSessione(sessione);

    // aggiunta degli studenti
    printf("\nInserisci le informazioni su uno studente: ");
    char repeatTmp;
    for(n_studenti = 1; repeat; n_studenti++) {
        // riallocazione della memoria per l'array con l'aggiunta di uno spazio per il nuovo studente
        studenti = (Studente *) realloc(studenti, sizeof(Studente) * n_studenti);
        sessione->voti = (float *) realloc(sessione->voti, sizeof(int) * n_studenti);
        aggiungiStudente(n_studenti - 1, n_studenti, studenti, sessione);
        printf("\nVuoi aggiungere un altro studente? (%c/%c): ", YES, NO);
        scanf(" %c", &repeatTmp);
        repeat = repeatTmp == YES;
    }

    // conta degli studenti promossi
    n_promossi = contaPromossi(n_studenti, *sessione);
    printf("\nNumero di studenti promossi: %d", n_promossi);

    // stampa degli studenti con un voto >= 28
    stampaSopraVentotto(n_studenti, studenti, *sessione);

    // deallocazione memoria
    free(studenti);
    free(sessione);

    return 0;
}


void aggiungiStudente(int posizione, int n_studenti, Studente studenti[], Sessione *sessione) {
    bool repeat; // condizione di ripetizione del ciclo while
    Studente studente; // variabile contenente lo studente da aggiungere

    // controllo dell'indice dell'array
    if(posizione < 0 || posizione >= n_studenti)
        printf("\nErrore: la posizione dello studente va fuori dai limiti dell'array.");
    // richiesta nome, cognome, data di nascita
    do {
        printf("\nInserisci il nome dello studente: ");
        scanf(" %20[^\n]s", studente.nome);
        printf("\nInserisci il cognome dello studente: ");
        scanf(" %30[^\n]s", studente.cognome);
        printf("\nInserisci la data di nascita dello studente: ");
        inserisciData(&studente.dataDiNascita);
        repeat = isInElenco(studente, n_studenti, studenti);
        if(repeat)
            printf("\nErrore: l'utente inserito e' gia' nell'elenco, riprova.");
    } while (repeat);
    studenti[posizione] = studente;

    // richiesta del voto
    printf("\nInserisci il voto dell'utente (tra %d e %d): ", VOTO_MINIMO, VOTO_MASSIMO);
    do {
        scanf("%f", &sessione->voti[posizione]);
        repeat = sessione->voti[posizione] < 0 || sessione->voti[posizione] > 30;
        if(repeat)
            printf("\nErrore, inserisci un voto valido: ");
    } while(repeat);
}

bool isInElenco(Studente studente, int n_studenti, Studente studenti[]) {
    for(int i = 0; i < n_studenti; i++) {
        if(strcmp(studenti[i].nome, studente.nome) == 0 &&
            strcmp(studenti[i].cognome, studente.cognome) == 0 &&
            studenti[i].dataDiNascita.giorno == studente.dataDiNascita.giorno &&
            studenti[i].dataDiNascita.mese == studente.dataDiNascita.mese &&
            studenti[i].dataDiNascita.anno == studente.dataDiNascita.anno)
            return true;
    }
    return false;
}

int contaPromossi(int n_studenti, Sessione sessione) {
    int promossi = 0;
    for(int i = 0; i < n_studenti; i++) {
        if(sessione.voti[i] >= 18)
            promossi++;
    }
    return promossi;
}

void stampaSopraVentotto(int n_studenti, Studente studenti[], Sessione sessione) {
    for(int i = 0; i < n_studenti; i++) {
        if(sessione.voti[i] >= 28)
            printf("\n%s %s ha ottenuto %.1f.", studenti[i].nome, studenti[i].cognome, sessione.voti[i]);
    }
}

void checkNotNullPointer(void *pointer) {
    if(pointer == NULL) {
        printf("\nImpossibile allocare sufficiente memoria.");
        exit(-1);
    }
}

void inserisciInformazioniSessione(Sessione *sessione) {
    // Inserimento del nome del prof e del luogo dell'esame
    printf("\nInserisci il nome del professore della sessione (max %d caratteri): ", NAME_LEN);
    scanf(" %20[^\n]s", sessione->nomeProf);
    printf("\nInserisci il luogo dove si e' tenuta la sessione (max %d caratteri): ", LOC_LEN);
    scanf(" %50[^\n]s", sessione->luogo);

    // Inserimento della data
    inserisciData(&sessione->dataEsame);
}

void inserisciData(Data *data) {
    bool repeat; // condizione di ripetizione dei cicli while

    // Inserimento dell'anno
    printf("\nInserisci l'anno: ");
    do {
        scanf("%d", &data->anno);
        repeat = data->anno < 0 || data->anno > CURRENT_YEAR;
        if(repeat)
            printf("\nErrore: inserisci un anno valido: ");
    } while (repeat);

    // Inserimento del mese
    printf("\nInserisci il mese (%d = Gennaio, %d = Dicembre): ", GEN, DIC);
    do {
        scanf("%d", &data->mese);
        repeat = data->mese < GEN || data->mese > DIC;
        if(repeat)
            printf("\nErrore: inserisci un mese valido: ");
    } while(repeat);

    // Inserimento del giorno
    int giorniMese;
    // condizione di bisestilità
    bool isBisestile = data->anno % 400 == 0 || (data->anno % 4 == 0 && data->anno % 100 != 0);
    // calcolo del numero di giorni per il mese
    switch (data->mese) {
        case APR:
        case GIU:
        case SET:
        case NOV:
            giorniMese = 30;
            break;
        case FEB:
            giorniMese = 28 + (isBisestile ? 1 : 0);
            break;
        default:
            giorniMese = 31;
            break;
    }
    printf("\nInserisci il giorno (tra 1 e %d): ", giorniMese);
    do {
        scanf("%d", &data->giorno);
        repeat = data->giorno < 1 || data->giorno > giorniMese;
        if(repeat)
            printf("\nErrore, inserisci un giorno valido: ");
    } while (repeat);
}