#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

/*écrire un programme C qui prend en argument la désignation d’un fichier
 * et affiche les caractéristiques suivantes : désignation du fichier, taille,
 * date de dernière modification des données.
 */

void erreur(const char *mess, int code) {
  perror(mess);
  exit(code);
}

int main(int argc, char *argv[]) {
  struct stat pInfos;

  if (argc != 2) {
    fprintf(stderr, "usage: ./%s designation-fichier", argv[0]);
    exit(1);
  }

  if (stat(argv[1], &pInfos) == -1) {
    erreur("fstat", 3);
  }

  printf("* Désignation du fichier: %s\n", argv[1]);
  printf("* Taille du fichier: %ld\n", pInfos.st_size);
  printf("* Dernière modification: %ld\n", pInfos.st_mtime);

  return 0;
}
