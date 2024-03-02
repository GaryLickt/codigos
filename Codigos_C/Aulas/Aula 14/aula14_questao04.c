#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  printf("Digite um numero:\n");
  scanf("%d",&N);
  char *array = (char *)malloc(N);
  if (array != NULL) {
    printf("Digite uma palavra (max: %d caracteres):\n",N);
    scanf("%s",array);

    for(int i = 0;array[i]!='\0';i++){
      if (array[i] == 'a' || array[i] == 'A' || array[i] == 'e' || array[i] == 'E' || array[i] == 'i' || array[i] == 'I' || array[i] == 'o' || array[i] == 'O' || array[i] == 'u' || array[i] == 'U'){
        array[i] = ' ';
      }
    }
    printf("%s",array);
    
    free(array);
    array = NULL;
  }
  return 0;
}

