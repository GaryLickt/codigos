#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  char palavra[7], palavraCriada[7],palavraDada[7],novamente;
  int i, j, tentativas = 0, acertos = 0,acertou = 0,denovo = 0,chances = 6,partidas=1;
  srand(time(NULL));

  while(denovo == 0) {
    int chanc = rand() % 51;
    strcpy(palavraCriada, "#####");

    // Aconselho deixar isso fechado-
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

    printf("TERMO 2: Aventuras no seu C#\n\n");
    while(acertou == 0 && chances > 0){
      printf("%d tentativa(s) restante(s).\n",chances);
      printf("PALAVRA: %s\n> ",palavraCriada);
      scanf("%s", palavraDada);
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
          for(int j = 0;palavra[j]!='\0';j++){
            int valor2 = palavra[j];
            if (valor2 == valorDado && palavraCriada[j] != palavra[j]) {
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
    
    printf("Deseja jogar novamente? (s/n)\n");
    scanf(" %c",&novamente);
    if (novamente == 's'){
      denovo = 0;
      acertou = 0;
      chances = 6;
      partidas+=1;
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

