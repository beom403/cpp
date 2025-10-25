#include <cstdint>
#include <iostream>

template <typename T>
class SamTestCaseTemplate
{
public:
    // methodes
    SamTestCaseTemplate(uint32_t nTicketNumber) : m_nTicketNumber(nTicketNumber) {};

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
        std::cout << "Executing test case for ticket number: " << m_nTicketNumber << std::endl;
        if (m_PreProcess)
        {
            std::cout << "Executing pre-process function." << std::endl;
            bRet &= m_PreProcess();
        }
        if (m_MainProcess)
        {
            std::cout << "Main test case execution logic goes here." << std::endl;
            bRet &= m_MainProcess();
        }
        if (m_PostProcess)
        {
            std::cout << "Executing post-process function." << std::endl;
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
};