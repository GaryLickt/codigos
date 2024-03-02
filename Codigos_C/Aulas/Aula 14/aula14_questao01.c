#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *array = malloc(5 * sizeof(int));
  if (array != NULL) {
    for (int i = 0;i<5;i++){
      printf("Digite o valor %d:\n",i+1);
      scanf("%d",(array+i));
    }
    printf("\nOs valores digitados foram:\n");
    for (int i = 0;i<5;i++){
      printf("%d\n",*(array+i));
    }
    free(array);
    array = NULL;
  }
  return 0;
}

