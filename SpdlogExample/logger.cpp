#include "logger.h"

#include <QDebug>

#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

spdlog::level::level_enum Logger::mLevel = spdlog::level::trace;

const spdlog::sink_ptr Logger::mRotatingFileSink =
        std::make_shared<spdlog::sinks::rotating_file_sink_mt>("log.txt", // file name
                                                               5 * 1024 * 1024, // max 5 MB
                                                               5); // max 5 files

LoggerPtr Logger::add(const std::string &name)
{
    try
    {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.push_back(mRotatingFileSink);
        sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

        LoggerPtr logger = std::make_shared<spdlog::logger>(name, sinks.begin(), sinks.end());

        spdlog::register_logger(logger);
        spdlog::set_level(mLevel);

        return logger;
    }
    catch (const spdlog::spdlog_ex &e)
    {
        qWarning() << "Logger " << QString::fromStdString(name) << " exception: " << e.what();
    }
    catch (...)
    {
        qWarning() << "Logger " << QString::fromStdString(name) << " unknown exception";
    }

    return nullptr;
}

void Logger::setLevel(spdlog::level::level_enum level)
{
    mLevel = level;
}
