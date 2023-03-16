#include <stdio.h>
// librerie
#include <stdbool.h>

// macro
#define DIM_1 4 // dimensione del primo array
#define DIM_2 10 // dimensione del secondo array

// dichiarazioni subroutine
// procedura e funzione semplice
void printMax(int n1, int n2, int n3);
int calcolaMax(int n1, int n2, int n3);
// maggiore e massimo tra due numeri
bool maggiore(int n1, int n2);
int massimo(int n1, int n2);
// procedure e funzioni definite con l'uso di maggiore()
void printMaxBis(int n1, int n2, int n3);
int calcolaMaxBis(int n1, int n2, int n3);
// procedure e funzioni definite con l'uso di massimo()
void printMaxTris(int n1, int n2, int n3);
int calcolaMaxTris(int n1, int n2, int n3);
// procedure e funzioni con array come parametro con massimo()
void printMaxArray(int l, int n[]);
int calcolaMaxArray(int l, int n[]);
// procedure e funzioni con array come parametro con maggiore()
void printMaxArrayBis(int l, int n[]);
int calcolaMaxArrayBis(int l, int n[]);
// procedura con array come parametro per i 3 valori più alti con massimo()
void printThreeMaxArray(int l, int n[]);

int main() {
    // dichiarazioni variabili
    int a = 3, b = 8, c = 7;
    int vettore_1[DIM_1] = {3, 8, 7, 10};
    int vettore_2[DIM_2] = {10, 6, 8, 4, 5, 9, 12, 15, 1, 7};

    // invoca la funzione calcolaMax()
    printf("[calcolaMax] Il numero massimo e': %d.\n", calcolaMax(a, b, c));
    // invoca la procedura printMax()
    printMax(a, b, c);

    // invoca la funzione calcolaMaxBis()
    printf("\n[calcolaMaxBis] Il numero massimo e': %d.\n", calcolaMaxBis(a, b, c));
    // invoca la procedura printMaxBis()
    printMaxBis(a, b, c);

    // invoca la funzione calcolaMaxTris()
    printf("\n[calcolaMaxTris] Il numero massimo e': %d.\n", calcolaMaxTris(a, b, c));
    // invoca la procedura printMaxTris()
    printMaxTris(a, b, c);

    printf("\n\n- Funzioni con i vettori -\n");
    printf("Elementi del vettore_1: { ");
    for (int i = 0; i < DIM_1; i++) {
        printf("%d ", vettore_1[i]);
    }
    printf("}\n");

    // invoca la funzione calcolaMaxArray()
    printf("\n[calcolaMaxArray] Il numero massimo e': %d.\n", calcolaMaxArray(DIM_1, vettore_1));
    // invoca la funzione printMaxArray()
    printMaxArray(DIM_1, vettore_1);

    // invoca la funzione calcolaMaxArrayBis()
    printf("\n[calcolaMaxArrayBis] Il numero massimo e': %d.\n", calcolaMaxArrayBis(DIM_1, vettore_1));
    // invoca la funzione printMaxArrayBis()
    printMaxArrayBis(DIM_1, vettore_1);

    printf("\n\n - Funzione per stampare i primi tre numeri per grandezza di un array - \n");
    printf("Elementi del vettore_2: { ");
    for (int i = 0; i < DIM_2; i++) {
        printf("%d ", vettore_2[i]);
    }
    printf("}\n");

    // invoca la funzione printThreeMaxArray()
    printThreeMaxArray(DIM_2, vettore_2);

    return 0;
}

// definizioni subroutine
/**
 * Restituisce un booleano che indica se n1 > n2
 * @param n1 Il primo numero da confrontare
 * @param n2 Il secondo numero da confrontare
 * @return "true" se n1 > n2, "false" altrimenti
 */
bool maggiore(int n1, int n2) {
    return n1 > n2;
}

/**
 * Restituisci il maggiore tra n1 e n2.
 * @param n1 Il primo numero da confrontare
 * @param n2 Il secondo numero da confrontare
 * @return Il maggiore tra n1 e n2
 */
