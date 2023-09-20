#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "string.h"
#include "stdbool.h"

#define MIN 0
#define MAX 100

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} arrayType;


int* generaArray(int dimensione, arrayType tipoArray);
void scambiaInteri(int* array, int elemento1, int elemento2);
int casuale_tra(int min, int max);