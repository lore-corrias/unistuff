//
// Created by just on 23/03/23.
//

#include <stdio.h>
#include <stdlib.h>

#define NUMC 15
#define NUMR 10

int numUsedIntegerClassic;  //variabile da usare per contare il numero di interi nella matrice tradizionale
int numUsedIntegerSparse;   //variabile da usare per contare il numero di interi nella matrice sparsa

typedef struct {
    int riga;
    int colonna;
    int valore;
} triplaMatrice;

triplaMatrice* inserisciTripleMatrice();
void fill_classic_matrix(int matrix[][NUMC], int numr, int numc);
void print_classic_matrix(int matrix[][NUMC], int numr, int numc);
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric);


int matrice_sparsa()
{
    int matrix[NUMR][NUMC] = {{0}};
    int numric = 71;     // assegnare a numric il numero da cercare.

    // INIZIO TEST MATRICE CLASSICA
    fill_classic_matrix(matrix, NUMR, NUMC);
    printf("\n");
    print_classic_matrix(matrix, NUMR, NUMC);
    search_element_in_classic_matrix(matrix, NUMR, NUMC, numric);
    // FINE TEST MATRICE CLASSICA

    /*
    INIZIO TEST MATRICE SPARSA
    Implementare:
        - creazione matrice sparsa, chiedendo le triple in input (per testare il corretto funzionamento: inserite gli stessi valori della matrice classica, vedi slide)
        - stampa matrice sparsa
        - ricerca di un elemento all'interno della matrice sparsa
        - trasposizione rapida della matrice sparsa.
    */

    triplaMatrice* matrice = inserisciTripleMatrice();

    /*
    FINE TEST MATRICE SPARSA
    */

    return 0;
}

triplaMatrice* inserisciTripleMatrice() {
    int nTriple;
    triplaMatrice* matrice = NULL;

    do {
        printf("\nInserisci il numero di elementi da inserire: ");
        scanf("%d", &nTriple);
    } while(nTriple <= 0);

    matrice = calloc(nTriple, sizeof(triplaMatrice));
    if(matrice == NULL) {
        printf("\nImpossibile allocare dinamicamente.");
        exit(-1);
    }

    for(int i = 0; i < nTriple; i++) {
        // inserimento numero riga
        do {
            printf("\nInserisci il numero della riga dell'elemento: ");
            scanf("%d", &matrice[i].riga);
        } while(matrice[i].riga <= 0);

        // inserimento numero colonna
        do {
            printf("\nInserisci il numero della colonna dell'elemento: ");
            scanf("%d", &matrice[i].colonna);
        } while(matrice[i].colonna <= 0);

        // inserimento valore
        do {
            printf("\nInserisci il valore dell'elemento: ");
            scanf("%d", &matrice[i].valore);
        } while(matrice[i].valore <= 0);
    }

    return matrice;
}

void stampaMatriceSparsa(triplaMatrice* matrice, int righeMatrice, int colonneMatrice, int nTriple) {
    int riga = 0;
    for(int i = 0; i < nTriple && riga < righeMatrice; i++) {
        if(riga != matrice[i].riga) {
            for(int j = 0; j < colonneMatrice; j++)
                printf("0 ");
            printf("\n");
            riga++;
        } else {
            for(int j = 0; j < colonneMatrice; j++) {
                if(j == matrice[i].colonna)
                    printf("%d ", matrice[i].valore);
                else
                    printf("0 ");
                printf("\n");
            }
        }
    }
}

void cercaElementoMatriceSparsa(triplaMatrice* matrice, int nElementi, int elemento) {
    for(int i = 0; i < nElementi; i++) {
        if (matrice[i].valore == elemento) {
            printf("\nElemento trovato in riga %d, colonna %d.\n", matrice[i].riga, matrice[i].colonna);
            return;
        }
    }
    printf("\nElemento non presente.");
}

// Funzione che riempie (con i valori dell'esempio presenti nelle slide della lezione 3) la matrice classica passata in ingresso
void fill_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    matrix[1][0] = 71;
    matrix[2][14] = 99;
    matrix[3][11] = 53;
    matrix[4][7] = 95;
    matrix[6][14] = 39;
    matrix[8][1] = 27;
    matrix[9][14] = 14;
}

// Funzione che stampa a video una matrice classica
void print_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    int i, j = 0;
    for(i=0; i<numr; i++)
    {
        for(j=0; j<numc; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

}

// Funzione che implementa la ricerca di un elemento (numric) in una matrice classica
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric)
{
    int i, j = 0;
    for(i=0; i<numr; i++)
    {
        for(j=0; j<numc; j++)
        {
            if(matrix[i][j] == numric)
            {
                printf("Elemento %d trovato in posizione (%d, %d).\n", numric, i, j);
                return;
            }
        }
    }
    printf("Elemento non trovato.\n");
}