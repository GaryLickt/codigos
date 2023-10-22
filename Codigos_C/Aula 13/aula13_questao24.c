#include <stdio.h>
#include <stdlib.h>

int encontrarCaractere(char *str, char caractere, int posicaoInicial) {
    int i;

    // Percorre a str a partir da posição inicial
    for (i = posicaoInicial; str[i] != '\0'; ++i) {
        // Se encontrar o caractere, retorna o índice
        if (str[i] == caractere) {
            return i;
        }
    }

    // Se não encontrar, retorna -1
    return -1;
}

int main() {
  char str[100];
  char caractere;

  int posicaoInicial;

  printf("Digite uma string: ");
  fgets(str, 100, stdin);

  if (str[strlen(str) - 1] == '\n') {
      str[strlen(str) - 1] = '\0';
  }

  // Solicita o caractere ao usuário
  printf("Digite um caractere: ");
  scanf(" %c", &caractere);

  // Solicita a posição inicial ao usuário
  printf("Digite a posição inicial: ");
  scanf("%d", &posicaoInicial);

  int indiceEncontrado = encontrarCaractere(str, caractere, posicaoInicial);

  // Imprime o resultado
  if (indiceEncontrado != -1) {
      printf("O caractere '%c' foi encontrado na posição %d da str.\n", caractere, indiceEncontrado);
  } else {
      printf("O caractere '%c' não foi encontrado na str a partir da posição %d.\n", caractere, posicaoInicial);
  }
  return 0;
}

