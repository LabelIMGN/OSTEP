#pragma once

#include <time.h>

void delay(int micro_seconds){
  int ms = 1000 * micro_seconds;
  clock_t start_time = clock();
  while(clock() < start_time + ms);
}
