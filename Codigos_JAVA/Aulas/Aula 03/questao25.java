
// 25- solicite ao usuario seu ano de nascimento e exiba uma mensagem de boas vindas
import java.util.Scanner;

public class questao25 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite o ano do seu nascimento: ");
    int ano = sc.nextInt();
    System.out.println("Bem vindo ao mundo da programação, você nasceu no ano de " + ano);
    sc.close();
  }
}