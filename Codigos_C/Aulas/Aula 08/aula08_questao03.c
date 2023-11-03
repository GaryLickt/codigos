#include <stdio.h>
#include <stdlib.h>
int fibo(int n){
  if (n == 0 || n == 1){
    return n;
  }else{
    return fibo(n-1) + fibo(n-2);
  }
}

int main() {
  int y;
  y = fibo(19);
  printf("%d\n",y);
  return 0;
}