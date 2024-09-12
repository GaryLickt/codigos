package ArvoresBalanceadas;

public class AVL {
  private AVLNo raiz;
  private boolean status;

  public AVLNo getRaiz(){
    return this.raiz;
  }

  public void setRaiz(AVLNo _valor){
    this.raiz = _valor;
  }

  private boolean isEmpty(){
    return this.raiz == null;
  }

  public void insert(Integer valor){
    if (this.isEmpty() == true){
      this.raiz = new AVLNo(valor);
      this.status = true;
    }else{
      this.raiz = insertNode(this.raiz, valor);
    }
  }

  private AVLNo insertNode(AVLNo no, Integer valor){
    if (no == null){
      no = new AVLNo(valor);
      this.status = true;
    }else if (no.getInfo().compareTo(valor) > 0){
      no.setEsquerda(insertNode(no.getEsquerda(), valor));
      if (this.status == true){
        switch(no.getBal()){
          case 1: no.setBal(0);
                  this.status = false;
                  break;
          case 0: no.setBal(-1);
                  break;
          case -1: no = this.rotateRight(no);
                  break;
        }
      }
    }else{
      no.setDireita(insertNode(no.getDireita(), valor));
      if (this.status == true){
        switch(no.getBal()){
          case -1: no.setBal(0);
                  this.status = false;
                  break;
          case 0: no.setBal(1);
                  break;
          case 1: no = this.rotateLeft(no);
                  break;
        }
      }
    }
    return no;
  }

  private AVLNo rotateRight(AVLNo a){
    AVLNo b, c;
    b = a.getEsquerda();
    return null;
  }
  private AVLNo rotateLeft(AVLNo a){
    AVLNo b, c;
    b = a.getDireita();
    if (b.getBal() > 1){ // rotação simples
      a.setDireita(b.getEsquerda());
      b.setEsquerda(a);
      a.setBal(0);
      a = b;
    }else{ // rotação dupla
      c = b.getEsquerda();
      b.setEsquerda(c.getDireita());
      c.setDireita(b);
      a.setDireita(c.getEsquerda());
      c.setEsquerda(a);
      if (c.getBal() == 1){
        a.setBal(-1);
      }else{
        a.setBal(0);
      }
      if (c.getBal() == -1){
        b.setBal(1);
      }else{
        b.setBal(0);
      }
      a = c;
    }
    a.setBal(0);
    this.status = false;
    return a;
  }

}

class AVLNo {
  private Integer info;
  private int bal;
  private AVLNo esq, dir;

  AVLNo(Integer _valor) {
      this.info = _valor;
  }

  Integer getInfo(){
      return this.info;
  }

  int getBal(){
    return this.bal;
  }

  AVLNo getEsquerda(){
      return this.esq;
  }

  AVLNo getDireita(){
      return this.dir;
  }

  void setInfo(Integer _valor){
      this.info = _valor;
  }

  void setBal(int _valor){
    this.bal = _valor;
  }

  void setEsquerda(AVLNo _valor){
      this.esq = _valor;
  }

  void setDireita(AVLNo _valor){
      this.dir = _valor;
  }
}