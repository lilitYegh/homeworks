
#include <iostream>
class Singleton
{
    private:
        static Singleton* instance;
        int m_num{0};
        Singleton(int num) : m_num{num}
        {}
        Singleton() = default;
    public:
        static Singleton* getInstance(int num = 0)
        {
            if(!instance)
            {
                instance = new Singleton;
            }
            return instance;
        }
        void setNum(int num)
        {
            m_num = num;
        }
        int getNum()
        {
            return m_num;
        }
    
};

Singleton* Singleton::instance = nullptr;
int main() 
{
    Singleton* inst = Singleton::getInstance();
    std::cout << inst->getNum() << "\n";
    Singleton* inst1 = Singleton::getInstance(2);
    std::cout << inst->getNum() << "\n";
    inst1->setNum(2);
    std::cout << inst->getNum() << " " << inst1->getNum() << "\n";
    return 0;
}
