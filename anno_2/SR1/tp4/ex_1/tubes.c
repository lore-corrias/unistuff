#include <pipeline.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void erreur(const char *mess) {
  perror(mess);
  exit(EXIT_FAILURE);
}

int main(void) {
  int n = 8, nb_lus, entier, f_pid, exit_fils;
  int tubes[2];

  if (pipe(tubes) == -1) {
    erreur("pipe");
  }

  switch ((f_pid = fork())) {
  case -1:
    erreur("fork");
  case 0:
    if (close(tubes[1]) == -1) {
      perror("close");
    }
    while ((nb_lus = read(tubes[0], (void *)&entier, sizeof(int))) > 0) {
      printf("[Fils] %d\n", entier + 1);
    }
    if (nb_lus == -1) {
      perror("read");
    }
    if (close(tubes[0]) == -1) {
      perror("close");
    }
    exit(1);
  default:
    if (close(tubes[0]) == -1) {
      perror("close");
    }
    for (int i = 0; i < n; i++) {
      if (write(tubes[1], (void *)&i, sizeof(int)) != sizeof(int)) {
        perror("write");
      }
      sleep(1);
    }
    if (close(tubes[1]) == -1) {
      perror("close");
    }
    wait(&exit_fils);
    printf("[Père] : Mon fils %d est terminé avec le code %d.\n", f_pid,
           WEXITSTATUS(exit_fils));
  }
  return 0;
}
