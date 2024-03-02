
// 33- receba a base a altura de um retangulo e calcule o seu perimetro
import java.util.Scanner;

public class questao33 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);

    System.out.println("Informe a base do retangulo: ");
    double base = entrada.nextDouble();

    System.out.println("Informe a altura do retangulo: ");
    double altura = entrada.nextDouble();

    double perimetro = 2 * (base + altura);

    System.out.println("O perimetro do retangulo é: " + perimetro);
    entrada.close();
  }
}