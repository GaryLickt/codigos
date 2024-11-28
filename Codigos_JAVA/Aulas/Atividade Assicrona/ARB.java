import java.util.HashSet;
import java.util.Set;

enum Cor {
  PRETO,
  VERMELHO
}
public class ARB {
  private ARBNode raiz;
  private Set<ARBNode> visitados = new HashSet<>();

  // Gets e Sets da classe
  public ARBNode getRaiz(){
    return this.raiz;
  }
  public void setRaiz(ARBNode valor){
    this.raiz = valor;
  }

  // Inserir
  public void inserir(Integer valor) {
    if (this.raiz == null) {
        this.raiz = new ARBNode(valor);
        this.raiz.setCor(Cor.PRETO); // Raiz sempre preta
    } else {
        ARBNode novoNo = inserirRecursivo(this.raiz, valor);
        novoNo.setCor(Cor.VERMELHO); // Todo novo nó é vermelho
        ajustarInsercao(novoNo); // Ajusta as propriedades da árvore
    }
    System.out.println("Valor inserido:");
    percorrer(true);
  }

  // Percorre recursivamente a árvore para adicionar um nó
  private ARBNode inserirRecursivo(ARBNode atual, Integer valor) {
    if (atual == null || atual.getInfo() == null) {
      ARBNode novoNo = new ARBNode(valor);

      // Definir nós folhas com info null e cor PRETO
      ARBNode folhaEsquerda = new ARBNode(null);
      folhaEsquerda.setCor(Cor.PRETO); // Nós folhas devem ser pretos
      novoNo.setEsquerda(folhaEsquerda);
      
      ARBNode folhaDireita = new ARBNode(null);
      folhaDireita.setCor(Cor.PRETO); // Nós folhas devem ser pretos
      novoNo.setDireita(folhaDireita);
      
      return novoNo;
  }

    if (valor < atual.getInfo()) {
        ARBNode esquerda = inserirRecursivo(atual.getEsquerda(), valor);
        atual.setEsquerda(esquerda);
        esquerda.setPai(atual); // Define o pai
        ajustarInsercao(esquerda);
    } else if (valor > atual.getInfo()) {
        ARBNode direita = inserirRecursivo(atual.getDireita(), valor);
        atual.setDireita(direita);
        direita.setPai(atual); // Define o pai
        ajustarInsercao(direita);
    }

    return atual;
  }

  // Ajusta a árvore após a inserção
  private void ajustarInsercao(ARBNode no) {
    // Se for a raiz, precisa ser preta
    try {
        System.out.println("Ajustando nó: " + no.getInfo() + ", cor atual: " + no.getCor());
        if (no == this.raiz) {
            no.setCor(Cor.PRETO);
            return;
        }

        // Caso 1: Pai é preto -> nada a fazer
        if (no.getPai().getCor() == Cor.PRETO) {
            return;
        }

        // Caso 2: Pai vermelho e tio vermelho
        ARBNode avo = no.getPai().getPai();
        ARBNode tio = getTio(no);

        if (tio != null && tio.getCor() == Cor.VERMELHO) {
            no.getPai().setCor(Cor.PRETO); // Pai fica preto
            tio.setCor(Cor.PRETO); // Tio fica preto
            avo.setCor(Cor.VERMELHO); // Avô fica vermelho
            ajustarInsercao(avo); // Ajustar o avô
        } else {
            // Caso 3: Rotação para balancear (casos esquerdo-esquerda, esquerdo-direita, etc.)
            if (no == no.getPai().getDireita() && no.getPai() == avo.getEsquerda()) {
                try {
                    rotacaoEsquerda(no.getPai());
                } catch (Exception e) {
                    System.err.println("Erro na rotação à esquerda: " + e.getMessage());
                    e.printStackTrace();
                }
                no = no.getEsquerda();
            } else if (no == no.getPai().getEsquerda() && no.getPai() == avo.getDireita()) {
                try {
                    rotacaoDireita(no.getPai());
                } catch (Exception e) {
                    System.err.println("Erro na rotação à direita: " + e.getMessage());
                    e.printStackTrace();
                }
                no = no.getDireita();
            }

            // Caso 4: Ajuste de cores e rotação final
            no.getPai().setCor(Cor.PRETO);
            avo.setCor(Cor.VERMELHO);
            if (no == no.getPai().getEsquerda()) {
                try {
                    rotacaoDireita(avo);
                } catch (Exception e) {
                    System.err.println("Erro na rotação final à direita: " + e.getMessage());
                    e.printStackTrace();
                }
            } else {
                try {
                    rotacaoEsquerda(avo);
                } catch (Exception e) {
                    System.err.println("Erro na rotação final à esquerda: " + e.getMessage());
                    e.printStackTrace();
                }
            }
        }
    } catch (Exception e) {
        System.err.println("Erro ao ajustar inserção: " + e.getMessage());
        e.printStackTrace();
    }
  }

  // Função para pegar o tio
  private ARBNode getTio(ARBNode no) {
    ARBNode avo = no.getPai().getPai();
    if (avo == null) {
        return null;
    }
    if (no.getPai() == avo.getEsquerda()) {
        return avo.getDireita();
    } else {
        return avo.getEsquerda();
    }
  }

