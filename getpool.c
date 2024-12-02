#include <stdio.h>
#include <string.h>

#include "getpool.h"

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