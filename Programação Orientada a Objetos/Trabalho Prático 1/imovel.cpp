#include "imovel.h"
#include <string>

//Construtor
Imovel::Imovel(int i, float v, std::string p, std::string r, std::string b, std::string c, int n, int q, int ba){
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

/** 
 * Método virtual que vai ser sobrecarregado pelas classes que importarem Imovel
 *  É necessário para possibilidar que o polimorfismo no momento de imprimir os dados
 *  seja mantido:
 * 
 *  Ex:
 *  std::vector<Imovel*> imoveis;
 *  Se neste container tiver um objeto Apartamento, sem o método virtual, caso esse objeto
 *  seja impresso, ele vai ser tratado como um objeto de tipo Imovel em vez de Apartamento
 */
std::ostream& Imovel::print(std::ostream& os) const{
    os  << "----\n"
        << "\t" << this->getProprietario() << "\n"
        << "\t" << this->getValor() << "\n"
        << "\t" << this->getQuartos() << "\n"
        << "\t" << this->getRua() << "\n"
        << "\t" << this->getBairro() << "\n"
        << "\t" << this->getCidade() << "\n"
        << "----\n";
    return os;
}

/**
 * Overload do operador << para possibilitar a sintaxe:
 * cout << Imovel;
 */
std::ostream& operator<<(std::ostream& os, const Imovel& im){
    return im.print(os);
}

//Getters e Setters
int Imovel::getId() const{
    return id;
}

void Imovel::setId(int i){
    id = i;
}

float Imovel::getValor() const{
    return valor;
}

void Imovel::setValor(float v){
    valor = v;
}

std::string Imovel::getProprietario() const{
    return proprietario;
}

void Imovel::setProprietario(std::string p){
    proprietario = p;
}

std::string Imovel::getRua() const{
    return rua;
}

void Imovel::setRua(std::string r){
    rua = r;
}

std::string Imovel::getBairro() const{
    return bairro;
}

void Imovel::setBairro(std::string b){
    bairro = b;
}

std::string Imovel::getCidade() const{
    return cidade;
}

void Imovel::setCidade(std::string c){
    cidade = c;
}

int Imovel::getNumero() const{
    return numero;
}

void Imovel::setNumero(int n){
    numero = n;
}

int Imovel::getQuartos() const{
    return quartos;
}

void Imovel::setQuartos(int q){
    quartos = q;
}

int Imovel::getBanheiros() const{
    return banheiros;
}

void Imovel::setBanheiros(int b){
    banheiros = b;
}