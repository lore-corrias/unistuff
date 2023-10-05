#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int tubes[2];
  char car;
  int nb_lus;

  if (pipe(tubes) == -1) {
    perror("pipe");
    exit(1);
  }

  switch (fork()) {
  case -1:
    perror("fork");
    exit(2);
  case 0:
    if (close(tubes[1]) == -1) {
      perror("close");
      exit(3);
    }
    while ((nb_lus = read(tubes[0], (void *)&car, sizeof(char))) ==
           sizeof(char)) {
      write(STDOUT_FILENO, (void *)&car, nb_lus);
    }
    if (nb_lus == -1) {
      perror("read");
      exit(6);
    }
    close(tubes[0]);
    return 0;
  default:
    if (close(tubes[0]) == -1) {
      perror("close");
      exit(3);
    }
    while ((nb_lus = read(STDIN_FILENO, (void *)&car, sizeof(char))) ==
           sizeof(char)) {
      if (write(tubes[1], (void *)&car, sizeof(char)) == -1) {
        perror("write");
        close(tubes[1]);
        exit(5);
      }
    }
    close(tubes[1]);
  }
  return 0;
}
