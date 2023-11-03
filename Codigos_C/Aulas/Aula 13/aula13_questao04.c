#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  char mini[5] = "";
  fgets(str,100,stdin);

  for(int i = 0;i<5;i++){
    mini[i] = str[i];
  }
  mini[4] = '\0';
  printf("%s.\n",mini);
  
  return 0;
}

