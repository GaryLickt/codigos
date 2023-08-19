// 27. Solicite ao usuário que insira seu ano de nascimento e concatene-o com uma mensagem de boas-vindas, como "Bem-vindo ao nosso programa, nascido em [ano de nascimento]!".
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char ano[20];
  printf("Digite seu ano de nascimento:\n");
  scanf("%s",&ano);
  printf("Bem-vindo ao nosso programa, nascido em %s\n",ano);
  return 0;
}
