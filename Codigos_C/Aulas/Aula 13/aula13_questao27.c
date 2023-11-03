#include <stdio.h>
#include <stdlib.h>

int verificaSubstring(char *str1, char *str2) {
  int tamanho1 = strlen(str1);
  int tamanho2 = strlen(str2);
  
  if (tamanho2 > tamanho1) {
      return 0;
  }

  return strcmp(str1 + tamanho1 - tamanho2, str2) == 0;
}

int main() {
  char string1[100];
  char string2[100];

  // Solicita a primeira string ao usuário
  printf("Digite a primeira string: ");
  fgets(string1, 100, stdin);

  // Remove o caractere de nova linha do final da primeira string
  if (string1[strlen(string1) - 1] == '\n') {
      string1[strlen(string1) - 1] = '\0';
  }

  // Solicita a segunda string ao usuário
  printf("Digite a segunda string: ");
  fgets(string2, 100, stdin);

  // Remove o caractere de nova linha do final da segunda string
  if (string2[strlen(string2) - 1] == '\n') {
      string2[strlen(string2) - 1] = '\0';
  }

  // Chama a função para verificar se a segunda string está contida no final da primeira
  if (verificaSubstring(string1, string2)) {
      printf("A segunda string está contida no final da primeira.\n");
  } else {
      printf("A segunda string não está contida no final da primeira.\n");
  }
  return 0;
}

