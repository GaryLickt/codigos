// 33. Peça ao usuário para digitar a base e a altura de um triângulo. Em seguida, calcule e exiba a área do triângulo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x,y;
  printf("Digite a base de um triangulo qualquer:\n");
  scanf("%d",&x);
  printf("Digite a altura de um triangulo qualquer:\n");
  scanf("%d",&y);
  int area = (x*y)/2;
  printf("A Area do triangulo é %d\n",area);
  return 0;
}
