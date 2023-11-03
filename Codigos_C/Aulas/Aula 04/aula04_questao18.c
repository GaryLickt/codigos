#include <stdio.h>
#include <stdlib.h>

int main() {
  int x;
  printf("Digite quantos anos você tem: ");
  scanf("%d",&x);

  if (x==0 || x==1){
    printf("Você ainda é um bebê.\n");
  }else if (x > 1 && x <= 12) {
    printf("Você ainda é uma criança.\n");
  }else if (x > 13 && x <= 18) {
    printf("Você ainda é um adolescente.\n");
  }else{
    printf("Você ja é um adulto.\n");
  }

  return 0;
}