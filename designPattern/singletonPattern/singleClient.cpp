#include "information.cpp"

int main()
{
    Information* pobjInfo = Information::getInstance();
    pobjInfo->testPrint();
    return 0;
}