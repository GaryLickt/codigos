
// 35- Peça a um usuario a sua idade, e em seguida informe quantos meses e quantos dias ele viveu (considerando um ano de 365 dias).

import java.util.Scanner;

public class questao35 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Digite sua idade: ");
    int idade = sc.nextInt();

    int meses = idade * 12;
    int dias = idade * 365;

    System.out.println("Você viveu " + meses + " meses e " + dias + " dias.");

    sc.close();
  }
}