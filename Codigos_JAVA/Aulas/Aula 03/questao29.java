
// 29- Receba uma string contendo um endereço de e-mail e concatene-a com uma mensagem de agradecimento personalizada.
import java.util.Scanner;

public class questao29 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String email;
    System.out.println("Digite seu e-mail: ");
    email = sc.nextLine();
    System.out.println("Obrigado por se cadastrar, " + email);
    sc.close();
  }
}