
// 18- receba a base e a altura de um retangulo e calcule a sua area
import java.util.Scanner;

public class questao18 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite a base do retangulo: ");
    double base = sc.nextDouble();
    System.out.println("Digite a altura do retangulo: ");
    double altura = sc.nextDouble();
    double area = base * altura;
    System.out.println("A area do retangulo é: " + area);
  }
}