#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// dimension of the buffer
#define BUF_DIM 512

int main(int argc, char *argv[]) {
  int src, dest, read_data;
  char data[BUF_DIM] = ""; // buffer for the data read from src

  // verifying the number of arguments
  if (argc < 3) {
    fprintf(stderr, "usage: %s src_file dest_file", argv[0]);
    exit(1);
  }

  // opening the files
  src = open(argv[1], O_RDONLY);
  // the dest file must be opened
  dest =
      open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IRGRP | S_IWUSR);

  if (src == -1 || dest == -1) {
    perror("error opening file");
    exit(2);
  }

  while ((read_data = read(src, data, BUF_DIM)) > 0) {
    if (write(dest, data, read_data) == -1) {
      perror("error writing dest");
      exit(3);
    }
  }

  if (read_data == -1) {
    perror("error reading src");
    exit(4);
  }

  if (close(src) == -1 || close(dest) == -1) {
    perror("error closing file");
    exit(5);
  }

  return 0;
}
