#include <stdio.h>
#include <stdlib.h>

int main() {
  int n,m;
  printf("Digite 2 numeros inteiros: ");
  scanf("%d %d",&n,&m);

  if (n > m) {
    printf("Pelos meus calculos, %d é maior que %d",n,m);
  }else if (n == m) {
    printf("Pelos meus calculos, %d e %d são iguais!",n,m);
  }else{
    printf("Pelos meus calculos, %d é maior que %d",m,n);
  }
  return 0;
}