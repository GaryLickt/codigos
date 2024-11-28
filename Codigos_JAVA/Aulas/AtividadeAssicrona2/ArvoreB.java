import java.util.ArrayList;
import java.util.Collections;

public class ArvoreB<T extends Comparable<T>>  {
  private ArvoreBNo<T> raiz;
  private int ordem;

  public ArvoreB(int ordem) {
      this.ordem = ordem;
      this.raiz = new ArvoreBNo<T>(ordem);
  }

  public boolean isEmpty() {
      return this.raiz == null || this.raiz.getInfos().isEmpty();
  }

  public void inserir(T valor) {
        ArvoreBNo<T> no = raiz;
 
        // Encontrar o nó folha onde o valor será inserido
        while (no.getFilhos() != null && !no.getFilhos().isEmpty()) { 
            int i = 0;
            while (i < no.getInfos().size() && valor.compareTo(no.getInfo(i)) > 0) {
                i++;
            }
            no = no.getFilho(i);  // Avança para o filho adequado
        }

        // Inserir o valor no nó folha
        no.addInfo(valor);
        Collections.sort(no.getInfos());  // Ordena os valores dentro do nó

        // Verificar se o nó está cheio e realizar divisões se necessário
        if (no.getInfos().size() > ordem - 1) {
            dividir(no);
        }
  }
  private void dividir(ArvoreBNo<T> no) {
    int meio = ((ordem + 1) / 2) - 1;
    T valorPromovido = no.getInfo(meio);

    // Criar o novo nó que armazenará os valores da direita
    ArvoreBNo<T> novoNoDireita = new ArvoreBNo<>(ordem);
    novoNoDireita.setInfos(new ArrayList<>(no.getInfos().subList(meio + 1, no.getInfos().size())));

    // Se o nó tiver filhos, dividir os filhos também
    if (no.getFilhos() != null && !no.getFilhos().isEmpty()) {
        novoNoDireita.setFilhos(new ArrayList<>(no.getFilhos().subList(meio + 1, no.getFilhos().size())));
        // Atualizar o pai dos filhos do novo nó
        for (ArvoreBNo<T> filho : novoNoDireita.getFilhos()) {
            filho.setPai(novoNoDireita);
        }
    }

    // Ajustar o nó original para manter apenas os valores da esquerda
    no.setInfos(new ArrayList<>(no.getInfos().subList(0, meio)));
    int limiteFilhos = Math.min(no.getFilhos().size(), meio + 1);
    no.setFilhos(new ArrayList<>(no.getFilhos().subList(0, limiteFilhos)));

    // Promover o valor do meio para o pai
    if (no.getPai() == null) {
        // Criar um novo nó raiz se não houver pai
        ArvoreBNo<T> novaRaiz = new ArvoreBNo<>(ordem);
        novaRaiz.addInfo(valorPromovido);
        novaRaiz.addFilho(no);
        novaRaiz.addFilho(novoNoDireita);
        raiz = novaRaiz;

        // Atualizar pai dos nós filhos
        no.setPai(raiz);
        novoNoDireita.setPai(raiz);
    } else {
        // Inserir o valor promovido no pai existente
        ArvoreBNo<T> pai = no.getPai();
        pai.addInfo(valorPromovido);
        Collections.sort(pai.getInfos());

        // Ajustar os filhos do pai
        int indicePai = pai.getFilhos().indexOf(no);
        pai.getFilhos().add(indicePai + 1, novoNoDireita);
        novoNoDireita.setPai(pai);

        // Dividir o pai se ele também estiver cheio
        if (pai.getInfos().size() > ordem - 1) {
            dividir(pai);
        }
    }
  }

  private ResultadoBusca<T> encontrarMaiorChave() {
    if (isEmpty()) {
        return new ResultadoBusca<T>(null, -1);
    }

    ArvoreBNo<T> noAtual = raiz;
    while (!noAtual.getFilhos().isEmpty()) {
        noAtual = noAtual.getFilho(noAtual.getFilhos().size() - 1);
    }

    return new ResultadoBusca<T>(noAtual, noAtual.getInfos().size() - 1);
  }
  public void exibirMaiorChave() {
    ResultadoBusca<T> resultado = encontrarMaiorChave();
    if (resultado.no != null) {
        System.out.println("Maior chave: " + resultado.no.getInfo(resultado.posicao));
    } else {
        System.out.println("A árvore está vazia.");
    }
  }
  
