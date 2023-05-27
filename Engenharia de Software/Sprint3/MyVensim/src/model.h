#ifndef MODEL_H
#define MODEL_H

#include "flow.h"
#include "modelInterface.h"
#include "systemInterface.h"
#include "flowInterface.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;

class Model: public ModelInterface{
    protected:
        vector<Flow*> flows;
        vector<SystemInt*> systems;

    public:
        Model();
        Model(SystemInt*, Flow*);
        virtual ~Model();
        double run(int, int, int);
        void add(SystemInt*);
        void add(Flow*);
        int sizeSystems();
        int sizeFlows();
        
    private:
        Model* operator=(ModelInterface*);
};

#endif