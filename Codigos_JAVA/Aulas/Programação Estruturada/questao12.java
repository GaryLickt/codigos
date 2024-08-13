
// 12- receba uma string do usuario, e diga seu tamanho
import java.util.Scanner;

public class questao12 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite uma palavra: ");
    String palavra = sc.nextLine();
    System.out.println("O tamanho da palavra é: " + palavra.length());
  }
}