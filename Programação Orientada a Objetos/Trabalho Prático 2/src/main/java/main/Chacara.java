package main;

public class Chacara extends Imovel {
    //Características específicas da chácara
    private boolean salao_festa;
    private boolean salao_jogos;
    private boolean campo_futebol;
    private boolean churrasqueira;
    private boolean piscina;

    //Construtor
    public Chacara (int i, float v, String p, String r, String b, String c, int n, int q, int ba, boolean sf, boolean sj, boolean cf, boolean ch, boolean pi) {
        super(i, v, p, r, b, c, n, q, ba);
        salao_festa = sf;
        salao_jogos = sj;
        campo_futebol = cf;
        churrasqueira = ch;
        piscina = pi;
    }

    //Método do printar
    @Override
    public void print() {
        super.print();
        if(piscina == true)
            System.out.printf("Tem piscina\n\n");
        else
            System.out.println("Não tem piscina\n\n");
    }

    //Getters e Setters
    public boolean getSalaoFesta() {
        return salao_festa;
    }

    public void setSalaoFesta(boolean sf){
        salao_festa = sf;
    }

    public boolean getSalaoJogos() {
        return salao_jogos;
    }

    public void setSalaoJogos(boolean sj){
        salao_jogos = sj;
    }

    public boolean getCampoFutebol() {
        return campo_futebol;
    }

    public void setCampoFutebol(boolean cf){
        campo_futebol = cf;
    }

    public boolean getChurrasqueira() {
        return churrasqueira;
    }

    public void setChurrasqueira(boolean c){
        churrasqueira = c;
    }

    public boolean getPiscina() {
        return piscina;
    }

    public void setPiscina(boolean p){
        piscina = p;
    }
}
