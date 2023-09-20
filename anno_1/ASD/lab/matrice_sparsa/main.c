#include "matrice_sparsa.h"


int main()
{
    int matrix[NUMR][NUMC] = {{0}};
    int numric = 71;     // assegnare a numric il numero da cercare.
    Tripla* matriceSparsa = NULL, *matriceTrasposta = NULL;
    int scelta;


    printf("Matrice classica:\n\n");
    // INIZIO TEST MATRICE CLASSICA
    fill_classic_matrix(matrix, NUMR, NUMC);
    printf("\n");
    print_classic_matrix(matrix, NUMR, NUMC);
    search_element_in_classic_matrix(matrix, NUMR, NUMC, numric);
    // FINE TEST MATRICE CLASSICA


    printf("\n\nTest matrice sparsa:\n\n");
    matriceSparsa = creaMatriceSparsa();

    do {
        printf("Cosa vuoi fare?\n"
               "1) Stampa la matrice creata\n"
               "2) Cerca un elemento nella matrice creata\n"
               "3) Fai la trasposta della matrice\n"
               "0) Esci\n");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:
                printf("Arrivederci!\n");
                return 0;
            case 1:
                printf("\n\n");
                stampaMatriceSparsa(matriceSparsa);
                printf("\n\n");
                break;
            case 2:
                printf("\n\n");
                cercaElementoMatriceSparsa(matriceSparsa);
                printf("\n\n");
                break;
            case 3:
                matriceTrasposta = (Tripla *) malloc((matriceSparsa[0].valore + 1) * sizeof(Tripla));
                inizializzaMatriceSparsa(matriceTrasposta);

                trasposizioneRapida(matriceSparsa, matriceTrasposta);

                stampaMatriceSparsa(matriceTrasposta);
                break;
        }
    }while(scelta != 0);



    return 0;
}
