#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[4][4];
  int transformada[4][4];

  //preenche matriz
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matriz[i][j] = rand()%20;
      transformada[i][j] = matriz[i][j];
    }
  }
  
  printf("Matriz:\n");
  for (int a = 0;a<4;a++){
    printf("| ");
    for (int b = 0;b<4;b++){
      printf("%d ",matriz[a][b]);
    }
    printf("|\n");
  }

  for (int i = 0;i<4;i++){
    for (int j = 0;j<4;j++){
      if (i<j){
        transformada[i][j] = 0;
      }
    }
  }

  
  printf("Matriz Transformada:\n");
  for (int a = 0;a<4;a++){
    printf("| ");
    for (int b = 0;b<4;b++){
      printf("%d ",transformada[a][b]);
    }
    printf("|\n");
  }
  
  return 0;
}