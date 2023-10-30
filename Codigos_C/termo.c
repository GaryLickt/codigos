#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void escolherPalavras(char* palavra, char* palavra2, char* palavra3){
  int chanc = rand() % 51;
  int chanc2 = rand() % 51;
  int chanc3 = rand() % 51;

  switch(chanc){
    case 0: strcpy(palavra, "REZAR");break;
    case 1: strcpy(palavra, "FEIRA");break;
    case 2: strcpy(palavra, "LEITE");break;
    case 3: strcpy(palavra, "CARRO");break;
    case 4: strcpy(palavra, "FAVOR");break;
    case 5: strcpy(palavra, "CUSTO");break;
    case 6: strcpy(palavra, "TEMPO");break;
    case 7: strcpy(palavra, "GOSTO");break;
    case 8: strcpy(palavra, "NAVIO");break;
    case 9: strcpy(palavra, "BARCO");break;
    case 10: strcpy(palavra, "DOIDO");break;

    case 11: strcpy(palavra, "LOUCO");break;
    case 12: strcpy(palavra, "EPICO");break;
    case 13: strcpy(palavra, "VASCO");break;
    case 14: strcpy(palavra, "AMIGO");break;
    case 15: strcpy(palavra, "COISA");break;
    case 16: strcpy(palavra, "BANCO");break;
    case 17: strcpy(palavra, "BAHIA");break;
    case 18: strcpy(palavra, "MARCO");break;
    case 19: strcpy(palavra, "GENTE");break;
    case 20: strcpy(palavra, "PEDIR");break;

    case 21: strcpy(palavra, "SANTO");break;
    case 22: strcpy(palavra, "POBRE");break;
    case 23: strcpy(palavra, "AJUDA");break;
    case 24: strcpy(palavra, "LUTAR");break;
    case 25: strcpy(palavra, "CRIAR");break;
    case 26: strcpy(palavra, "GESTO");break;
    case 27: strcpy(palavra, "VERBO");break;
    case 28: strcpy(palavra, "GRANA");break;
    case 29: strcpy(palavra, "TROCA");break;
    case 30: strcpy(palavra, "FREVO");break;

    case 31: strcpy(palavra, "SAGAZ");break;
    case 32: strcpy(palavra, "NEGRO");break;
    case 33: strcpy(palavra, "TERMO");break;
    case 34: strcpy(palavra, "MEXER");break;
    case 35: strcpy(palavra, "SENSO");break;
    case 36: strcpy(palavra, "NOBRE");break;
    case 37: strcpy(palavra, "SUTIL");break;
    case 38: strcpy(palavra, "ASSIM");break;
    case 39: strcpy(palavra, "MORAL");break;
    case 40: strcpy(palavra, "CARNE");break;

    case 41: strcpy(palavra, "ANEXO");break;
    case 42: strcpy(palavra, "SONHO");break;
    case 43: strcpy(palavra, "EXPOR");break;
    case 44: strcpy(palavra, "AMIGO");break;
    case 45: strcpy(palavra, "PESAR");break;
    case 46: strcpy(palavra, "SABER");break;
    case 47: strcpy(palavra, "CAUSA");break;
    case 48: strcpy(palavra, "COMUM");break;
    case 49: strcpy(palavra, "DIGNO");break;
    case 50: strcpy(palavra, "MUNDO");break;
  }
  
  switch(chanc2){
    case 0: strcpy(palavra2, "REZAR");break;
    case 1: strcpy(palavra2, "FEIRA");break;
    case 2: strcpy(palavra2, "LEITE");break;
    case 3: strcpy(palavra2, "CARRO");break;
    case 4: strcpy(palavra2, "FAVOR");break;
    case 5: strcpy(palavra2, "CUSTO");break;
    case 6: strcpy(palavra2, "TEMPO");break;
    case 7: strcpy(palavra2, "GOSTO");break;
    case 8: strcpy(palavra2, "NAVIO");break;
    case 9: strcpy(palavra2, "BARCO");break;
    case 10: strcpy(palavra2, "DOIDO");break;

    case 11: strcpy(palavra2, "LOUCO");break;
    case 12: strcpy(palavra2, "EPICO");break;
    case 13: strcpy(palavra2, "VASCO");break;
    case 14: strcpy(palavra2, "AMIGO");break;
    case 15: strcpy(palavra2, "COISA");break;
    case 16: strcpy(palavra2, "BANCO");break;
    case 17: strcpy(palavra2, "BAHIA");break;
    case 18: strcpy(palavra2, "MARCO");break;
    case 19: strcpy(palavra2, "GENTE");break;
    case 20: strcpy(palavra2, "PEDIR");break;

    case 21: strcpy(palavra2, "SANTO");break;
    case 22: strcpy(palavra2, "POBRE");break;
    case 23: strcpy(palavra2, "AJUDA");break;
    case 24: strcpy(palavra2, "LUTAR");break;
    case 25: strcpy(palavra2, "CRIAR");break;
    case 26: strcpy(palavra2, "GESTO");break;
    case 27: strcpy(palavra2, "VERBO");break;
    case 28: strcpy(palavra2, "GRANA");break;
    case 29: strcpy(palavra2, "TROCA");break;
    case 30: strcpy(palavra2, "FREVO");break;

    case 31: strcpy(palavra2, "SAGAZ");break;
    case 32: strcpy(palavra2, "NEGRO");break;
    case 33: strcpy(palavra2, "TERMO");break;
    case 34: strcpy(palavra2, "MEXER");break;
    case 35: strcpy(palavra2, "SENSO");break;
    case 36: strcpy(palavra2, "NOBRE");break;
    case 37: strcpy(palavra2, "SUTIL");break;
    case 38: strcpy(palavra2, "ASSIM");break;
    case 39: strcpy(palavra2, "MORAL");break;
    case 40: strcpy(palavra2, "CARNE");break;

    case 41: strcpy(palavra2, "ANEXO");break;
    case 42: strcpy(palavra2, "SONHO");break;
    case 43: strcpy(palavra2, "EXPOR");break;
    case 44: strcpy(palavra2, "AMIGO");break;
    case 45: strcpy(palavra2, "PESAR");break;
    case 46: strcpy(palavra2, "SABER");break;
    case 47: strcpy(palavra2, "CAUSA");break;
    case 48: strcpy(palavra2, "COMUM");break;
    case 49: strcpy(palavra2, "DIGNO");break;
    case 50: strcpy(palavra2, "MUNDO");break;
  }
  
  switch(chanc3){
    case 0: strcpy(palavra3, "REZAR");break;
    case 1: strcpy(palavra3, "FEIRA");break;
    case 2: strcpy(palavra3, "LEITE");break;
    case 3: strcpy(palavra3, "CARRO");break;
    case 4: strcpy(palavra3, "FAVOR");break;
    case 5: strcpy(palavra3, "CUSTO");break;
    case 6: strcpy(palavra3, "TEMPO");break;
    case 7: strcpy(palavra3, "GOSTO");break;
    case 8: strcpy(palavra3, "NAVIO");break;
    case 9: strcpy(palavra3, "BARCO");break;
    case 10: strcpy(palavra3, "DOIDO");break;

    case 11: strcpy(palavra3, "LOUCO");break;
    case 12: strcpy(palavra3, "EPICO");break;
    case 13: strcpy(palavra3, "VASCO");break;
    case 14: strcpy(palavra3, "AMIGO");break;
    case 15: strcpy(palavra3, "COISA");break;
    case 16: strcpy(palavra3, "BANCO");break;
    case 17: strcpy(palavra3, "BAHIA");break;
    case 18: strcpy(palavra3, "MARCO");break;
    case 19: strcpy(palavra3, "GENTE");break;
    case 20: strcpy(palavra3, "PEDIR");break;

    case 21: strcpy(palavra3, "SANTO");break;
    case 22: strcpy(palavra3, "POBRE");break;
    case 23: strcpy(palavra3, "AJUDA");break;
    case 24: strcpy(palavra3, "LUTAR");break;
    case 25: strcpy(palavra3, "CRIAR");break;
    case 26: strcpy(palavra3, "GESTO");break;
    case 27: strcpy(palavra3, "VERBO");break;
    case 28: strcpy(palavra3, "GRANA");break;
    case 29: strcpy(palavra3, "TROCA");break;
    case 30: strcpy(palavra3, "FREVO");break;

    case 31: strcpy(palavra3, "SAGAZ");break;
    case 32: strcpy(palavra3, "NEGRO");break;
    case 33: strcpy(palavra3, "TERMO");break;
    case 34: strcpy(palavra3, "MEXER");break;
    case 35: strcpy(palavra3, "SENSO");break;
    case 36: strcpy(palavra3, "NOBRE");break;
    case 37: strcpy(palavra3, "SUTIL");break;
    case 38: strcpy(palavra3, "ASSIM");break;
    case 39: strcpy(palavra3, "MORAL");break;
    case 40: strcpy(palavra3, "CARNE");break;

    case 41: strcpy(palavra3, "ANEXO");break;
    case 42: strcpy(palavra3, "SONHO");break;
    case 43: strcpy(palavra3, "EXPOR");break;
    case 44: strcpy(palavra3, "AMIGO");break;
    case 45: strcpy(palavra3, "PESAR");break;
    case 46: strcpy(palavra3, "SABER");break;
    case 47: strcpy(palavra3, "CAUSA");break;
    case 48: strcpy(palavra3, "COMUM");break;
    case 49: strcpy(palavra3, "DIGNO");break;
    case 50: strcpy(palavra3, "MUNDO");break;
  }
  
}

