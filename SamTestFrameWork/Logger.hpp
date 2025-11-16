#pragma once

#include <iostream>
#include <string>

class Logger
{
public:
    void SetCaller(const std::string& strCaller);
    // Base case
    void LogInfo();
    template<typename T, typename... Args>
    void LogInfo(const T& first, const Args&... args)
    {
        std::cout << "LOG: [Caller: " << m_strCaller << "]: " << first << " ";
        LogInfo(args...);
    }
private:
    std::string m_strCaller;
};
