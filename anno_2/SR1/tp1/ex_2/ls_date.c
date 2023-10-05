#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void erreur(const char *mess, int valExit) {
  perror(mess);
  exit(valExit);
}

int main() {
  switch (fork()) {
  case -1:
    erreur("fork", EXIT_FAILURE);
  case 0: // je suis le fils
    execlp("ls", "ls", "-al", NULL);
    erreur("ls", EXIT_FAILURE); // si je suis là, il y a une erreur
  default:                      // je suis le pére
    wait(NULL);                 // j'attend la fin du processus fils
    execlp("date", "date", NULL);
    erreur("date", EXIT_FAILURE); // si je suis là, il y a une erreur
  }
}
