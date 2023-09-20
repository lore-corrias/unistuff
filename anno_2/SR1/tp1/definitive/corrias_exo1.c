#include "afficher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define EXIT_PERE 57
#define EXIT_FILS 95

void afficher(const char *mess) {
  if (strcmp(mess, "pere") == 0) { // je suis le pére
    printf("** Processus pére:\n");
  } else if (strcmp(mess, "fils") == 0) { // je suis le fils
    printf("** Processus fils:\n");
  }
  printf("- PID: %d\n", getpid());
  printf("- PPID: %d\n", getppid());
  printf("- Utilisateur du groupe: %d\n", getpgrp());
  printf("- Nom de login: %s\n", getlogin());
  printf("- UID: %d\n", getuid());
  printf("- GID: %d\n", getgid());
}

int main() {
  pid_t retour_fils;

  switch (fork()) {
  case -1:
    perror("fork");
    exit(EXIT_FAILURE);
  case 0: // je suis le fils
    afficher("fils");
    printf("retour code: %d\n\n", EXIT_FILS);
    exit(EXIT_FILS);
  default: // je suis le pére
    wait(&retour_fils);
    afficher("pere");
    printf("retour code: %d\n", EXIT_PERE);
    printf("retour code fils: %d\n", WEXITSTATUS(retour_fils));
    exit(EXIT_PERE);
  }
}
