#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[4][4] = {{3,6,1,8},{12,34,28,9},{8,23,40,24},{50,23,5,12}};
  int total = 0;
  for (int x = 0;x<4;x++){
    for (int y = 0;y<4;y++){
      if (matriz[x][y] > 10){
        total+= 1;
      }
    }
  }
  printf("A Matriz usada possui %d numero(s) maiores que 10.\n",total);
  return 0;
}