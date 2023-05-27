#ifndef IMOVELCLASS_H
#define IMOVELCLASS_H
#include <string>
#include <iostream>

class Imovel
{
    int id;
    
    std::string proprietario;
    std::string rua;
    std::string bairro;
    std::string cidade;
    int numero;
    int quartos;
    int banheiros;
    float valor;
public:
    Imovel(int i, float v, std::string p, std::string r, std::string b, std::string c, int n, int q, int ba);
    Imovel();
    friend std::ostream& operator<<(std::ostream& os, const Imovel& im);
    virtual std::ostream& print(std::ostream& os) const = 0;
    int getId() const;
    void setId(int i);
    float getValor() const;
    void setValor(float v);
    std::string getProprietario() const;
    void setProprietario(std::string p);
    std::string getRua() const;
    void setRua(std::string r);
    std::string getBairro() const;
    void setBairro(std::string b);
    std::string getCidade() const;
    void setCidade(std::string c);
    int getNumero() const;
    void setNumero(int n);
    int getQuartos() const;
    void setQuartos(int q);
    int getBanheiros() const;
    void setBanheiros(int b);
};

#endif