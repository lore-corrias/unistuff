#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int erreur(const char *mess, int exit_code) {
  perror(mess);
  exit(exit_code);
}

int main() {
  char car;
  int nb_lus, nb_ecr;
  int tubes_alfa[2], tubes_chiffres[2];

  char car_sum['z' - 'a'] = {0};
  char int_sum = 0;

  if (pipe(tubes_alfa) == -1 || pipe(tubes_chiffres) == -1) {
    erreur("pipe", 1);
  }

  switch (fork()) {
  case -1:
    erreur("fork", 2);
  case 0: // fils "alfabetiques"
    close(tubes_alfa[1]);
    close(tubes_chiffres[0]);
    close(tubes_alfa[1]);
    while ((nb_lus = read(tubes_alfa[0], (void *)&car, sizeof(char))) ==
           sizeof(char)) {
      car_sum[tolower(car) - 'a'] += 1;
    }
    if (nb_lus == -1)
      erreur("read", 4);
    printf("A) Nb des car Alfabetiques: \n");
    for (int i = 0; i < ('z' - 'a'); i++) {
      printf("--- %c: %d\n", ('a' + i), car_sum[i]);
    }
    close(tubes_alfa[0]);
    exit(0);
  default:
    switch (fork()) {
    case -1:
      erreur("fork", 2);
    case 0: // fils "chiffres"
      close(tubes_chiffres[1]);
      close(tubes_alfa[0]);
      close(tubes_alfa[1]);
      while ((nb_lus = read(tubes_chiffres[0], (void *)&car, sizeof(char))) ==
             sizeof(char)) {
        int_sum += atoi(&car);
      }
      if (nb_lus == -1)
        erreur("read", 4);
      printf("C) Sum totale des Chiffres: %d\n", int_sum);
      close(tubes_chiffres[0]);
      exit(0);
    default:
      close(tubes_alfa[0]);
      close(tubes_chiffres[0]);
      while ((nb_lus = read(STDIN_FILENO, (void *)&car, sizeof(char))) ==
             sizeof(char)) {
        if (isalpha(car)) {
          nb_ecr = write(tubes_alfa[1], (void *)&car, sizeof(char));
        } else if (isdigit(car)) {
          nb_ecr = write(tubes_chiffres[1], (void *)&car, sizeof(char));
        }
        if (nb_ecr == -1)
          erreur("write", 3);
        if (car == '\n')
          break;
      }
      if (nb_lus == -1)
        erreur("read", 4);
      // TODO: da rivedere, così attende all'infinito,
      //  forse ci vuole un controllo sulla lettura
      // while (wait(NULL) != -1)
      //  continue;
      close(tubes_alfa[1]);
      close(tubes_chiffres[1]);
    }
  }

  return 0;
}
