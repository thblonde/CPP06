#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstdlib>
# include <iterator>
# include <string>
# include <climits>
# include <cfloat>
# include <sstream>
# include <string.h>
# include <iomanip>

enum Type
{
	PSEUDO,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};
	
union Value
{
    char    *pseudo;
	char	c;
	int		i;
	float	f;
	double	d;
};

typedef struct	s_type	
{
    Type    type;
    Value   value;
}           t_type;

class ScalarConverter
{
	public:
		static void convert(std::string const literal);
		
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();

		ScalarConverter& operator=(ScalarConverter const & rhs );
};

std::ostream & operator<<(std::ostream& out, ScalarConverter const & value);

#endif
