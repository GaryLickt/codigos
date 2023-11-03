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
  fgets(str,100,stdin);
  char carater;
  scanf("%c",&carater);
  int total = 0;
  for(int i = 0;str[i]!='\0';i++){
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
      str[i] = carater;
      total += 1;
    }else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
      str[i] = carater;
      total += 1;
    }
  }
  printf("Total de vogais: %d\n",total);
  printf("String alterada: %s\n",str);
  return 0;
}

