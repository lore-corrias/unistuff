// Lorenzo Corrias, 20/09/2023
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>

void erreur(const char *mess, int code) {
  perror(mess);
  exit(code);
}

int main(int argc, char *argv[]) {
  int fd_in, fd_out;

  if (argc < 4) {
    fprintf(stderr, "usage: ./%s commande fich_entree fich_sortie", argv[0]);
    return 1;
  }

  // ouverture du fichier d'entrée
  fd_in = open(argv[2], O_RDONLY);
  // ouverture du fichier du sortie
  fd_out =
      open(argv[3], O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
  if (fd_in == -1 || fd_out == -1)
    erreur("open", 1);
  // redirection du stdio
  dup2(fd_in, STDIN_FILENO);
  // redirection du stdout
  dup2(fd_out, STDOUT_FILENO);

  // fork pour l'execution du commande
  switch (fork()) {
  case -1:
    erreur("fork", 2);
  case 0:
    // execution du commande
    execlp(argv[1], argv[1], NULL);
    erreur("execlp", 3);
  default:
    // le processus pére attende
    wait(NULL);
  }

  if (close(fd_in) == -1 || close(fd_out) == -1) {
    erreur("close", 4);
  }

  return 0;
}
