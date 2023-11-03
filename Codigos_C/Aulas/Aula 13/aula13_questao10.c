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

int pegarTamanho(char texto[100]){
  int tamanho = 0;
  for (int i = 0;texto[i]!='\0';i++){
    tamanho += 1;
  }
  return tamanho-1;
}

int main() {
  char str[100];
  char str2[100];
  scanf("%s",str);

  int rob = pegarTamanho(str);
  for (int i = rob;i>=0;i--){
    str2[rob-i] = str[i];
  }
  printf("%s.\n",str2);
  return 0;
}

