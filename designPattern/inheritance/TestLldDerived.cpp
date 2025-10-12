#include "TestLldBase.cpp"

class TestLldDerived : public TestLldBase
{
public:
    TestLldDerived() : TestLldBase()
    {
        m_nPublicNum = 100;
    };
};