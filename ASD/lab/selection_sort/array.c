#include "array.h"



int casuale_tra(int min, int max) {
    return min + rand() % (max - min + 1);
}

/**
 * Genera un array di dimensione data in quattro modalità diverse:
 * 1) Ordinato: gli elementi sono ordinati in maniera crescente, da 1 a dimensione
 * 2) Inversamente ordinato: stessa cosa del precedente, ma in ordine decrescente
 * 3) Quasi ordinato: prima metà ordinata, seconda metà casuale
 * 4) Random: ogni elemento è generato in maniera completamente randomica
 *
 * @param dimensione
 * @param tipoArray
 * @return
 */
int* generaArray(int dimensione, arrayType tipoArray) {

    int* array = calloc(dimensione, sizeof(int));


    switch(tipoArray)
    {
        case ORDINATO:
            for(int i=0;i<dimensione; i++)
            {
                array[i]=i;
            }
            break;

        case QUASI_ORDINATO:
            for(int i=0;i<dimensione; i++)
            {
                if(i<dimensione/2)
                {
                    array[i]=i;
                }
                else
                {
                    array[i]= casuale_tra(MIN,MAX );
                }
            }
            break;

        case INV_ORDINATO:
            for(int i=0;i<dimensione; i++)
            {
                array[i]=dimensione-i-1;
            }
            break;

        case CASUALE:
            for(int i=0;i<dimensione; i++)
            {
                array[i]= casuale_tra(MIN, MAX);
            }
            break;

        default:
            exit(-1);
    }

    return array;
}


/**
 * Funzione per scambiare due interi in una lista.
 *
 * @param array La lista di interi.
 * @param elemento1 L'indice del primo intero da scambiare.
 * @param elemento2 L'indice del secondo intero da scambiare.
 */
void scambiaInteri(int* array, int elemento1, int elemento2) {
    int tmp = array[elemento1];
    array[elemento1] = array[elemento2];
    array[elemento2] = tmp;
}