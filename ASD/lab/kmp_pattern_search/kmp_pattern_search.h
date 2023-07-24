#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STR_LEN_MAX 15
#define PATTERN_LEN_MAX 15

int* insuccesso(char* pattern);
int kmp_match(char* stringa, char* pattern);
_Bool kmp_ciclico(char *stringa, char *pattern);
void search_pattern();