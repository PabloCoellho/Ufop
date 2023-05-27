#ifndef MODEL_H
#define MODEL_H

#include "flow.h"
#include "system.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;

class Model{
    protected:
        vector<Flow*> flows;
        vector<System*> systems;

    public:
        Model();
        Model(System*, Flow*);
        virtual ~Model();
        double run(int, int, int);
        void add(System*);
        void add(Flow*);
    
    private:
        Model* operator=(Model*);
};

#endif