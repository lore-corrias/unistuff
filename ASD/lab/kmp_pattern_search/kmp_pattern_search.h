//
// Created by just on 30/03/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_LEN_MAX 15
#define PATTERN_LEN_MAX 15

int* funzione_insuccesso(char pattern[], int pattern_len);
int kmp_match(char stringa[], char pattern[], int stringa_len, int pattern_len);
int kmp_match_ciclica(char stringa[], char pattern[], int stringa_len, int pattern_len);
void search_pattern();