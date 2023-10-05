#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * écrire une fonction d’en-tête :
 * long TailleRepCour(void)
 * qui retourne le nombre total d’octets occupés par les fichiers ordinaires
 * présents dans le répertoire courant. Attention à ne pas suivre les liens
 * symboliques. La fonction retourne -1 en cas de problème.
 */

long TailleRepCour(void) {
  long n_oct = 0;
  DIR *cour_dir;
  struct dirent *dirent;
  struct stat pInfos;

  if ((cour_dir = opendir(".")) == NULL) {
    return -1;
  }

  while ((dirent = readdir(cour_dir)) != NULL) {
    if (lstat(dirent->d_name, &pInfos) == -1) {
      return -1;
    }
    if (S_ISREG(pInfos.st_mode) != 0)
      n_oct += pInfos.st_size;
  }

  if (closedir(cour_dir) == -1)
    return -1;

  return n_oct;
}

int main(int argc, char *argv[]) {
  printf("* Dimension du repertoire courant: %ld", TailleRepCour());
}
