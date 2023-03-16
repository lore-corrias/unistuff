/* Esercizio 05/12/2022 n° 1
 *
 * Testo:
 * "Scrivere un programma in cui viene definita una struttura NumeroComplesso, atta a contenere due variabili reali:
 * •parte reale;
 * •parte immaginaria.
 * •Il programma deve dichiarare una variabile di tipo NumeroComplesso, acquisire in input
 * dall'utente le due parti del numero, effettuare il calcolo del modulo del numero e
 * stampare le due parti del numero e il modulo calcolato.
 *
 * NB: dato un numero complesso z, la sua parte reale x e immaginaria y, il modulo si calcola come: 𝑧=𝑥2+𝑦2"
 */
#include <stdio.h>
// librerie
#include <math.h>


// definizioni tipi
// struct che rappresenta un numero complesso, con la sua parte reale e immaginaria
typedef struct {
    int parteReale;
    int parteImmaginaria;
} numeroComplesso;


// dichiarazioni subroutine
float modulo(numeroComplesso n);


// entry point
int main() {
    // dichiarazione variabili
    numeroComplesso n = {3, 5};
    float modulo_n;

    // invocazione modulo()
    modulo_n = modulo(n);

    // stampa
    printf("Parte reale: %d", n.parteReale);
    printf("\nParte immaginaria: %d", n.parteImmaginaria);
    printf("\nModulo: %.2f", modulo_n);

    // exit point
    return 0;
}


// definizioni subroutine
/**
 * Calcola il modulo di un numero complesso, definito come
 * sqrt(parte_reale^2 + parte_immaginaria^2)
 * @param n Il numero complesso di cui calcolare il modulo
 * @return Il modulo
 */
float modulo(numeroComplesso n) {
    return sqrt(pow(n.parteReale, 2) + pow(n.parteImmaginaria, 2));
}