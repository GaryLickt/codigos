#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int soma = 0;

  for (int x = 3-1; x >=0; x--) {
      soma += matriz[x][(3-1)-x];
    }
  
  printf("A Soma dos valores na diagonal secundaria é igual a %d.\n",soma);
  
  return 0;
}