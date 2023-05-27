#include "unit_Flow.h"

void unit_Flow_constructor(){
    SystemInt* s1 = new System(0.2, "Name");
    SystemInt* s2 = new System(0.5, "Destination");
    Flow* f = new Exponential(s1, s2);

    assert(f->getSource() == s1);
    assert(f->getDestination() == s2);

    SystemInt* s3 = new System(10, "Second");
    SystemInt* s4 = new System(20, "First");
    Flow* f2 = new Logistic(s3, s4);

    assert(f2->getSource() == s3);
    assert(f2->getDestination() == s4);

    Flow* f3 = new UnitFlow();
    assert(f3->function() == 0);

    //cout << endl << "Flow constructor OK";
}

void unit_Flow_destructor(){
    double bef, aft, aux;
    memory_usage(bef, aux);    
    Flow* f = new Exponential();
    delete (f);
    memory_usage(aft, aux); 
    assert(bef == aft);

    //cout << endl << "Flow destructor OK";
}

void unit_Flow_setSource(){
    Flow* f = new Exponential();
    SystemInt* s = new System();
    f->setSource(s);

    assert(f->getSource() == s);

    //cout << endl << "Flow set source OK";
}

void unit_Flow_setDestination(){
    Flow* f = new Exponential();
    SystemInt* s = new System();
    f->setDestination(s);

    assert(f->getDestination() == s);

    //cout << endl << "Flow set destination OK";
}

void unit_Flow_getSource(){
    SystemInt* s1 = new System(10,"Source");
    Flow* f = new Exponential(s1, NULL);
    SystemInt* s2 = f->getSource();

    assert(s1->getName() == s2->getName());
    assert(s1->getValue() == s2->getValue());

    //cout << endl << "Flow get source OK";
}
void unit_Flow_getDestination(){
    SystemInt* s1 = new System(10,"Destination");
    Flow* f = new Exponential(NULL, s1);
    SystemInt* s2 = f->getDestination();

    assert(s1->getName() == s2->getName());
    assert(s1->getValue() == s2->getValue());

    //cout << endl << "Flow get destination OK";
}

void unit_Flow_operator(){
    SystemInt* s1 = new System(10, "Source");
    SystemInt* s2 = new System(20, "Destination");

    Flow* f = new Exponential(s1, s2);
    Flow* f2 = f;

    assert(f->getSource() == f2->getSource());
    assert(f->getDestination() == f2->getDestination());

    //cout << endl << "Flow operator overcharge OK";
}

void run_unit_test_Flow(){
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_setSource();
    unit_Flow_setDestination();
    unit_Flow_getSource();
    unit_Flow_getDestination();
    unit_Flow_operator();
}