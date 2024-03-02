
// 7- Peça ao usuário que digite seu primeiro nome e seu sobrenome separadamente.Em seguida,concatene-os em uma única string e exiba o nome completo.
import java.util.Scanner;

public class questao07 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite seu primeiro nome: ");
    String nome = sc.nextLine();
    System.out.println("Digite seu sobrenome: ");
    String sobrenome = sc.nextLine();
    String nomeCompleto = nome + " " + sobrenome;
    System.out.println("Seu nome completo é: " + nomeCompleto);
  }
}