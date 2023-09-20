#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * écrire un programme C ANSI qui prend en paramètre une liste de nombres
 * entiers et affiche à l’écran leur valeur après les avoir convertis en int.
 * Le programme doit vérifier que le paramètre est bien un entier.
 * Utiliser la fonction strtol pour convertir la chaîne de caractères de chaque
 * argument du programme en int. En effet, cette fonction gère correctement
 * les erreurs contrairement à la fonction atoi.
 */

int main(int argc, char *argv[]) {
  char *endptr;
  long int val;
  errno = 0;

  if (argc < 2) {
    fprintf(stderr, "usage: ./%s int1 int2 ...\n", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    val = strtol(argv[i], &endptr, 10);
    if (errno != 0 || endptr == argv[i]) {
      fprintf(stderr, "int n° %d is not a number\n", i);
      return 2;
    } else {
      printf("int n° %d: %ld\n", i, val);
    }
  }

  return 0;
}
