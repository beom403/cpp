#include <cstdint>
#include <iostream>

class TestLldBase
{
public:
    // attributes
    uint32_t m_nPublicNum = 0;
    // methodes
    TestLldBase()
    {
    };
    void PrintAllMembers(void)
    {
        std::cout << this << std::endl;
        std::cout << "public: " << m_nPublicNum << " , private: " << m_nPrivateNum << std::endl;
    };

private:
    uint32_t m_nPrivateNum = 1;
};
