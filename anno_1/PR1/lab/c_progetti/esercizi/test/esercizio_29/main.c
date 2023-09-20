#include <stdio.h>

/* Esercizio 18/10/2022 n° 2
 *
 * Testo:
 * "Scrivere un programma che, utilizzando lo switch-case, legga in input un voto rappresentato da un numero
 * tra 2 e 10 e ne stampi il significato in questo modo:
 * •10 →'Ottimo'
 * •9   →'Distinto'
 * •8 →'Buono'
 * •7 →'Discreto'
 * •6 →'Sufficiente'
 * •5 →'Lievemente insufficiente'
 * •4 →'Gravemente insufficiente'
 * •3 →'Gravemente insufficiente'
 * •2 →'Gravemente insufficiente'"
*/

// entry point
int main() {
    // dichiarazione variabile
    int voto;

    // lettura variabile da terminale
    printf("Inserisci il numero tra 2 e 10 da valutare: ");
    scanf("%d", &voto);

    // controllo del voto
    switch(voto) {
        case 10:
            printf("Ottimo");
            break;
        case 9:
            printf("Distinto");
            break;
        case 8:
            printf("Buono");
            break;
        case 7:
            printf("Discreto");
            break;
        case 6:
            printf("Sufficiente");
            break;
        case 5:
            printf("Lievemente insufficiente");
        case 4:
        case 3:
        case 2:
            printf("Gravemente insufficiente");
            break;
        default:
            printf("Inserisci un numero tra 2 e 10.");
            break;
    }

    // exit point
    return 0;
}
