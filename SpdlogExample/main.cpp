#include "logger.h"

#include "dummyclass.h"

int main()
{
    Logger::setLevel(spdlog::level::trace);

    LoggerPtr logger = Logger::add("main");

    SPDLOG_LOGGER_INFO(logger, "Application started");

    DummyClass dummy;
    dummy.doSomething();

    return 0;
}
