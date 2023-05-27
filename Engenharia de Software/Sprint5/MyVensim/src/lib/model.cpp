#include "model.h"
#include "system.h"
#include "flow.h"

using namespace std;

vector<ModelInterface*> ModelBody:: models;

ModelBody::ModelBody(){}

ModelBody::ModelBody(string ids){
    this->id = ids;
}

ModelBody::~ModelBody(){
    //! O destrutor deve deletar o espaço alocado para flow e system
    //!
    for (auto it = flows.begin(); it != flows.end(); it++) 
        delete *it;
    for (auto it = systems.begin(); it != systems.end(); it++)
        delete *it;
    // for (auto it = models.begin(); it != models.end(); it++)
    //     delete *it;
    //delete[] &models;
}

void ModelBody::add(SystemInt* s){
    systems.push_back(s);
}

void ModelBody::add(Flow* f){
    flows.push_back(f);
}

double ModelBody::run(int start, int finish, int initValue){
    //!Run executa a junção dos flows com os 
    //!systems, e atualiza todos os valores.
    vector<double> values;
    SystemInt* source;
    SystemInt* destination;
    int size = flows.size();

    for (int i = start; i < finish; i++){
        for(int j=0; j< size; j++){
            values.push_back(flows[j]->function());
        }
        for(int k=0; k < size; k++){
            source = flows[k]->getSource();
            destination = flows[k]->getDestination();
            source->setValue(source->getValue() - values[k]);
            destination->setValue(destination->getValue() + values[k]);
        }
        values.clear();
    }

    return values[finish];
}

int ModelBody::sizeFlows(){
    return flows.size();
}

int ModelBody::sizeSystems(){
    return systems.size();
}

SystemInt* ModelBody::createSystem(double value, string name){
    SystemInt* s = new System(value, name);
    this->add(s);
    return s;
}

ModelInterface* ModelInterface::createModel(string id){
    return ModelBody::createModel(id);
}
