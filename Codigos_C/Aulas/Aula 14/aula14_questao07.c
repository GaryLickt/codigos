#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *array = calloc(1500,sizeof(int));
  int check = 0;
  if (array != NULL) {
    // a. Faça um loop e verifique se o vetor realmente contém os 1500 valores inicializados com zero (conte os 1500 zeros do vetor).
    for(int i = 0;i<1500;i++){
      if (array[i] == 0){
        check ++;
      }
      //  b. Atribua para cada elemento do vetor o valor do seu índice junto a este vetor.
      array[i] = i;
    }
    // c. Exiba na tela os 10 primeiros e os 10 últimos elementos do vetor.
    printf("10 primeiros | 10 ultimos\n");
    for(int i = 0;i<10;i++){
      printf("%dº: %d | %dº: %d\n",i+1,array[i],(1499-i)+1,array[1499-i]);
    }
  }
  return 0;
}