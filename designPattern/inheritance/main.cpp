#include "TestLldDerived.cpp"

int main(void)
{
    TestLldBase base;
    TestLldDerived derived;
    base.PrintAllMembers();
    derived.PrintAllMembers();

    return 0;
}