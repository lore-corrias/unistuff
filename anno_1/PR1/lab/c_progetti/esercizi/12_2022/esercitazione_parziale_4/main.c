#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/**
--------------------------------------------------------------------------------------------------
Testo del problema:

Vogliamo creare un programma che permetta di gestire una guida dei migliori cuochi italiani.
Ogni cuoco ha un nome, un cognome, un'eta', un tipo (cuoco, pizzaiolo, pasticcere)
e un numero di stelle michelin.

Il programma deve permettere di:

1)inserire un numero arbitrario di cuochi,
2)stamparli a video,
3)contare quanti cuochi di ogni tipo sono stati inseriti,
4)restituire il cuoco piu' giovane e il cuoco piu' vecchio,
5)permettere di modificare il nome e il cognome di un cuoco in modo che sia
  tutto in maiuscolo se il cuoco ha piu' di 3 stelle michelin


--------------------------------------------------------------------------------------------------
Direttive generali:

Creare opportune subroutine per ogni operazione e chiamarle dal main.

E' possibile la creazione di subroutine ausiliarie.


--------------------------------------------------------------------------------------------------
*/
// dichiarazione costanti
#define NAME_LEN 20
#define SURNAME_LEN 40
#define STELLE_MIN 1
#define STELLE_MAX 3
#define LOWERCASE_MIN 'a'
#define LOWERCASE_MAX 'z'
#define LOWER_UPPER_DIST (LOWERCASE_MIN-'A')

// dichiarazione enumerazioni e strutture
// enumerazione contenente i tre tipi di cuoco
typedef enum {CUOCO, PIZZAIOLO, PASTICCERE} TipoCuoco;

// struttura contenente le informazioni di un cuoco
typedef struct {
    char nome[NAME_LEN+1];
    char cognome[SURNAME_LEN+1];
    int eta;
    TipoCuoco tipoCuoco;
    int numeroStelle;
} Cuoco;

// definizione firme subroutine
void checkNotNullPointer(void * pointer);
Cuoco acquisisciCuoco();
Cuoco * acquisisciCuochi(int n_cuochi);
void stampaArrayCuochi(Cuoco cuochi[], int n_cuochi);
int contaCuochiTipo(Cuoco cuochi[], int n_cuochi, TipoCuoco tipoCuoco);
void calcolaEtaMinMax(Cuoco cuochi[], int n_cuochi, Cuoco *giovane, Cuoco *vecchio);
void stampaCuoco(Cuoco cuoco);
void toUppercase(char *ch);
void modificaNome(Cuoco *cuoco);

int main() {
    // definizione variabili
    Cuoco *guidaMichelin = NULL;
    Cuoco giovane, vecchio;
    int nCuochi = 0;

    do {
        printf("Quanti cuochi vuoi inserire nella guida? \n");
        scanf("%d", &nCuochi);

        if (nCuochi < 0) {
            printf("Il numero di cuochi deve essere maggiore di 0. Riprova.\n");
        }
    } while (nCuochi <= 0);

    guidaMichelin = acquisisciCuochi(nCuochi);

    stampaArrayCuochi(guidaMichelin, nCuochi);

    //stampo quanti cuochi di ogni tipo sono stati inseriti
    printf("\n\nHai inserito %d cuochi di tipo cuoco.\n", contaCuochiTipo(guidaMichelin, nCuochi, CUOCO));
    printf("Hai inserito %d cuochi di tipo pizzaiolo.\n", contaCuochiTipo(guidaMichelin, nCuochi, PIZZAIOLO));
    printf("Hai inserito %d cuochi di tipo pasticcere.\n", contaCuochiTipo(guidaMichelin, nCuochi, PASTICCERE));

    //calcolo l'eta minima e massima
    calcolaEtaMinMax(guidaMichelin, nCuochi, &giovane, &vecchio);
    printf("\n\n--------------------------------\n");
    printf("Il cuoco piu' giovane e':");
    stampaCuoco(giovane);
    printf("\n--------------------------------\n");
    printf("Il cuoco piu' vecchio e':");
    stampaCuoco(vecchio);

    //modifico il nome del cuoco giovane
    printf("\n\n--------------------------------");
    printf("\nCuochi con tre stelle Michelin:");
    modificaNome(&giovane);
    stampaCuoco(giovane);
    //modifico il nome del cuoco vecchio
    modificaNome(&vecchio);
    stampaCuoco(vecchio);

    return 0;
}

