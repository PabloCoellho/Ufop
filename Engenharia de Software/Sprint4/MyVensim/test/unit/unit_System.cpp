#include "unit_System.h"

void unit_System_constructor(){
    SystemInt* s = new System(10.0, "Name");
    assert(s->getName() == "Name");
    assert(s->getValue() == 10.0);
    
    //cout << endl << "System constructor OK";
}

void unit_System_destructor(){
    double bef, aft, aux;
    memory_usage(bef, aux);
    SystemInt* s = new System(10.0, "Name");
    delete s;
    memory_usage(aft, aux);
    assert(bef == aft);

    //cout << endl << "System destructor OK";
}
void unit_System_setName(){
    SystemInt* s = new System();
    s->setName("Name");
    assert(s->getName() == "Name");

    //cout << endl << "System set name OK";
}

void unit_System_setValue(){
    SystemInt* s = new System();
    s->setValue(10);
    assert(s->getValue() == 10);

    //cout << endl << "System set value OK";
}

void unit_System_getName(){
    SystemInt* s = new System(10, "Name");
    string x = s->getName();
    assert(x == "Name");

    //cout << endl << "System get name OK";
}

void unit_System_getValue(){
    SystemInt* s = new System(10, "Name");
    double x = s->getValue();
    assert(x == 10);

    //cout << endl << "System get value OK";
}

void unit_System_operator(){
    SystemInt* s1 = new System(10, "Name");
    SystemInt* s2 = s1;

    assert(s1->getValue() == s2 -> getValue());
    assert(s1->getName() == s2->getName());

    //cout << endl << "System operator overcharge OK";
}

void run_unit_test_System(){
    unit_System_constructor();
    unit_System_destructor();
    unit_System_setName();
    unit_System_setValue();
    unit_System_getName();
    unit_System_getValue();
    unit_System_operator();
}