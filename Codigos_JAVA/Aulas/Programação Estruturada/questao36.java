
// 36- receba um valor em reais, e a cotação do dolar, e em seguida, converta e mostre o valor em dolares.

import java.util.Scanner;

public class questao36 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Digite o valor em reais: ");
    double valorReais = sc.nextDouble();

    System.out.println("Digite a cotação do dolar: ");
    double cotacaoDolar = sc.nextDouble();

    double valorDolar = valorReais / cotacaoDolar;

    System.out.println("O valor em dolares é: " + valorDolar);

  }
}