#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>
#include "common.h"

#define NUM_BYTES 256

int main(int argc, char *argv[]){
  int fd = open("tmp/file", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
  assert(fd > -1);
  int rc = write(fd, "Hello W0rld! This is way more than 12 bytes\n", NUM_BYTES); 
  assert(rc == NUM_BYTES);
  close(fd);

  return 0;
}
