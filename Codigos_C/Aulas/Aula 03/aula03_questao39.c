// 39. Solicite ao usuário para digitar um número decimal e arredonde-o para o inteiro mais próximo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  float x;
  printf("Digite um numero decimal:\n");
  scanf("%f",&x);
  int numero;
  if (x > (int)x + 0.5) {
    numero = (int)x+1;
  }else{
    numero = (int)x;
  }
  printf("O numero %f arredondado é igual a %d\n",x,numero);
  return 0;
}
