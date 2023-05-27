#ifndef FLOW_H
#define FLOW_H

#include "systemInterface.h"
#include "flowInterface.h"

#include <iostream>
#include <cstdlib>

using namespace std;

class Flow: public FlowInterface {
    protected:
        SystemInt* source;
        SystemInt* destination;

    public:
        Flow();
        Flow(SystemInt*, SystemInt*);
        virtual ~Flow();
        void setSource(SystemInt*);
        void setDestination(SystemInt*);
        SystemInt* getSource();
        SystemInt* getDestination();
        virtual double function() = 0; //É virtual para que a classe Flow nao possa ser intanciada
                                       //sem ser herdada e ter essa funcao implementada de forma correta
    private:
        Flow* operator= (FlowInterface*);
        Flow(const Flow &flow);
};

//Toda heranca de Flow implementa function de acordo com sua propria funcao
class Exponential: public Flow{
    public:
        Exponential(){};
        Exponential(SystemInt* source, SystemInt* destination):Flow(source, destination){};
        double function();
};

class Logistic: public Flow{
    public:
        Logistic(){};
        Logistic(SystemInt* source, SystemInt* destination):Flow(source, destination){};
        double function();
};

class UnitFlow: public Flow{
    public:
        UnitFlow(){};
        UnitFlow(SystemInt* source, SystemInt* destination):Flow(source, destination){};
        double function();
};

#endif