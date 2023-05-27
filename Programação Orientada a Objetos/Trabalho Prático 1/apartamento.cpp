#include "apartamento.h"
#include "imovel.h"
 
//Construtor
Apartamento::Apartamento(int i, float v, std::string p, std::string r, std::string b, std::string c, int n, int q, int ba, int a, float tc, bool e, bool s) : Imovel(i, v, p, r, b, c, n, q, ba){
    andar = a;
    taxa_condominio = tc;
    elevador = e;
    sacada = s;
}

//Overload do método print
std::ostream& Apartamento::print(std::ostream& os) const{
    os  << "----\n"
        << "\t" << this->getProprietario() << "\n"
        << "\t" << this->getValor() << "\n"
        << "\t" << this->getQuartos() << "\n"
        << "\t" << this->getRua() << "\n"
        << "\t" << this->getBairro() << "\n"
        << "\t" << this->getCidade() << "\n"
        << "\t" << ((this->getElevador()) ? "Possui elevador" : "Não possui elevador") << "\n"
        << "----\n";
    return os;
}

//Getters e Setters
int Apartamento::getAndar() const{
    return andar;
}

void Apartamento::setAndar(int a){
    andar = a;
}

float Apartamento::getTaxaCondominio() const{
    return taxa_condominio;
}

void Apartamento::setTaxaCondominio(float tc){
    taxa_condominio = tc;
}

bool Apartamento::getElevador() const{
    return elevador;
}

void Apartamento::setElevador(bool e){
    elevador = e;
}

bool Apartamento::getSacada() const{
    return sacada;
}

void Apartamento::setSacada(bool s){
    sacada = s;
}