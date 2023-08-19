// 37. Peça ao usuário para digitar a sua idade e, em seguida, informe quantos meses e quantos dias ele já viveu (considerando um ano com 365 dias).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x;
  printf("Digite sua idade (em anos):\n");
  scanf("%d",&x);
  int meses = 12 * x;
  int dias = 365 * x;
  printf("Parabens! você ja viveu %d dias e %d meses!\n",dias,meses);
  return 0;
}
