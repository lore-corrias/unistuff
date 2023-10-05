#include "decoupe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MAX_LEN_CURR 200

void erreur(const char *mess, int valExit) {
  perror(mess);
  exit(valExit);
}

int main(int argc, char *argv[]) {
  char *pMots[NBMOTSMAX + 1], commandeCurr[MAX_LEN_CURR] = "";
  int f_id;

  for (int i = 1; i < argc; i++) {
    // c'est necessaire parce que, après l'exécution de fork(),
    // printf("%s", argv[i]) deviennent "commande" sans les arguments
    strcpy(commandeCurr, argv[i]);

    Decoupe(argv[i], pMots);
    switch (f_id = fork()) {
    case -1:
      erreur("fork", EXIT_FAILURE);
    case 0:
      printf("[%d] Je lance %s:\n", getpid(), commandeCurr);
      execvp(pMots[0], pMots);
      erreur("execvp erreur", EXIT_FAILURE);
    default:
      printf("[%d] J'ai délégué %s à %d. J'attends sa fin...\n", getpid(),
             commandeCurr, f_id);
      wait(NULL);
      printf("[%d] %d terminé.\n", getpid(), f_id);
    }
  }

  printf("[%d] J'ai fini.\n", getpid());
  return 0;
}
