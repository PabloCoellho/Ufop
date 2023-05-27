#include "flow.h"

Flow::Flow(){
    source = NULL; //systema de origem
    destination = NULL; //systema de destino
}

Flow::Flow(SystemInt* s, SystemInt* d){ //define os systemas de origem e destino
    source = s;
    destination = d;
}

Flow::~Flow(){}

void Flow::setSource (SystemInt* s){
    source = s;
}

void Flow::setDestination(SystemInt* d){
    destination = d;
}

SystemInt* Flow::getSource(){
    return source;
}

SystemInt* Flow::getDestination(){
    return destination;
}

Flow* Flow::operator=(FlowInterface* flow){ //atribuir usando "=" invés de criar uma cópia, atribuição
    if (this == flow)
        return this;
        
    this->source = flow->getSource();
    this->destination = flow->getSource();
    return this;
}

double Exponential::function(){
    return 0.01 * this->getSource()->getValue();
}

double Logistic::function(){
    return 0.01 * this->getDestination()->getValue() * (1 - this->getDestination()->getValue() / 70);
}

double UnitFlow::function(){
    return 0;
}
