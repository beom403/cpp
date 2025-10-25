#include <cstdint>
#include <iostream>

constexpr uint32_t CORE_ID = 1;

class HCoreTargetAccessTest
{
public:
    bool operator()(void)
    {
        if (CORE_ID != 0)
        {
            std::cout << "test executed on core ID: " << CORE_ID << std::endl;
            return true;
        }
        std::cout << "Single access test executed." << std::endl;
        return true;
    }
};

class SequentialAccessTest
{
public:
    bool operator()(void)
    {
        std::cout << "Single access test executed." << std::endl;
        return true;
    }
};

class SimultaneousAccessTest
{
public:
    bool operator()(void)
    {
        std::cout << "Simultaneous access test executed." << std::endl;
        return true;
    }
};