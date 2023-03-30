//
// Created by just on 30/03/23.
//

#include "kmp_pattern_search.h"

void search_pattern() {
    char stringa[STR_LEN_MAX + 1] = "";
    char pattern[PATTERN_LEN_MAX + 1] = "";

    int patternPosition;

    printf("\nInserisci la stringa in cui ricercare il pattern (max %d caratteri): ", STR_LEN_MAX);
    scanf("%[^\n]15s", stringa);
    printf("\nInserisci il pattern da ricercare nella stringa (max %d caratteri): ", PATTERN_LEN_MAX);
    scanf(" %[^\n]15s", pattern);

    patternPosition = kmp_match(stringa, pattern, strlen(stringa), strlen(pattern));

    if(patternPosition == -1) {
        printf("\nPattern non trovato.");
    } else {
        printf("\nPattern trovato alla posizione %d.", patternPosition + 1);
    }

    patternPosition = kmp_match_ciclica(stringa, pattern, strlen(stringa), strlen(pattern));
    if(patternPosition == -1) {
        printf("\nPattern ciclico non trovato.");
    } else {
        printf("\nPattern ciclico trovato alla posizione %d.", patternPosition + 1);
    }
}

int* funzione_insuccesso(char pattern[], int pattern_len) {
    int i, j;

    // allocazione dinamica dell'array insuccesso
    int* insuccesso = (int*) calloc(pattern_len, sizeof(int));
    if(insuccesso == NULL) {
        printf("\nImpossibile allocare dinamicamente l'array insuccesso.");
        exit(-1);
    }

    // il primo elemento dell'array insuccesso è sempre 0
    insuccesso[0] = -1;
    // analisi del pattern
    for(j = 1; j < pattern_len; j++) {
        i = insuccesso[j-1];

        // incrementa i se viene trovata un'occorrenza
        while(pattern[j] == pattern[i+1] && i >= 0)
            i = insuccesso[i];

        if(pattern[j] == pattern[i+1]) {
            insuccesso[j] = i+1;
        } else {
            insuccesso[j] = -1;
        }
    }

    return insuccesso;
}

int kmp_match(char stringa[], char pattern[], int stringa_len, int pattern_len) {
    int* insuccesso = funzione_insuccesso(pattern, pattern_len);

    int i = 0, j = 0;

    while(i < stringa_len && j < pattern_len) {
        if(stringa[i] == pattern[j]) {
            i++;
            j++;
        } else if(j == 0) {
            i++;
        } else {
            j = insuccesso[j-1]+1;
        }
    }

    if(j == pattern_len)
        return i-pattern_len;
    else
        return -1;
}

int kmp_match_ciclica(char stringa[], char pattern[], int stringa_len, int pattern_len) {
    int* insuccesso = funzione_insuccesso(pattern, pattern_len);

    int i = 0, j = 0;

    while(j < pattern_len) {
        if(stringa[i % stringa_len] == pattern[j % pattern_len]) {
            i++;
            j++;
        } else if(j == 0) {
            i++;
        } else {
            j = insuccesso[(j % pattern_len) - 1]+1;
        }
    }

    printf("%d", j);

    if(j == pattern_len)
        return i-pattern_len;
    else
        return -1;
}