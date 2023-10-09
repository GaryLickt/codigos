#include <stdio.h>
#include <stdlib.h>

int main() {
  int mt1[2][2];
  int mt2[2][2];

  // Setando valores aleatorios nas 2 matrizes
  for (int i = 0;i<2;i++){
    for (int j = 0;j<2;j++){
      mt1[i][j] = rand()%34; 
      //numeros colocados de forma aleatoria, não a nenhum motivo especifico para a escolha de 34 e 73
      mt2[i][j] = rand()%73;
    }
  }
  // Pegando a opção do usuario
  char entrada;
  int evento = 0;
  printf("Bem-vindo(a)! Escolha uma das alternativas abaixo:\n[A]. Somar matrizes.\n[B]. Subtrair a primeira matriz da segunda.\n[C]. Adicionar uma costante as duas matrizes.\n[D]. Imprimir matrizes.\n(Favor escrever exatamente como esta dentro dos colchetes)\n");
  scanf("%c",&entrada);
  switch(entrada){
    case 'A': evento = 1;break;
    case 'B': evento = 2;break;
    case 'C': evento = 3;break;
    case 'D': evento = 4;break;
    default: printf("Opção Inexistente.\n");
  }

  if (evento == 1){
    int mt3[2][2];

    for (int i = 0;i<2;i++){
      for (int j = 0;j<2;j++){
        mt3[i][j] = mt1[i][j] + mt2[i][j];
      }
    }

    printf("| %d %d | + | %d %d | = | %d %d |\n",mt1[0][0],mt1[0][1],mt2[0][0],mt2[0][1],mt3[0][0],mt3[0][1]);
    printf("| %d %d |   | %d %d |   | %d %d |\n",mt1[1][0],mt1[1][1],mt2[1][0],mt2[1][1],mt3[1][0],mt3[1][1]);
    
  }else if (evento == 2){
    int mt3[2][2];

    for (int i = 0;i<2;i++){
      for (int j = 0;j<2;j++){
        mt3[i][j] = mt2[i][j] - mt1[i][j];
      }
    }

    printf("| %d %d | - | %d %d | = | %d %d |\n",mt2[0][0],mt2[0][1],mt1[0][0],mt1[0][1],mt3[0][0],mt3[0][1]);
    printf("| %d %d |   | %d %d |   | %d %d |\n",mt2[1][0],mt2[1][1],mt1[1][0],mt1[1][1],mt3[1][0],mt3[1][1]);
  }else if (evento == 3){
    int k;
    printf("Qual a constante a ser usada?\n");
    scanf("%d",&k);
    for (int i = 0;i<2;i++){
      for (int j = 0;j<2;j++){
        mt1[i][j] = mt1[i][j] + k;
        mt2[i][j] = mt2[i][j] + k;
      }
    }

    printf("Matriz 1 = | %d %d |\n",mt1[0][0],mt1[0][1]);
    printf("           | %d %d |\n",mt1[1][0],mt1[1][1]);
    printf("\n");
    printf("Matriz 2 = | %d %d |\n",mt2[0][0],mt2[0][1]);
    printf("           | %d %d |\n",mt2[1][0],mt2[1][1]);
    
  }else if (evento == 4){
    printf("Matriz 1 = | %d %d |\n",mt1[0][0],mt1[0][1]);
    printf("           | %d %d |\n",mt1[1][0],mt1[1][1]);
    printf("\n");
    printf("Matriz 2 = | %d %d |\n",mt2[0][0],mt2[0][1]);
    printf("           | %d %d |\n",mt2[1][0],mt2[1][1]);
  }
    
  
  return 0;
}

