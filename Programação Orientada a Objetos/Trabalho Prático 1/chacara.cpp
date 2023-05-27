#include "chacara.h"
#include "imovel.h"

using namespace std;

//Construtor
Chacara::Chacara(int i, float v, std::string p, std::string r, std::string b, std::string c, int n, int q, int ba, bool sf, bool sj, bool cf, bool ch, bool pi) : Imovel(i, v, p, r, b, c, n, q, ba){
    salao_festa = sf;
    salao_jogos = sj;
    campo_futebol = cf;
    churrasqueira = ch;
    piscina = pi;
}

//Overload do método print
std::ostream& Chacara::print(std::ostream& os) const{
    os  << "----\n"
        << "\t" << this->getProprietario() << "\n"
        << "\t" << this->getValor() << "\n"
        << "\t" << this->getQuartos() << "\n"
        << "\t" << this->getRua() << "\n"
        << "\t" << this->getBairro() << "\n"
        << "\t" << this->getCidade() << "\n"
        << "\t" << ((this->getPiscina()) ? "Possui piscina" : "Não possui piscina") << "\n"
        << "----\n";
    return os;
}

//Getters e Setters
bool Chacara::getSalaoFesta() const{
    return salao_festa;
}

void Chacara::setSalaoFesta(bool sf){
    salao_festa = sf;
}

bool Chacara::getSalaoJogos() const{
    return salao_jogos;
}

void Chacara::setSalaoJogos(bool sj){
    salao_jogos = sj;
}
 
bool Chacara::getCampoFutebol() const{
    return campo_futebol;
}

void Chacara::setCampoFutebol(bool cf){
    campo_futebol = cf;
}

bool Chacara::getChurrasqueira() const{
    return churrasqueira;
}

void Chacara::setChurrasqueira(bool c){
    churrasqueira = c;
}

bool Chacara::getPiscina() const{
    return piscina;
}

void Chacara::setPiscina(bool p){
    piscina = p;
}