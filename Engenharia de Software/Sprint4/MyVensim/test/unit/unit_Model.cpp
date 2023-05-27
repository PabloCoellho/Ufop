#include "unit_Model.h"

void unit_Model_constructor(){
    ModelInterface* m = new Model();
    SystemInt* s = new System();

    m->add(s);

    assert(m->sizeFlows() == 0);
    assert(m->sizeSystems() == 1);

    //cout << endl << "Model Constructor OK";
}

void unit_Model_destructor(){
    double bef, aft, aux;

    memory_usage(bef, aux);
    ModelInterface* M = new Model();
    delete M;
    memory_usage(aft, aux);    
    assert(bef == aft);

    //cout << endl << "Model Destructor OK";
}

void unit_Model_run(){
    ModelInterface* M = new Model();
    SystemInt* pop1= new System();
    pop1->setValue(100.0);
    SystemInt* pop2 = new System();
    pop2->setValue(0.0);
    Flow* f = new Exponential(pop1,pop2);
    M->add(f);
    M->add(pop1);
    M->add(pop2);
    M->run(0,100, 1);
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);

    //cout << endl << "Model run OK";
}

void unit_Model_add_System(){
    ModelInterface* m = new Model();
    SystemInt* s = new System();

    m->add(s);
    assert(m->sizeSystems() == 1);

    //cout << endl << "Model add system OK";
}

void unit_Model_add_Flow(){
    ModelInterface* m = new Model();
    Flow* f = new Exponential();

    m->add(f);
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