  private ArvoreBNo<T> encontrarMenorChave() {
    if (isEmpty()) {
        return null;
    }

    ArvoreBNo<T> noAtual = raiz;
    while (!noAtual.getFilhos().isEmpty()) {
        noAtual = noAtual.getFilho(0);
    }

    return noAtual;
  }
  public void exibirMenorChave() {
    ArvoreBNo<T> menorNo = encontrarMenorChave();
    if (menorNo != null) {
        System.out.println("Menor chave: " + menorNo.getInfo(0));
    } else {
        System.out.println("A árvore está vazia.");
    }
  }
  
  public int calcularAltura() {
    int altura = 0;
    ArvoreBNo<T> noAtual = raiz;

    while (noAtual != null && !noAtual.getFilhos().isEmpty()) {
        altura++;
        noAtual = noAtual.getFilho(0);
    }

    return altura;
  }
  
  private ResultadoBusca<T> encontrarValor(T valor) {
    if (isEmpty()) {
        return new ResultadoBusca<T>(null, -1);
    }

    ArvoreBNo<T> noAtual = raiz;
    while (noAtual != null) {
        int i = 0;
        while (i < noAtual.getInfos().size() && valor.compareTo(noAtual.getInfo(i)) > 0) {
            i++;
        }

        if (i < noAtual.getInfos().size() && valor.equals(noAtual.getInfo(i))) {
            return new ResultadoBusca<T>(noAtual, i);
        }

        if (noAtual.getFilhos().isEmpty()) {
            break;
        } else {
            noAtual = noAtual.getFilho(i);
        }
    }

    return new ResultadoBusca<T>(null, -1);
  }
  public void procurarValor(T valor) {
    ResultadoBusca<T> resultado = encontrarValor(valor);
    if (resultado.no != null) {
        System.out.println("Valor " + valor + " encontrado na posição " + resultado.posicao + " do nó.");
    } else {
        System.out.println("Valor " + valor + " não encontrado.");
    }
  }

  public void exibirPorNivel() {
    if (isEmpty()) {
        System.out.println("A árvore está vazia.");
        return;
    }

    ArrayList<ArvoreBNo<T>> fila = new ArrayList<>();
    fila.add(raiz);

    while (!fila.isEmpty()) {
        ArvoreBNo<T> noAtual = fila.remove(0);
        System.out.println(noAtual.getInfos());

        fila.addAll(noAtual.getFilhos());
    }
  }
  public void exibirPreOrdem() {
    exibirPreOrdemRecursivo(raiz);
  }
  private void exibirPreOrdemRecursivo(ArvoreBNo<T> no) {
      if (no != null) {
          System.out.println(no.getInfos());
          for (ArvoreBNo<T> filho : no.getFilhos()) {
              exibirPreOrdemRecursivo(filho);
          }
      }
  }

