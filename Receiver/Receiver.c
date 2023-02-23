#include <stdio.h>
#include <stdlib.h>

int main() {
  char *lineptr = NULL;
  size_t len;
  size_t read;
  //Read summary
  if((read = getline(&lineptr, &len, stdin)) != -1){
     printf("\n%s", lineptr);
  }
  //
  printf("\nTest receiver workflow");
  return 0;
}