int main() {
  char palavra[7], palavraCriada[7],palavraDada[7],novamente,outro_modo;
  char palavra2[7], palavra2Criada[7],palavra2Dada[7];
  char palavra3[7], palavra3Criada[7],palavra3Dada[7];
  int i, j, tentativas = 0, acertos = 0,acertou = 0,denovo = 0,chances = 6,partidas=1,modo_jogo=0;
  srand(time(NULL));

  printf("Qual Modo de jogo deseja jogar?\n(0 - Solo / 1 - Duo / 2 - Trio)\n(3 - Hardcore WIP / 4 - Anagrama WIP)\n> ");
  scanf("%d",&modo_jogo);
  while(denovo == 0) {
    strcpy(palavraCriada, "#####");
    strcpy(palavra2Criada, "#####");
    strcpy(palavra3Criada, "#####");

    escolherPalavras(palavra,palavra2,palavra3);

    if (modo_jogo == 0) {
      printf("TERMO 2: C Edition\nModo: Solo\n\n");
      while(acertou == 0 && chances > 0){
        printf("%d tentativa(s) restante(s).\n",chances);
        printf("PALAVRA: %s\n> ",palavraCriada);
        scanf(" %s", palavraDada);
        while(strlen(palavraDada) != 5){
          if (strlen(palavraDada) < 5){
            printf("palavra muito pequena.\n> ");
            getchar();
            scanf(" %s", palavraDada);
          }else if (strlen(palavraDada) > 5){
            printf("palavra muito grande.\n> ");
            getchar();
            scanf(" %s", palavraDada);
          }
          
        }
        tentativas += 1;
        chances -= 1;
  
        for(int i = 0;palavra[i]!='\0';i++){
          int valor = palavra[i];
          int valorDado = palavraDada[i];
  
          if (valorDado > 96 && valorDado < 123){
            valorDado -= 32;
          }
          if(valor == valorDado){
            palavraCriada[i] = palavra[i];
          }else{
            if (palavraCriada[i] == '?'){
              palavraCriada[i] = '#';
            }
            for(int j = 0;palavra[j]!='\0';j++){
              int valor2 = palavra[j];
              if (valor2 == valorDado && palavraCriada[i] != palavra[i]) {
                palavraCriada[i] = '?';
              }
            }
          }
        }
        if (strcmp(palavra, palavraCriada) == 0){
          printf("\nParabéns, você acertou!\n");
          acertou = 1;
          acertos += 1;
        }else if (chances <= 0){
          printf("\nQue pena, você perdeu! a palavra certa era '%s'\n",palavra);
        }
        getchar();
      }
    }else if (modo_jogo == 1) {
        printf("TERMO 2: C Edition\nModo: Duo\n\n");
        chances = 9;
        while(acertou == 0 && chances > 0){
          printf("%d tentativa(s) restante(s).\n",chances);
          printf("PALAVRAS: %s  %s\n> ",palavraCriada,palavra2Criada);
          scanf(" %s", palavraDada);
          while(strlen(palavraDada) != 5){
            if (strlen(palavraDada) < 5){
              printf("palavra muito pequena.\n> ");
              getchar();
              scanf(" %s", palavraDada);
            }else if (strlen(palavraDada) > 5){
              printf("palavra muito grande.\n> ");
              getchar();
              scanf(" %s", palavraDada);
            }

          }
          printf("\n");
          tentativas += 1;
          chances -= 1;

          for(int i = 0;palavra[i]!='\0';i++){
            int valor = palavra[i];
            int valor2 = palavra2[i];
            int valorDado = palavraDada[i];

            if (valorDado > 96 && valorDado < 123){
              valorDado -= 32;
            }
            // Checa a primeira palavra
            if(valor == valorDado){
              palavraCriada[i] = palavra[i];
            }else{
              if (palavraCriada[i] == '?'){
                palavraCriada[i] = '#';
              }
              for(int j = 0;palavra[j]!='\0';j++){
                int valor2 = palavra[j];
                if (valor2 == valorDado && palavraCriada[i] != palavra[i]) {
                  palavraCriada[i] = '?';
                }
              }
            }
            // Checa a segunda palavra
            if(valor2 == valorDado){
              palavra2Criada[i] = palavra2[i];
            }else{
              if (palavra2Criada[i] == '?'){
                palavra2Criada[i] = '#';
              }
              for(int j = 0;palavra2[j]!='\0';j++){
                int valor2 = palavra2[j];
                if (valor2 == valorDado && palavra2Criada[i] != palavra2[i]) {
                  palavra2Criada[i] = '?';
                }
              }
            }
          }
          if (strcmp(palavra, palavraCriada) == 0 && strcmp(palavra2, palavra2Criada) == 0){
            printf("\nParabéns, você acertou!\n");
            acertou = 1;
            acertos += 2;
          }else if (chances <= 0){
            printf("\nQue pena, você perdeu! as palavras certas eram '%s' e '%s'\n",palavra,palavra2);
          }
          getchar();
        }
    }else if (modo_jogo == 2) {
        printf("TERMO 2: C Edition\nModo: Trio\n\n");
      chances = 12;
      while(acertou == 0 && chances > 0){
        printf("%d tentativa(s) restante(s).\n",chances);
        printf("PALAVRAS: %s  %s  %s\n> ",palavraCriada,palavra2Criada,palavra3Criada);
        scanf(" %s", palavraDada);
        while(strlen(palavraDada) != 5){
          if (strlen(palavraDada) < 5){
            printf("palavra muito pequena.\n> ");
            getchar();
            scanf(" %s", palavraDada);
          }else if (strlen(palavraDada) > 5){
            printf("palavra muito grande.\n> ");
            getchar();
            scanf(" %s", palavraDada);
          }

        }
        printf("\n");
        tentativas += 1;
        chances -= 1;

        for(int i = 0;palavra[i]!='\0';i++){
          int valor = palavra[i];
          int valor2 = palavra2[i];
          int valor3 = palavra3[i];
          int valorDado = palavraDada[i];

          if (valorDado > 96 && valorDado < 123){
            valorDado -= 32;
          }
          // Checa a primeira palavra
          if(valor == valorDado){
            palavraCriada[i] = palavra[i];
          }else{
            if (palavraCriada[i] == '?'){
              palavraCriada[i] = '#';
            }
            for(int j = 0;palavra[j]!='\0';j++){
              int valor2 = palavra[j];
              if (valor2 == valorDado && palavraCriada[i] != palavra[i]) {
                palavraCriada[i] = '?';
              }
            }
          }
          // Checa a segunda palavra
          if(valor2 == valorDado){
            palavra2Criada[i] = palavra2[i];
          }else{
            if (palavra2Criada[i] == '?'){
              palavra2Criada[i] = '#';
            }
            for(int j = 0;palavra2[j]!='\0';j++){
              int valor2 = palavra2[j];
              if (valor2 == valorDado && palavra2Criada[i] != palavra2[i]) {
                palavra2Criada[i] = '?';
              }
            }
          }
          // Checa a terceira palavra
          if(valor3 == valorDado){
            palavra3Criada[i] = palavra3[i];
          }else{
            if (palavra3Criada[i] == '?'){
              palavra3Criada[i] = '#';
            }
            for(int j = 0;palavra3[j]!='\0';j++){
              int valor3 = palavra3[j];
              if (valor3 == valorDado && palavra3Criada[i] != palavra2[i]) {
                palavra3Criada[i] = '?';
              }
            }
          }
        }
        if (strcmp(palavra, palavraCriada) == 0 && strcmp(palavra2, palavra2Criada) == 0 && strcmp(palavra3, palavra3Criada) == 0){
          printf("\nParabéns, você acertou!\n");
          acertou = 1;
          acertos += 3;
        }else if (chances <= 0){
          printf("\nQue pena, você perdeu! as palavras certas eram '%s', '%s' e '%s'\n",palavra,palavra2,palavra3);
        }
        getchar();
      }
    }
    printf("Deseja jogar novamente? (s/n)\n");
    scanf(" %c",&novamente);
    if (novamente == 's'){
      denovo = 0;
      acertou = 0;
      chances = 6;
      partidas+=1;
      printf("Deseja trocar o modo de jogo? (s/n)\n");
      scanf(" %c",&outro_modo);
      if (outro_modo == 's'){
        printf("Qual Modo de jogo deseja jogar agora?\n(0 - Solo / 1 - Duo / 2 - Trio)\n(3 - Hardcore WIP / 4 - Anagrama WIP)\n> ");
        scanf("%d",&modo_jogo);
      }
      
    }else{
      denovo = 1;
    }
    getchar();

  }
  if (acertos > 0) {
  printf("\nVocê acertou %d palavras de %d jogos.\n", acertos, partidas);
  }else{
    printf("\nQue pena. você não acertou nenhuma palavra!\n");
  }

  return 0;
}

