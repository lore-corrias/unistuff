#include <stdio.h>

/*
 * Esercizio 04/10/2022 n°2
 *
 * Testo:
 * "Scrivere un programma dichiarando due variabili, a e b, e si assegnino
 * arbitrariamente due valori. Scambiare il contenuto di a e b, e stampare i valori
 * prima e dopo lo scambio."
 */

// entry point
int main() {
    // dichiarazione e assegnazioni di di a e b
    int a = 5, b = 7;
    /*
     * dichiarazione di una variabile temporanea "temp".
     * durante lo scambio, il valore di A sarà assegnato alla variabile, così da conservarlo dopo lo scambio con B.
     * dopo lo scambio, a B sarà assegnato il valore della variabile "temp", ossia quello di A prima dello scambio.
     */
    int temp;

    // stampa di a e b prima dell'operazione
    printf("Valore di A: %d. Valore di B: %d\n", a, b);

    // inversione dei valori di a e b
    // assegnazione di A alla variabile temporanea "temp"
    temp = a;
    // scambio di A e B
    a = b;
    // assegnazione di B alla variabile temporanea "temp", che contiene il valore di A precedente allo scambio
    b = temp;

    // stampa di a e b dopo lo scambio
    printf("Valore di A: %d. Valore di B: %d", a, b);

    // exit point
    return 0;
}

/*
 * un approccio diverso che non utilizza variabili di supporto (ma considerato errato) è:
 * a = a + b;
 * b = a - b;
 * a = a - b;
 * approccio peggiore perché disordinatissimo e più lento (i calcoli sono più lenti dell'assegnazione di una variabile extra)
 */