// 21. Peça ao usuário que digite a sua cidade e verifique se ela começa com a letra "S" (ou outra letra de sua escolha).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char cidade[20];
  char letraDesejada = 'S';
  char letradesejada = 's';
  printf("Digite sua cidade:\n");
  scanf("%s",&cidade);
  if (cidade[0] == letraDesejada || cidade[0] == letradesejada){
    printf("Sua cidade começa com S\n");
  }else{
    printf("Sua cidade não começa com S\n");
  }
  return 0;
}
