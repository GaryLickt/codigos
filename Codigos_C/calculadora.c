#include <stdio.h>
#include <stdlib.h>
// Funções de Calculo
int soma(int a, int b){
  return a + b;
}
int subtrair(int a, int b){
  return a - b;
}
int multiplicar(int a, int b){
  int c = 0;
  while(b>0){
    c = soma(c,a);
    b = subtrair(b,1);
  }
  return c;
}
int dividir(int a, int b){
  int c = 0;
  while(a>=b){
    a = subtrair(a,b);
    c = soma(c,1);
  }
  return c;
}
int elevado(int a, int b){
  int c = 1;
  while(b>0){
    c = multiplicar(c,a);
    b = subtrair(b,1);
  }
  return c;
}
int dividir_resto(int a, int b){
  int c = 0;
  while(a>=b){
    a = subtrair(a,b);
    c = soma(c,1);
  }
  return a;
}
// Codigo main
int main() {
  int x,y,resul;
  char sinal;
  printf("Qual problema vamos resolver hoje?\n");
  scanf("%d %c %d",&x,&sinal,&y);
  switch(sinal){
    case '+': resul = soma(x,y);printf("= %d\n",resul);break;
    case '-': resul = subtrair(x,y);printf("= %d\n",resul);break;
    case '*': resul = multiplicar(x,y);printf("= %d\n",resul);break;
    case '^': resul = elevado(x,y);printf("= %d\n",resul);break;
    case '/': resul = dividir(x,y);printf("= %d\n",resul);break;
    case '%': resul = dividir_resto(x,y);printf("= %d\n",resul);break;
    default: printf("ERROR: sinal inexistente e/ou não conhecido.\n");
  }
  return 0;
}
