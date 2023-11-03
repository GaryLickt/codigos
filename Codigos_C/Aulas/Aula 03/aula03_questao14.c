// 14. Solicite ao usuário um número inteiro e exiba se ele é par ou ímpar.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  printf("Digite um numero:\n");
  scanf("%d",&n);
  int check = n%2;
  if (check == 0) {
    printf("O numero %d é par\n",n);
  }else{
    printf("O numero %d é impar\n",n);
  }
  return 0;
}
