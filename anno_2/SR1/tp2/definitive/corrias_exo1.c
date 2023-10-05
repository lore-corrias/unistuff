#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAILLE_BLOC 512

void erreur(const char *mess, int exit_code) {
  perror(mess);
  exit(exit_code);
}

void ecrire_dans_stdout(char nom_fich[]) {
  int fd = open(nom_fich, O_RDONLY), read_dim = 0;
  char buf[TAILLE_BLOC] = "";

  if (fd == -1)
    erreur("open", 1);

  while ((read_dim = read(fd, buf, TAILLE_BLOC)) > 0) {
    if (write(STDOUT_FILENO, buf, read_dim) == -1) {
      close(fd);
      erreur("write", 2);
    }
  }

  if (read_dim == -1) {
    close(fd);
    erreur("read", 3);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: ./%s fichier", argv[0]);
    return 4;
  }

  ecrire_dans_stdout(argv[1]);

  return 0;
}
