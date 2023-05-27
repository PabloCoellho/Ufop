#ifndef FLOW_H
#define FLOW_H

#include "system.h"

#include <iostream>
#include <cstdlib>

using namespace std;


class Flow{
    protected:
        System* source;
        System* destination;
        
    public:
        Flow();
        Flow(System*, System*);
        virtual ~Flow();
        void setSource(System*);
        void setDestination(System*);
        System* getSource();
        System* getDestination();
        virtual double function() = 0; //É virtual para que a classe Flow nao possa ser instanciada 
                                       //sem ser herdada e ter essa funcao implementada de forma correta
    
    private:
        Flow* operator= (Flow*);
};

//Toda heranca de Flow implementa function de acordo com sua propria funcao
class Exponential: public Flow{
    public:
        Exponential();
        Exponential(System* source, System* destination):Flow(source, destination){};

        double function();
};

class Logistic: public Flow{
    public:
        Logistic();
        Logistic(System* source, System* destination):Flow(source, destination){};

        double function();
};

#endif