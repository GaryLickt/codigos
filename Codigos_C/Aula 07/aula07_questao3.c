#include <stdio.h>
#include <stdlib.h>

int main() {
  int x, y;
  printf("Digite um numero inteiro: ");
  scanf("%d",&x);
  printf("Digite outro numero inteiro: ");
  scanf("%d",&y);

  printf("O endereço da variavel 1 é: %p\n",&x);
  printf("O endereço da variavel 2 é: %p\n",&y);
  return 0;
}