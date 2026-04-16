#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int grep(FILE *stream, const char *term, const char *filename){

  char *line = NULL;
  size_t buf_size = 0;

  while(getline(&line, &buf_size, stream) != -1){
    if(strstr(line, term) != NULL){
      if(filename != NULL){
        printf("%s:%s", filename, line);
      }else{
        printf("%s", line);
      }
      #ifdef DEBUG
      printf("Buff size: %zu\n", buf_size);
      #endif
    }
  }

  return 0;

}

int main(int argc, char **argv){

  if(argc < 2){
    fprintf(stderr, "Usage: wgrep [searchterm] [file...]\n");
    return 1;
  }

  if(argc == 2){
    grep(stdin, argv[1], NULL);
    return 0;
  }

  for(int i = 2; i < argc; i++){
    FILE *file = fopen(argv[i], "r");
    if(file == NULL){
      perror("Error opening file");
      return -1;
    }
    grep(file, argv[1], argc > 3 ? argv[i] : NULL);
    fclose(file);
  }

  return 0;
}
