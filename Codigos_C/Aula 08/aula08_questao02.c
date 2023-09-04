#include <stdio.h>
#include <stdlib.h>
int fatorar(int n){
  if (n == 0){
    return 1;
  }else{
    return n * fatorar(n-1);
  }
}

int main() {
  int x, y;
  scanf("%d",&x);
  y = fatorar(x);
  printf("%d! = %d\n",x,y);
  return 0;
}