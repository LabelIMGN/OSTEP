#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "common.h"

volatile int counter = 0;
int loops, num_threads;

void *worker(void *arg){
  for(int i = 0; i < loops; i++){
    counter++;
  }
  delay(10000);
  return NULL;
}

int main(int argc, char *argv[]){
  if(argc != 3){
    fprintf(stderr, 
            "Usage: threads <value> <number of threads>\n");
    exit(1);
  }

  loops = atoi(argv[1]);
  num_threads = atoi(argv[2]);

  pthread_t *threads = malloc(sizeof(pthread_t)*num_threads);
  printf("Initial value: %d\n", counter);

  for(int i = 0; i < num_threads; i++){
    pthread_create(&threads[i], NULL, worker, NULL);
  }

  for(int i = 0; i < num_threads; i++){
    pthread_join(threads[i], NULL);
  }

  printf("Final value: %d\n", counter);

  free(threads);
  return 0;
}
