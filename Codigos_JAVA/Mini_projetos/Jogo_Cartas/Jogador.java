package codigos.Codigos_JAVA.Mini_projetos.Jogo_Cartas;
import java.util.ArrayList;
import java.util.UUID;
public class Jogador {
  private UUID uuid;
  private ArrayList<Integer> cartas_possuidas;
  private String nome;
  private String email;
  private String senha;
  private int moedas;
  private int gemas;

  public UUID getUuid() {
    return uuid;
  }

  public ArrayList<Integer> getCartas(){
    return cartas_possuidas;
  }

  public void addCarta(Integer id){
    cartas_possuidas.add(id);
  }

  public Integer getCarta(int index){
    return cartas_possuidas.get(index);
  }

  public int getMoedas(){
    return moedas;
  }

  public int getGemas(){
    return gemas;
  }

  public void addMoedas(int quant){
    this.moedas+= quant;
  }

  public void addGemas(int quant){
    this.gemas+= quant;
  }

  public void setMoedas(int quant){
    this.moedas = quant;
  }

  public void setGemas(int quant){
    this.gemas = quant;
  }

  public void setUuid(UUID uuid) {
      this.uuid = uuid;
  }

  public String getNome() {
      return nome;
  }

  public void setNome(String nome) {
      this.nome = nome;
  }

  public String getSenha() {
      return senha;
  }

  public void setSenha(String senha) {
      this.senha = senha;
  }

  public String getEmail() {
      return email;
  }

  public void setEmail(String email) {
      this.email = email;
  }

  // Exibir informações do jogador
  @Override
  public String toString() {
      return "Jogador{" +
              "uuid=" + uuid +
              ", nome='" + nome + '\'' +
              ", senha='" + senha + '\'' +
              ", email='" + email + '\'' +
              '}';
  }
}
