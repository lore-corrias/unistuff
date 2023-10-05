#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

#define MAX_BASSIN 5

void erreur(const char *mess) {
  perror(mess);
  exit(EXIT_FAILURE);
}

int main(void) {
  int Remplir[2], Etat[2];
  int f_pid, f_status, f_flags;
  int n = 10, entier_boucle = 1, entier_negatif = -1, entier_lus;
  int nb_lus;
  int bassin = 0;

  if (pipe(Remplir) == -1 || pipe(Etat) == -1) {
    erreur("pipe");
  }

  f_flags = fcntl(Etat[0], F_GETFL); /* Recuperation des flags */
  f_flags |= O_NONBLOCK;             /* Positionnement du flag de non blocage */
  fcntl(Etat[0], F_SETFL, f_flags);  /* Mis `a jour des flags */

  switch ((f_pid = fork())) {
  case -1:
    erreur("fork");
  case 0:
    if (close(Remplir[1]) == -1 || close(Etat[0]) == -1) {
      erreur("close");
    }
    while ((nb_lus = read(Remplir[0], (void *)&entier_lus, sizeof(int))) ==
           sizeof(int)) {
      if (entier_lus > 0) {
        bassin += entier_lus;
        if (bassin >= MAX_BASSIN) {
          if (write(Etat[1], (void *)&entier_lus, sizeof(int)) != sizeof(int)) {
            erreur("write");
          }
        }
        printf("*");
        fflush(stdout);
      } else {
        bassin = 0;
        printf("\n");
      }
    }
    if (nb_lus == -1) {
      erreur("read");
    }
    if (close(Remplir[0]) == -1 || close(Etat[1]) == -1) {
      erreur("close");
    }
    exit(1);
  default:
    if (close(Remplir[0]) == -1 || close(Etat[1]) == -1) {
      erreur("close");
    }
    for (int i = 0; i < n; i++) {
      if (write(Remplir[1], (void *)&entier_boucle, sizeof(int)) !=
          sizeof(int)) {
        erreur("write");
      }
      sleep(1);
      if ((nb_lus = read(Etat[0], (void *)&entier_lus, sizeof(int))) ==
          sizeof(int)) {
        if (write(Remplir[1], (void *)&entier_negatif, sizeof(int)) !=
            sizeof(int)) {
          erreur("write");
        }
      }
      if (nb_lus == -1 && errno != EAGAIN) {
        erreur("read");
      }
    }
    if (close(Remplir[1]) == -1 || close(Etat[0]) == -1) {
      erreur("close");
    }
    wait(&f_status);
    printf("[Père] : Mon fils %d est terminé avec le code %d", f_pid,
           WEXITSTATUS(f_status));
  }

  return 0;
}
