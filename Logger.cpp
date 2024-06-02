#include "Logger.h"

Logger::Logger(const std::string& filename) {
    m_file.open("log.txt", std::ios::app);
}

void Logger::log(const std::string& message) {
    if (m_file.is_open()) {
        m_file << message << std::endl;
    }
}