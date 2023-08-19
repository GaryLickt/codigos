// 28. Receba um número inteiro e uma string do usuário. Em seguida, concatene-os em uma única string, separando-os com um espaço.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x;
  char man[20];
  printf("Digite um numero:\n");
  scanf("%d",&x);
  printf("Digite um nome:\n");
  scanf("%s",&man);

  printf("%s %d\n",man,x);
  return 0;
}
