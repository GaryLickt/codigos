public class ARBNode {
  private Integer info;
  private Cor cor;
  private ARBNode esq;
  private ARBNode dir;
  private ARBNode pai;
  private int estado;

  ARBNode(Integer _valor){
    this.info = _valor;
    this.estado = 1;
    this.cor = Cor.VERMELHO;
  }

  // Gets e Sets da classe
  int getEstado(){
    return this.estado;
  }
  Integer getInfo(){
    return this.info;
  }
  Cor getCor(){
    return this.cor;
  }
  ARBNode getEsquerda(){
    return this.esq;
  }
  ARBNode getPai(){
    return this.pai;
  }
  ARBNode getDireita(){
    return this.dir;
  }
  void setEstado(int valor){
    this.estado = valor;
  }
  void setInfo(Integer valor){
    this.info = valor;
  }
  void setCor(Cor valor){
    this.cor = valor;
  }
  void setEsquerda(ARBNode valor){
    this.esq = valor;
  }
  void setPai(ARBNode valor){
    this.pai = valor;
  }
  void setDireita(ARBNode valor){
    this.dir = valor;
  }
}