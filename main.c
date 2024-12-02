#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <immintrin.h>

#define MAX_CHAR_POOL 95 // Sum of upper and lower case letters, numbers and symbols, and plus one.

int generate(char*, int, char*);
int getPool(char*, char*);
int getRand(void);

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Invarid input\n");
    return 1;
  }

  int passwordLength = atoi(argv[1]);
  if (passwordLength < 1) {
    printf("Invalid password length\n");
    return 1;
  }

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

int getPool(char* charPool, char* charTypes) {
  if (strchr(charTypes, (int)'U') != NULL) {
    strncat(charPool, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", MAX_CHAR_POOL - strlen(charPool) -  1);
  }
  if (strchr(charTypes, (int)'L') != NULL) {
    strncat(charPool, "abcdefghijklmnopqrstuvwxyz", MAX_CHAR_POOL - strlen(charPool) -  1);
  }
  if (strchr(charTypes, (int)'N') != NULL) {
    strncat(charPool, "1234567890", MAX_CHAR_POOL - strlen(charPool) -  1);
  }
  if (strchr(charTypes, (int)'S') != NULL) {
    strncat(charPool, "`~!@#$%^&*()-_=+[{\\|;:\'\",<.>/?}]", MAX_CHAR_POOL - strlen(charPool) -  1);
  }
  if (charPool[0] == '\0')
    return 1;
  return 0;
}

int getRand(void) {
  unsigned int randomValue;
  if (_rdrand32_step(&randomValue) != 1) {
    printf("RDRAND failed\n");
    return 1;
  }
  srand(randomValue);
  return rand();
}
