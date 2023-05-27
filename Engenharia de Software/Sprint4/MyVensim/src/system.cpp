#include "system.h"

System::System(){
    value = 0;
    name = " ";
}

System::System(double v, string n){
    value = v;
    name = n;
}

System::~System() {}

void System::setName(string n){
    name = n;
}

void System::setValue(double v){
    value = v;
}

string System::getName(){
    return name;
}

double System::getValue(){
    return value;
}

System* System::operator=(System* system){
    if (this == system)
        return this;
    this->name = system->getName();
    this->value = system->getValue();
    return this;
}