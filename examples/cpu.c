#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"


int main(int argc, char *argv[]){

  if(argc !=2){
    fprintf(stderr, "Usage: cpu <string>\n");
    exit(1);
  }

  char *str = argv[1];
  for(int i = 0; i < 10; i++){
    delay(1000);
    printf("%s\n", str);
  }

  return 0;
}
