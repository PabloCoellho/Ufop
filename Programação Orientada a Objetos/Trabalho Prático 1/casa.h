#ifndef CASACLASS_H
#define CASACLASSE_H
#include "imovel.h"

class Casa : public Imovel
{
    int andares;
    bool sala_jantar;

public:
    Casa(int i, float v, std::string p, std::string r, std::string b, std::string c, int n, int q, int ba, int a, bool sj);
    std::ostream& print(std::ostream& os) const override;
    int getAndares() const;
    void setAndares(int a);
    bool getSalaJantar() const;
    void setSalaJantar(float sj);
};

#endif