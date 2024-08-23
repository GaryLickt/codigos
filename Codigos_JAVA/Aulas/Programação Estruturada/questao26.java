
// 26- solicite um numero inteiro e uma string do usuario, e concaete os dois valores em uma unica mensagem separando os valores por um espaco.
import java.util.Scanner;

public class questao26 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite um numero inteiro: ");
    int numero = sc.nextInt();
    System.out.println("Digite uma string: ");
    String string = sc.next();
    System.out.println(numero + " " + string);
    sc.close();
  }
}