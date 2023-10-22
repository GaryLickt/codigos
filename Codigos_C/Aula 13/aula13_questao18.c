#include <stdio.h>
#include <stdlib.h>

void substituirLetra(char *str, char L1, char L2) {
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] == L1) {
      str[i] = L2;
    }
    i++;
  }
}

int main() {
  char str[100];
  char L1,L2;
  fgets(str,100,stdin);

  if (str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  }

  printf("Digite a letra L1: ");
  scanf(" %c", &L1);

  printf("Digite a letra L2: ");
  scanf(" %c", &L2);

  substituirLetra(str, L1, L2);
  printf("String resultante: %s\n", str);
  
  return 0;
}

