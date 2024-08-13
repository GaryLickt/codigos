
// 34- solicite ao usuario 3 numeros decimais e calcule a media aritmética deles.

import java.util.Scanner;

public class questao34 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Digite o primeiro numero: ");
    double num1 = sc.nextDouble();

    System.out.println("Digite o segundo numero: ");
    double num2 = sc.nextDouble();

    System.out.println("Digite o terceiro numero: ");
    double num3 = sc.nextDouble();

    double media = (num1 + num2 + num3) / 3;

    System.out.println("A media aritmetica dos numeros digitados é: " + media);
    sc.close();
  }
}