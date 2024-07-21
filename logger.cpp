#include "logger.h"


Logger::Logger() {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern("[%H:%M:%S] [%^%l%$] %v");

    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("E:\\New Folder2\\ExxportAndImportV2\\logs.txt", 1024 * 1024 * 5, 3);
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

    std::vector<spdlog::sink_ptr> sinks {console_sink, file_sink};
    this->logger = std::make_shared<spdlog::logger>("multi_sink", sinks.begin(), sinks.end());
    spdlog::register_logger(this->logger);
    this->logger->set_level(spdlog::level::debug);
    this->logger->flush_on(spdlog::level::debug);
}

Logger& Logger::instance() {
    static Logger logger;
    return logger;
}

void Logger::info(const QString& msg){
    logger->info(msg.toStdString());

}

void Logger::warn(const QString& msg){
    logger->warn(msg.toStdString());

}

void Logger::error(const QString& msg){
    logger->error(msg.toStdString());
}

void Logger::debug(const QString& msg){
    logger->debug(msg.toStdString());
}
