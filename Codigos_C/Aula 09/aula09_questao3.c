#include <stdio.h>
#include <stdlib.h>

void alterarValor(int **a, int b){
  int c = **a + b;
  **a = c;
}

int main() {
  int x,y;
  int *X = &x;
  printf("Digite valores para A e B:\n");
  scanf("%d %d",&x,&y);
  printf("Valores de A e de B antigos: %d %d\n",x,y);
  alterarValor(&X,y);
  printf("Valores de A e de B agora: %d %d\n",*X,y);
  return 0;
}