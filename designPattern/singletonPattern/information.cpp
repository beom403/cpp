#include <iostream>

class Information
{
    private:
        Information() {};
        ~Information() {};

    public:
        static Information* getInstance()
        {
            // static initializer is safe @ c++11
            static Information* pobjInformation = new Information();
            return pobjInformation;
        };
        void testPrint()
        {
            std::cout<<"test print for singleton pattern"<<std::endl;
        }
};