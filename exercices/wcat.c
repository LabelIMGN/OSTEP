#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_SIZE 8192

int main(int argc, char **argv){

  if(argc < 2){
    fprintf(stderr, "Usage: wcat [file...]\n");
    return 1;
  }

  for(int i = 1; i < argc; i++){
    FILE *file = fopen(argv[i], "r");
    if(file == NULL){
      perror("Error opening file");
      return -1;
    }
    char *line = malloc(MAX_LINE_SIZE);

    while(fgets(line, MAX_LINE_SIZE, file) != NULL){
      printf("%s", line);
    }
    free(line);
    fclose(file);
  }

  return 0;
}
