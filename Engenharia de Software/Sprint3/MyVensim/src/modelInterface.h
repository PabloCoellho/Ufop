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
        virtual void add(SystemInt*) = 0;
        virtual void add(Flow*) = 0;
        virtual int sizeSystems() = 0;
        virtual int sizeFlows() = 0;

    private:
        virtual ModelInterface* operator=(ModelInterface*) = 0;
};

#endif