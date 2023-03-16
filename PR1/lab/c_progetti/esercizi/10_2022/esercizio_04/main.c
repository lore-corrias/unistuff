#include <stdio.h>

/* Esercizio 04/10/2022 n° 5
 *
 * Testo:
 * "Scrivere un programma che, dato un numero complessivo di gatti
 * e il numero di questi per fila, fornisca in output il numero di file
 * risultanti e il numero di gatti rimamenti, in caso in cui l'ultima fila non
 * sia completa. Non devono essere presenti magic numbers e
 * si deve commentare opportunamente tutto il codice
 */

// entry point
int main() {
  // dichiaro le variabili contenenti il numero di gatti e di file
  int n_gatti, n_gatti_fila;
  // dichiaro le variabili con i risultati, il numero di file e i gatti
  // rimanenti
  int n_file, n_gatti_remainder;

  // leggo il valore del numero di gatti
  printf("Inserisci il numero totale di gatti: ");
  scanf("%d", &n_gatti);
  // leggo il valore del numero di file
  printf("\nInserisci il numero di gatti per fila: ");
  scanf("%d", &n_gatti_fila);

  // calcolo il numero di file
  n_file = n_gatti / n_gatti_fila;
  // calcolo il numero di gatti fuori dalle file
  n_gatti_remainder = n_gatti % n_gatti_fila;

  // stampo i risultati
  printf("\nNumero di file totali: %d\n", n_file);
  printf("Numero gatti fuori dalle fila: %d", n_gatti_remainder);

  // exit point
  return 0;
}
