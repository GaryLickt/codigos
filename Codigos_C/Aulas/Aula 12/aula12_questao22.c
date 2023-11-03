#include <stdio.h>
#include <stdlib.h>

int main() {
  int A[3][3];
  int B[3][3];
  
  // Setando valores aleatorios nas 2 matrizes
  for (int i = 0;i<3;i++){
    for (int j = 0;j<3;j++){
      A[i][j] = rand()%10; 
    }
  }

  // Calculando multiplicação C = A * B
  for (int i = 0;i<3;i++){
    for (int j = 0;j<3;j++){
      B[i][j] = A[i][j] * 2;
    }
  }

  for (int i = 0;i<3;i++){
    printf("| ");
    for (int j = 0;j<3;j++){
      printf("%d ",B[i][j]);
    }
    printf("|\n");
  }
  
  return 0;
}

