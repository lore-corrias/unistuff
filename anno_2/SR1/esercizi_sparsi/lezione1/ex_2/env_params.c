#include <stdio.h>
#include <stdlib.h>

/*
 * écrire un programme C ANSI qui prend en paramètre le nom d’une
 * variable d’environnement et qui affiche à l’écran sa valeur.
 */

int main(int argc, char *argv[]) {
  // correct usage check
  if (argc != 2) {
    fprintf(stderr, "usage: ./%s variable_env", argv[0]);
    return 1;
  }

  printf("%s", getenv(argv[1]));

  return 0;
}
