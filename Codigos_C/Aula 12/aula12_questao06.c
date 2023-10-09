#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[4][4] = {{1,5,2,67},{7,4,2,8},{12,52,7,2},{78,3,1,6}};
  int vector[4][4] = {{7,4,2,6},{8,2,6,2},{42,12,52,5},{56,2,6,2}};
  int array[4][4];
  
  for (int x = 0;x<4;x++){
    for (int y = 0;y<4;y++){
      if (matriz[x][y] > vector[x][y]){
        array[x][y] = matriz[x][y];
      }else{
        array[x][y] = vector[x][y];
      }
    }
  }
  printf("| %d %d %d %d |\n",array[0][0],array[0][1],array[0][2],array[0][3]);
  printf("| %d %d %d %d |\n",array[1][0],array[1][1],array[1][2],array[1][3]);
  printf("| %d %d %d %d |\n",array[2][0],array[2][1],array[2][2],array[2][3]);
  printf("| %d %d %d %d |\n",array[3][0],array[3][1],array[3][2],array[3][3]);
  
  return 0;
}