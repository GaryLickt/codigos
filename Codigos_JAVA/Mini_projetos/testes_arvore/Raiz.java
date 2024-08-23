class Raiz {
    public No no;
    public int nivel;

    public Raiz(){
        this.no = null;
        this.nivel = 0;
    }

    public void inserir_no(int _id){
        if (no == null){
            no = new No(_id);
        }else{
            No aux = no;
            if (aux.id > _id){
                while((aux.id > _id) || (aux == null)){
                    aux = aux.dir;
                }
            }
        }
    }
}
