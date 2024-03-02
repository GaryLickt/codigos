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
    int x,multiplos;
    printf("\nDigite um numero:\n");
    scanf("%d",&x);
    
    for (int i = 0;i<N;i++){
      if (array[i]%x == 0){
        multiplos++;
      }
    }
    printf("Dos numeros dentro do vetor, %d são multiplos de %d.\n",multiplos,x);
    free(array);
    array = NULL;
  }
  return 0;
}