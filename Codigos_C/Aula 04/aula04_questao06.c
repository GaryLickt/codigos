#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Digite um numero inteiro: ");
  scanf("%d",&n);

  if (n%2 == 0){
    printf("%d é um numero par\n",n);
  }else{
    printf("%d é um numero impar\n",n);
  }

  return 0;
}