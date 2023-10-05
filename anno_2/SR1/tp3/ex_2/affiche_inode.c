#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void erreur(const char *mess) {
  perror(mess);
  exit(EXIT_FAILURE);
}

void affiche_inode(struct stat *infos) {
  char type[100] = "";

  switch (infos->st_mode & S_IFMT) {
  case S_IFREG:
    strcpy(type, "fichier ordinaire");
    break;
  case S_IFDIR:
    strcpy(type, "répertoire");
    break;
  case S_IFIFO:
    strcpy(type, "fichier spécial tube (FIFO)");
    break;
  case S_IFCHR:
    strcpy(type, "périphérique caractère");
    break;
  case S_IFBLK:
    strcpy(type, "périphérique bloc");
    break;
  case S_IFLNK:
    strcpy(type, "lien symbolique");
    break;
  case S_IFSOCK:
    strcpy(type, "socket");
    break;
  default:
    strcpy(type, "inconnu ?");
    break;
  }

  printf("%-20s %10ld octets %s", type, infos->st_size, ctime(&infos->st_mtim));
}

int main(int argc, char *argv[]) {
  struct stat infos;

  if (argc < 2) {
    fprintf(stderr, "usage: %s fichier1 [fichier2] [...]", argv[0]);
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (lstat(argv[i], &infos) == -1) {
      erreur("lstat");
    }

    printf("%-30s", argv[i]);
    affiche_inode(&infos);
  }

  return 0;
}
