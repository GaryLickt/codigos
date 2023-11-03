// 9. Peça ao usuário que digite seu primeiro nome e seu sobrenome separadamente. Em seguida, concatene-os em uma única string e exiba o nome completo.
#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Digite seu primeiro nome\n");
    char x[20];
    char z[20];
    scanf("%s",&x);
  printf("Digite seu segundo nome\n");
    scanf("%s",&z);
    printf("Seu nome é %s %s!\n",x,z);
  return 0;
}
