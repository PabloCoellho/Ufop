package main;

import java.util.Comparator;

public abstract class Imovel{
    //Características comuns a todos os imóveis
    protected int id;
    protected float valor;
    protected String proprietario;
    protected String rua;
    protected String bairro;
    protected String cidade;
    protected int numero;
    protected int quartos;
    protected int banheiros;
    static final Comparator<Imovel> comparator = new Comparator<Imovel>() {
        @Override
        public int compare(Imovel o1, Imovel o2) {
            if(o1.valor > o2.valor) return 1;
            else if(o1.valor < o2.valor) return -1;
            else return 0;
        }
    };
    
    static final Comparator<Imovel> comparatorR = new Comparator<Imovel>() {
        @Override
        public int compare(Imovel o1, Imovel o2) {
            if(o1.valor < o2.valor) return 1;
            else if(o1.valor > o2.valor) return -1;
            else return 0;
        }
    };

    //Construtor
    public Imovel (int i, float v, String p, String r, String b, String c, int n, int q, int ba) {
        id = i;
        valor = v;
        proprietario = p;
        rua = r;
        bairro = b;
        cidade = c;
        numero = n;
        quartos = q;
        banheiros = ba;
    }
    
    public Imovel(){};

    //Método de printar
    public void print() {  
        System.out.printf("Proprietario: %s \n", this.getProprietario());
        System.out.printf("Preco: R$%f \n", this.getValor());
        System.out.printf("Numero de quartos: %d \n", this.getQuartos());
        System.out.printf("Rua: %s \n", this.getRua());
        System.out.printf("Bairro: %s \n", this.getBairro());
        System.out.printf("Cidade: %s \n", this.getCidade());

    }

    //Getters e Setters
    public int getId() {
        return id;
    }

    public void setId(int i){
        id = i;
    }

    public float getValor() {
        return valor;
    }

    public void setValor(float v){
        valor = v;
    }

    public String getProprietario() {
        return proprietario;
    }

    public void setProprietario(String p) {
        proprietario = p;
    }

    public String getRua() {
        return rua;
    }

    public void setRua(String r){
        rua = r;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String b){
        bairro = b;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String c){
        cidade = c;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int n){
        numero = n;
    }

    public int getQuartos() {
        return quartos;
    }

    public void setQuartos(int q){
        quartos = q;
    }

    public int getBanheiros() {
        return banheiros;
    }

    public void setBanheiros(int b){
        banheiros = b;
    }
}
