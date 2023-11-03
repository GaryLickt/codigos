#include <stdio.h>
#include <stdlib.h>

int main() {
  int a,b,operador;
  printf("Qual operação vamos fazer hoje?\n(1 - adição)\n(2 - subtração)\n(3 - multiplicação)\n(4 - divisão)\n");
  scanf("%d",&operador);
  printf("Digite um Numero Inteiro: ");
  scanf("%d",&a);
  printf("Digite outro Numero Inteiro: ");
  scanf("%d",&b);
  switch(operador){
    case 1: printf("%d + %d = %d\n",a,b,a+b);break;
    case 2: printf("%d - %d = %d\n",a,b,a-b);break;
    case 3: printf("%d * %d = %d\n",a,b,a*b);break;
    case 4: printf("%d / %d = %d\n",a,b,a/b);break;
  }
  return 0;
}