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
            No auxprox = this.raiz;
            do{
                if (aux.getInfo() > valor){
                    auxprox = aux.getEsquerda();
                    if (auxprox != null){
                        aux = auxprox;
                    }
                }else if (aux.getInfo() < valor){
                    auxprox = aux.getDireita();
                    if (auxprox != null){
                        aux = auxprox;
                    }
                }else {
                    return aux;
                }
            }
            while(auxprox != null);
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
            System.out.print(r.getInfo() + " ");
            percorrerEmOrdem(r.getDireita());
        }
    }
    private void percorrerPosOrdem(No r){
        if (r != null){
            percorrerEmOrdem(r.getEsquerda());
            percorrerEmOrdem(r.getDireita());
            System.out.print(r.getInfo() + " ");
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
                System.out.print(r.getInfo() + " ");
            }
        }
    }

    public void emOrdem(){
        if (this.isEmpty()){
            System.out.println("Arvore vazia.");
        }else{
            System.out.print("[ ");
            percorrerEmOrdem(raiz);
            System.out.println("]");
        }
    }
    public void posOrdem(){
        if (this.isEmpty()){
            System.out.println("Arvore vazia.");
        }else{
            System.out.print("[ ");
            percorrerPosOrdem(raiz);
            System.out.println("]");
        }
    }
    public void porNivel(){
        if (this.isEmpty()){
            System.out.println("Arvore vazia.");
        }else{
            System.out.print("[ ");
            passeioPorNivel(raiz);
            System.out.println("]");
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

    public int contarNosRecursivo(No raiz) {
        if (raiz == null) {
            return 0;
        }
        return 1 + contarNosRecursivo(raiz.getEsquerda()) + contarNosRecursivo(raiz.getDireita());
    }

    public int contarNosNaoRecursivo(No raiz) {
        if (raiz == null) {
            return 0;
        }
    
        int contador = 0;
        Stack<No> stack = new Stack<>();
        stack.push(raiz);
    
        while (!stack.isEmpty()) {
            No atual = stack.pop();
            contador++;
    
            if (atual.getDireita() != null) {
                stack.push(atual.getDireita());
            }
    
            if (atual.getEsquerda() != null) {
                stack.push(atual.getEsquerda());
            }
        }
    
        return contador;
    }

    public int contarFolhasRecursivo(No raiz) {
        if (raiz == null) {
            return 0;
        }
    
        if (raiz.getEsquerda() == null && raiz.getDireita() == null) {
            return 1;
        }
    
        return contarFolhasRecursivo(raiz.getEsquerda()) + contarFolhasRecursivo(raiz.getDireita());
    }

    public int contarFolhasNaoRecursivo(No raiz) {
        if (raiz == null) {
            return 0;
        }
    
        int contador = 0;
        Stack<No> stack = new Stack<>();
        stack.push(raiz);
    
        while (!stack.isEmpty()) {
            No atual = stack.pop();
    
            if (atual.getEsquerda() == null && atual.getDireita() == null) {
                contador++;
            }
    
            if (atual.getDireita() != null) {
                stack.push(atual.getDireita());
            }
    
            if (atual.getEsquerda() != null) {
                stack.push(atual.getEsquerda());
            }
        }
    
        return contador;
    }

    public int contarNosNaoTerminaisRecursivo(No raiz) {
        if (raiz == null || (raiz.getEsquerda() == null && raiz.getDireita() == null)) {
            return 0;
        }
    
        return 1 + contarNosNaoTerminaisRecursivo(raiz.getEsquerda()) + contarNosNaoTerminaisRecursivo(raiz.getDireita());
    }

    public int contarNosNaoTerminaisNaoRecursivo(No raiz) {
        if (raiz == null) {
            return 0;
        }
    
        int contador = 0;
        Stack<No> stack = new Stack<>();
        stack.push(raiz);
    
        while (!stack.isEmpty()) {
            No atual = stack.pop();
    
            if (atual.getEsquerda() != null || atual.getDireita() != null) {
                contador++;
            }
    
            if (atual.getDireita() != null) {
                stack.push(atual.getDireita());
            }
    
            if (atual.getEsquerda() != null) {
                stack.push(atual.getEsquerda());
            }
        }
    
        return contador;
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