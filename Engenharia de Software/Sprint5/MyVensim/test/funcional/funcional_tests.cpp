#include "funcional_tests.h"
#include "../../src/lib/model.h"

void exponentialFunctionalTest(){
    ModelInterface* ModelExponential = Model::createModel("Expo");

    SystemInt* pop1 = ModelExponential->createSystem(100.0, "pop1");
    SystemInt* pop2 = ModelExponential->createSystem(0.0, "pop2");

    Flow* f = ModelExponential->createFlow<Exponential>(pop1, pop2);
    ModelExponential->run(0, 100, 0);

    assert(fabs(pop1->getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2->getValue() - 63.3968) < 0.0001);

    //cout << endl << "Exponential test OK!" << endl;
}

void logisticalFunctionalTest(){
    ModelInterface* ModelLogistic = Model::createModel("Logistic");
    SystemInt* p1 = ModelLogistic->createSystem(100.0, "p1");
    SystemInt* p2 = ModelLogistic->createSystem(10.0, "p2");
    Flow* l = ModelLogistic->createFlow<Logistic>(p1, p2);

    ModelLogistic->run(0, 100, 0);
    
    assert(fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(fabs(p2->getValue() - 21.7834) < 0.0001);

    //cout << endl << "Logistic test OK!" << endl;
}

void complexFunctionalTest(){
    ModelInterface* model = Model::createModel("Complex");
    SystemInt* q1 = model->createSystem(100.0, "q1");
    SystemInt* q2 = model->createSystem(0.0, "q2");
    SystemInt* q3 = model->createSystem(100.0, "q3");
    SystemInt* q4 = model->createSystem(0.0, "q4");
    SystemInt* q5 = model->createSystem(0.0, "q5");

    Flow* f1 = model->createFlow<Exponential>(q1, q2);
    Flow* f2 = model->createFlow<Exponential>(q1, q3);
    Flow* f3 = model->createFlow<Exponential>(q2, q3);
    Flow* f4 = model->createFlow<Exponential>(q2, q5);
    Flow* f5 = model->createFlow<Exponential>(q3, q4);
    Flow* f6 = model->createFlow<Exponential>(q4, q1);

    model->run(0, 100, 0);
    
    assert(fabs((q1->getValue() - 31.8513)) < 0.0001);
    assert(fabs((q2->getValue() - 18.4003)) < 0.0001);
    assert(fabs((q3->getValue() - 77.1143)) < 0.0001);
    assert(fabs((q4->getValue() - 56.1728)) < 0.0001);
    assert(abs((q5->getValue() - 16.4612)) < 0.0001);

    //cout << endl << "Complex test OK!" << endl;
}
