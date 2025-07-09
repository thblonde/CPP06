#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstdlib>
# include <string>
# include <climits>
# include <cfloat>
# include <sstream>

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
