#include <stdio.h>
#include <stdlib.h>

int comparar(char texto[100], char texto2[100]){
  int valor_igual = 0, tamanho = 0;
  for(int i = 0;texto[i]!='\0';i++){
    tamanho += 1;
    if (texto[i] == texto2[i]) {
      valor_igual += 1;
      printf("%c\n",texto[i]);
    }
  }
  if (valor_igual == tamanho) {
    return 1;

  } else {
    return 0;
  }
}

int main() {
  char str[100];
  scanf("%s",str);
  int total = 0;
  for (int i = 0;str[i]!='\0';i++){
    if (str[i] == '1'){
      total += 1;
    }
  }

  printf("%d.\n",total);
  
  return 0;
}

