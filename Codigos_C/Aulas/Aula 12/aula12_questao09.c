#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[3][3] = {{0,2,3},{4,0,6},{7,8,0}};
  int soma = 0;
  for (int x = 0;x<3;x++){
    for (int y = 0;y<3;y++){
      if (x > y) {
        soma += matriz[x][y];
      }
    }
  }
  printf("A Soma dos valores abaixo da diagonal principal é igual a %d.\n",soma);
  
  return 0;
}