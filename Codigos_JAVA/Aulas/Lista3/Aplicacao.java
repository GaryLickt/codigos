package codigos.Codigos_JAVA.Aulas.Lista3;
import java.util.Scanner;

public class Aplicacao {
    public static void main(String[] args) {
        Cadastro cadastro = new Cadastro();
        Scanner scanner = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("\n1. Cadastrar Produto");
            System.out.println("2. Exibir Produtos");
            System.out.println("3. Procurar Produto");
            System.out.println("4. Alterar Preço");
            System.out.println("5. Alterar Quantidade");
            System.out.println("6. Exibir Informações de um Produto");
            System.out.println("7. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("Código: ");
                    String codigo = scanner.next();
                    System.out.print("Descrição: ");
                    String descricao = scanner.next();
                    System.out.print("Fornecedor: ");
                    String fornecedor = scanner.next();
                    System.out.print("Preço: ");
                    double preco = scanner.nextDouble();
                    System.out.print("Quantidade: ");
                    int quantidade = scanner.nextInt();
                    Produto produto = new Produto(codigo, descricao, fornecedor, preco, quantidade);
                    cadastro.cadastrarProduto(produto);
                    break;
                case 2:
                    cadastro.exibirProdutos();
                    break;
                case 3:
                    System.out.print("Código do produto: ");
                    String codigoProcurar = scanner.next();
                    Produto produtoProcurado = cadastro.procurarProduto(codigoProcurar);
                    if (produtoProcurado != null) {
                        System.out.println("Produto encontrado: " + produtoProcurado);
                    } else {
                        System.out.println("Produto não encontrado.");
                    }
                    break;
                case 4:
                    System.out.print("Código do produto: ");
                    String codigoPreco = scanner.next();
                    System.out.print("Novo preço: ");
                    double novoPreco = scanner.nextDouble();
                    cadastro.alterarPreco(codigoPreco, novoPreco);
                    break;
                case 5:
                    System.out.print("Código do produto: ");
                    String codigoQuantidade = scanner.next();
                    System.out.print("Nova quantidade: ");
                    int novaQuantidade = scanner.nextInt();
                    cadastro.alterarQuantidade(codigoQuantidade, novaQuantidade);
                    break;
                case 6:
                    System.out.print("Código do produto: ");
                    String codigoInfo = scanner.next();
                    cadastro.exibirInformacoesProduto(codigoInfo);
                    break;
                case 7:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opção inválida.");
            }
        } while (opcao != 7);
        scanner.close();
      }
}
