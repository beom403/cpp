#include <cstdint>
#include <typeinfo>
#include "Logger.hpp"

constexpr uint32_t CORE_ID = 0;

class BaseTestModule
{
public:
    BaseTestModule()
    {
        m_Log.SetCaller(__PRETTY_FUNCTION__);
    }
protected:
    Logger m_Log;
};

class HCoreTargetAccessTest : public BaseTestModule
{
public:
    HCoreTargetAccessTest()
    {
        m_Log.SetCaller(__func__);
    }

    bool operator()(void)
    {
        if (CORE_ID != 0)
        {
            m_Log.LogInfo("HCore access test skipped for non-core 0.");
            return true;
        }
        m_Log.LogInfo("test start.");
        m_Log.LogInfo("test done.");
        return true;
    }
};

class SequentialAccessTest : public BaseTestModule
{
public:
    SequentialAccessTest()
    {
        m_Log.SetCaller(__func__);
    }
    bool operator()(void)
    {
        m_Log.LogInfo("test start.");
        m_Log.LogInfo("test done.");
        return true;
    }
};

class SimultaneousAccessTest : public BaseTestModule
{
public:
    SimultaneousAccessTest()
    {
        m_Log.SetCaller(__func__);
    }
    bool operator()(void)
    {
        m_Log.LogInfo("test start.");
        m_Log.LogInfo("test done.");
        return true;
    }
};