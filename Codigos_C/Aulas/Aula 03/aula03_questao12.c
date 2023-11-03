// 12. Peça ao usuário que digite o seu nome e o seu sobrenome. Em seguida, exiba o nome completo invertido (sobrenome, nome).
#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Digite seu primeiro nome\n");
    char x[20];
    char z[20];
    scanf("%s",&x);
  printf("Digite seu segundo nome\n");
    scanf("%s",&z);
    printf("Seu nome ao contrario é %s %s!\n",z,x);
  return 0;
}
