#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N, pares = 0, impares = 0;
  printf("Digite um numero:\n");
  scanf("%d",&N);
  int *array = malloc(N * sizeof(int));
  if (array != NULL) {
    for (int i = 0;i<N;i++){
      printf("\nDigite o valor %d:\n",i+1);
      scanf("%d",(array+i));
      if (array[i]%2 == 0){
        pares++;
      }else{
        impares++;
      }
    }
    printf("\nDos valores digitados, %d são pares.\n",pares);
    printf("Dos valores digitados, %d são impares.\n",impares);
    
    free(array);
    array = NULL;
  }
  return 0;
}

