#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[3][6];
  for (int i = 0;i<3;i++){
    for (int j = 0;j<6;j++){
      matriz[i][j] = rand()%99;
    }
  }

  //Imprimindo a matriz inicial
  for (int i = 0;i<3;i++){
    printf("| ");
    for (int j = 0;j<6;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("|\n");
  }
  printf("\n");
  //Imprimindo a soma de todos os elementos das colunas impares [1,3,5]
  int soma = 0;
  for (int i = 0;i<3;i++){
    for (int j = 0;j<6;j++){
      if (j == 0 || j == 2 || j == 4){
        soma += matriz[i][j];
      }
    }
  }
  printf("A Soma de todos os elementos das colunas impares é igual a %d.\n",soma);
  printf("\n");
  //Imprimindo a media aritmetica dos elementos da segunda e da quarta coluna
  int media = 0;
  int total = 0;
  for (int i = 0;i<3;i++){
    for (int j = 0;j<6;j++){
      if (j == 1 || j == 3){
        media += matriz[i][j];
        total += 1;
      }
    }
  }
  media = media/total;
  printf("A Media Aritmetica de todos os elementos das colunas 2 e 4 é igual a %d.\n",media);
  printf("\n");
  //Substituindo a coluna 6 pela soma da coluna 1 com a coluna 2
  for (int i = 0;i<3;i++){
    matriz[i][5] = matriz[i][0] + matriz[i][1];
  }

  //Imprimindo a matriz final
  for (int i = 0;i<3;i++){
    printf("| ");
    for (int j = 0;j<6;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("|\n");
  }
  
  return 0;
}

