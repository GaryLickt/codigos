
// 6- peça ao usuario que insira seu ano de nascimento e calcule sua idade
import java.util.Scanner;

public class questao06 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.println("Digite o ano de nascimento: ");
    int anoNascimento = input.nextInt();
    int idade = 2024 - anoNascimento;
    System.out.println("A idade é: " + idade);
    input.close();
  }
}