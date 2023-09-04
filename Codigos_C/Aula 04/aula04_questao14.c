#include <stdio.h>
#include <stdlib.h>

int main() {
  int x;
  printf("Digite um numero inteiro: ");
  scanf("%d",&x);

  if (x%3 == 0 && x%5 == 0){
    printf("%d é divisivel por 3 e por 5 ao mesmo tempo.\n",x);
  }else{
    printf("%d não é divisivel por 3 e por 5 ao mesmo tempo.\n",x);
  }
  return 0;
}