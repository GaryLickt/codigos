
// 21- solicite um numero decimal e converta ele para inteiro
import java.util.Scanner;

public class questao21 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite um número decimal: ");
    double numero = sc.nextDouble();
    int inteiro = (int) numero;
    System.out.println("O número inteiro é: " + inteiro);
    sc.close();
  }
}