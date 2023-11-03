// 20. Receba a base e a altura de um retângulo digitados pelo usuário. Em seguida, calcule a sua área e exiba o resultado.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x;
  int y;
  printf("Digite a Base e a Altura de um retangulo:\n");
  scanf("%d %d",&x,&y);
  int area = x * y;
  printf("A Area do retangulo é %d",area);
  return 0;
}
