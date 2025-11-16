#include <vector>
#include <functional>
#include "SamTestCaseTemplate.hpp"
#include "MemoryTestModule.cpp"
#include "Logger.hpp"

class BasicTestPlan
{
public:
    BasicTestPlan(void)
    {
        m_Log.SetCaller(__func__);
        //////////////////////////////////////////////////////////////////////////////
        // create test modules
        //////////////////////////////////////////////////////////////////////////////
        static HCoreTargetAccessTest s_objHCoreTest;
        static SequentialAccessTest s_objSeqTest;
        static SimultaneousAccessTest s_objSimulTest;
        //////////////////////////////////////////////////////////////////////////////
        // create test cases
        //////////////////////////////////////////////////////////////////////////////
        static SamTestCaseTemplate<std::function<bool()>> s_objTestCase_0001(1);
        s_objTestCase_0001
            .SetPreProc(s_objHCoreTest)
            .SetMainProc(s_objSeqTest)
            .SetPostProc(s_objSeqTest);
        static SamTestCaseTemplate<std::function<bool()>> s_objTestCase_0002(3);
        s_objTestCase_0002
            .SetPreProc(s_objHCoreTest)
            .SetMainProc(s_objSimulTest)
            .SetPostProc(s_objHCoreTest);
        //////////////////////////////////////////////////////////////////////////////
        // store test case
        //////////////////////////////////////////////////////////////////////////////
        m_TestCases.push_back(&s_objTestCase_0001);
        m_TestCases.push_back(&s_objTestCase_0002);
    };

    void RunAllTests(void)
    {
        m_Log.LogInfo("Starting all test cases execution.");
        for (auto testCase : m_TestCases)
        {
            testCase->ExecuteTestCase();
        }
    };
private:
    std::vector<SamTestCaseTemplate<std::function<bool()>>*> m_TestCases;
    Logger m_Log;
};
