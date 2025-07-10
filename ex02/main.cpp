#include "Base.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;

    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else if (random == 2)
        return new C;
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "type pointed: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "type pointed: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "type pointed: C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& refA = dynamic_cast<A&>(p);
        static_cast<void>(refA);
        std::cout << "type referenced: A" << std::endl;
    }
    catch(const std::exception& e)
    {
        ;
    }
    try
    {
        B& refB = dynamic_cast<B&>(p);
        static_cast<void>(refB);
        std::cout << "type referenced: B" << std::endl;
    }
    catch(const std::exception& e)
    {
        ;
    }
    try
    {
        C& refC = dynamic_cast<C&>(p);
        static_cast<void>(refC);
        std::cout << "type referenced: C" << std::endl;
    }
    catch(const std::exception& e)
    {
        ;
    }
}

int main()
{
    Base    *ptrBase = generate();
    if (!ptrBase)
        return 1;
    
    Base&   refBase = *ptrBase;

    identify(ptrBase);

    identify(refBase);

    delete ptrBase;
    return (0);
}
