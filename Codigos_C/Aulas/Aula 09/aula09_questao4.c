#include <stdio.h>
#include <stdlib.h>

int recur(int n){
  if (n == 0 || n == 1 || n == 2){
    printf("%d\n",n);
  }else{
    return printf("%d\n",(2 * recur(n-1)) + (3 * recur(n-2)));
  }
  return 0;
}

int main() {
  int x;
  printf("Digite quantas vezes a sequencia deve repetir: ");
  scanf("%d",&x);
  recur(x);
  return 0;
}
