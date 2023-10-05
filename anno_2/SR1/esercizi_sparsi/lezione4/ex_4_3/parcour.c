#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

/*
 * écrire une fonction qui affiche à l’écran les désignations de tous les
 * fichiers ordinaires contenus dans la sous-arborescence dont le répertoire
 * racine est passé en paramètre. Par exemple, supposons que l’on se trouve dans
 * la configuration suivante : le répertoire TEST contient le fichier fich.txt,
 * les répertoires REP1 et REP2 ; le répertoire REP1 contient les fichiers
 * fich11.txt et fich12.txt ; le répertoire REP2 contient le fichier fich2.txt.
 *
 * Si le répertoire TEST est passé en paramètre à la fonction, elle doit alors
 * afficher : TEST/REP1/fich11.txt TEST/REP1/fich12.txt TEST/REP2/fich2.txt
 *    TEST/fich.txt
 */

void parcour(char *parcours) {
  DIR *cour_dir;
  struct dirent *dir_infos;
  struct stat p_infos;
  char cour_par[300] = "";

  if ((cour_dir = opendir(parcours)) == NULL) {
    perror("opendir");
    exit(1);
  }

  while ((dir_infos = readdir(cour_dir)) != NULL) {
    if (strcmp(dir_infos->d_name, ".") != 0 &&
        strcmp(dir_infos->d_name, "..") != 0) {
      strcpy(cour_par, parcours);
      strcat(cour_par, "/");
      strcat(cour_par, dir_infos->d_name);
      if (stat(cour_par, &p_infos) != -1) {
        if (S_ISDIR(p_infos.st_mode)) {
          parcour(cour_par);
        } else if (S_ISREG(p_infos.st_mode)) {
          printf("%s\n", cour_par);
        }
      } else {
        perror("stat");
        exit(2);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  parcour("/home/just/Personal/erasmus");
  return 0;
}