  // Aplica rotação à esquerda (simples ou dupla)
  private void rotacaoEsquerda(ARBNode no) {
    ARBNode direita = no.getDireita();
    if (direita == null) return; // Verificação de segurança para evitar NullPointerException

    // Verifica se é necessário aplicar rotação dupla
    if (direita.getEsquerda() != null) {
        // Rotação dupla à esquerda
        rotacaoDireita(direita);
    }

    // Rotação simples à esquerda
    no.setDireita(direita.getEsquerda());
    if (direita.getEsquerda() != null) {
        direita.getEsquerda().setPai(no);
    }

    direita.setPai(no.getPai());
    if (no.getPai() == null) {
        this.raiz = direita; // Atualizando a raiz
    } else if (no == no.getPai().getEsquerda()) {
        no.getPai().setEsquerda(direita);
    } else {
        no.getPai().setDireita(direita);
    }

    direita.setEsquerda(no);
    no.setPai(direita);
  }


  // Aplica rotação à direita (simples ou dupla)
  private void rotacaoDireita(ARBNode no) {
    ARBNode esquerda = no.getEsquerda();
    if (esquerda == null) return; // Verificação de segurança para evitar NullPointerException

    // Verifica se é necessário aplicar rotação dupla
    if (esquerda.getDireita() != null) {
        // Rotação dupla à direita
        rotacaoEsquerda(esquerda);
    }

    // Rotação simples à direita
    no.setEsquerda(esquerda.getDireita());
    if (esquerda.getDireita() != null) {
        esquerda.getDireita().setPai(no);
    }

    esquerda.setPai(no.getPai());
    if (no.getPai() == null) {
        this.raiz = esquerda; // Atualizando a raiz
    } else if (no == no.getPai().getDireita()) {
        no.getPai().setDireita(esquerda);
    } else {
        no.getPai().setEsquerda(esquerda);
    }

    esquerda.setDireita(no);
    no.setPai(esquerda);
  }


  // Remover nó
  public void remover(Integer valor){
    ARBNode aux;
    aux = removerPregRecursivo(this.raiz, valor);
    if (aux != null) {
      aux.setEstado(0); // "Marca" o nó como removido
      System.out.println("Nó marcado como removido.");
    }
    System.out.println("Valor Removido:");
    percorrer(true);
    visitados.clear();
  }

  // Remover (preguiçoso)
  private ARBNode removerPregRecursivo(ARBNode no, Integer valor){
    if (valor > no.getInfo()){
      return removerPregRecursivo(no.getDireita(), valor);
    }else if (valor < no.getInfo()){
      return removerPregRecursivo(no.getEsquerda(), valor);
    }else {
      return no;
    }
  }

  // Percorrer em ordem
  private void percorrerEmOrdem(ARBNode r){
    if (r != null && !visitados.contains(r)) {
        visitados.add(r); // Marca o nó como visitado

        if (r.getEsquerda() != null){
            if (r.getEsquerda().getInfo() != null && r.getEsquerda().getEstado() == 1){
                percorrerEmOrdem(r.getEsquerda());
            }
        }
        if (r.getEstado() == 1){
          System.out.print(r.getInfo() + "." + r.getCor() + " ");
        }

        if (r.getDireita() != null){
            if (r.getDireita().getInfo() != null && r.getDireita().getEstado() == 1){
                percorrerEmOrdem(r.getDireita());
            }
        }
    }
  }

  // Percorrer por nivel
  private void passeioPorNivel(ARBNode r) {
    Queue fila = new Queue();
    ARBNode aux;
    int contNodosNoNivel = 1; // Contador para o número de nós no nível atual
    int contNodosProximoNivel = 0; // Contador para o número de nós no próximo nível

    if (this.raiz != null) {
        fila.enqueue(raiz);
        System.out.print("[ ");
        while (!fila.isEmpty()) {
            aux = fila.dequeue();
            visitados.add(aux);
            if (aux.getInfo() != null){
              System.out.print(aux.getInfo() + "." + aux.getCor() + " ");
            }else{
              System.out.print(aux.getInfo() + " ");
            }

            // Enfileira os filhos e incrementa os contadores
            if (aux.getEsquerda() != null) {
                if (aux.getEsquerda().getInfo() != null && aux.getEsquerda().getEstado() == 1 && !visitados.contains(aux.getEsquerda())) {
                    fila.enqueue(aux.getEsquerda());
                    contNodosProximoNivel++;
                }else if (aux.getInfo() == null){
                  fila.enqueue(aux.getEsquerda());
                  contNodosProximoNivel++;
                }
                
            }
            if (aux.getDireita() != null) {
                if (aux.getDireita().getInfo() != null && aux.getDireita().getEstado() == 1 && !visitados.contains(aux.getDireita())) {
                    fila.enqueue(aux.getDireita());
                    contNodosProximoNivel++;
                }else if (aux.getDireita().getInfo() == null){
                  fila.enqueue(aux.getDireita());
                  contNodosProximoNivel++;
                }
                
            }

            // Verifica se todos os nós do nível atual foram processados
            contNodosNoNivel--;
            if (contNodosNoNivel == 0) {
                System.out.println("]"); // Nova linha para o próximo nível
                contNodosNoNivel = contNodosProximoNivel; // Passa o contador do próximo nível
                contNodosProximoNivel = 0; // Reseta o contador para o próximo nível
                System.out.print("[ ");
              }
        }
    }
  }

  // Percorrer arvore no geral
  public void percorrer(boolean tipo){
    if (this.raiz == null){
        System.out.println("Arvore vazia.");
    }else{
      if (tipo == true){
        System.out.print("[ ");
        percorrerEmOrdem(this.raiz);
        System.out.println("]");
      }else{
        passeioPorNivel(this.raiz);
      }
      visitados.clear();
    }
  }
}
