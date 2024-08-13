
// 24- Receba o nome de uma cidade do usuário e concatene-o com o nome do estado para formar uma mensagem completa, como "Você mora em [cidade],[estado].".
import java.util.Scanner;

public class questao24 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String cidade, estado;

    System.out.print("Digite o nome da cidade: ");
    cidade = sc.nextLine();

    System.out.print("Digite o nome do estado: ");
    estado = sc.nextLine();

    System.out.println("Você mora em " + cidade + ", " + estado + ".");

    sc.close();
  }
}