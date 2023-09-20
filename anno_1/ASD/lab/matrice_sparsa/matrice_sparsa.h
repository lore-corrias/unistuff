#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMC 15
#define NUMR 10


typedef struct{
    int riga;
    int colonna;
    int valore;
}Tripla;


void fill_classic_matrix(int matrix[][NUMC], int numr, int numc);
void print_classic_matrix(int matrix[][NUMC], int numr, int numc);
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric);



Tripla *creaMatriceSparsa();
void stampaMatriceSparsa(Tripla* matriceSparsa);
void cercaElementoMatriceSparsa(Tripla *matriceSparsa);
void trasposizioneRapida(Tripla* a, Tripla* b);
void inizializzaMatriceSparsa(Tripla *matriceSparsa);
