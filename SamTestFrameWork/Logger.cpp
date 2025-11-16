#include "Logger.hpp"

void Logger::SetCaller(const std::string& strCaller)
{
    m_strCaller = strCaller;
}

void Logger::LogInfo()
{
    std::cout << std::endl;
}

