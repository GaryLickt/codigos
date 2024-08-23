import java.util.Scanner;
import ArvoresBinariasdeBusca.*;

public class Main {

    public static void main(String[] args) {
        ABB arvore = new ABB();
        Scanner sc = new Scanner(System.in);
        
        int op = -1;
        int valor = 0;
        do {
            System.out.println("O que deseja fazer?");
            System.out.println("1- adicionar nó");
            System.out.println("2- buscar nó");
            System.out.println("3- listar arvore");
            System.out.println("0 - sair");
            op = sc.nextInt();
            System.out.println("opção escolhida: " + op);
            switch(op){
                case 1:
                    System.out.println("Digite o valor:");
                    valor = sc.nextInt();
                    arvore.inserir(valor);
                    break;
                case 2:
                    System.out.println("Digite o valor:");
                    valor = sc.nextInt();
                    arvore.procurar(valor);
                    break;
                case 3:
                    System.out.println("Como deseja listar a arvore?\n1-Em ordem\n2- Pos ordem\n3- Por nivel");
                    valor = sc.nextInt();
                    switch(valor){
                        case 1: arvore.emOrdem();break;
                        case 2: arvore.posOrdem();break;
                        case 3: arvore.porNivel();break;
                    }
                    break;
                case 0:
                    System.out.println("Bye Bye.");
            }
        }while(op != 0);
        sc.close();
    }
}
