#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>
# include <string>

class Data
{
    public:
        Data();
        Data(char c, int i, float f, double d);
        Data(Data const & src);
        ~Data();

        Data& operator=(Data const & rhs);

        char    getChar() const;
        int     getInt() const;
        float   getfloat() const;
        double  getDouble() const;

    private:

    
        char    c;
        int     i;
        float   f;
        double  d;
};

std::ostream& operator<<(std::ostream& out, Data& src);

#endif