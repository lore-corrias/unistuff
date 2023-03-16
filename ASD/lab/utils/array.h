//
// Created by just on 16/03/23.
//
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include <stdbool.h>


typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} arrayType;
int* generaArray(int dimensione, arrayType tipoArray);
void scambia(int* array, int elemento1, int elemento2);