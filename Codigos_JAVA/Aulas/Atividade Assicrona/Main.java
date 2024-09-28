import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    ARB arvore = new ARB();
    Scanner sc = new Scanner(System.in);
    int op;
    int valor;

    do{
      System.out.println("Menu:\n1- Inserir\n2- Remover (Preguiçoso)\n3- Listar\n0- Sair");
      op = sc.nextInt();
      switch(op){
        case 1: 
        System.out.println("Digite o valor a ser inserido: ");
        valor = sc.nextInt();
        arvore.inserir(valor);
        break;
        case 2:
        System.out.println("Digite qual valor deseja remover:");
        valor = sc.nextInt();
        arvore.remover(valor);
        break;
        case 3:
        System.out.println("Deseja lista em ordem ou por nivel? (1- em ordem / 2- por nivel)");
        valor = sc.nextInt();
        if (valor == 1){
          arvore.percorrer(true);
        }else if (valor == 2){
          arvore.percorrer(false);
        }else{
          System.out.println("Opção Invalida.");
        }
        break;
        case 0: System.out.println("Bye bye.");break;
      }
    }while(op != 0);
    sc.close();
  }
}
