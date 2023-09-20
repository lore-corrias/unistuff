// Lorenzo Corrias, 20/09/2023
#include <stdio.h>

/*
 * écrire un programme C ANSI qui affiche à l’écran
 * ses arguments (un argument par ligne)
 */

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++)
    printf("%s\n", argv[i]);

  return 0;
}
