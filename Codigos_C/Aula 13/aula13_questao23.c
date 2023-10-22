#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  int i,j;
  fgets(str,100,stdin);
  scanf("%d %d",&i,&j);

  for(i = i;i <= j;i++){
    printf("%c",str[i]);
  } 
  printf("\n");
  
  return 0;
}

