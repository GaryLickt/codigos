#include <stdio.h>
#include <stdlib.h>

int main() {
  char str1[100];
  char str2[100];

  printf("Digite a primeira frase: ");
  fgets(str1, 100, stdin);

  // Remove o caractere de nova linha do final da primeira str
  if (str1[strlen(str1) - 1] == '\n') {
      str1[strlen(str1) - 1] = '\0';
  }

  printf("Digite a segunda frase: ");
  fgets(str2, 100, stdin);

  if (str2[strlen(str2) - 1] == '\n') {
      str2[strlen(str2) - 1] = '\0';
  }

  
  printf("Frase 1 invertida e com 'A' trocado por '*': ");
  for (int i = strlen(str1) - 1; i >= 0; --i) {
      if (str1[i] == 'A' || str1[i] == 'a') {
          printf("*");
      } else {
          printf("%c", str1[i]);
      }
  }
  printf("\n");

  printf("Frase 2 invertida e com 'A' trocado por '*': ");
  for (int i = strlen(str2) - 1; i >= 0; --i) {
      if (str2[i] == 'A' || str2[i] == 'a') {
          printf("*");
      } else {
          printf("%c", str2[i]);
      }
  }
  printf("\n");
  return 0;
}

