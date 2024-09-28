package codigos.Codigos_JAVA.Mini_projetos.Jogo_Cartas;

import java.util.ArrayList;
import java.util.Random;

public class Baralho {
  private ArrayList<Carta> baralho;
  private int cartas_max;
  private Jogador dono;

  public Baralho(Jogador id){
    this.dono = id;
    this.cartas_max = 5;
  }

  public void criarBaralho(){
    ArrayList<Integer> cartas = dono.getCartas();
    Random gerador = new Random();

    for(int i = 0;i<cartas_max;i++){
      Integer aux = cartas.get(gerador.nextInt(cartas.size()+1));
      addCard(aux);
    }
  }

  private void addCard(int _id){
    Carta temp = new Carta(_id);
    if (temp.getTipo() == "Movimento"){
      baralho.add(new CartaMovimento(_id));
    }else if (temp.getTipo() == "Ataque"){
      baralho.add(new CartaAtaque(_id));
    }else{
      baralho.add(temp);
    }
  }

  public void removerCarta(Carta carta){
    baralho.remove(carta);
  }

  public void removerCartas(){
    while(baralho.size() > 0){
      baralho.removeLast();
    }
  }
}
