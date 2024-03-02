
// 4- receba um numero decimal e calcule seu quadrado
import java.util.Scanner;

public class questao05 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite um número decimal: ");
    double num = sc.nextDouble();
    double quadrado = num * num;
    System.out.println("O quadrado de " + num + " é: " + quadrado);
  }
}