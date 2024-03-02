#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkValueInMatrix(int** matrix, int rows, int cols, int value) {
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if (matrix[i][j] == value) {
              return 1;
          }
      }
  }
  return 0;
}
int main() {
  int rows, cols;
  printf("Digite o numero de linhas: ");
  scanf("%d", &rows);
  printf("Digite o numero de colunas: ");
  scanf("%d", &cols);
  int** matrix = (int**) malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
      matrix[i] = (int*) malloc(cols * sizeof(int));
  }
  printf("Digite os elementos da matriz:\n");
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          scanf("%d", &matrix[i][j]);
      }
  }
  int value;
  printf("Digite um valor para verificar se ele esta na matriz: ");
  scanf("%d", &value);
  int result = checkValueInMatrix(matrix, rows, cols, value);
  if (result) {
      printf("O Valor %d esta presente na matriz.\n",value);
  } else {
      printf("O Valor %d não esta presente na matriz.\n",value);
  }
  for (int i = 0; i < rows; i++) {
      free(matrix[i]);
  }
  free(matrix);
  return 0;
}