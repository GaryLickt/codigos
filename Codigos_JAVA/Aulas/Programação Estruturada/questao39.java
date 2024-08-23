
// 39- Peça ao usuário que digite uma temperatura em graus Celsius e a converta para Fahrenheit usando a fórmula: Fahrenheit = (Celsius*9/5) + 32.

import java.util.Scanner;

public class questao39 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Digite a temperatura em graus Celsius: ");
    double celsius = sc.nextDouble();

    double fahrenheit = (celsius * 9 / 5) + 32;

    System.out.println("A temperatura em graus Fahrenheit é: " + fahrenheit);
    sc.close();
  }
}