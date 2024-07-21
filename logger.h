#ifndef LOGGER_H
#define LOGGER_H


#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <QString>
#include "spdlog/sinks/rotating_file_sink.h"

class Logger
{
public:

    Logger();
    static Logger& instance();
    void info(const QString& msg);
    void warn(const QString& msg);
    void error(const QString& msg);
    void debug(const QString& msg);

private:
    std::shared_ptr<spdlog::logger> logger;

};
#endif // LOGGER_H
