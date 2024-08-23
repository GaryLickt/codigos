
// 14- Peça ao usuario que digite 2 numeros, e diga qual o maior e o menor deles.
import java.util.Scanner;

public class questao14 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int num1, num2;
    System.out.println("Digite o primeiro numero: ");
    num1 = sc.nextInt();
    System.out.println("Digite o segundo numero: ");
    num2 = sc.nextInt();
    if (num1 > num2) {
      System.out.println("O maior numero e: " + num1);
    } else {
      System.out.println("O maior numero e: " + num2);
    }
    sc.close();
  }
}