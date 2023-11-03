#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Digite um numero inteiro: ");
  scanf("%d",&n);

  if (n>0) {
    printf("%d eh um numero positivo.\n",n);
  }else if (n == 0){
    printf("%d eh igual a 0.\n",n);
  }else{
    printf("%d eh um numero negativo",n);
  }
  return 0;
}