  private ArvoreBNo<T> buscValor(T valor){
    ArvoreBNo<T> noAtual = this.raiz;
    while (noAtual != null) {
        int i = 0;
        while (i < noAtual.getInfos().size() && valor.compareTo(noAtual.getInfo(i)) > 0) {
            i++;
        }

        if (i < noAtual.getInfos().size() && valor.equals(noAtual.getInfo(i))) {
            return noAtual;
        }

        if (noAtual.getFilhos().isEmpty()) {
            break;
        } else {
            noAtual = noAtual.getFilho(i);
        }
    }
    return null;
  }
  public void remover(T valor) {
    ArvoreBNo<T> noAtual = buscValor(valor);

    if (noAtual == null) {
        System.out.println("O valor não existe na árvore.");
        return;
    }

    int indice = noAtual.getInfos().indexOf(valor);

    if (noAtual.getFilhos().isEmpty()) {
        // Caso 1: O nó é folha, basta remover o valor
        noAtual.getInfos().remove(indice);

        // Verifica se o nó está abaixo do mínimo e reequilibra a árvore se necessário
        if (noAtual != raiz && noAtual.getInfos().size() < (ordem - 1) / 2) {
            reequilibrarAposRemocao(noAtual);
        }
    } else {
        // Caso 2: O nó não é folha
        T predecessor = encontrarMaiorPredecessor(noAtual, indice);
        noAtual.getInfos().set(indice, predecessor);

        // Recursivamente remover o predecessor do nó folha
        if (predecessor != null){
            remover(predecessor);
        }
    }

    // Se a raiz ficar vazia, ajusta a estrutura da árvore
    if (raiz.getInfos().isEmpty() && !raiz.getFilhos().isEmpty()) {
        raiz = raiz.getFilho(0); // A raiz agora é seu único filho
        raiz.setPai(null);
    }
}
  private T encontrarMaiorPredecessor(ArvoreBNo<T> no, int indice) {
        ArvoreBNo<T> atual = no.getFilho(indice);
        while (!atual.getFilhos().isEmpty()) {
            atual = atual.getFilho(atual.getFilhos().size() - 1);
        }
        return atual.getInfos().get(atual.getInfos().size() - 1);
    }
  private void reequilibrarAposRemocao(ArvoreBNo<T> no) {
        ArvoreBNo<T> pai = no.getPai();
        if (pai == null) return; // A raiz não precisa de reequilíbrio

        int indiceNo = pai.getFilhos().indexOf(no);
        ArvoreBNo<T> irmaoEsquerdo = (indiceNo > 0) ? pai.getFilho(indiceNo - 1) : null;
        ArvoreBNo<T> irmaoDireito = (indiceNo < pai.getFilhos().size() - 1) ? pai.getFilho(indiceNo + 1) : null;

        if (irmaoEsquerdo != null && irmaoEsquerdo.getInfos().size() > (ordem - 1) / 2) {
            // Caso 1: Emprestar do irmão esquerdo
            no.getInfos().add(0, pai.getInfo(indiceNo - 1));
            pai.getInfos().set(indiceNo - 1, irmaoEsquerdo.getInfos().remove(irmaoEsquerdo.getInfos().size() - 1));

            if (!irmaoEsquerdo.getFilhos().isEmpty()) {
                no.getFilhos().add(0, irmaoEsquerdo.getFilhos().remove(irmaoEsquerdo.getFilhos().size() - 1));
                no.getFilho(0).setPai(no);
            }
        } else if (irmaoDireito != null && irmaoDireito.getInfos().size() > (ordem - 1) / 2) {
            // Caso 2: Emprestar do irmão direito
            no.getInfos().add(pai.getInfo(indiceNo));
            pai.getInfos().set(indiceNo, irmaoDireito.getInfos().remove(0));

            if (!irmaoDireito.getFilhos().isEmpty()) {
                no.getFilhos().add(irmaoDireito.getFilhos().remove(0));
                no.getFilho(no.getFilhos().size() - 1).setPai(no);
            }
        } else {
            // Caso 3: Fusão com irmão
            if (irmaoEsquerdo != null) {
                irmaoEsquerdo.getInfos().add(pai.getInfos().remove(indiceNo - 1));
                irmaoEsquerdo.getInfos().addAll(no.getInfos());
                irmaoEsquerdo.getFilhos().addAll(no.getFilhos());

                pai.getFilhos().remove(indiceNo);
            } else if (irmaoDireito != null) {
                no.getInfos().add(pai.getInfos().remove(indiceNo));
                no.getInfos().addAll(irmaoDireito.getInfos());
                no.getFilhos().addAll(irmaoDireito.getFilhos());

                pai.getFilhos().remove(indiceNo + 1);
            }

            if (pai.getInfos().size() < (ordem - 1) / 2) {
                reequilibrarAposRemocao(pai);
            }
        }
    }

  // Gets e Sets
  public ArvoreBNo<T> getRaiz(){
    return this.raiz;
  }
  public void setRaiz(ArvoreBNo<T> i){
    this.raiz = i;
  }
}
