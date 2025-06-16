#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstdlib>
# include <string>
# include <climits>
# include <cfloat>

class ScalarConverter {
public:
	static void convert( std::string & literal );

private:
	ScalarConverter();
	ScalarConverter( const ScalarConverter & copy );
	ScalarConverter& operator=( const ScalarConverter & assign );
	~ScalarConverter();
};

std::ostream & operator<<( std::ostream & out, const ScalarConverter & value );

#endif

