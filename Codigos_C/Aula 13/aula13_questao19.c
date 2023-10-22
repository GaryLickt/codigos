#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100],nomeMaisJovem[50],nomeMaisVelha[50];

  int idade,idadeMaisJovem = 1000,idadeMaisVelha = 0;

  while (1) {
      
    printf("Digite a idade (ou um número negativo para encerrar): ");
    scanf("%d", &idade);

      
    if (idade < 0) {
      break;
    }

    printf("Digite o primeiro nome: ");
    scanf("%s", str);
  
      
    if (idade < idadeMaisJovem) {
      idadeMaisJovem = idade;
      strcpy(nomeMaisJovem, str);
    }

     
    if (idade > idadeMaisVelha) {
      idadeMaisVelha = idade;
      strcpy(nomeMaisVelha, str);
    }
  }

  // Imprime os resultados
  if (idadeMaisJovem != 1000) {
    printf("Pessoa mais jovem: %s, idade: %d anos\n", nomeMaisJovem, idadeMaisJovem);
  } else {
    printf("Nenhuma pessoa foi inserida.\n");
  }

  if (idadeMaisVelha != 0) {
    printf("Pessoa mais velha: %s, idade: %d anos\n", nomeMaisVelha, idadeMaisVelha);
  } else {
    printf("Nenhuma pessoa foi inserida.\n");
  }
  return 0;
}

