#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[4][4] = {{2,4,1,7},{8,43,1,4},{9,83,23,12},{214,435,21,64}};
  int maiorAtual = -1000000,posx,posy;
  for (int x = 0;x<4;x++){
    for (int y = 0;y<4;y++){
      if (matriz[x][y] > maiorAtual){
        maiorAtual = matriz[x][y];
        posx = x;
        posy = y;
      }
    }
  }
  printf("O Maior valor da matriz é o numero '%d', localizado nas posições [%d,%d].\n",maiorAtual,posx,posy);
  return 0;
}