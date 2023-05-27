#ifndef CHACARACLASS_H
#define CHACARACLASS_H
#include "imovel.h"

class Chacara : public Imovel
{
    bool salao_festa;
    bool salao_jogos;
    bool campo_futebol;
    bool churrasqueira;
    bool piscina;
    
public:
    Chacara(int i, float v, std::string p, std::string r, std::string b, std::string c, int n, int q, int ba, bool sf, bool sj, bool cf, bool ch, bool pi);
    std::ostream& print(std::ostream& out) const override;
    bool getSalaoFesta() const;
    void setSalaoFesta(bool sf);
    bool getSalaoJogos() const;
    void setSalaoJogos(bool sj);
    bool getCampoFutebol() const;
    void setCampoFutebol(bool cf);
    bool getChurrasqueira() const;
    void setChurrasqueira(bool c);
    bool getPiscina() const;
    void setPiscina(bool p);
};

#endif