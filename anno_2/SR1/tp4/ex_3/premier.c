#include "est_premier.c"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void erreur(const char *mess) {
  perror(mess);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  int tube[2];
  int n = 4, n_premiers, exit_status;
  long long arg_long;
  char *endptr;
  int nb_lus;

  if (argc < 2) {
    fprintf(stderr, "usage: %s n1 [n2] [...]", argv[0]);
    exit(1);
  }

  if (pipe(tube) == -1) {
    erreur("pipe");
  }

  for (int i = 0; i < n; i++) {
    switch (fork()) {
    case -1:
      erreur("fork");
    case 0:
      if (close(tube[1]) == -1) {
        erreur("close");
      }
      while ((nb_lus = read(tube[0], (void *)&arg_long, sizeof(long))) > 0) {
        printf("[Fils %d] %-25llu ", i, arg_long);
        if (est_premier(arg_long)) {
          n_premiers++;
          printf("est premier");
        }
        printf("\n");
      }
      if (nb_lus == -1) {
        erreur("read");
      }
      exit(n_premiers);
    }
  }

  if (close(tube[0]) == -1) {
    erreur("close");
  }
  for (int j = 1; j < argc; j++) {
    arg_long = strtoull(argv[j], &endptr, 10);
    if (arg_long == 0 && endptr == argv[j]) {
      fprintf(stderr, "[Pére] : %s n'est pas un parametre valid\n", argv[j]);
    } else {
      if (write(tube[1], (void *)&arg_long, sizeof(long)) != sizeof(long)) {
        erreur("write");
      }
    }
  }

  if (close(tube[1]) == -1) {
    erreur("close");
  }

  while (wait(&exit_status) != -1) {
    n_premiers += WEXITSTATUS(exit_status);
  }
  printf("Il y a %d nombres premiers", n_premiers);

  return EXIT_SUCCESS;
}
