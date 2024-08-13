
// 27- Receba o nome de um produto digitado pelo usuário e concatene-o com o preço do produto, adicionando os simbolo de moeda da sua escolha.
import java.util.Scanner;

public class questao27 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String nomeProduto;
    double precoProduto;
    String moeda;

    System.out.println("Digite o nome do produto: ");
    nomeProduto = sc.nextLine();
    System.out.println("Digite o preço do produto: ");
    precoProduto = sc.nextDouble();
    System.out.println("Digite a moeda: ");
    moeda = sc.next();

    System.out.println("Produto: " + nomeProduto + " Preço: " + moeda + precoProduto);
    sc.close();
  }
}