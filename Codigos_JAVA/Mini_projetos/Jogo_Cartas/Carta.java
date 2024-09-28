package codigos.Codigos_JAVA.Mini_projetos.Jogo_Cartas;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Carta {
  private int id;
  private String elemento;
  private String nome;
  private String raridade;
  private String descricao;
  private String tipo;
  private Integer custo;

  public Carta(int _id){
    this.id = _id;
    Map<String, String> cartaDados = this.gerarCarta(_id);
    if (cartaDados != null) {
      this.nome = cartaDados.get("nome");
      this.elemento = cartaDados.get("elemento");
      this.raridade = cartaDados.get("raridade");
      this.descricao = cartaDados.get("descricao");
      this.tipo = cartaDados.get("tipo");
      this.custo = Integer.valueOf(cartaDados.get("custo"));
    }
  }

  public String getTipo(){
    return this.tipo;
  }

  Map<String, String> gerarCarta(int idProcurado) {
        String linha;
        String arquivo = "cartas.txt"; // Nome do arquivo onde os dados estão armazenados

        try (BufferedReader br = new BufferedReader(new FileReader(arquivo))) {
            // Lê a primeira linha (cabeçalhos)
            String[] cabecalhos = br.readLine().split("|");

            // Percorre as demais linhas do arquivo
            while ((linha = br.readLine()) != null) {
                String[] dados = linha.split(",");

                // Verifica se o ID corresponde ao da carta procurada
                int idCarta = Integer.parseInt(dados[0]);
                if (idCarta == idProcurado) {
                    Map<String, String> cartaDados = new HashMap<>();
                    for (int i = 0; i < cabecalhos.length; i++) {
                        cartaDados.put(cabecalhos[i], dados[i]);
                    }
                    return cartaDados;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null; // Retorna null se a carta não for encontrada
    }

  @Override
    public String toString() {
        return "Carta{" +
                "id=" + id +
                ", elemento='" + elemento + '\'' +
                ", nome='" + nome + '\'' +
                ", raridade='" + raridade + '\'' +
                ", descricao='" + descricao + '\'' +
                ", tipo='" + tipo + '\'' +
                ", custo=" + custo +
                '}';
  }
}

class CartaMovimento extends Carta {
  public CartaMovimento(int _id) {
    super(_id);
  }

  void Movimentar(){

  }

}

class CartaAtaque extends Carta {
  public CartaAtaque(int _id) {
    super(_id);
  }

  void Atacar(){
    
  }
}