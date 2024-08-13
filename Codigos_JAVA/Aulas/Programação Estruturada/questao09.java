
// 9- receba o nome de um animal e exiba uma mensagem informando qual animal foi digitado
import java.util.Scanner;

public class questao09 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite o nome de um animal: ");
    String animal = sc.nextLine();
    System.out.println("O animal digitado foi: " + animal);
  }
}