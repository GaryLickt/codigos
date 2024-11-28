import java.util.ArrayList;

public class ArvoreBNo<T> {
  private int ordem;
  private ArrayList<T> info;
  private ArrayList<ArvoreBNo<T>> filhos;
  private ArvoreBNo<T> pai;

  public ArvoreBNo(int _ordem){
    this.ordem = _ordem;
    this.info = new ArrayList<>();
    this.filhos = new ArrayList<>();
  }

  // Gets e Sets
  public int getOrdem(){
    return this.ordem;
  }
  public ArvoreBNo<T> getPai(){
    return this.pai;
  }
  public ArrayList<ArvoreBNo<T>> getFilhos(){
    return this.filhos;
  }
  public ArvoreBNo<T> getFilho(int i){
    return filhos.get(i);
  }
  public ArrayList<T> getInfos(){
    return this.info;
  }
  public T getInfo(int i){
    return info.get(i);
  }

  public void setOrdem(int i){
    this.ordem = i;
  }
  public void setPai(ArvoreBNo<T> i){
    this.pai = i;
  }
  public void setFilhos(ArrayList<ArvoreBNo<T>> i){
    this.filhos = i;
  }
  public void setFilho(int i, ArvoreBNo<T> value){
    this.filhos.set(i, value);
  }
  public void setInfos(ArrayList<T> i){
    this.info = i;
  }
  public void setInfo(int i, T value){
    this.info.set(i, value);
  }

  public void addFilho(ArvoreBNo<T> i){
    this.filhos.add(i);
  }
  public void addInfo(T i){
    this.info.add(i);
  }
}