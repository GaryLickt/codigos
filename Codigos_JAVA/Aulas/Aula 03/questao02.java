// 2- Peça ao usuário que digite sua idade em texto (por exemplo, "18") e converta-a em um número inteiro.

import java.util.Scanner;

public class questao02 {
  public static void main(String[] args) {
    System.out.println("Digite sua idade: ");
    Scanner ler = new Scanner(System.in);
    String idade = ler.nextLine();
    ler.close();
    int idadeNum = Integer.parseInt(idade);
    System.out.println("Sua idade é: " + idadeNum);
  }
}