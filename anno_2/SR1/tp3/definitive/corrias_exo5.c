#include <dirent.h>
#include <pwd.h>
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
  struct passwd *pswd;

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

  if ((pswd = getpwuid(infos->st_uid)) == NULL) {
    erreur("getpwuid");
  }

  printf("%-20s %10ld octets %s %s", type, infos->st_size, pswd->pw_name,
         ctime(&infos->st_mtim));
}

int main(int argc, char *argv[]) {
  struct stat infos;
  char cour_path[200];
  DIR *dir;
  struct dirent *cour_fich;

  if (argc < 2) {
    fprintf(stderr, "usage: %s fichier1 [fichier2] [...]", argv[0]);
    exit(EXIT_FAILURE);
  } else if (argc == 2) {
    if (lstat(argv[1], &infos) == -1) {
      erreur("lstat");
    }
    printf("%-40s", argv[1]);
    affiche_inode(&infos);
    if (S_ISDIR(infos.st_mode) != 0) {
      if ((dir = opendir(argv[1])) == NULL) {
        erreur("dir");
      }
      while ((cour_fich = readdir(dir)) != NULL) {
        if (strcmp(cour_fich->d_name, ".") != 0 &&
            strcmp(cour_fich->d_name, "..") != 0) {
          sprintf(cour_path, "%s/%s", argv[1], cour_fich->d_name);
          if (lstat(cour_path, &infos) == -1) {
            erreur("lstat");
          }
          printf("%-40s", cour_path);
          affiche_inode(&infos);
        }
      }
    }
  } else {
    for (int i = 1; i < argc; i++) {
      if (lstat(argv[i], &infos) == -1) {
        erreur("lstat");
      }
      printf("%-30s", argv[i]);
      affiche_inode(&infos);
    }
  }

  return 0;
}
