#include <stdio.h>
// librerie
#include <string.h>

// macro
#define DIM 20


// dichiarazioni subroutine
int countChar(char count, char s[]);


int main() {
    // dichiarazione variabili
    char stringa[DIM]; // la stringa di cui contare i caratteri
    int tmpcount; // variabile temporanea in cui immagazzinare il counter
    int i;

    // lettura da tastiera
    printf("Inserisci la frase: ");
    scanf("%20[^\n]s", stringa);

    // invocazione countChar()
    i = 0;
    while(i < strlen(stringa)) {
        for(int j = 0; j <= i; j++) {
            if(stringa[j] == stringa[i]) {
                i += 2;
                break;
            }
        }
        tmpcount = countChar(stringa[i], stringa);
        if(tmpcount > 1) {
            printf("\nIl carattere '%c' si ripete '%d' volte.", stringa[i], tmpcount);
        }
        i++;
    }

    return 0;
}


// definizioni subroutine
int countChar(char count, char s[]) {
    int counter = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == count)
            counter++;
    }
    return counter;
}