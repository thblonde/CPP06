#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data    *ptrdata = new Data('*', 42, 42.0f, 42.0);

    std::cout << std::endl;

    std::cout << *ptrdata << std::endl;
    
    uintptr_t   i = Serializer::serialize(ptrdata);

    std::cout << "i: " << i << std::endl;

    std::cout << std::endl;

    ptrdata = Serializer::deserialize(i);

    std::cout << *ptrdata << std::endl;

    delete ptrdata;
    return 0;
}
