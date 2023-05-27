#include "casa.h"
#include "imovel.h"
 
//Construtor
Casa::Casa(int i, float v, std::string p, std::string r, std::string b, std::string c, int n, int q, int ba, int a, bool sj) : Imovel(i, v, p, r, b, c, n, q, ba){
    andares = a;
    sala_jantar = sj;
}

//Overload do método print
std::ostream& Casa::print(std::ostream& os) const{
    os  << "----\n"
        << "\t" << this->getProprietario() << "\n"
        << "\t" << this->getValor() << "\n"
        << "\t" << this->getQuartos() << "\n"
        << "\t" << this->getRua() << "\n"
        << "\t" << this->getBairro() << "\n"
        << "\t" << this->getCidade() << "\n"
        << "\t" << this->getAndares() << "\n"
        << "----\n";
    return os;
}

//Getters e Setters
int Casa::getAndares() const{
    return andares;
}

void Casa::setAndares(int a){
    andares = a;
}

bool Casa::getSalaJantar() const{
    return sala_jantar;
}

void Casa::setSalaJantar(float sj){
    sala_jantar = sj;
}