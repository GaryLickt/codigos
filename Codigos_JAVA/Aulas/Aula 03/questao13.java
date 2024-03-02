
// 13- receba um numero inteiro e diga se ele é positivo ou negativo.
import java.util.Scanner;

public class questao13 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int numero;
    System.out.println("Digite um número inteiro: ");
    numero = sc.nextInt();
    if (numero > 0) {
      System.out.println("O número é positivo");
    } else if (numero < 0) {
      System.out.println("O número é negativo");
    } else {
      System.out.println("O número é zero");
    }
    sc.close();
  }
}