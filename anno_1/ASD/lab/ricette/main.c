#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM_NOME 30
#define SEPARATORE "------------------------------------------------------------------------------\n"

typedef struct{
    char nome[DIM_NOME+1];
    double tempo;
    int difficolta;
} Ricetta;

int compareRicette(Ricetta r1,Ricetta r2);
void stampaArrayRicette(Ricetta array[],int nRicette);
void swapRicette(Ricetta* r1, Ricetta* r2);
void selectionSort(Ricetta array[],int dimensione);
void freeBuffer();


int main() {
    srand(time(NULL)); //Generazione Seme per la Generazione PseudoCasuale

    char c;
    int nRicette;
    printf("Quante ricette vuoi inserire? ");
    do{
        scanf("%d",&nRicette);
        if(nRicette<=0){
            printf("Inserisci un valore valido.\n");
        }
    }while(nRicette<=0);

    Ricetta* arrayRicette= calloc(nRicette,sizeof(Ricetta));

    printf("\n");
    for(int i=0;i<nRicette;i++){
        freeBuffer();
        printf("\nNome della ricetta: ");
        gets(arrayRicette[i].nome);
        printf("\nTempo necessario: ");
        scanf("%lf",&arrayRicette[i].tempo);
        printf("\nDifficoltà: ");
        scanf("%d",&arrayRicette[i].difficolta);
        printf("\n");
    }

    printf(SEPARATORE);
    printf("RICETTE INSERITE\n");
    printf(SEPARATORE);
    stampaArrayRicette(arrayRicette,nRicette);
    selectionSort(arrayRicette,nRicette);
    printf(SEPARATORE);
    printf("RICETTE ORDINATE\n");
    printf(SEPARATORE);
    stampaArrayRicette(arrayRicette,nRicette);

    freeBuffer();
    printf("\nPremi invio per uscire.");
    scanf("%c",&c);

    return 0;
}

void stampaArrayRicette(Ricetta array[],int nRicette){
    for(int i=0;i<nRicette;i++){
        printf("Ricetta %d:\n",i+1);
        printf("\tNome Ricetta: %s\n",array[i].nome);
        printf("\tTempo Impiegato: %.2lf Minuti\n",array[i].tempo);
        printf("\tDifficolta': %d Stelle\n\n",array[i].difficolta);
    }

}

void selectionSort(Ricetta array[],int dimensione){
    int min;
    for(int i=0;i<dimensione-1;i++){
        min = i;
        for(int j=i+1;j<dimensione;j++){
            if(compareRicette(array[j],array[min])==0){
                min = j;
            }
        }
        swapRicette(&array[min],&array[i]);
    }
}

void swapRicette(Ricetta* r1, Ricetta* r2){
    Ricetta temp= *r1;
    *r1 = *r2;
    *r2 = temp;
}

int compareRicette(Ricetta r1,Ricetta r2){
    int valueCompare;
    if(r1.tempo<r2.tempo){
        valueCompare=0;
    }else if(r1.tempo==r2.tempo && r1.difficolta<r2.difficolta){
        valueCompare=0;
    }else{ //In tutti gli altri casi..
        valueCompare=1;
    }
    return valueCompare;
}

void freeBuffer(){
    while(getchar()!='\n');
}