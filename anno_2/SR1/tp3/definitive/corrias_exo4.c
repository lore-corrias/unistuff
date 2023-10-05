#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int fich_vides = 0;

void erreur(const char *mess) {
  perror(mess);
  exit(EXIT_FAILURE);
}

void parcouir(const char *rep) {
  DIR *dir;
  char cour_fich_path[200] = "";
  struct dirent *cour_fich;
  struct stat infos;

  if ((dir = opendir(rep)) == NULL) {
    erreur("opendir");
  }
  strcpy(cour_fich_path, rep);
  while ((cour_fich = readdir(dir)) != NULL) {
    if (strcmp(cour_fich->d_name, ".") != 0 &&
        strcmp(cour_fich->d_name, "..") != 0) {
      sprintf(cour_fich_path, "%s/%s", rep, cour_fich->d_name);
      if (lstat(cour_fich_path, &infos) == -1) {
        printf("%s\n", cour_fich_path);
        erreur("lstat");
      }
      if (S_ISDIR(infos.st_mode)) {
        parcouir(cour_fich_path);
      } else if (infos.st_size == 0) {
        fich_vides++;
        printf("%s\n", cour_fich_path);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  struct stat infos;
  DIR *dir;

  if (argc != 2) {
    fprintf(stderr, "usage: %s repertoire", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (lstat(argv[1], &infos) == -1) {
    erreur("lstat");
  }

  if (!S_ISDIR(infos.st_mode)) {
    fprintf(stderr, "%s n'est pas une repertoire", argv[1]);
    exit(EXIT_FAILURE);
  } else {
    parcouir(argv[1]);
    printf("%d fichier(s) vide(s) trouvé(s)", fich_vides);
  }

  return 0;
}
