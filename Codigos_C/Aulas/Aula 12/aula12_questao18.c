#include <stdio.h>
#include <stdlib.h>

int main() {
  float matriz[5][4];
  printf("Digite a Matricula e a media das provas e dos trabalhos do Aluno 1:\n");
  scanf("%f %f %f",&matriz[0][0],&matriz[0][1],&matriz[0][2]);
  printf("Digite a Matricula e a media das provas e dos trabalhos do Aluno 2:\n");
  scanf("%f %f %f",&matriz[1][0],&matriz[1][1],&matriz[1][2]);
  printf("Digite a Matricula e a media das provas e dos trabalhos do Aluno 3:\n");
  scanf("%f %f %f",&matriz[2][0],&matriz[2][1],&matriz[2][2]);
  printf("Digite a Matricula e a media das provas e dos trabalhos do Aluno 4:\n");
  scanf("%f %f %f",&matriz[3][0],&matriz[3][1],&matriz[3][2]);
  printf("Digite a Matricula e a media das provas e dos trabalhos do Aluno 5:\n");
  scanf("%f %f %f",&matriz[4][0],&matriz[4][1],&matriz[4][2]);

  for(int i = 0;i<5;i++){
    float soma = 0;
    for(int j = 0;j<3;j++){
      if (j > 0) {
        soma += matriz[i][j];
      }
    }
    matriz[i][3] = soma;
  }

  float maiorNota = 0;
  float maiorMatricula = 0;
  float mediaNotas = 0;
  
  for (int i = 0;i<5;i++){
    if (matriz[i][3] > maiorNota){
      maiorNota = matriz[i][3];
      maiorMatricula = matriz[i][0];
    }
    mediaNotas += matriz[i][3];
  }

  mediaNotas = mediaNotas/5;

  printf("O Aluno de matricula #%.0f foi o que obteve a maior media.\n",maiorMatricula);
  printf("A media aritmética das notas finais é de %.2f.\n",mediaNotas);
  
  return 0;
}

