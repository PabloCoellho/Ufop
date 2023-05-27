#include "model.h"

Model::Model(){}

Model::Model(SystemInt* s, Flow* f){
    systems.push_back(s);
    flows.push_back(f);
}

Model::~Model(){
    //O destrutor deleta o espaço alocado para flow e system
    for (auto it = flows.begin(); it != flows.end(); it++) 
        delete *it;
    for (auto it = systems.begin(); it != systems.end(); it++)
        delete *it;
}

void Model::add(SystemInt* s){ //adiciona um system no model
    systems.push_back(s);
}

void Model::add(Flow* f){ //adiciona um flow no model
    flows.push_back(f);
}

double Model::run(int start, int finish, int initValue){
    //Run executa a juncao dos flows com os systems, e atualiza todos os valores
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

int Model::sizeFlows(){
    return flows.size();
}

int Model::sizeSystems(){
    return systems.size();
}

Model* Model::operator=(ModelInterface* model){
    if(this == model)
        return this;

    /**int size = model->flows.size();
    for (int i=0; i < size; i++){
        Flow* aux = this->flows[i];
        model->flows.push_back(aux);
    }

    size = model->systems.size();
    for (int i=0; i < size; i++){
        SystemInt* aux = this->systems[i];
        model->systems.push_back(aux);
    }**/

    return this;
}
