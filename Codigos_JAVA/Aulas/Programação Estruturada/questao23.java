
// 23- Solicite ao usuário que digite uma data no formato "dd/mm/aaaa" e extraia o dia, o mês e o ano separadamente, convertendo-os em números inteiros.
import java.util.Scanner;

public class questao23 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite uma data no formato dd/mm/aaaa: ");
    String data = sc.nextLine();
    String[] partes = data.split("/");
    int dia = Integer.parseInt(partes[0]);
    int mes = Integer.parseInt(partes[1]);
    int ano = Integer.parseInt(partes[2]);
    System.out.println("Dia: " + dia);
    System.out.println("Mês: " + mes);
    System.out.println("Ano: " + ano);
    sc.close();
  }
}