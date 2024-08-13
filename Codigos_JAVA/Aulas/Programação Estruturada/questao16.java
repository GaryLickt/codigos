
// 16- Peça ao usuario que digite seu nome, e exiba uma mensagem caso ele tenha mais de 5 caracteres
import java.util.Scanner;

public class questao16 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.println("Digite seu nome: ");
    String nome = input.nextLine();
    if (nome.length() > 5) {
      System.out.println("Seu nome tem mais de 5 caracteres");
    }
  }
}