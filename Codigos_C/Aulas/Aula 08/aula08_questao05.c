#include <stdio.h>
#include <stdlib.h>
int decrescente(int n){
  if (n == 0){
    printf("%d.\n",0);
  }else{
    printf("%d, ",n);
    decrescente(n-1);
  }
  return 0;
}

int main() {
  int x;
  scanf("%d",&x);
  printf("\n");
  decrescente(x);
  return 0;
}