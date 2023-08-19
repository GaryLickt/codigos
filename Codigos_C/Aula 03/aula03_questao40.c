// 40. Receba três números inteiros digitados pelo usuário e exiba o resultado da operação (n1 + n2) * n3.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n1,n2,n3;
  printf("Digite 3 numeros inteiros separados por espaço:\n");
  scanf("%d %d %d",&n1,&n2,&n3);
  int op = (n1+n2) * n3;
  printf("O resultado de (%d + %d) * %d é igual a %d\n",n1,n2,n3,op);
  return 0;
}
