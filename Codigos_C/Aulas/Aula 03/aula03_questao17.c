// 17. Receba a altura e o peso de uma pessoa digitados pelo usuário. Em seguida, calcule o seu índice de massa corporal (IMC) utilizando a fórmula: IMC = peso / (altura * altura) e exiba o resultado.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  float x;
  int y;
  printf("Digite sua altura: \n");
  scanf("%f",&x);
  printf("Digite seu peso: \n");
  scanf("%d",&y);
  float imc = (y)/(x*x);
  printf("Seu IMC deu %f",imc);
  return 0;
}
