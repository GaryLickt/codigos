class ResultadoBusca<T> {
  ArvoreBNo<T> no;
  int posicao;

  ResultadoBusca(ArvoreBNo<T> no, int posicao) {
      this.no = no;
      this.posicao = posicao;
  }
}