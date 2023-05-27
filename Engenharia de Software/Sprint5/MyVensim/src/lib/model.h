#ifndef MODEL_H
#define MODEL_H

#include "modelInterface.h"
#include "systemInterface.h"
#include "flowInterface.h"
#include "handleBodySemDebug.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iterator>

using namespace std;

class ModelBody: public Body{
    protected:
        vector<Flow*> flows;
        vector<SystemInt*> systems;
        static vector<ModelInterface*> models;
        string id;
    public:
        ModelBody();
        ModelBody(string);
        virtual ~ModelBody();
        double run(int, int, int);
        int sizeSystems();
        int sizeFlows();
        SystemInt* createSystem(double, string);
        static ModelInterface* createModel(string);
        void add(SystemInt*);
        void add(Flow*);
        void setId(string);
    private:
        ModelBody* operator=(ModelInterface*);
};

class ModelHandle : public Handle<ModelBody>, public ModelBody{
    public:
        ModelHandle() : Handle() {}
        virtual ~ModelHandle() {}
        static ModelInterface* createModel(string id){
            ModelHandle* m = new ModelHandle();
            m->setId(id);
            m->pImpl_->add(m);
            return m;
        }
        double run(int start,int finish){
            return pImpl_->run(start, finish);
        }
        System* createSystem(string name,double value){
            return pImpl_->createSystem(name, value);
        }
        System* getSystem(string name){
            return pImpl_->getSystem(name);
        }
        vector<Flow*> getFlows(){
            return pImpl_->getFlows();
        }
        string getId(){
            return pImpl_->getId();
        }
        void setId(string id){
            pImpl_->setId(id);
        }
        void add(System* system){
            pImpl_->add(system);
        }
        void add(Flow* flow){
            pImpl_->add(flow);
        }
        void add(ModelInterface* model) {
            pImpl_->add(model);
        }
};

#endif