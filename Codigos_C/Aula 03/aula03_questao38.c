// 38. Receba um valor em reais e a cotação do dólar digitados pelo usuário. Em seguida, converta o valor para dólares e exiba o resultado.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x;
  float y;
  printf("Digite um valor (em real):\n");
  scanf("%d",&x);
  printf("Digite quanto vale 1 real na moeda que você quer converter:\n");
  scanf("%f",&y);
  float conversao = y * x;
  printf("R$%d vale $%f em dolar \n",x,conversao);
  return 0;
}
