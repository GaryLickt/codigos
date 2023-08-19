// 15. Receba um número inteiro digitado pelo usuário e verifique se ele é positivo ou negativo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  printf("Digite um numero:\n");
  scanf("%d",&n);
  if (n >= 0) {
    printf("O numero %d é positivo\n",n);
  }else{
    printf("O numero %d é negativo\n",n);
  }
  return 0;
}
