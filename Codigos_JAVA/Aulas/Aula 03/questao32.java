
// 32- receba o raio da circunferencia e calcule seu périmetro
import java.util.Scanner;

public class questao32 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Digite o raio da circunferencia: ");
    double raio = sc.nextDouble();
    double perimetro = 2 * Math.PI * raio;
    System.out.println("O perimetro da circunferencia é: " + perimetro);
    sc.close();
  }
}