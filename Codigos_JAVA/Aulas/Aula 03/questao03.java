
// 3- receba um numero inteiro do usuario e converta ele para float
import java.util.Scanner;

public class questao03 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite um número inteiro: ");
    int numero = sc.nextInt();
    float numeroConvertido = (float) numero;
    System.out.println("O número convertido é: " + numeroConvertido);
    sc.close();
  }
}