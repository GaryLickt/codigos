// 32. Receba dois números inteiros do usuário e exiba a soma, a diferença, o produto e o quociente (divisão inteira) entre eles.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x,y;
  printf("Digite um numero inteiro:\n");
  scanf("%d",&x);
  printf("Digite outro numero inteiro:\n");
  scanf("%d",&y);
  int soma = x + y;
  int sub = x - y;
  int multi = x * y;
  int quoci = x / y;
  printf("A soma entre %d e %d é igual a %d\n",x,y,soma);
  printf("A subtração entre %d e %d é igual a %d\n",x,y,sub);
  printf("A multiplicação entre %d e %d é igual a %d\n",x,y,multi);
  printf("O quociente da divisão entre %d e %d é igual a %d\n",x,y,quoci);
  return 0;
}
