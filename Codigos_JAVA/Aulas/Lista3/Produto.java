package codigos.Codigos_JAVA.Aulas.Lista3;

public class Produto implements Comparable<Produto> {
  private String codigo;
  private String descricao;
  private String fornecedor;
  private double preco;
  private int quantidade;

  public Produto(String codigo, String descricao, String fornecedor, double preco, int quantidade) {
      this.codigo = codigo;
      this.descricao = descricao;
      this.fornecedor = fornecedor;
      this.preco = preco;
      this.quantidade = quantidade;
  }

  public String getCodigo() {
      return codigo;
  }

  public void setCodigo(String codigo) {
      this.codigo = codigo;
  }

  public String getDescricao() {
      return descricao;
  }

  public void setDescricao(String descricao) {
      this.descricao = descricao;
  }

  public String getFornecedor() {
      return fornecedor;
  }

  public void setFornecedor(String fornecedor) {
      this.fornecedor = fornecedor;
  }

  public double getPreco() {
      return preco;
  }

  public void setPreco(double preco) {
      this.preco = preco;
  }

  public int getQuantidade() {
      return quantidade;
  }

  public void setQuantidade(int quantidade) {
      this.quantidade = quantidade;
  }

  @Override
  public String toString() {
      return "Produto{" +
              "codigo='" + codigo + '\'' +
              ", descricao='" + descricao + '\'' +
              ", fornecedor='" + fornecedor + '\'' +
              ", preco=" + preco +
              ", quantidade=" + quantidade +
              '}';
  }

  @Override
  public int compareTo(Produto outroProduto) {
      return this.codigo.compareTo(outroProduto.getCodigo());
  }
}
