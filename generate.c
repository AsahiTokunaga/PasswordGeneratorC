#include <string.h>
#include<stdio.h>

#include "generate.h"
#include "getrand.h"

int generate(char* password, int passwordLength, char* charPool) {
  if (passwordLength < 1) {
    printf("Too short password length\n");
    return 1;
  }
  for (int i = 0; i < passwordLength; i++) {
    int randomValue = getRand();
    int charIndex = randomValue % strlen(charPool);
    password[i] =  charPool[charIndex];
  }
  return 0;
}