#include <stdio.h>
#include <stdlib.h>
int soma(int n){
  if (n == 0) {
    return n;
  }else{
  return n + soma(n-1);
  }
}

int main() {
  int x,y;
  scanf("%d",&x);
  y = soma(x);
  printf("%d\n",y);
  return 0;
}