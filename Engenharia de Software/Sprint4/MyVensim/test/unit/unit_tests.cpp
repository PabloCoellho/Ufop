#include "unit_tests.h"

void testFlow(){
    System* s1 = new System();
    System* s2 = new System();

    Flow* test1 = new Exponential(s1,s2);
    assert(test1->getSource() == s1);
    assert(test1->getDestination() == s2);

    Flow* test2 = new Logistic(s1,s2);

    assert(test2->getSource() == s1); //teste
    assert(test2->getDestination() == s2);

    //cout << endl << "Flow test OK!" << endl;
}

void testModel(){
    Model* modelTest = new Model();
    System* s1= new System();
    s1->setValue(100.0);
    System* s2 = new System();
    s2->setValue(0.0);
    Exponential* f = new Exponential(s1,s2);
    modelTest->add(f);
    modelTest->add(s1);
    modelTest->add(s2);

    //cout << endl << "Model test OK!" << endl;
}

void testSystem(){
    System* s1 = new System();
    s1->setName("Name");
    s1->setValue(0);

    assert(s1->getName() == "Name"); //teste
    assert(s1->getValue() == 0);

    //cout << endl << "System test OK!\n" << endl;
}