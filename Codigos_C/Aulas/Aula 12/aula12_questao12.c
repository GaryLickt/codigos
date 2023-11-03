#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int transposta[3][3];

  printf("Matriz:\n");
  for (int a = 0;a<3;a++){
    printf("| ");
    for (int b = 0;b<3;b++){
      printf("%d ",matriz[a][b]);
    }
    printf("|\n");
  }
  
  for (int i = 0;i<3;i++){
    for (int j = 0;j<3;j++){
      transposta[i][j] = matriz[j][i];
    }
  }
  printf("Transposta da Matriz:\n");
  for (int a = 0;a<3;a++){
    printf("| ");
    for (int b = 0;b<3;b++){
      printf("%d ",transposta[a][b]);
    }
    printf("|\n");
  }
  
  return 0;
}