#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  fgets(str,100,stdin);

  for (int j = 0;str[j]!='\0'; j++) {
    if (str[j] != ' ') {
      printf("%c", str[j]);
    }
  }
  
  return 0;
}

