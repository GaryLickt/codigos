
// 38- Receba três números inteiros digitados pelo usuário e exiba o resultado da operação (n1+n2)*n3.

import java.util.Scanner;

public class questao38 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Digite o primeiro número: ");
    int n1 = sc.nextInt();

    System.out.print("Digite o segundo número: ");
    int n2 = sc.nextInt();

    System.out.print("Digite o terceiro número: ");
    int n3 = sc.nextInt();

    int resultado = (n1 + n2) * n3;

    System.out.println("O resultado da operação (n1+n2)*n3 é: " + resultado);
    sc.close();
  }
}