#include <stdio.h>
#include <stdlib.h>

int main() {
  int a,b;
  printf("-- Gerador de Matriz Identidade --\n");
  printf("Digite as dimensões de uma matriz qualquer:\n");
  scanf("%d %d",&a,&b);
  printf("\n");
  printf("Aqui está uma matriz identidade %dx%d\n",a,b);
  for (int x = 0;x<a;x++){
    for (int y = 0;y<b;y++){
      if (x==y) {
        printf("1. ");
      }else{
        printf("0. ");
      }
    }
    printf("\n");
  
  }
  if (a != b) {
    printf("\n");
    printf("Note que a diagonal principal da matriz %dx%d não esta completa.\npois, a matriz não é quadrada.\n",a,b);
  }
  return 0;
}
