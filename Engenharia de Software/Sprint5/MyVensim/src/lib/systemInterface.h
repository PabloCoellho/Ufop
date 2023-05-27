#ifndef SYSTEMINTERFACE_H
#define SYSTEMINTERFACE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class SystemInt{
    public:
        virtual ~SystemInt(){};
        virtual void setName(string) = 0;
        virtual void setValue(double) = 0;
        virtual string getName() = 0;
        virtual double getValue() = 0;

    private:
        virtual SystemInt* operator=(SystemInt*) = 0;
};

#endif