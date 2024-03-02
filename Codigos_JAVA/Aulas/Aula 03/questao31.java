
// 31- receba a base e a altura de um triângulo, calcule e mostre sua área.
import java.util.Scanner;

public class questao31 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite a base do triângulo: ");
    double base = sc.nextDouble();
    System.out.println("Digite a altura do triângulo: ");
    double altura = sc.nextDouble();
    double area = (base * altura) / 2;
    System.out.println("A área do triângulo é: " + area);
    sc.close();
  }
}