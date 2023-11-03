#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 3;
  float b = 5.2;
  char c = 'x';

  int *A = &a;
  float *B = &b;
  char *C = &c;

  printf("valor de 'a' antigo: %d\n",*A);
  printf("valor de 'b' antigo: %.2f\n",*B);
  printf("valor de 'c' antigo: %c\n",*C);
  printf("\n");
  *A += 4;
  *B -= 2;
  *C = 'k';
  printf("valor de 'a' novo: %d\n",*A);
  printf("valor de 'b' novo: %.2f\n",*B);
  printf("valor de 'c' novo: %c\n",*C);
}