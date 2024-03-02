// 22- receba uma string contendo um numero inteiro, e some 10 a esse numero, convertendo-o novamente para string e imprima o resultado.
import java.util.Scanner;

public class questao22 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite um numero inteiro: ");
    String num = sc.nextLine();
    int numInt = Integer.parseInt(num);
    numInt = numInt + 10;
    String numStr = String.valueOf(numInt);
    System.out.println("O resultado é: " + numStr);
    sc.close();
  }
}