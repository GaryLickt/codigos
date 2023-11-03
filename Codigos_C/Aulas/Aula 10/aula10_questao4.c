#include <stdio.h>

int buscarMaior(int vetor[5],int tamanho){
  int maiorAtual = 0;
  int maiorPosicao = 0;
  for(int i = 0;i<tamanho;i++){
    if (vetor[i] > maiorAtual){
      maiorPosicao = i;
    }
  }
  return maiorPosicao;
}

int buscarMenor(int vetor[5],int tamanho){
  int menorAtual = vetor[0];
  int menorPosicao = 0;
  for(int i = 0;i<tamanho;i++){
    if (vetor[i] < menorAtual){
      menorPosicao = i;
    }
  }
  return menorPosicao;
}

int main() {
  int array[5];
  printf("Digite 5 numeros inteiros:\n");
  scanf("%d %d %d %d %d",&array[0],&array[1],&array[2],&array[3],&array[4]);
  int tamanho = sizeof(array)/sizeof(array[0]);
  int maior = buscarMaior(array,tamanho);
  int menor = buscarMenor(array,tamanho);
  printf("Entre os numeros dados, o maior numero se encontra na posição %d, e o menor numero na posição %d\n",maior,menor);
  return 0;
}