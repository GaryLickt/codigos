#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[10][10];
  
  for (int x = 0;x<10;x++){
    for (int y = 0;y<10;y++){
      if (x < y){
        matriz[x][y] = (2 * x) + (7 * y);
      }else if (x == y){
        matriz[x][y] = (3 * (x*x));
      }else{
        matriz[x][y] = (5 * (y*y) + 1);
      }
    }
  }

  for (int a = 0;a<10;a++){
    printf("| ");
    for (int b = 0;b<10;b++){
      printf("%d ",matriz[a][b]);
    }
    printf("|\n");
  }
  
  return 0;
}