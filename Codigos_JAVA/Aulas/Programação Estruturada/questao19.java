
// 19- receba a cidade do usuario e verifique se ela começa com S
import java.util.Scanner;

public class questao19 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String cidade;
    System.out.println("Digite a cidade: ");
    cidade = sc.next();
    if (cidade.startsWith("S")) {
      System.out.println("A cidade começa com S");
    } else {
      System.out.println("A cidade não começa com S");
    }
    sc.close();
  }
}