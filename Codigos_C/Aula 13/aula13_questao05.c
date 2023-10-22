#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  fgets(str,100,stdin);

  int total = 0;
  for (int i = 0;str[i]!='\0';i++){
    total += 1;
  }

  printf("A string tem %d letra(s).\n",total-1);
  
  return 0;
}