int massimo(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

/**
 * Calcola il maggiore tra n1, n2 e n3
 * @param n1 Il primo numero da confrontare
 * @param n2 Il secondo numero da confrontare
 * @param n3 Il terzo numero da confrontare
 * @return Il maggiore tra n1, n2 e n3
 */
int calcolaMax(int n1, int n2, int n3) {
    // restituisce il maggiore tra n1, n2 e n3
    if (n1 > n2 && n1 > n3) {
        return n1;
    } else if(n2 > n1 && n2 > n3) {
        return n2;
    } else {
        return n3;
    }
}

/**
 * Stampa il maggiore tra n1, n2 e n3
 * @param n1 Il primo numero da confrontare
 * @param n2 Il secondo numero da confrontare
 * @param n3 Il terzo numero da confrontare
 */
void printMax(int n1, int n2, int n3) {
    // stampa il maggiore tra n1, n2 e n3
    int max;
    if (n1 > n2 && n1 > n3) {
        max = n1;
    } else if(n2 > n1 && n2 > n3) {
        max =  n2;
    } else {
        max =  n3;
    }
    printf("[printMax] Il numero maggiore e': %d", max);
}

/**
 * Calcola il maggiore tra n1, n2 e n3 con la funzione "maggiore()"
 * @param n1 Il primo numero da confrontare
 * @param n2 Il secondo numero da confrontare
 * @param n3 Il terzo numero da confrontare
 * @return Il maggiore tra n1, n2 e n3
 */
int calcolaMaxBis(int n1, int n2, int n3) {
    if(maggiore(n1, n2) && maggiore(n2, n3)) {
        return n1;
    } else if(maggiore(n2, n1) && maggiore(n2, n3)) {
        return n2;
    } else {
        return n3;
    }
}

/**
 * Stampa il maggiore tra n1, n2 e n3 con la funzione "maggiore()"
 * @param n1 Il primo numero da confrontare
 * @param n2 Il secondo numero da confrontare
 * @param n3 Il terzo numero da confrontare
 */
void printMaxBis(int n1, int n2, int n3) {
    int max;
    if(maggiore(n1, n2) && maggiore(n2, n3)) {
        max = n1;
    } else if(maggiore(n2, n1) && maggiore(n2, n3)) {
        max = n2;
    } else {
        max = n3;
    }
    printf("[printMaxBis] Il numero maggiore e': %d", max);
}

/**
 * Calcola il maggiore tra n1, n2 e n3 con la funzione "massimo()"
 * @param n1 Il primo numero da confrontare
 * @param n2 Il secondo numero da confrontare
 * @param n3 Il terzo numero da confrontare
 * @return Il maggiore tra n1, n2 e n3
 */
int calcolaMaxTris(int n1, int n2, int n3) {
    return massimo(massimo(n1, n2), n3);
}

/**
 * Stampa il maggiore tra n1, n2 e n3 con la funzione "massimo()"
 * @param n1 Il primo numero da confrontare
 * @param n2 Il secondo numero da confrontare
 * @param n3 Il terzo numero da confrontare
*/
void printMaxTris(int n1, int n2, int n3) {
    int max = massimo(massimo(n1, n2), n3);
    printf("[printMaxTris] Il numero maggiore e': %d", max);
}

/**
 * Stampa il maggiore degli elementi di un array di int, usando "massimo()"
 * @param l La lunghezza dell'array
 * @param n L'array di interi da scorrere
 */
void printMaxArray(int l, int n[]) {
    int max = n[0];
    for (int i = 1; i < l; i++) {
        max = massimo(max, n[i]);
    }
    printf("[printMaxArray] Il numero maggiore e': %d", max);
}

/**
 * Calcola il maggiore degli elementi di un array di int, usando "massimo()"
 * @param l La lunghezza dell'array
 * @param n L'array di interi da scorrere
 * @return L'intero maggiore presente nell'array
 */
int calcolaMaxArray(int l, int n[]) {
    int max = n[0];
    for (int i = 1; i < l; i++) {
        max = massimo(max, n[i]);
    }
    return max;
}

/**
 * Stampa il maggiore degli elementi di un array di int, usando "maggiore()"
 * @param l La lunghezza dell'array
 * @param n L'array di interi da scorrere
 */
void printMaxArrayBis(int l, int n[]) {
    int max = n[0];
    for (int i = 1; i < l; i++) {
        if (maggiore(n[i], max))
            max = n[i];
    }
    printf("[printMaxArrayBis] Il numero maggiore e': %d", max);
}

/**
 * Stampa il maggiore degli elementi di un array di int, usando "maggiore()"
 * @param l La lunghezza dell'array
 * @param n L'array di interi da scorrere
 * @return L'intero maggiore presente nell'array
 */
int calcolaMaxArrayBis(int l, int n[]) {
    int max = n[0];
    for (int i = 1; i < l; i++) {
        if (maggiore(n[i], max))
            max = n[i];
    }
    return max;
}

/**
 * Stampa i tre numeri più grandi di un array di interi, usando la funzione "massimo()"
 * @param l La lunghezza dell'array
 * @param n L'array di interi
 */
void printThreeMaxArray(int l, int n[]) {
    if (l >= 3) {
        int max[3] = {};
        for (int i = 0; i < l; i++) {
            if(max[0] < n[i])
                max[0] = n[i];
        }
        for(int i = 0; i < l; i++) {
            if(max[1] < n[i] && n[i] != max[0])
                max[1] = n[i];
        }
        for(int i = 0; i < l; i++) {
            if(max[2] < n[i] && n[i] != max[0] && n[i] != max[1])
                max[2] = n[i];
        }
        printf("[printMaxThreeArray] Primo numero: %d\n", max[0]);
        printf("[printMaxThreeArray] Secondo numero: %d\n", max[1]);
        printf("[printMaxThreeArray] Terzo numero: %d", max[2]);
    }
}