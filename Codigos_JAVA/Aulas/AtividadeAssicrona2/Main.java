import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArvoreB<Integer> arvore = new ArvoreB<>(5);

        int opcao;
        do {
            System.out.println("\nOpções:");
            System.out.println("1 - Inserir valor na árvore");
            System.out.println("2 - Exibir a maior chave armazenada na árvore");
            System.out.println("3 - Exibir a menor chave armazenada na árvore");
            System.out.println("4 - Exibir a altura da árvore");
            System.out.println("5 - Procurar um valor na árvore");
            System.out.println("6 - Exibir as chaves por nível");
            System.out.println("7 - Exibir as chaves em pré-ordem");
            System.out.println("8 - Remover um valor da árvore");
            System.out.println("9 - Sair");
            System.out.print("Informe a opção desejada: ");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1 : {
                    System.out.print("Valor a inserir: ");
                    int valor = scanner.nextInt();
                    arvore.inserir(valor);break;
                }
                case 2 : arvore.exibirMaiorChave();break;
                case 3 : arvore.exibirMenorChave();break;
                case 4 : System.out.println("Altura da árvore: " + arvore.calcularAltura());break;
                case 5 : {
                    System.out.print("Valor a procurar: ");
                    int valor = scanner.nextInt();
                    arvore.procurarValor(valor);break;
                }
                case 6 : arvore.exibirPorNivel();break;
                case 7 : arvore.exibirPreOrdem();break;
                case 8 : {
                    System.out.print("Valor a remover: ");
                    int valor = scanner.nextInt();
                    arvore.remover(valor);break;
                }
                case 9 : System.out.println("Saindo...");break;
                default : System.out.println("Opção inválida.");break;
            }
        } while (opcao != 9);

        scanner.close();
    }
}