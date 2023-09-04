#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Digite um numero inteiro: ");
  scanf("%d",&n);
  if (n > 10){
    printf("O numero %d é maior que 10\n",n);
  }else if (n == 10){
    printf("O numero %d é igual a 10\n",n);
  }else{
    printf("O numero %d é menor que 10\n",n);
  }
  return 0;
}