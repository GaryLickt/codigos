
// 37- receba um numero decimal, e arredonde ele para o inteiro mais proximo

import java.util.Scanner;

public class questao37 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite um número decimal: ");
    double num = sc.nextDouble();
    double arredondado = Math.round(num);
    System.out.println("O número arredondado é: " + arredondado);
    sc.close();
  }
}