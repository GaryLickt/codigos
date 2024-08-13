
// 17- receba o estado civil do usuario, e exiba uma mensagem correspondente ao mesmo
import java.util.Scanner;

public class questao17 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite seu estado civil: ");
    String estadoCivil = sc.nextLine();
    if (estadoCivil.equals("casado")) {
        System.out.println("Casado");
    } else if (estadoCivil.equals("solteiro")) {
        System.out.println("Solteiro");
    } else if (estadoCivil.equals("viuvo")) {
        System.out.println("Viuvo");
    } else if (estadoCivil.equals("divorciado")) {
        System.out.println("Divorciado");
    } else {
        System.out.println("Estado civil inválido");
    }
    sc.close();
  }
}