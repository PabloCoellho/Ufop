#ifndef MODELINTERFACE_H
#define MODELINTERFACE_H

#include "flow.h"
#include "systemInterface.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;

class ModelInterface{
    public:
        virtual ~ModelInterface(){};
        virtual double run(int, int, int) = 0;
        static ModelInterface* createModel(string);
        virtual SystemInt* createSystem(double, string) = 0;
        virtual int sizeSystems() = 0;
        virtual int sizeFlows() = 0;
        template <typename typeFlow>
        Flow* createFlow(SystemInt* source = nullptr, SystemInt* destination = nullptr){
            Flow* flow = new typeFlow();
            flow->setSource(source);
            flow->setDestination(destination);
            add(flow);
            return flow;
        }
    private:
        virtual void add(SystemInt*) = 0;
        virtual void add(Flow*) = 0;
};


#endif