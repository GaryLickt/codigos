// 6. Peça ao usuário para digitar dois números inteiros e exiba a soma deles.
#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Digite 2 numeros inteiros\n");
    int x;
    int y;
    int z;
    scanf("%d %d",&x,&y);
    z = x + y;
    printf("A soma de %d + %d é igual a %d\n",x,y,z);
  return 0;
}
