#include <stdio.h>
#include <stdlib.h>

int comparar(char texto[100], char texto2[100]){
  int valor_igual = 0, tamanho = 0;
  for(int i = 0;texto[i]!='\0';i++){
    tamanho += 1;
    if (texto[i] == texto2[i]) {
      valor_igual += 1;
    }
  }
  if (valor_igual == tamanho) {
    return 1;

  } else {
    return 0;
  }
}

int repetir(char texto[100], char caractere){
  int valor_igual = 0;
  for(int i = 0;texto[i]!='\0';i++){
    if (texto[i] == caractere) {
      valor_igual += 1;
    }
  }
  return valor_igual;
}

void substituir(char texto[100], char caractere, char caractere2){
  for(int i = 0;texto[i]!='\0';i++){
    if (texto[i] == caractere) {
      texto[i] = caractere2;
      break;
    }
  }

  for(int i = 0;texto[i]!='\0';i++){
    printf("%c",texto[i]);
  }
  printf("\n");
}

void criarSubstring(char texto[100], int posicao, int tamanho){
  for (int i = posicao;i<tamanho;i++){
    printf("%c",texto[i]);
  }
  printf("\n");
}

int pegarTamanho(char texto[100]){
  int tamanho = 0;
  for (int i = 0;texto[i]!='\0';i++){
    tamanho += 1;
  }
  return tamanho-1;
}

void InverterIGuardar(char texto[100]){
  int rob = pegarTamanho(texto);
  char subs[100];
  for (int i = rob;i>=0;i--){
    subs[rob-i] = texto[i];
    printf("%c",subs[rob-i]);
  }
  printf("\n");
}

int verificaSubstring(char *str1, char *str2) {
  int tamanho1 = strlen(str1);
  int tamanho2 = strlen(str2);

  if (tamanho2 > tamanho1) {
      return 0;
  }

  return strcmp(str1 + tamanho1 - tamanho2, str2) == 0;
}

int main() {
  printf("=== Menu Inicial: ===\n> Escolha uma das opções abaixo:\n");
  printf("[a].Ler uma string S1 (tamanho máximo 20 caracteres)\n[b].Imprimir o tamanho da string S1\n[c].Comparar a string S1 com uma nova string S2 e imprimir o resultado\n[d].Concatenar a string S1 com uma nova string S2 e imprimir o resultado\n[e].Imprimir a string S1 de forma reversa\n[f].Contar quantas vezes um dado caractere aparece na string S1\n[g].Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2.\n[h].Verificar se uma string S2 e substring de S1.\n[i].Retornar uma substring da string S1.\n\n");
  
  char letra,S1[20],S2[20];
  char C1,C2;
  int valor,pos,big;
    scanf(" %c",&letra);
    switch(letra){
      case 'a': printf("Digite a String S1:\n");scanf("%s",S1);break;
      
      case 'b': printf("Digite a String S1:\n");scanf("%s",S1);valor = pegarTamanho(S1);printf("O Tamanho da String S1 eh: %d.\n",valor);break;
      
      case 'c': printf("Digite a String S1:\n");scanf("%s",S1);printf("Digite a String S2:\n");scanf(" %s",S2);valor = comparar(S1,S2);if(valor == 1){
      printf("S1 e S2 são Iguais.\n");
      }else{
        printf("S1 e S2 são Diferentes.\n");
      };break;
      
      case 'd': printf("Digite a String S1:\n");scanf("%s",S1);printf("Digite a String S2:\n");scanf(" %s",S2);printf("O Resultado da concatenação eh '%s'",strcat(S1,S2));break;
      
      case 'e': printf("Digite a String S1:\n");scanf("%s",S1);printf("A string S1 reversa fica:\n");InverterIGuardar(S1);break;
      
      case 'f': printf("Digite a String S1:\n");scanf("%s",S1);printf("Digite o Caractere C1:\n");scanf(" %c",&C1);valor = repetir(S1,C1);printf("O Caractere '%c' se repete %d vez(es) na string S1.\n",C1,valor);break;
      
      case 'g': printf("Digite a String S1:\n");scanf("%s",S1);printf("Digite o Caractere C1:\n");scanf(" %c",&C1);printf("Digite o Caractere C2:\n");scanf(" %c",&C2);printf("A string S1 com o Caractere C1 substituido por C2 fica:\n");substituir(S1,C1,C2);break;

      case 'h': printf("Digite a String S1:\n");scanf("%s",S1);printf("Digite a String S2:\n");scanf(" %s",S2);if (verificaSubstring(S1,S2)){
        printf("A String S2 eh substring de S1.\n");
      
      }else{
        printf("A String S2 nao eh substring de S1.\n");
      };break;
      case 'i': printf("Digite a String S1:\n");scanf("%s",S1);printf("Digite a posição da Substring\n");scanf("%d",&pos);printf("Digite o tamanho da Substring\n");scanf("%d",&big);printf("A Substring criada eh:\n");criarSubstring(S1,pos,big);break;
  }
  return 0;
}

