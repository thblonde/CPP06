#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer default constructor" << std::endl;
}

Serializer::Serializer(Serializer const & src)
{
    std::cout << "Serializer copy constructor" << std::endl;
    static_cast<void>(src);
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor" << std::endl;
}

Serializer& Serializer::operator=(Serializer const & rhs)
{
    std::cout << "Serializer copy assignment operator" << std::endl;
    static_cast<void>(rhs);
    return *this;
}

uintptr_t   Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data    *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
