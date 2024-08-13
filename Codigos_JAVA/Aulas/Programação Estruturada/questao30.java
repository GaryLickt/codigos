
// 30- Receba dois números inteiros do usuário e exiba a soma, a diferença, o produto e o quociente (divisão inteira) entre eles.
import java.util.Scanner;

public class questao30 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int num1, num2, soma, diferenca, produto, quociente;

    System.out.print("Digite o primeiro número: ");
    num1 = sc.nextInt();
    System.out.print("Digite o segundo número: ");
    num2 = sc.nextInt();

    soma = num1 + num2;
    diferenca = num1 - num2;
    produto = num1 * num2;
    quociente = num1 / num2;

    System.out.println("Soma: " + soma);
    System.out.println("Diferença: " + diferenca);
    System.out.println("Produto: " + produto);
    System.out.println("Quociente: " + quociente);

    sc.close();
  }
}