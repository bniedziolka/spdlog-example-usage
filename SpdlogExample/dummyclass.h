#ifndef DUMMYCLASS_H
#define DUMMYCLASS_H

#include "logger.h"

class DummyClass
{
public:
    DummyClass();
    void doSomething();
private:
    LoggerPtr mLogger;
};

#endif // DUMMYCLASS_H
