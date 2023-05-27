#ifndef APARTAMENTOCLASS_H
#define APARTAMENTOCLASS_H
#include "imovel.h"

class Apartamento : public Imovel
{
    int andar;
    float taxa_condominio;
    bool elevador;
    bool sacada;

public:
    Apartamento(int i, float v, std::string p, std::string r, std::string b, std::string c, int n, int q, int ba, int a, float tc, bool e, bool s);
    Apartamento();
    std::ostream& print(std::ostream& os) const override;
    int getAndar() const;
    void setAndar(int a);
    float getTaxaCondominio() const;
    void setTaxaCondominio(float tc);
    bool getElevador() const;
    void setElevador(bool e);
    bool getSacada() const;
    void setSacada(bool s);
};

#endif