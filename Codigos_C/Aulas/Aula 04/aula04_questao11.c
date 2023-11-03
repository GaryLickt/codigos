#include <stdio.h>
#include <stdlib.h>

int main() {
  float altura, peso, IMC;
  printf("Digite sua altura:\n");
  scanf("%f",&altura);
  printf("Digite seu peso:\n");
  scanf("%f",&peso);
  IMC = peso/pow(altura,2);
  printf("O seu IMC é de %.2f\n",IMC);
  return 0;
}