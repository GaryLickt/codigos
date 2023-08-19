// 35. Receba a base e a altura de um retângulo digitados pelo usuário. Em seguida, calcule e exiba o perímetro do retângulo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x,y;
  printf("Digite a base de um retangulo qualquer:\n");
  scanf("%d",&x);
  printf("Digite a altura de um retangulo qualquer:\n");
  scanf("%d",&y);
  int area = 2*(x+y);
  printf("O perimetro do retangulo é de %d\n",area);
  return 0;
}
