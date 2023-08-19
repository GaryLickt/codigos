// 41. Peça ao usuário que digite uma temperatura em graus Celsius e a converta para Fahrenheit usando a fórmula: Fahrenheit = (Celsius * 9/5) + 32.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int c;
  printf("Digite uma temperatura em graus Celsius:\n");
  scanf("%d",&c);
  int f = (c * 9/5) + 32;
  printf("%d°C é igual a %d°F\n",c,f);
  return 0;
}
