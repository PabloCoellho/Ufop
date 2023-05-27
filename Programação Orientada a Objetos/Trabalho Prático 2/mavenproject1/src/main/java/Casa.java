public class Casa extends Imovel {
    //Características específicas da Casa
    private int andares;
    private boolean sala_jantar;

    //Construtor
    public Casa (int i, float v, String p, String r, String b, String c, int n, int q, int ba, int a, boolean sj) {
        super(i, v, p, r, b, c, n, q, ba);
        andares = a;
        sala_jantar = sj;
    }

    //Método do printar
    @Override
    public void print() {
        super.print();
        System.out.printf("Andares: %d\n", this.andares);

    }

    //Getters e Setters
    public int getAndares() {
        return andares;
    }
    
    public void setAndares(int a){
        andares = a;
    }
    
    public boolean getSalaJantar() {
        return sala_jantar;
    }
    
    public void setSalaJantar(boolean sj){
        sala_jantar = sj;
    }

}
