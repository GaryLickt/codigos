#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  printf("Digite um numero:\n");
  scanf("%d",&N);
  int *array = malloc(N * sizeof(int));
  if (array != NULL) {
    for (int i = 0;i<N;i++){
      printf("\nDigite o valor %d:\n",i+1);
      scanf("%d",(array+i));
    }
    printf("\nOs valores digitados foram:\n");
    for (int i = 0;i<N;i++){
      printf("%d\n",*(array+i));
    }
    free(array);
    array = NULL;
  }
  return 0;
}

