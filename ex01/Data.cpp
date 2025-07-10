#include "Data.hpp"

Data::Data()
: c('0'), i(0), f(0), d(0)
{
    std::cout << "Data default constructor" << std::endl;
}

Data::Data(char c, int i, float f, double d)
: c(c), i(i), f(f), d(d)
{
    std::cout << "Data constructor" << std::endl;
}

Data::Data(Data const & src)
{
    std::cout << "Data copy constructor" << std::endl;
    *this = src;
}

Data::~Data()
{
    std::cout << "Data destructor" << std::endl;
}

Data& Data::operator=(Data const & rhs)
{
    std::cout << "Data copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        this->c = rhs.c;
        this->i = rhs.i;
        this->f = rhs.f;
        this->d = rhs.d;
    }
    return *this;
}

char    Data::getChar() const
{
    return this->c;
}

int    Data::getInt() const
{
    return this->i;
}

float    Data::getfloat() const
{
    return this->f;
}

double    Data::getDouble() const
{
    return this->d;
}

std::ostream& operator<<(std::ostream& out, Data& src)
{
    out << "char: " << src.getChar() << std::endl;
    out << "int: " << src.getInt() << std::endl;
    out << "float: " << src.getfloat() << std::endl;
    out << "double: " << src.getDouble() << std::endl;
    return out;
}
