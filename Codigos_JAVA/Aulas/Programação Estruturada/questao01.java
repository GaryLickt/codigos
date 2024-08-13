// 1- Solicite o nome do usuario e digite uma mensagem de boas vindas

import java.util.Scanner;

public class questao01 {
  public static void main(String[] args) {
    System.out.println("Digite seu nome");
    Scanner entrada = new Scanner(System.in);
    String nome = entrada.nextLine();
    entrada.close();
    System.out.println("Bem vindo(a) " + nome);
  }
}