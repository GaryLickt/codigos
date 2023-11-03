#include <stdio.h>
#include <stdlib.h>

int main() {
  char str1[100];
  char str2[100];

  printf("Digite a primeira string: ");
  scanf("%s", str1);

  printf("Digite a segunda string: ");
  scanf("%s", str2);

  int comparacao = strcmp(str1, str2);

  if (comparacao < 0) {
      printf("%s vem primeiro na ordem alfabética.\n", str1);
  } else if (comparacao > 0) {
      printf("%s vem primeiro na ordem alfabética.\n", str2);
  } else {
      printf("As strings são iguais.\n");
  }
  return 0;
}

