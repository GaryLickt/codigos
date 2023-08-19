// 34. Receba o raio de uma circunferência digitado pelo usuário e calcule o seu perímetro (2 * π * raio).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x;
  printf("Digite o raio de uma circunferência qualquer:\n");
  scanf("%d",&x);
  float area = (2 * 3.14 * x);
  printf("O perimetro da circunferência é de %f\n",area);
  return 0;
}
