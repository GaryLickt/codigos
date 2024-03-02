#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  printf("Digite quantos bytes seram alocados:\n");
  scanf("%d",&N);
  if(N%2==0 || N%8==0){
    int *array = malloc(N * sizeof(int));
    if (array != NULL) {
      int opcao;
      while(opcao!=3){
        printf("Oque deseja fazer?\n(1- Inserir memoria em uma determinada posição)\n(2-Consultar o valor contido em uma determinada posição)\n(3-Sair)\n");
        scanf("%d",&opcao);
        if (opcao==1){
          int posicao,valor;
          printf("\nDigite a posicao e o valor:\n");
          scanf("%d %d",&posicao,&valor);

          printf("\nO Valor %d foi armazenado na posição %d.\n",valor,posicao);
          array[posicao] = valor;
        }else if (opcao == 2){
          int posicao,valor;
          printf("\nDigite a posicao:\n");
          scanf("%d",&posicao);

          printf("\nNa posição %d, esta armazenado o valor %d.\n",posicao,array[posicao]);
        }
        getchar();
      }
      free(array);
      array = NULL;
    }
  }
  return 0;
}