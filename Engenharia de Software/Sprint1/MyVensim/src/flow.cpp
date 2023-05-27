#include "flow.h"

Flow::Flow(){
    source = NULL; //systema de origem
    destination = NULL; //systema de destino
}

Flow::Flow(System* s, System* d){ //define os systemas de origem e destino
    source = s;
    destination = d;
}

Flow::~Flow(){}

void Flow::setSource (System* s){
    source = s;
}

void Flow::setDestination(System* d){
    destination = d;
}

System* Flow::getSource(){
    return source;
}

System* Flow::getDestination(){
    return destination;
}

Flow* Flow::operator=(Flow* flow){ //atribuir usando "=" invés de criar uma cópia, atribuição
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