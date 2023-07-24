#include "matrice_sparsa.h"


int numUsedIntegerClassic;  //variabile da usare per contare il numero di interi nella matrice tradizionale
int numUsedIntegerSparse;   //variabile da usare per contare il numero di interi nella matrice sparsa

/* Da cambiare, non passarla come parametro */
Tripla* creaMatriceSparsa() {
    Tripla tripla;
    Tripla* matriceSparsa = NULL;
    int i;

    numUsedIntegerSparse = 0;
    printf("Inserisci la prima tripla:\n\n");
    printf("Numero di righe: ");
    scanf("%d", &tripla.riga);
    printf("Numero di colonne: ");
    scanf("%d", &tripla.colonna);
    numUsedIntegerClassic = tripla.riga * tripla.colonna;
    numUsedIntegerSparse+=3;

    do{
        printf("Numero di elementi non nulli: ");
        scanf("%d", &tripla.valore);
    }while (tripla.valore > (tripla.riga * tripla.colonna));

    matriceSparsa = (Tripla*)malloc((tripla.valore + 1) * sizeof(Tripla));

    matriceSparsa[0] = tripla;

    printf("Inserisci i valori:\n\n");
    for(i = 1; i <= tripla.valore; i++){
        do {
            printf("Riga (max %d): ", tripla.riga - 1);
            scanf("%d", &matriceSparsa[i].riga);
        }while(matriceSparsa[i].riga < 0 || matriceSparsa[i].riga > tripla.riga - 1);

        do {
            printf("Colonna (max %d): ", tripla.colonna - 1);
            scanf("%d", &matriceSparsa[i].colonna);
        }while(matriceSparsa[i].colonna < 0 || matriceSparsa[i].colonna > tripla.colonna - 1);

        printf("Valore: ");
        scanf("%d", &matriceSparsa[i].valore);

        numUsedIntegerSparse+=3;
    }

    printf("Numero di locazioni intere usate nella rappresentazione classica delle matrici: %d\n", numUsedIntegerClassic);
    printf("Numero di locazioni intere usate nella rappresentazione delle matrici sparse: %d\n\n", numUsedIntegerSparse);

    return matriceSparsa;
}

void stampaMatriceSparsa(Tripla* matriceSparsa){
    int i, j, k = 1;

    for(i = 0; i < matriceSparsa[0].riga; i++){
        for(j = 0; j < matriceSparsa[0].colonna; j++){
            if(i == matriceSparsa[k].riga && j == matriceSparsa[k].colonna) {
                printf("%-2d ", matriceSparsa[k].valore);
                k++;
            }
            else {
                printf("%-2d ", 0);
            }
        }
        printf("\n");
    }

    printf("\n\n");
}

void cercaElementoMatriceSparsa(Tripla *matriceSparsa) {
    int primo, ultimo, mezzo;
    int posizione, numRic;
    _Bool keepSearching = true;

    printf("Che numero vuoi cercare? (Diverso da 0): ");
    scanf("%d", &numRic);

    posizione = -1;

    primo = 1;
    ultimo = matriceSparsa[0].valore;
    while (primo <= ultimo && keepSearching){
        mezzo = (primo + ultimo)/2;
        if(numRic < matriceSparsa[mezzo].valore)
            ultimo = mezzo - 1;
        else if(numRic == matriceSparsa[mezzo].valore) {
            keepSearching = false;
            posizione = mezzo;
        }
        else
            primo = mezzo + 1;
    }

    if(posizione == -1)
        printf("L'elemento non e\' presente nella matrice\n");
    else
        printf("L'elemento cercato e\' in posizione: [%d] [%d]\n", matriceSparsa[posizione].riga, matriceSparsa[posizione].colonna);
}

void trasposizioneRapida(Tripla* a, Tripla* b){
    int numCol = a[0].colonna;
    int numVal = a[0].valore;
    int *terminiRiga = NULL, *posIniziale = NULL;
    int posCorr;
    int i;

    b[0].riga = numCol;
    b[0].colonna = a[0].riga;
    b[0].valore = numVal;

    terminiRiga = (int*)malloc(numCol * sizeof(int));
    posIniziale = (int*)malloc(numCol * sizeof(int));

    if(numVal > 0) {
        /* Creazione terminiRiga */
        for (i = 0; i < numCol; i++)
            terminiRiga[i] = 0;
        for (i = 1; i <= numVal; i++)
            terminiRiga[a[i].colonna]++;
        //terminiRiga[a[i].colonna] = terminiRiga[a[i].colonna] + 1;

        /* Creazione posIniziale */
        posIniziale[0] = 1;
        for (i = 1; i < numCol; i++)
            posIniziale[i] = posIniziale[i - 1] + terminiRiga[i - 1];

        /* Trasposizione */
        for (i = 1; i <= numVal; i++) {
            posCorr = posIniziale[a[i].colonna];
            posIniziale[a[i].colonna]++;
            //posIniziale[a[i].colonna] = posIniziale[a[i].colonna] + 1;
            b[posCorr].riga = a[i].colonna;
            b[posCorr].colonna = a[i].riga;
            b[posCorr].valore = a[i].valore;
        }
    }
}

/**
 * Procedura che inizializza la prima posizone della matrice sparsa a 0
 * @param matriceSparsa
 */
void inizializzaMatriceSparsa(Tripla *matriceSparsa){
    matriceSparsa[0].riga = matriceSparsa[0].colonna = matriceSparsa[0].valore = 0;
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
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric) {
    int i, j = 0;
    for (i = 0; i < numr; i++) {
        for (j = 0; j < numc; j++) {
            if (matrix[i][j] == numric) {
                printf("Elemento %d trovato in posizione (%d, %d).\n", numric, i, j);
                return;
            }
        }
    }
    printf("Elemento non trovato.\n");
}