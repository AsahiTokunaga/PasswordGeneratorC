#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>

#include "getrand.h"

int getRand(void) {
  unsigned int randomValue;
  if (_rdrand32_step(&randomValue) != 1) {
    printf("RDRAND failed\n");
    return 1;
  }
  srand(randomValue);
  return rand();
}