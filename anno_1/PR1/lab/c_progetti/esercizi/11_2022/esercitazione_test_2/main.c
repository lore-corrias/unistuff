#include <stdio.h>
// librerie
// generazione randomica
#include <stdlib.h>
#include <time.h>

// macro
// dimensioni della matrice
#define R 5
#define C 7

// dichiarazione subroutine
int inputValue();
int randRange(int min, int max);
void printMatrix(int r, int c, int matrix[r][c]);
void initMatrix(int r, int c, int matrix[r][c], int min, int max);
float avgMatrix(int r, int c, int matrix[r][c]);


int main() {
    // dichiarazioni variabili
    int matrix[R][C]; // la matrice da inizializzare
    int min, max; // gli estremi del range di generazione
    float avg; // media dei valori della matrice

    // inizializzazione del seed
    srand(time(NULL));

    // richiesta degli estremi del range di generazione con inputValue()
    min = inputValue();
    max = inputValue();

    // generazione e stampa della matrice
    initMatrix(R, C, matrix, min, max);
    printf("\nMatrice %dx%d generata: \n", R, C);
    printMatrix(R, C, matrix);

    // calcolo e stampa della media
    avg = avgMatrix(R, C, matrix);
    printf("La media dei valori della matrice e': %.2f", avg);

    return 0;
}

// definizioni subroutine
/**
 * Chiede all'utente di inserire un numero positivo e lo restituisce.
 * Se viene inserito un numero negativo, la richiesta è fatta di nuovo.
 * @return Il numero positivo inserito.
 */
int inputValue() {
    int n = -1;
    // richiesta all'utente finché il numero inserito non è positivo
    do {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
    } while (n < 0);
    return n;
}

/**
 * Restituisce un numero randomico generato tra min e max.
 * Se il minimo e il massimo sono invertiti, li scambia di nuovo.
 * @param min Il minimo dell'intervallo di generazione.
 * @param max Il massimo dell'intervallo di generazione.
 * @return Il numero generato, 0 se il minimo e il massimo coincidono.
 */
int randRange(int min, int max) {
    if (min == max)
        return 0;
    else if(min > max)
        return randRange(max, min); // esecuzione con gli estremi scambiati
    return min + rand() % (max - min + 1); // formula per la generazione randomica
}

/**
 * Stampa una matrice rxc.
 * @param r Il numero di righe della matrice.
 * @param c Il numero di colonne della matrice.
 * @param matrix La matrice da stampare.
 */
void printMatrix(int r, int c, int matrix[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Inizializza una matrice rxc con valori randomici tra min e max generati con la funzione randRange().
 * @param r Il numero di righe della matrice.
 * @param c Il numero di colonne della matrice.
 * @param matrix La matrice da inizializzare.
 * @param min Il minimo dell'intervallo di generazione, si veda randRange().
 * @param max Il massimo dell'intervallo di generazione, si veda randRange().
 */
void initMatrix(int r, int c, int matrix[r][c], int min, int max) {
    // scorrimento della matrice
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = randRange(min, max); // assegnazione di un valore randomico
        }
    }
}

/**
 * Calcola la media dei valori di una matrice rxc di interi.
 * @param r Il numero di righe della matrice.
 * @param c Il numero di colonne della una matrice.
 * @param matrix La matrice contenente i valori.
 * @return La media aritmetica.
 */
float avgMatrix(int r, int c, int matrix[r][c]) {
    // inizializzazione di una variabile contenente la somma dei valori e la media
    float sum = 0.0;
    float avg = 0.0;
    // scorrimento della matrice
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum += matrix[i][j]; // aggiunta alla somma del valore attuale
        }
    }
    // calcolo della media
    avg = sum / (r * c);
    // return del risultato
    return avg;
}