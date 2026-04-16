#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "common.h"

#define NUM_ITER 5
#define ARRAY_SIZE 5

int main(int argc, char *argv[]){

  int *p = malloc(sizeof(int));
  assert(p != NULL);
  printf("(%d) address pointed to by p: %p\n", getpid(), p);
  *p = 0;
  for(int i = 0; i < NUM_ITER; i++){
    delay(500);
    *p = *p + 1;
    printf("(%d) p: %d\n", getpid(), *p);
  }
  return 0;

}
