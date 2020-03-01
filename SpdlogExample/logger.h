#ifndef LOGGER_H
#define LOGGER_H

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "spdlog/spdlog.h"

using LoggerPtr = std::shared_ptr<spdlog::logger>;

class Logger
{
public:
    static LoggerPtr add(const std::string &name);
    static void setLevel(spdlog::level::level_enum level);
private:
    static spdlog::level::level_enum mLevel;
    static const spdlog::sink_ptr mRotatingFileSink;
};

#endif // LOGGER_H
