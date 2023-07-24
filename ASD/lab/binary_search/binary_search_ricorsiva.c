#include "binary_search.h"


/**
 * Versione ricorsiva dell'algoritmo di ricerca binaria.
 *
 * @param array L'array in cui ricercare "numric".
 * @param numric L'elemento da ricercare.
 * @param primo Il primo estremo da cui far partire la ricerca.
 * @param ultimo Il secondo estremo in cui terminare la ricerca.
 * @return L'indice dell'elemento trovato, -1 altrimenti.
 */
int binarySearchRicorsiva(int array[], int numric, int primo, int ultimo) {
    // le metà sono state analizzate e non è stato trovato l'elemento
    if(primo > ultimo)
        return -1;

    // come per la ricerca iterativa
    int mezzo = (primo + ultimo) / 2;

    if(array[mezzo] == numric) {
        return mezzo; // elemento trovato
    } else if(array[mezzo] < numric) {
        // l'elemento si trova nella seconda metà: chiamo l'algoritmo per analizzare quella
        return binarySearchRicorsiva(array, numric, mezzo+1, ultimo);
    } else {
        // l'elemento si trova nella prima metà
        return binarySearchRicorsiva(array, numric, primo, mezzo-1);
    }
}