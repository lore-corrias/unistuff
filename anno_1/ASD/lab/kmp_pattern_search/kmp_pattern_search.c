#include "kmp_pattern_search.h"

void search_pattern() {
    char stringa[STR_LEN_MAX + 1] = "";
    char pattern[PATTERN_LEN_MAX + 1] = "";
    char ciclico;

    int patternPosition;

    printf("\nInserisci la stringa in cui ricercare il pattern (max %d caratteri): ", STR_LEN_MAX);
    scanf("%[^\n]15s", stringa);
    printf("\nInserisci il pattern da ricercare nella stringa (max %d caratteri): ", PATTERN_LEN_MAX);
    scanf(" %[^\n]15s", pattern);
    printf("\nDesideri utilizzare l'algoritmo di match ciclico?\n"
           "y/n) ");
    scanf(" %c", &ciclico);

    if(ciclico == 'y') {
        patternPosition = kmp_ciclico(stringa, pattern);
        if(patternPosition)
            printf("\nPattern trovato.");
        else
            printf("\nPatter non trovato.");
    } else {
        patternPosition = kmp_match(stringa, pattern);
        if(patternPosition == -1) {
            printf("\nPattern non trovato.");
        } else {
            printf("\nPattern trovato alla posizione %d.", patternPosition + 1);
        }
    }
}

int* insuccesso(char* pattern){
    int n = strlen(pattern);
    int *insucc = NULL;
    int i, j;

    insucc = (int*)malloc(n * sizeof(int));

    insucc[0] = -1;

    /* Analisi dei prefissi */
    for(j = 1; j <= n - 1; j++){
        i = insucc[j - 1];

        while (pattern[j] != pattern[i + 1] && i >= 0)
            i = insucc[i];

        if(pattern[j] == pattern[i + 1])
            insucc[j] = i + 1;
        else
            insucc[j] = -1;
    }

    return insucc;
}

int kmp_match(char* stringa, char* pattern){
    int* insucc = insuccesso(pattern);
    int i = 0, j = 0;
    int lenS, lenP;

    lenS = strlen(stringa);
    lenP = strlen(pattern);

    while (i < lenS && j < lenP){
        if(stringa[i] == pattern[j]){
            i++;
            j++;
        }
        else if(j == 0){
            i++;
        }
        else{
            j = insucc[j - 1] + 1;
        }
    }

    if(j == lenP)
        return i - lenP;
    else
        return -1;
}

_Bool kmp_ciclico(char *stringa, char *pattern){
    int *insuc = insuccesso(pattern);
    int i = 0;
    int j = 0;
    int c = 0;

    int lenS = strlen(stringa);
    int lenP = strlen(stringa);

    while(c < lenS * 2 && j < lenP) {
        if(pattern[i] == pattern[j]){
            i++;
            j++;
            c++;
        }else if(j == 0) {
            c++;
            i++;
        }else {
            j = insuc[j - 1] + 1;
        }

        i %= lenS;
    }

    c++;

    return j == lenP;
}