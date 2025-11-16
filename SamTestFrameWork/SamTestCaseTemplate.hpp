#include <cstdint>
#include <iostream>
#include "Logger.hpp"

template <typename T>
class SamTestCaseTemplate
{
public:
    // methodes
    SamTestCaseTemplate(uint32_t nTicketNumber) : m_nTicketNumber(nTicketNumber)
    {
        m_Log.SetCaller("TestCase Ticket#" + std::to_string(nTicketNumber));
    };

    SamTestCaseTemplate& SetPreProc(T PreProcess)
    {
        m_PreProcess = PreProcess;
        return *this;
    };

    SamTestCaseTemplate& SetMainProc(T MainProcess)
    {
        m_MainProcess = MainProcess;
        return *this;
    };

    SamTestCaseTemplate& SetPostProc(T PostProcess)
    {
        m_PostProcess = PostProcess;
        return *this;
    };

    bool ExecuteTestCase(void)
    {
        bool bRet = true;
        if (m_PreProcess)
        {
            m_Log.LogInfo("Executing pre-process function.");
            bRet &= m_PreProcess();
        }
        if (m_MainProcess)
        {
            m_Log.LogInfo("Executing main-process function.");
            bRet &= m_MainProcess();
        }
        if (m_PostProcess)
        {
            m_Log.LogInfo("Executing post-process function.");
            bRet &= m_PostProcess();
        }
        return bRet;
    };

protected:
    // attributes
    uint32_t m_nTicketNumber = 0;
    T m_PreProcess{};
    T m_MainProcess{};
    T m_PostProcess{};
    Logger m_Log;
};