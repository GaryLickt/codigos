package codigos.Codigos_JAVA.Aulas.Lista3;

public class Cadastro {
    private ABB produtos;

    public Cadastro() {
        this.produtos = new ABB();
    }

    public void cadastrarProduto(Produto produto) {
        if (produtos.search(produto.getCodigo()) == null) {
            produtos.insert(produto);
            System.out.println("Produto cadastrado com sucesso.");
        } else {
            System.out.println("Produto com o mesmo código já existe.");
        }
    }

    public void exibirProdutos() {
        if (produtos.isEmpty()) {
            System.out.println("Nenhum produto cadastrado.");
        } else {
            produtos.inOrderTraversal();
        }
    }

    public Produto procurarProduto(String codigo) {
        return produtos.search(codigo);
    }

    public void alterarPreco(String codigo, double novoPreco) {
        Produto produto = procurarProduto(codigo);
        if (produto != null) {
            produto.setPreco(novoPreco);
            System.out.println("Preço alterado com sucesso.");
        } else {
            System.out.println("Produto não encontrado.");
        }
    }

    public void alterarQuantidade(String codigo, int novaQuantidade) {
        Produto produto = procurarProduto(codigo);
        if (produto != null) {
            produto.setQuantidade(novaQuantidade);
            System.out.println("Quantidade alterada com sucesso.");
        } else {
            System.out.println("Produto não encontrado.");
        }
    }

    public void exibirInformacoesProduto(String codigo) {
        Produto produto = procurarProduto(codigo);
        if (produto != null) {
            System.out.println(produto);
        } else {
            System.out.println("Produto não encontrado.");
        }
    }
}
