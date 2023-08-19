// 8. Peça ao usuário que insira o seu ano de nascimento e, em seguida, exiba a sua idade.
#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Digite seu ano de nascimento\n");
    int x;
    int z;
    scanf("%d",&x);
    z = 2023-x;
    printf("Você tem %d anos!\n",z);
  return 0;
}
