#include <stdio.h>
#include <stdlib.h>

int main() {
  int x;
  printf("Digite um numero entre 1 e 5: ");
  scanf("%d",&x);
  switch(x){
    case 1: printf("Muito insuficiente.\n");break;
    case 2: printf("Insuficiente.\n");break;
    case 3: printf("Regular.\n");break;
    case 4: printf("Bom.\n");break;
    case 5: printf("Muito bom.\n");break;
  }
  return 0;
}