// definizione subroutine
/**
 * Verifica che un puntatore a cui e' stata allocata della memoria non sia null.
 * Se lo e', il programma termina con codice "-1" e un messaggio di errore.
 * @param pointer Il puntatore da verificare.
 */
void checkNotNullPointer(void *pointer) {
    if(pointer == NULL) {
        printf("\nErrore: impossibile allocare sufficente memoria.");
        exit(-1);
    }
}

/**
 * Acquisisce i dati di un cuoco. Vengono effettuati i seguenti controlli:
 * 1) Il nome deve avere un numero di caratteri > 0
 * 2) Il cognome deve avere un numero di caratteri > 0
 * 3) L'eta' deve essere > 0
 * 4) Il tipo di cuoco deve essere uno tra CUOCO, PIZZAIOLO e PASTICCERE
 * 5) Il numero di stelle michelin deve essere compreso tra STELLE_MIN e STELLE_MAX.
 * Restituisce una struttura "Cuoco" con i dati del cuoco inserito.
 * @return Il cuoco di cui sono stati inseriti di dati.
 */
Cuoco acquisisciCuoco() {
    bool repeat; // condizione di ripetizione del corrente ciclo do-while
    Cuoco cuoco; // il cuoco da acquisire

    // acquisizione nome
    printf("\nInserisci il nome del cuoco (max %d caratteri): ", NAME_LEN);
    do {
        scanf(" %20[^\n]s", cuoco.nome);
        repeat = strlen(cuoco.nome) == 0; // verifica che la stringa inserita non sia vuota
        if(repeat)
            printf("\nErrore, inserisci un nome: ");
    } while(repeat);

    // acquisizione cognome
    printf("\nInserisci il cognome del cuoco (max %d caratteri): ", SURNAME_LEN);
    do {
        scanf(" %40[^\n]s", cuoco.cognome);
        repeat = strlen(cuoco.cognome) == 0; // verifica che la stringa inserita non sia vuota
        if(repeat)
            printf("\nErrore, inserisci un cognome: ");
    } while(repeat);

    // acquisizione eta'
    printf("\nInserisci l'eta' del cuoco: ");
    do {
        scanf("%d", &cuoco.eta);
        repeat = cuoco.eta <= 0;
        if(repeat)
            printf("\nErrore, inserisci un'eta' valida: ");
    } while(repeat);

    // acquisizione tipo cuoco
    printf("\nInserisci il tipo di cuoco: \n"
           "%d) Cuoco\n"
           "%d) Pizzaiolo\n"
           "%d) Pasticcere\n", CUOCO, PIZZAIOLO, PASTICCERE);
    do {
        scanf("%d", &cuoco.tipoCuoco);
        repeat = cuoco.tipoCuoco < CUOCO || cuoco.tipoCuoco > PASTICCERE;
        if(repeat)
            printf("\nErrore, inserisci un tipo valido: ");
    } while(repeat);

    // acquisizione numero stelle
    printf("\nInserisci un numero di stelle (tra %d e %d): \n", STELLE_MIN, STELLE_MAX);
    do {
        scanf("%d", &cuoco.numeroStelle);
        repeat = cuoco.numeroStelle < STELLE_MIN || cuoco.numeroStelle > STELLE_MAX;
        if(repeat)
            printf("\nErrore inserisci un numero valido: ");
    } while(repeat);

    // restituisco il cuoco inserito
    return cuoco;
}

/**
 * Acquisisce un numero di cuochi pari a 'n_cuochi',
 * attraverso la subroutine acquisisciCuoco().
 * @param n_cuochi Il numero di cuochi da inserire.
 * @return Un puntatore al primo elemento dell'array con i cuochi inseriti.
 */
Cuoco * acquisisciCuochi(int n_cuochi) {
    // allocazione dinamica dell'array dei cuochi
    Cuoco *cuochi = NULL;
    cuochi = (Cuoco *) calloc(n_cuochi, sizeof(Cuoco));
    // verifico la corretta allocazione
    checkNotNullPointer(cuochi);

    // acquisizione di n cuochi
    for(int i = 0; i < n_cuochi; i++)
        *(cuochi + i) = acquisisciCuoco();

    // restituzione della lista di cuochi "guidaMichelin"
    return cuochi;
}

