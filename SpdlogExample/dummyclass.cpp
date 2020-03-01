#include "dummyclass.h"

DummyClass::DummyClass()
    : mLogger(Logger::add("dummy"))
{
    SPDLOG_LOGGER_INFO(mLogger, "Dummy class created");
}

void DummyClass::doSomething()
{
    int value = 0;
    SPDLOG_LOGGER_CRITICAL(mLogger, "Something went wrong");
    SPDLOG_LOGGER_TRACE(mLogger, "Last known value: {}", value);
}
