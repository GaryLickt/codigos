#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[5][5];
  for (int x = 0;x<5;x++){
    for (int y = 0;y<5;y++){
      matriz[x][y] = x*y;
    }
  }
  printf("| %d %d %d %d %d |\n",matriz[0][0],matriz[0][1],matriz[0][2],matriz[0][3],matriz[0][4]);
  printf("| %d %d %d %d %d |\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],matriz[1][4]);
  printf("| %d %d %d %d %d |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4]);
  printf("| %d %d %d %d %d |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4]);
  printf("| %d %d %d %d %d |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4]);
  return 0;
}