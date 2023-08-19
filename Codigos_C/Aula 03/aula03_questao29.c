//29. Receba o nome de um produto digitado pelo usuário e concatene-o com o preço do produto, adicionando o símbolo de moeda da sua escolha.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char produto[20];
  int preco = 15;
  char simbolo[10] = "$";
  printf("Vai querer oque para beber?\n");
  scanf("%s",&produto);
  printf("um(a) %s vai custar %s%d\n",produto,simbolo,preco);
  return 0;
}
