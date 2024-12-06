#include <stdlib.h>
#include <stdio.h>

#include "generate.h"
#include "getpool.h" // Sum of upper and lower case letters, numbers and symbols, and plus one.

int main(int argc, char* argv[]) {
  if (argc != 3 || atoi(argv[1]) < 1) {
    printf("Invarid input\n");
    return 1;
  }

  int passwordLength = atoi(argv[1]);
  char* charTypes = argv[2];
  char* charPool = (char*)malloc(MAX_CHAR_POOL * sizeof(char));
  char* password = (char*)malloc((passwordLength + 1) * sizeof(char));
  if (!charPool || !password) {
    perror("To allocate memory failed\n");
    free(password);
    password = NULL;
    free(charPool);
    charPool = NULL;
    return 1;
  }

  getPool(charPool, charTypes);
  generate(password, passwordLength, charPool);
  printf("%s\n", password);
  free(password);
  password = NULL;
  free(charPool);
  charPool = NULL;

  return 0;
}
