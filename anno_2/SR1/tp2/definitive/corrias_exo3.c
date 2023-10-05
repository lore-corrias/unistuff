#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void erreur(const char *mess, int exit_code) {
  perror(mess);
  exit(exit_code);
}

void afficherFichier(int fichier, int destination) {
  int read_siz;
  char buf[BUFSIZ] = "";

  while ((read_siz = read(fichier, buf, BUFSIZ)) > 0) {
    if (write(destination, buf, read_siz) == -1) {
      close(fichier);
      close(destination);
      erreur("write", 4);
    }
  }
  if (read_siz == -1) {
    close(fichier);
    close(destination);
    erreur("read", 5);
  }
}

int main(int argc, char *argv[]) {
  int fd_fichier_courent;
  int fd_destination = STDOUT_FILENO;
  int n_fichier;

  if (argc == 1) {
    fprintf(stderr,
            "usage: %s fichier1 [fichier2] [...] [> fichier_destination]",
            argv[0]);
    return 1;
  }

  if (argc >= 4 && strcmp(argv[argc - 2], ">") == 0) {
    if ((fd_destination = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY,
                               S_IWUSR | S_IRUSR)) == -1)
      erreur("open", 2);
    n_fichier = argc - 3;
  } else {
    n_fichier = argc - 1;
  }

  for (int i = 1; i <= n_fichier; i++) {
    if ((fd_fichier_courent = open(argv[i], O_RDONLY)) == -1) {
      close(fd_destination);
      erreur("open", 2);
    }

    switch (fork()) {
    case -1:
      close(fd_destination);
      close(fd_fichier_courent);
      erreur("fork", 3);
    case 0:
      wait(NULL);
      break;
    default:
      afficherFichier(fd_fichier_courent, fd_destination);
      exit(0);
    }
  }

  if (close(fd_fichier_courent) == -1 || close(fd_destination) == -1)
    erreur("close", 6);
}
