#include <stdio.h>

// macro
#define N 20 // lunghezza della stringa
// prime e ultime lettere maiuscole/minuscole
#define UP_MIN 'A'
#define UP_MAX 'Z'
#define LOW_MIN 'a'
#define LOW_MAX 'z'
// distanza nella tabella ascii tra una lettera maiuscola e la sua minuscola
#define LOW_UP_DISTANCE ('a'-'A')

// dichiarazioni subroutine
void strCAPSLOCK(int l, char s[], char s_return[]);
void strMinus(int l, char s[], char s_return[]);
void strInvertCaps(int l, char s[], char s_return[]);
void strInitCaps(int l, char s[], char s_return[]);
void strSigla(int l, char s[], char s_return[]);


// entry point
int main() {
    // dichiarazioni
    char stringa[N];
    char stringa_modificata[N];
    
    // inserimento da tastiera della stringa
    printf("Inserisci una stringa di %d caratteri: ", N);
    scanf("%[^\n]s", stringa);
    
    // stringa in capslock
    strCAPSLOCK(N, stringa, stringa_modificata);
    printf("\nStringa in caps-lock: %s", stringa_modificata);
    // stringa in minuscolo
    strMinus(N, stringa, stringa_modificata);
    printf("\nStringa in minuscolo: %s", stringa_modificata);
    // stringa con maiuscole e minuscole invertite
    strInvertCaps(N, stringa, stringa_modificata);
    printf("\nStringa con maiuscole e minuscole invertite: %s", stringa_modificata);
    // stringa con iniziali delle parole maiuscole
    strInitCaps(N, stringa, stringa_modificata);
    printf("\nStringa con iniziali delle parole maiuscole: %s", stringa_modificata);
    // stringa contenente la sigla della frase
    strSigla(N, stringa, stringa_modificata);
    printf("\nStringa contenente la sigla della frase: %s", stringa_modificata);
    
    // exit point
    return 0;
}

// definizioni subroutine
void strCAPSLOCK(int l, char s[], char s_return[]) {
    for(int i = 0; i < l && s[i] != '\0'; i++) {
        if(s[i] >= LOW_MIN && s[i] <= LOW_MAX)
            s_return[i] = s[i] - LOW_UP_DISTANCE;
        else
            s_return[i] = s[i];
    }
}

void strMinus(int l, char s[], char s_return[]) {
    for(int i = 0; i < l && s[i] != '\0'; i++) {
        if(s[i] >= UP_MIN && s[i] <= UP_MAX)
            s_return[i] = s[i] + LOW_UP_DISTANCE;
        else
            s_return[i] = s[i];
    }
}

void strInvertCaps(int l, char s[], char s_return[]) {
    for(int i = 0; i < l && s[i] != '\0'; i++) {
        if(s[i] >= UP_MIN && s[i] <= UP_MAX)
            s_return[i] = s[i] + LOW_UP_DISTANCE;
        else if(s[i] >= LOW_MIN && s[i] <= LOW_MAX)
            s_return[i] = s[i] - LOW_UP_DISTANCE;
    }
}

void strInitCaps(int l, char s[], char s_return[]) {
    for(int i = 0; i < l && s[i] != '\0'; i++) {
        if (i == 0 || s[i - 1] == ' ') {
            if (s[i] >= LOW_MIN && s[i] <= LOW_MAX) {
                s_return[i] = s[i] - LOW_UP_DISTANCE;
            } else {
                s_return[i] = s[i];
            }
        } else {
            if (s[i] >= UP_MIN && s[i] <= UP_MAX) {
                s_return[i] = s[i] + LOW_UP_DISTANCE;
            } else {
                s_return[i] = s[i];
            }
        }
    }
}

void strSigla(int l, char s[], char s_return[]) {
    int counter = 0;
    for(int i = 0; i < l && s[i] != '\0'; i++) {
        if(i == 0 || s[i-1] == ' ') {
            s_return[counter] = s[i];
            counter += 1;
        }
    }
    for(int i = l-1; i >= counter; i--) {
        s_return[i] = '\0';
    }
}