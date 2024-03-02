
// 28- Receba um número inteiro do usuário e concatene-o com uma mensagem, informando o dobro desse número.
import java.util.Scanner;

public class questao28 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int num;
    System.out.println("Digite um número inteiro: ");
    num = sc.nextInt();
    System.out.println("O dobro do número digitado é: " + (num * 2));
    sc.close();
  }
}