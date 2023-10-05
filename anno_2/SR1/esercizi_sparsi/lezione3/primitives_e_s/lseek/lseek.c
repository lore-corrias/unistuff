#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int position(int fd) { return lseek(fd, 0, SEEK_CUR); }

int set_position(int fd, int pos) { return lseek(fd, pos, SEEK_SET); }

off_t taille(int fd) { return lseek(fd, 0, SEEK_END); }

int n_ieme_int(int fd, int n) {
  int n_int;

  set_position(fd, (n - 1) * sizeof(int));
  read(fd, (void *)&n_int, sizeof(int));

  return n_int;
}

int main(int argc, char *argv[]) {}
