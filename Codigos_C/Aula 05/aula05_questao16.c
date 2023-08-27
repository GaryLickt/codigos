// 16.Crie um programa que leia 5 notas de alunos ee xiba quantos deles foram aprovados (nota maior ou igual a 7).
#include <stdio.h>
#include <stdlib.h>
int main(){
  float a;
  int contador = 0;
  int passaram = 0;
  while (contador < 5) {
    printf("Insira a nota do aluno %d: ",contador+1);
    scanf("%f",&a);
    if (a >= 7){
      passaram += 1;
    }
    contador += 1;
  }
  printf("%d Alunos passaram de ano\n",passaram);
  return 0;
}