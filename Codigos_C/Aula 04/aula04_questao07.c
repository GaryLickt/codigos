#include <stdio.h>
#include <stdlib.h>

int main() {
  float x,y,z,media;
  printf("Digite 3 notas de 1 aluno:\n");
  scanf("%f %f %f",&x,&y,&z);
  media = (x+y+z)/3;

  if (media >= 7){
    printf("Aluno Aprovado com media %.2f .\n",media);
  }else{
    printf("Aluno Reprovado com media %.2f .\n",media);
  }
  

  return 0;
}