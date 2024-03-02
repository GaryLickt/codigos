
// 10- solicite o nome e sobrenome do usuario separadamente, e depois exiba o nome invertido (sobrenome, nome).
import java.util.Scanner;

public class questao10 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);

    System.out.println("Digite seu nome: ");
    String nome = entrada.nextLine();

    System.out.println("Digite seu sobrenome: ");
    String sobrenome = entrada.nextLine();

    System.out.println("Seu nome invertido é: " + sobrenome + " " + nome);
    entrada.clear();
  }
}