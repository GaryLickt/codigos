#include <stdio.h>
#include <stdlib.h>

int main() {
  char c = 'a';
  char *pc = &c;

  printf("\n");
  printf("a) o endereço de c: %p\no valor guardado em c: %c\n",&c,c);
  printf("\n");
  printf("b) o valor que pc armazena: %p\no valor guardado em seu endereço: %c\n",pc,*pc);
  printf("\n");
  printf("c) o endereço de pc: %p\n",&pc);
  return 0;
}