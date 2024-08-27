package codigos.Codigos_JAVA.Aulas.Lista3;

public class ABB {
  private ABBNode root;

  public ABB() {
      this.root = null;
  }

  public boolean isEmpty() {
      return root == null;
  }

  public void insert(Produto produto) {
      root = insertRec(root, produto);
  }

  private ABBNode insertRec(ABBNode root, Produto produto) {
      if (root == null) {
          root = new ABBNode(produto);
          return root;
      }
      if (produto.compareTo(root.produto) < 0)
          root.left = insertRec(root.left, produto);
      else if (produto.compareTo(root.produto) > 0)
          root.right = insertRec(root.right, produto);
      return root;
  }

  public Produto search(String codigo) {
      return searchRec(root, codigo);
  }

  private Produto searchRec(ABBNode root, String codigo) {
      if (root == null || root.produto.getCodigo().equals(codigo))
          return root == null ? null : root.produto;

      if (codigo.compareTo(root.produto.getCodigo()) < 0)
          return searchRec(root.left, codigo);

      return searchRec(root.right, codigo);
  }

  public void inOrderTraversal() {
      inOrderTraversalRec(root);
  }

  private void inOrderTraversalRec(ABBNode root) {
      if (root != null) {
          inOrderTraversalRec(root.left);
          System.out.println(root.produto);
          inOrderTraversalRec(root.right);
      }
  }
}
