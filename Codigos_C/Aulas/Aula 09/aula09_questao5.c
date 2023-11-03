#include <stdio.h>
#include <stdlib.h>

int pell(int n){
  if (n == 0 || n == 1){
    printf("%d\n",n);
  }else if (n > 1){
    return printf("%d\n",(2 * pell(n-1)) + pell(n-2));
  }
  return 0;
}

int main() {
  int x;
  printf("Digite quantas vezes a sequencia deve repetir: ");
  scanf("%d",&x);
  pell(x);
  return 0;
}
