#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "send_to_child.h"

int send_to_child(int fd, char * s) {
  size_t n = strlen(s);
  size_t w = 0;
  while (w < n) {
    ssize_t x = write(fd, s, n - w);
    if (x == -1) { perror("write"); exit(1); }
    w += (size_t)x;
  }
  return 1;                     /* OK */
}

