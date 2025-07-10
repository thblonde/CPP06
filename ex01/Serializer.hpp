#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"
class Serializer
{
    public:
        static uintptr_t    serialize(Data *ptr);
        static Data        *deserialize(uintptr_t raw);
    
    private:
        Serializer();
        Serializer(char c, int i, float f, double d);
        Serializer(Serializer const & src);
        ~Serializer();

        Serializer& operator=(Serializer const & rhs);
    
};

std::ostream& operator<<(std::ostream& out, Serializer& src);

#endif
