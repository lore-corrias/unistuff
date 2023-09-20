/* Esercizio 18/12/2022 n° 3
 *
 * Testo:
 * "Scrivere una funzione che verifichi se c'è una sovrapposizione tra due intervalli
 * (min1,max1) e (min2,max2). Se sì, la funzione restituirà vero e il punto medio
 * della loro sovrapposizione si troverà in un argomento di output, altrimenti renderà falso.
 * I due intervalli sono quattro valori allocati dinamicamente e vanno acquisiti mediante input utente.
 */
#include <stdio.h>
// librerie
#include <stdbool.h>
#include <stdlib.h>


// dichiarazione subroutine
bool sovrapposizione(int, int, int, int, int*);

int main() {
    // dichiarazione variabili
    int *min1 = NULL, *min2 = NULL, *max1 = NULL, *max2 = NULL; // puntatori agli estremi degli intervalli
    int *medio = NULL; // puntatore alla variabile contenente il valore medio dell'intersezione
    bool intersezione; // valore booleano di ritorno della subroutine

    // allocazione dinamica
    min1 = (int *) malloc(sizeof(int));
    min2 = (int *) malloc(sizeof(int));
    max1 = (int *) malloc(sizeof(int));
    max2 = (int *) malloc(sizeof(int));
    medio = (int *) calloc(1, sizeof(int));
    // verifica della corretta allocazione
    if(min1 == NULL || min2 == NULL || max1 == NULL || max2 == NULL || medio == NULL) {
        printf("Impossibile allocare sufficiente memoria.");
        exit(-1);
    }

    // richiesta dei valori all'utente
    printf("Inserisci il minimo del primo intervallo: ");
    scanf("%d", min1);
    printf("\nInserisci il massimo del primo intervallo: ");
    scanf("%d", max1);
    printf("\nInserisci il minimo del secondo intervallo: ");
    scanf("%d", min2);
    printf("\nInserisci il massimo del secondo intervallo: ");
    scanf("%d", max2);

    // invocazione subroutine
    intersezione = sovrapposizione(*min1, *max1, *min2, *max2, medio);

    // stampa
    if(intersezione) {
        printf("\nIl valore medio dell'intersezione dei due intervalli e': %d.", *medio);
    } else {
        printf("\nI due intervalli non si intersecano.");
    }

    // deallocazione
    free(min1);
    free(max1);
    free(min2);
    free(max2);
    free(medio);

    return 0;
}


// definizioni subroutine
/**
 * Verifica che due intervalli di estremi (min1,max1) e (min2,max2) abbiano
 * una sovrapposizione. Se è così, la funzione restituisce true e modifica il
 * puntatore a intero "medio" con il valore medio della sovrapposizione.
 * In caso contrario, restituisce falso.
 * @param min1 Il minimo del primo intervallo.
 * @param max1 Il massimo del primo intervallo.
 * @param min2 Il minimo del secondo intervallo.
 * @param max2 Il massimo del secondo intervallo.
 * @param medio Il punto medio dell'intersezione, se esiste.
 * @return Vero se gli intervalli si intersecano, falso altrimenti.
 */
bool sovrapposizione(int min1, int max1, int min2, int max2, int *medio) {
    // determino il maggiore degli estremi sinistri e il minore dei destri degli intervalli
    int min_max = 0, max_min = 0;
    if(min1 > min2)
        max_min = min1;
    else
        max_min = min2;
    if(max1 < max2)
        min_max = max1;
    else
        min_max = max2;
    // condizione di intersezione
    if(max_min > min_max)
        return false;
    /* ottengo il valore medio sommando
     * all'estremo sinistro dell'intervallo di intersezione
     * metà della lunghezza dell'intervallo
    */
    *(medio) = min_max + (max_min - min_max) / 2;
    return true;
}
