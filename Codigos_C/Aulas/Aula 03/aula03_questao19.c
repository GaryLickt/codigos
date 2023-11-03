// 19. Solicite ao usuário que insira o seu estado civil e exiba uma mensagem apropriada (por exemplo: "Você é casado(a)", "Você é solteiro(a)", etc.).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char estado[20];
  printf("Qual seu estado civil?\n");
  scanf("%s",&estado);
  if (strcmp(estado, "solteiro") == 0) {
    printf("Você é solteiro(a)\n");
  }else if (strcmp(estado, "casado") == 0) {
    printf("Você é casado(a)\n");
  }else if (strcmp(estado, "separado") == 0) {
    printf("Você é separado(a)\n");
  }else if (strcmp(estado, "divorciado") == 0) {
    printf("Você é divorciado(a)\n");
  }else if (strcmp(estado, "viuvo") == 0) {
    printf("Você é viuvo(a)\n");
  }
  

  return 0;
}
