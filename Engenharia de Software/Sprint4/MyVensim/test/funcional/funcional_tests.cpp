#include "funcional_tests.h"

void exponentialFunctionalTest(){
    Model* ModelExponential = new Model();

    System* pop1= new System();
    pop1->setValue(100.0);
 
    System* pop2 = new System();
    pop2->setValue(0.0);

    Exponential* f = new Exponential(pop1, pop2);

    ModelExponential->add(f);
    ModelExponential->add(pop1);
    ModelExponential->add(pop2);
    ModelExponential->run(0, 100, 0);

    assert(fabs(pop1->getValue() - 36.6032) < 0.0001); //teste
    assert(fabs(pop2->getValue() - 63.3968) < 0.0001);

    //cout << endl << "Exponential test OK!" << endl;
}

void logisticalFunctionalTest(){
    Model* ModelLogistic = new Model();
    System* p1= new System();
    p1->setValue(100.0);

    System* p2 = new System();
    p2->setValue(10.0);

    Logistic* l = new Logistic(p1, p2);
    
    ModelLogistic->add(l);
    ModelLogistic->add(p1);
    ModelLogistic->add(p2);
    ModelLogistic->run(0, 100, 0);
    
    assert(fabs(p1->getValue() - 88.2167) < 0.0001); //teste
    assert(fabs(p2->getValue() - 21.7833) < 0.0001);

    //cout << endl << "Logistic test OK!" << endl;
}

void complexFunctionalTest(){
    System* q1 = new System();
    q1->setValue(100.0);
    System* q2 = new System();
    q2->setValue(0.0);
    System* q3 = new System();
    q3->setValue(100.0);
    System* q4 = new System();
    q4->setValue(0.0);
    System* q5 = new System();
    q5->setValue(0.0);
    
    Flow* f1 = new Exponential(q1, q2);
    Flow* f2 = new Exponential(q1, q3);
    Flow* f3 = new Exponential(q2, q5);
    Flow* f4 = new Exponential(q2, q3);
    Flow* f5 = new Exponential(q3, q4);
    Flow* f6 = new Exponential(q4, q1);

    Model* model = new Model();
    model->add(q1);
    model->add(q2);
    model->add(q3);
    model->add(q4);
    model->add(q5);
    model->add(f1);
    model->add(f2);
    model->add(f3);
    model->add(f4);
    model->add(f5);
    model->add(f6);


    model->run(0, 100, 0);
    assert(fabs((q1->getValue() - 31.8513)) < 0.0001); //teste
    assert(fabs((q2->getValue() - 18.4003)) < 0.0001);
    assert(fabs((q3->getValue() - 77.1143)) < 0.0001);
    assert(fabs((q4->getValue() - 56.1728)) < 0.0001);
    assert(fabs((q5->getValue() - 16.4612)) < 0.0001);

    //cout << endl << "Complex test OK!\n" << endl;
}