/**
 * Stampa l'array con tutti i dati dei cuochi della guida michelin.
 * @param cuochi I cuochi inseriti.
 * @param n_cuochi Il numero di cuochi inseriti.
 */
void stampaArrayCuochi(Cuoco cuochi[], int n_cuochi) {
    for(int i = 0; i < n_cuochi; i++) {
        stampaCuoco(cuochi[i]);
        printf("\n");
    }
}

/**
 * Restituisce il numero di cuochi di una certa categoria.
 * @param cuochi Lista dei cuochi
 * @param n_cuochi Numero di cuochi nella lista
 * @param tipoCuoco Tipo dei cuochi da contare
 * @return Il numero di cuochi di tipo tipoCuoco
 */
int contaCuochiTipo(Cuoco cuochi[], int n_cuochi, TipoCuoco tipoCuoco) {
    int contaCuochi = 0;
    for(int i = 0; i < n_cuochi; i++) {
        if(cuochi[i].tipoCuoco == tipoCuoco)
            contaCuochi++;
    }
    return contaCuochi;
}

/**
 * Data una lista di cuochi e la sua dimensione, inserisce nel puntatore
 * "giovane" il più giovane dei cuochi, e nel puntatore "vecchio" il più vecchio.
 * @param cuochi La lista dei cuochi.
 * @param n_cuochi Il numero di cuochi della lista.
 * @param giovane Puntatore alla variabile con il cuoco più giovane.
 * @param vecchio Puntatore alla variabile con il cuoco più anziano.
 */
void calcolaEtaMinMax(Cuoco cuochi[], int n_cuochi, Cuoco *giovane, Cuoco *vecchio) {
    // inizializzazione dei puntatori
    checkNotNullPointer(giovane);
    checkNotNullPointer(vecchio);
    *(vecchio) = cuochi[0];
    *(giovane) = cuochi[0];

    // calcolo del più giovane e del più vecchio
    for(int i = 0; i < n_cuochi; i++) {
        if(cuochi[i].eta >= vecchio->eta)
            *(vecchio) = cuochi[i];
        else if(cuochi[i].eta < giovane->eta)
            *(giovane) = cuochi[i];
    }
}

/**
 * Stampa le informazioni di un cuoco.
 * @param cuoco Il cuoco da stampare.
 */
void stampaCuoco(Cuoco cuoco) {
    // stampa nome e cognome
    printf("\n- %s %s:", cuoco.nome, cuoco.cognome);
    // stampa eta'
    printf("\n- - Eta': %d.", cuoco.eta);
    // stampa del tipo di cuoco
    printf("\n- - Tipo di cuoco: ");
    switch (cuoco.tipoCuoco) {
        case CUOCO:
            printf("cuoco.");
            break;
        case PIZZAIOLO:
            printf("pizzaiolo.");
            break;
        case PASTICCERE:
            printf("pasticcere.");
            break;
        default:
            printf(" non riconosciuto.");
            break;
    }
    // stampa numero stelle michelin
    printf("\n- - Numero di stelle Michelin: %d", cuoco.numeroStelle);
}

/**
 * Dato una stringa, la modifica rendendo tutti i caratteri maiuscoli
 * @param str La stringa da modificare
 */
void toUppercase(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        // verifico che il carattere sia maiuscolo
        if(str[i] >= LOWERCASE_MIN && str[i] <= LOWERCASE_MAX)
            str[i] = str[i] - LOWER_UPPER_DIST;  // rendo il carattere maiuscolo sottraendo la distanza in ASCII
    }
}

/**
 * Modifica il nome del cuoco fornito rendendolo maiuscolo se questo
 * ha ottenuto più di tre stelle Michelin.
 * @param cuoco Il cuoco di cui modificare il nome
 */
void modificaNome(Cuoco *cuoco) {
    if(cuoco->numeroStelle == STELLE_MAX) {
        // rendo nome e cognome maiuscolo
        toUppercase(cuoco->nome);
        toUppercase(cuoco->cognome);
    }
}