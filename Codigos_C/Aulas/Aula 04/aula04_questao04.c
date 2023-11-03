#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Digite sua idade: ");
  scanf("%d",&n);

  if (n < 18){
    printf("Voce eh menor de idade!\n");
  }else{
    printf("Você ja eh maior de idade!\n");
  }
  return 0;
}