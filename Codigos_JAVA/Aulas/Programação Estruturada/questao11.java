
// 11- solicite ao usuario um numero inteiro, e diga se ele é impar ou par.
import java.util.Scanner;

public class questao11 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite um número inteiro: ");
    int num = sc.nextInt();
    if (num % 2 == 0) {
      System.out.println("O número é par");
    } else {
      System.out.println("O número é impar");
    }
    sc.close();
  }
}