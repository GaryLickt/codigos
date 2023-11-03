#include <stdio.h>
#include <stdlib.h>

int main(){
  char matriz[5][10];
  char respostas[4] = {'a','b','c','d'};
  char gabarito[10] = {'a','b','b','c','a','d','d','b','c','a'};
  int resultado[5];
  
  for (int i = 0;i<5;i++){
    resultado[i] = 0;
    for (int j = 0;j<10;j++){
      matriz[i][j] = respostas[rand()%4];
      if (matriz[i][j] == gabarito[j]){
        resultado[i] += 1;
      }
    }
  }

  printf("Resultado: [%d, %d, %d, %d, %d].\n",resultado[0],resultado[1],resultado[2],resultado[3],resultado[4]);

  return 0;
}
