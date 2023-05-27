#ifndef FLOWINTERFACE_H
#define FLOWINTERFACE_H

#include "systemInterface.h"

#include <iostream>
#include <cstdlib>

using namespace std;

class FlowInterface{
    public:
        virtual ~FlowInterface(){};
        virtual void setSource(SystemInt*) = 0;
        virtual void setDestination(SystemInt*) = 0;
        virtual SystemInt* getSource() = 0;
        virtual SystemInt* getDestination() = 0;
        virtual double function() = 0;

    private:
        virtual FlowInterface* operator= (FlowInterface*) = 0;
};

#endif