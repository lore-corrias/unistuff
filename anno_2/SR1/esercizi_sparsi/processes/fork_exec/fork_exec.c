#include <stdlib.h>
#include <wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  switch(fork()) {
    case -1:
      perror("Erreur");
      exit(3);
    case 0: // se fork() restituisce 0, sono il figlio
      execlp("ls", "ls", "-l", NULL);
      exit(1);
    default: // altrimenti, sono il padre
      wait(NULL);
  }
  switch(fork()) {
    case -1:
      perror("Erreur");
      exit(-1);
    case 0:
      execlp("pwd", "pwd", NULL);
      exit(1);
    default:
      wait(NULL);
  }
}
