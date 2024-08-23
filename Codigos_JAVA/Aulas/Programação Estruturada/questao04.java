
// 4- peça para o usuario digitar 2 numeros inteiros e exiba a soma deles
import java.util.Scanner;

public class questao04 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int num1, num2, soma;

    System.out.println("Digite o primeiro numero: ");
    num1 = sc.nextInt();
    System.out.println("Digite o segundo numero: ");
    num2 = sc.nextInt();

    soma = num1 + num2;

    System.out.println("A soma dos numeros é: " + soma);
    sc.close();
  }
}