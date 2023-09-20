#include <stdio.h>

/* Esercizio 07/10/2022
 *
 * Testo:
 * "Scrivere un programma che visualizzi i numeri da 1 a 4 sulla stessa riga. Scrivere il programma utilizzando i seguenti metodi:
 * •Usando un'istruzione printf senza segnaposto.
 * •Usando un'istruzione printf con 4 segnaposto.
 * •Usando 4 istruzioni printf."
 */

// entry point
int main() {
    // printf senza segnaposto
    printf("1234\n");

    // printf con 4 segnaposto
    printf("%d%d%d%d\n", 1, 2, 3, 4);

    // 4 printf
    printf("1");
    printf("2");
    printf("3");
    printf("4");

    // exit point
    return 0;
}