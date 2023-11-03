#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0}};
  int alvo = 1,encontrado = 0;
  int posx = -1, posy = -1;
  for (int x = 0;x<5;x++){
    for (int y = 0;y<5;y++){
      if (matriz[x][y] == alvo && encontrado == 0){
        posx = x;
        posy = y;
      }
    }
  }
  if (posx == -1 || posy == -1){
    printf("Alvo não encontrado.\n");
  }else{
    printf("Alvo encontrado na posição [%d,%d].\n",posx,posy);
  }
  
  return 0;
}