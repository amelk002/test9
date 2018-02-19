#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "Base.h"
#include <cstdlib>
using namespace std;

class Connector: public Base {
    protected:

    Base* lhs; //left hand operand of the connector
    Base* rhs; //right hand operand of the connector

    public:

    //constructors
    Connector(Base* lhs, Base* rhs);
    Connector();

    virtual bool execute(int in, int out) = 0; //execute function to be overridden by derived classes
    virtual string get_data();
};


class AND: public Connector {
    public:
    //constructors
    AND(Base* lhs, Base* rhs);
    AND();
    virtual bool execute(int in, int out);
};


class OR: public Connector {
    //constructors
    public:
    OR(Base* lhs, Base* rhs);
    OR();
    //execute function
    virtual bool execute(int in, int out);
};

class Semicolon: public Connector {
    public:
    //constructors
    Semicolon(Base* lhs, Base* rhs);
    Semicolon();

    //executes both of its children regardless of the success of the
    //other child
    //returns true or false based on the success of the right child
    virtual bool execute(int in, int out);
};

#endif
