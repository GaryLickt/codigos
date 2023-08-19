// 18. Peça ao usuário que digite o seu nome e verifique se ele contém mais de 5 caracteres.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char minhaString[100];

  printf("Digite seu nome: ");
  scanf("%s", minhaString);

  int tamanho = strlen(minhaString);

  if (tamanho > 5) {
    printf("Seu nome possue mais de 5 caracteres\n");
  }else{
    printf("Seu nome possue 5 ou menos caracteres\n");
  }

  return 0;
}
