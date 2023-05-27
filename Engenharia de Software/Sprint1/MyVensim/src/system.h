#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <cstdlib>

using namespace std;

class System{
    protected:
        double value;
        string name;
        
    public:
        System();
        System(double, string);
        virtual ~System();
        void setName(string);
        void setValue(double);
        string getName();
        double getValue();

    private:
        System* operator=(System*);
};

#endif