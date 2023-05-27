public class Apartamento extends Imovel{
    //Características específicar do Apartamento
    private int andar;
    private float taxa_condominio;
    private boolean elevador;
    private boolean sacada;

    //Construtor
    public Apartamento (int i, float v, String p, String r, String b, String c, int n, int q, int ba, int a, float tc, boolean e, boolean s) {
        super(i, v, p, r, b, c, n, q, ba);
        andar = a;
        taxa_condominio = tc;
        elevador = e;
        sacada = s;
    }

    //Método do printar
    @Override
    public void print() {
        super.print();
        if (elevador == true)
            System.out.printf("Tem elevador\n");

    }

    //Getters e Setters
    public int getAndar() {
        return andar;
    }

    public void setAndar(int a){
        andar = a;
    }

    public float getTaxaCondominio() {
        return taxa_condominio;
    }

    public void setTaxaCondominio(float tc) {
        taxa_condominio = tc;
    }

    public boolean getElevador() {
        return elevador;
    }

    public void setElevador(boolean e){
        elevador = e;
    }

    public boolean getSacada() {
        return sacada;
    }

    public void setSacada(boolean s){
        sacada = s;
    }
}
