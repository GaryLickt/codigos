// 16. Peça ao usuário que insira dois números e exiba o maior deles.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x;
  int y;
  printf("Digite 2 numeros: \n");
  scanf("%d %d",&x,&y);
  if (x < y) {
    printf("%d é o maior",y);
  }else if (x > y) {
    printf("%d é o maior",x);
  }else if (x == y) {
    printf("Ambos são iguais");
  }
  return 0;
}
