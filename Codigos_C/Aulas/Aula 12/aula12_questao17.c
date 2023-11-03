#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[3][3];
  int soma[3] = {0,0,0};
  printf("Digite 9 numeros:\n");
  scanf("%d %d %d",&matriz[0][0],&matriz[0][1],&matriz[0][2]);
  scanf("%d %d %d",&matriz[1][0],&matriz[1][1],&matriz[1][2]);
  scanf("%d %d %d",&matriz[2][0],&matriz[2][1],&matriz[2][2]);

  for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++){
      soma[j] += matriz[i][j];
    }
  }
  printf("%d %d %d\n",soma[0],soma[1],soma[2]);
  return 0;
}