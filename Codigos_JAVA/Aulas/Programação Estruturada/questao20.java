
// 20- solicite ao usuario 2 numeros decimais, e calcule o resto da divisão entre eles
import java.util.Scanner;

public class questao20 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite o primeiro número: ");
    double num1 = sc.nextDouble();
    System.out.println("Digite o segundo número: ");
    double num2 = sc.nextDouble();
    double resto = num1 % num2;
    System.out.println("O resto da divisão entre " + num1 + " e " + num2 + " é: " + resto);
    sc.close();
  }
}