#include "parcheggio_multipiano.h"


void carica_auto_test(Nodo* parcheggio[])
{
    Auto a0 = {"PI555TA", 12, 15};
    Auto a1 = {"CA220TO", 7, 59};
    Auto a2 = {"EG000AL", 19, 45};
    Auto a3 = {"GO000LE", 15, 20};
    Auto a4 = {"BA220TO", 10, 35};
    Auto a5 = {"AP111LE", 15, 20};
    Auto a6 = {"MI123FT", 18, 40};
    Auto a7 = {"NO985LE", 20, 30};
    Auto a8 = {"GI124CH", 11, 20};
    Auto a9 = {"LO199RE", 8, 30};
    Auto a10 = {"ZA156KF", 7, 10};

    inserisci_auto(parcheggio, a0);
    inserisci_auto(parcheggio, a1);
    inserisci_auto(parcheggio, a2);
    inserisci_auto(parcheggio, a3);
    inserisci_auto(parcheggio, a4);
    inserisci_auto(parcheggio, a5);
    inserisci_auto(parcheggio, a6);
    inserisci_auto(parcheggio, a7);
    inserisci_auto(parcheggio, a8);
    inserisci_auto(parcheggio, a9);
    inserisci_auto(parcheggio, a10);
}

int chiedi_piano()
{
    int piano=0;

    do
    {
        printf("\nInserisci il numero del piano: ");
        scanf("%d", &piano);
        getchar();
    }
    while(piano<0 || piano > NUM_PIANI);

    return piano;
}

char * chiedi_targa(char * targa)
{
    printf("\nInserisci il numero di targa: ");
    scanf("%9s", targa);
    getchar();

    return targa;
}

Auto genera_ora_e_min(Auto a)
{
    a.ora = rand()%MAX_ORA;
    a.min = rand()%MAX_MINUTI;

    return a;
}

int hash_function(char targa[])
{
    //la funzione è costante perchè le targhe hanno un numero prefissato di caratteri, definito da una macro
    int somma=0;
    for(int i=0; i<strlen(targa) && i<MAX_TARGA; i++)
    {
        somma+=targa[i];
    }

    return somma%NUM_PIANI;
}

Auto acquisisci_auto()
{
    Auto a;

    strcpy(a.targa , chiedi_targa(a.targa));

    ///genero casualmente l'ora e il minuto
    a = genera_ora_e_min(a);

    return a;
}

void inserisci_auto(Nodo* parcheggio[], Auto a)
{
    int valore_hash = hash_function(a.targa);

    Nodo* nodo = (Nodo*) calloc(1 , sizeof(Nodo));
    Nodo *appoggio;

    nodo->info = a;
    nodo->link = NULL;


    if(parcheggio[valore_hash] == NULL) //caso in cui è la prima auto della lista del piano
    {
        parcheggio[valore_hash] = nodo;
    }
    else
    {
        //scorro finche non raggiungo l'ultima posizione
        for(appoggio = parcheggio[valore_hash]; appoggio->link != NULL; )
            appoggio = appoggio->link;

        //aggiungo il nodo alla lista
        appoggio->link = nodo;
    }

}

void stampa_parcheggio(Nodo* parcheggio[])
{
    for(int i = 0; i < NUM_PIANI; i++)
    {
        stampa_piano(parcheggio, i);
        printf("\n");
    }
}

void stampa_piano(Nodo* parcheggio[], int piano)
{
    if(parcheggio[piano] == NULL)
    {
        printf("\n---------------------------------------");
        printf("\nIl piano %d è vuoto!", piano);
        printf("\n---------------------------------------\n");
    }
    else
    {
        Nodo *ii;

        printf("\n---------------------------------------\n");
        printf("\nPIANO %d: ", piano);
        printf("\n---------------------------------------");

        for(ii = parcheggio[piano]; ii != NULL; ii = ii->link)
        {
            printf("\nNumero di targa: %s", ii->info.targa);
            printf("\nOrario di arrivo: %d:%d\n", ii->info.ora, ii->info.min);
        }
    }
}
Nodo* ricerca_auto(Nodo* parcheggio[], char targa[])
{
    Nodo *a = NULL;

    if(strlen(targa) > 0)
    {
        for(a = parcheggio[hash_function(targa)]; a != NULL; a = a->link)
        {
            if(strcmp(a->info.targa, targa) == 0)
            {
                printf("\nL'auto si trova al piano %d.", hash_function(targa));
                return a;
            }
        }
    }
    printf("\nL'auto non esiste.\n");

    return a;
}
void elimina_auto(Nodo* parcheggio[], char targa[])
{
    Nodo * appoggio=parcheggio[hash_function(targa)];

    if(appoggio!=NULL && strcmp(appoggio->info.targa, targa)==0) //rimozione in testa
    {
        parcheggio[hash_function(targa)]=parcheggio[hash_function(targa)]->link;
        free(appoggio);
        printf("\nMacchina rimossa.");
        return;
    }

    //se c'era solo un elemento ed è stato rimosso nel for manco entra per la condizione tmp!= NULL
    for(Nodo * tmp = parcheggio[hash_function(targa)];  tmp!=NULL;  tmp = tmp->link )
    {
        if(tmp->link != NULL  && strcmp(tmp->link->info.targa, targa) == 0)
        {
            appoggio=tmp->link;
            tmp->link=tmp->link->link;
            free(appoggio);

            printf("\nMacchina rimossa");
            return;
        }
    }


    printf("\nLa macchina fornita non esiste");
}