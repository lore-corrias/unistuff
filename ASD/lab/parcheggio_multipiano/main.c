#include "parcheggio_multipiano.h"


int main()
{
    srand(time(NULL));

    Nodo* parcheggio[NUM_PIANI]={};

    for(int i = 0; i < NUM_PIANI; i++)
        parcheggio[i] = NULL;

    //inserire qui le funzioni per i test

    int scelta;
    char targa_temp[MAX_TARGA]={};

    printf("\nBenvenuto nel parcheggio multipiano!\n");
    do
    {
        printf("\nScegli un azione.");
        printf("\n1) Aggiungi un auto."
               "\n2) Aggiungi le auto di prova."
               "\n3) Stampa un piano a scelta."
               "\n4) Stampa il parcheggio intero."
               "\n5) Cerca un auto a partire dalla targa."
               "\n6) Cancella un auto a partire dalla targa."
               "\n0) Esci dal programma"
               "\n?) ");

        scanf(" %d", &scelta);
        getchar();

        switch (scelta)
        {
            case 1:
                inserisci_auto(parcheggio,acquisisci_auto());
                break;
            case 2:
                carica_auto_test(parcheggio);
                break;
            case 3:
                stampa_piano(parcheggio, chiedi_piano());
                break;
            case 4:
                stampa_parcheggio(parcheggio);
                break;
            case 5:
                ricerca_auto(parcheggio, chiedi_targa(targa_temp));
                break;
            case 6:
                elimina_auto(parcheggio, chiedi_targa(targa_temp));
                break;
            default:
                break;
        }
    }
    while(scelta != 0);


    return 0;
}