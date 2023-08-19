// 26. Receba o nome de uma cidade do usuário e concatene-o com o nome do estado para formar uma mensagem completa, como "Você mora em [cidade], [estado].".
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char cidade[20], estado[20];
  printf("Digite sua cidade:\n");
  scanf("%s",&cidade);
  printf("Digite seu estado:\n");
  scanf("%s",&estado);
  printf("Você mora em %s, %s.\n",cidade,estado);
  return 0;
}
