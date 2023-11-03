#include <stdio.h>
#include <stdlib.h>

int main() {
  double altura, raio, pi, calc1, volume;
  printf("Digite a altura de um cilindro circular qualquer: ");
  scanf("%lf",&altura);
  printf("Digite o raio de um cilindro circular qualquer: ");
  scanf("%lf",&raio);
  
  pi = 3.141592;
  calc1 = pi * pow(raio,2.0);
  volume = calc1 * altura;
  printf("O Volume desse cilindro circular é de: %.2lf\n",volume);
  return 0;
}
