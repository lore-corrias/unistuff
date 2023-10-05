#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void erreur(const char *mess, int exit_code) {
  perror(mess);
  exit(exit_code);
}

int conversion_str_int(const char *str) {
  int long n;
  char *endptr;
  errno = 0;

  n = strtol(str, &endptr, 10);
  if (errno != 0 || endptr == str)
    erreur("strtol", 2);

  return (int)n;
}

int taille(int fd) {
  int curr_pos, taille;

  curr_pos = lseek(fd, 0, SEEK_CUR);
  taille = lseek(fd, 0, SEEK_END);
  // le fd est placé à la position initiale
  lseek(fd, curr_pos, SEEK_SET);

  return taille;
}

void affiche_entier(int fd, int n) {
  int entier;

  lseek(fd, (n - 1) * sizeof(int), SEEK_SET);
  if (read(fd, &entier, sizeof(int)) < sizeof(int)) {
    close(fd);
    erreur("read", 5);
  }

  printf("%d\n", entier);
}

int creer_fichier(const char *fich) {
  int fd;
  int entiers[9] = {15, 18, 4, 29, 66, 78, 101, 562, 24};

  // si open == -1, le fichier n'existe pas
  if ((fd = open(fich, O_RDWR)) == -1) {
    if ((fd = open(fich, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR)) == -1)
      erreur("open", 6);
    if (write(fd, entiers, sizeof(int) * 9) < sizeof(int) * 9) {
      close(fd);
      erreur("write", 7);
    }
  }

  return fd;
}

void ecrire_entier(int fd, int n, int entier) {
  lseek(fd, (n - 1) * sizeof(int), SEEK_SET);

  if (write(fd, &entier, sizeof(int)) < sizeof(int)) {
    close(fd);
    erreur("write", 6);
  }
}

int main(int argc, char *argv[]) {
  int n, fd, entier, n_entiers;

  // correct usage
  if (argc < 3) {
    fprintf(stderr, "usage: ./%s n [entier] fichier\n", argv[0]);
    return 1;
  }

  // ouverture du fichier
  fd = creer_fichier(argv[argc - 1]);

  // je calcule le numero du entiers dans le fichier
  n_entiers = taille(fd) / sizeof(int);

  // je fais la conversion du string à entier
  n = conversion_str_int(argv[1]);

  // je verifie que le parametre n est valide
  if (n <= 0 || n > n_entiers) {
    fprintf(stderr, "le parametre 'n' (%d) n'est pas valide.\n", n);
    return 4;
  }

  if (argc == 4) {
    entier = conversion_str_int(argv[2]);
    ecrire_entier(fd, n, entier);
  } else if (argc == 3) {
    affiche_entier(fd, n);
  }

  close(fd);

  return 0;
}
