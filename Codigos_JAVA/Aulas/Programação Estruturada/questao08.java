
// 8- solicite uma sequencia de numeros na mesma linha separados por espaço, e indique quandos numeros foram digitados
import java.util.Scanner;

public class questao08 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite uma sequencia de numeros separados por espaço: ");
    String input = sc.nextLine();
    String[] numeros = input.split(" ");
    System.out.println("Foram digitados " + numeros.length + " numeros.");
    sc.close();
  }
}