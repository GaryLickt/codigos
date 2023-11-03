#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  char str2[100];
  int valor_igual = 0, tamanho = 0;
  fgets(str,100,stdin);
  fgets(str2,100,stdin);

  for(int i = 0;str[i]!='\0';i++){
    tamanho += 1;
    if (str[i] == str2[i]) {
      valor_igual += 1;
    }
  }
  if (valor_igual == tamanho) {
    printf("Iguais\n");
  
  } else {
    printf("Diferentes\n");
  }
  return 0;
}

