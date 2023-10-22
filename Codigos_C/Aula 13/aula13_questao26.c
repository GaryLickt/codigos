#include <stdio.h>
#include <stdlib.h>

void codificarCesar(char *string, int deslocamento) {
    // Percorre cada caractere na string
    for (int i = 0; i < strlen(string); ++i) {
        // Verifica se o caractere é uma letra maiúscula
        if (isalpha(string[i]) && isupper(string[i])) {
            // Aplica a troca de acordo com o deslocamento
            string[i] = 'A' + (string[i] - 'A' + deslocamento) % 26;
        }
        // Verifica se o caractere é uma letra minúscula
        else if (isalpha(string[i]) && islower(string[i])) {
            // Aplica a troca de acordo com o deslocamento
            string[i] = 'a' + (string[i] - 'a' + deslocamento) % 26;
        }
    }
}

int main() {
  char str[100];

  printf("Digite uma string: ");
  fgets(str, 100, stdin);

  if (str[strlen(str) - 1] == '\n') {
      str[strlen(str) - 1] = '\0';
  }

  codificarCesar(str, 3);

  printf("String codificada: %s\n", str);
  return 0;
}

