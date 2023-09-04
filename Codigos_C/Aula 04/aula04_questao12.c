#include <stdio.h>
#include <stdlib.h>

int main() {
  int mes;
  printf("Digite um numero de 1 a 12: ");
  scanf("%d",&mes);
  switch(mes){
    case 1: printf("o mês 1 é o mês de Janeiro.\n");break;
    case 2: printf("o mês 2 é o mês de Fevereiro.\n");break;
    case 3: printf("o mês 3 é o mês de Março.\n");break;
    case 4: printf("o mês 4 é o mês de Abril.\n");break;
    case 5: printf("o mês 5 é o mês de Maio.\n");break;
    case 6: printf("o mês 6 é o mês de Junho.\n");break;
    case 7: printf("o mês 7 é o mês de Julho.\n");break;
    case 8: printf("o mês 8 é o mês de Agosto.\n");break;
    case 9: printf("o mês 9 é o mês de Setembro.\n");break;
    case 10: printf("o mês 10 é o mês de Outubro.\n");break;
    case 11: printf("o mês 11 é o mês de Novembro.\n");break;
    case 12: printf("o mês 12 é o mês de Dezembro.\n");break;
    default: printf("esse numero não esta entre 1 e 12.\n");
  }
  return 0;
}