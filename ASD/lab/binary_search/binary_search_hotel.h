#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "../utils/array.h"

#define DIM_NOME 50 // lunghezza del nome dell'hotel ('\0' escluso)


/**
 * Struttura contenente le informazioni di un hotel
 */
typedef struct {
    char nome[DIM_NOME + 1]; // nome dell'hotel
    double prezzo_notte; // prezzo a notte di una camera
    int recensione; // valutazione dell'hotel, da 1 a 5
} Hotel;


Hotel* creaHotel(int nHotel);
void selectionSortHotels(Hotel hotels[], int dimension);
int binarySearchHotels(Hotel hotels[], char* hotelRic, int dimension);
void searchHotels();