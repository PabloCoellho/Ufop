#include "unit_Model.h"

void unit_Model_constructor(){
    ModelInterface* m = ModelInterface::createModel("unit_const");
    SystemInt* s;
    s = m->createSystem(100, "test");

    assert(m->sizeFlows() == 0);
    assert(m->sizeSystems() == 1);

    //cout << endl << "Model Constructor OK";
}

void unit_Model_destructor(){
    double bef, aft, aux;

    memory_usage(bef, aux);
    ModelInterface* M = Model::createModel("unit_dest");    
    delete M;
    memory_usage(aft, aux);    
    assert(bef == aft);

    //cout << endl << "Model Destructor OK";
}

void unit_Model_run(){
    ModelInterface* M = Model::createModel("unit_run");
    SystemInt* pop1;
    pop1 = M->createSystem(100.0, "test");
    SystemInt* pop2;
    pop2 = M->createSystem(0.0, "test2");

    Flow* f;
    f = M->createFlow<Exponential>(pop1, pop2);

    M->run(0,100, 1);
    assert(fabs(pop1->getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2->getValue() - 63.3968) < 0.0001);

    //cout << endl << "Model run OK";
}

void unit_Model_add_System(){
    ModelInterface* m = Model::createModel("unit_addS");
    SystemInt* s;
    s = m->createSystem(100.0, "test");

    assert(m->sizeSystems() == 1);

    //cout << endl << "Model add system OK";
}

void unit_Model_add_Flow(){
    ModelInterface* m = Model::createModel("unit_addF");
    Flow* f;
    f = m->createFlow<Exponential>(nullptr, nullptr);

    assert(m->sizeFlows() == 1);

    //cout << endl << "Model add flows OK";
}
void run_unit_test_Model(){
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_run();
    unit_Model_add_System();
    unit_Model_add_Flow();
}