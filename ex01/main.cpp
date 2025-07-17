#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data('*', 42, 42.0f, 42.0);
    uintptr_t intptr = Serializer::serialize(ptr);
    Data *copy = Serializer::deserialize(intptr);
    std::cout << *copy;
    delete copy;
}
