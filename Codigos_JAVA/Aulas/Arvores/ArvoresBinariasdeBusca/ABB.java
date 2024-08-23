// Arvore Binaria de Busca
package ArvoresBinariasdeBusca;

import java.util.Stack;

public class ABB {
    private No raiz;

    public No getRaiz(){
        return this.raiz;
    }

    public void setRaiz(No _valor){
        this.raiz = _valor;
    }

    public boolean isEmpty(){
        if (this.raiz == null){
            return true;
        }else{
            return false;
        }
    }

    public void inserir(Integer valor) {
        No novo = new No(valor);
        if (isEmpty()){
            this.raiz = novo;
            System.out.println("Valor inserido com sucesso!");
        }else{
            No aux = this.raiz;

            while(aux != null){
                int result = valor.compareTo(aux.getInfo());
                if (result > 0) {
                    // X > Y, coloca na direita
                    if (aux.getDireita() != null){
                        aux = aux.getDireita();
                    }else{
                        aux.setDireita(new No(valor));
                        System.out.println("Valor inserido com sucesso!");
                        break;
                    }
                }else if (result < 0) {
                    // X < Y, coloca na esquerda
                    if (aux.getEsquerda() != null){
                        aux = aux.getEsquerda();
                    }else{
                        aux.setEsquerda(new No(valor));
                        System.out.println("Valor inserido com sucesso!");
                        break;
                    }
                }else{
                    System.out.println("Valor Repetido");
                    break;
                }  
            }
        }
    }

    // 1º Questão
    No buscar(Integer valor){
        if (!isEmpty()){
            No aux = this.raiz;
            do{
                if (aux.getInfo() > valor){
                    aux = aux.getDireita();
                }else if (aux.getInfo() < valor){
                    aux = aux.getEsquerda();
                }else {
                    return aux;
                }
            }
            while(aux != null);
        }else{
            System.out.println("Arvore vazia.");
        }
        return null;
    }
    // 2º Questão
    public void procurar(Integer valor){
        No aux = buscar(valor);
        if (aux != null){
            System.out.println("O valor está na arvore");
        }else{
            System.out.println("O valor não está na arvore");
        }
    }
    // 4º Questão
    // letra a
    private No buscarMenor(){
        No aux = this.raiz;
        No aux2 = this.raiz;
        if (aux2.getDireita() != null){
            aux2 = aux2.getDireita();
        }
        do {
            if (aux.getEsquerda() != null){
                aux = aux.getEsquerda();
            }
            if (aux2.getEsquerda() != null){
                aux2 = aux2.getEsquerda();
            }

            if ((aux2.getEsquerda() == null) && (aux.getEsquerda() == null)){
                if (aux.getInfo() > aux2.getInfo()){
                    return aux2;
                }else{
                    return aux;
                }
            }
        }while((aux2.getEsquerda() != null) || (aux.getEsquerda() != null));
        return null;
    }
    // letra b
    private No buscarMaior(){
        No aux = this.raiz;
        No aux2 = this.raiz;
        if (aux2.getEsquerda() != null){
            aux2 = aux2.getEsquerda();
        }
        do {
            if (aux.getDireita() != null){
                aux = aux.getDireita();
            }
            if (aux2.getDireita() != null){
                aux2 = aux2.getDireita();
            }

            if ((aux2.getDireita() == null) && (aux.getDireita() == null)){
                if (aux.getInfo() > aux2.getInfo()){
                    return aux;
                }else{
                    return aux2;
                }
            }
        }while((aux2.getDireita() != null) || (aux.getDireita() != null));
        return null;
    }
    // letra c
    public void exibirMenor(){
        No menor = buscarMenor();
        System.out.println("O menor valor é: " + menor.getInfo());
    }
    // letra d
    public void exibirMaior(){
        No maior = buscarMaior();
        System.out.println("O maior valor é: " + maior.getInfo());
    }

    private void percorrerEmOrdem(No r){
        if (r != null){
            percorrerEmOrdem(r.getEsquerda());
            System.out.println(r.getInfo());
            percorrerEmOrdem(r.getDireita());
        }
    }
    private void percorrerPosOrdem(No r){
        if (r != null){
            percorrerEmOrdem(r.getEsquerda());
            percorrerEmOrdem(r.getDireita());
            System.out.println(r.getInfo());
        }
    }
    private void passeioPorNivel(No r){
        Queue fila = new Queue();
        No aux;
        if (!this.isEmpty()){
            fila.enqueue(raiz);
            while(fila.isEmpty()){
                aux = fila.dequeue();
                if (aux.getEsquerda() != null){
                    fila.enqueue(aux.getEsquerda());
                }
                if (aux.getDireita() != null){
                    fila.enqueue(aux.getDireita());
                }
                System.out.println(aux.getInfo());
            }
        }
    }

    public void emOrdem(){
        if (this.isEmpty()){
            System.out.println("Arvore vazia.");
        }else{
            percorrerEmOrdem(raiz);
        }
    }
    public void posOrdem(){
        if (this.isEmpty()){
            System.out.println("Arvore vazia.");
        }else{
            percorrerPosOrdem(raiz);
        }
    }
    public void porNivel(){
        if (this.isEmpty()){
            System.out.println("Arvore vazia.");
        }else{
            passeioPorNivel(raiz);
        } 
    }

    public void preOrder() {
        if (this.raiz == null) {
            return;
        }

        Stack<No> stack = new Stack<>();
        stack.push(this.raiz);

        while (!stack.isEmpty()) {
            No current = stack.pop();
            System.out.print(current.getInfo() + " ");

            if (current.getDireita() != null) {
                stack.push(current.getDireita());
            }
            if (current.getEsquerda() != null) {
                stack.push(current.getEsquerda());
            }
        }
    }

    public void inOrder() {
        if (this.raiz == null) {
            return;
        }

        Stack<No> stack = new Stack<>();
        No current = this.raiz;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.getEsquerda();
            }

            current = stack.pop();
            System.out.print(current.getInfo() + " ");

            current = current.getDireita();
        }
    }
}

class No {
    private Integer info;
    private No esq, dir;

    No(Integer _valor) {
        this.info = _valor;
    }

    Integer getInfo(){
        return this.info;
    }

    No getEsquerda(){
        return this.esq;
    }

    No getDireita(){
        return this.dir;
    }

    void setInfo(Integer _valor){
        this.info = _valor;
    }

    void setEsquerda(No _valor){
        this.esq = _valor;
    }

    void setDireita(No _valor){
        this.dir = _valor;
    }
}