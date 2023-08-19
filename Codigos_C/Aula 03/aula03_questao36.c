// 36. Solicite ao usuário que insira três números decimais. Em seguida, calcule e exiba a média aritmética desses números.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  float x,y,z;
  printf("Digite 3 numeros decimais separados por espaço:\n");
  scanf("%f %f %f",&x,&y,&z);
  float media = (x+y+z)/3;
  printf("A media obtida foi de %f",media);
  return 0;
}
