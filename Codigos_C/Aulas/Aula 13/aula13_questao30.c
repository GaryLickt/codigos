#include <stdio.h>
#include <stdlib.h>

int main() {
  char nomes[5][50];
  char nomeBusca[50];
  int numAlunos = 0;

  printf("Digite os nomes dos alunos (limite de %d alunos).\n", 5);
  while (numAlunos < 5) {
      printf("Nome do aluno %d: ", numAlunos + 1);
      fgets(nomes[numAlunos], 50, stdin);

      size_t len = strlen(nomes[numAlunos]);
      if (len > 0 && nomes[numAlunos][len - 1] == '\n') {
          nomes[numAlunos][len - 1] = '\0';
      }

      printf("Deseja adicionar mais um aluno? (S/N): ");
      char resposta;
      scanf(" %c", &resposta);

      if (resposta != 'S' && resposta != 's') {
          break;
      }

      while (getchar() != '\n');

      numAlunos++;
  }

  printf("\nDigite o nome (ou parte do nome) a ser buscado: ");
  scanf(" %s",nomeBusca);

  size_t len = strlen(nomeBusca);
  if (len > 0 && nomeBusca[len - 1] == '\n') {
      nomeBusca[len - 1] = '\0';
  }

  int encontrado = 0;
  for (int i = 0; i < numAlunos; i++) {
      if (strstr(nomes[i], nomeBusca) != NULL) {
          printf("Nome encontrado: %s (Índice: %d)\n", nomes[i], i);
          encontrado = 1;
      }
  }

  if (!encontrado) {
      printf("Nome não encontrado na lista.\n");
  }
  return 0;
}

