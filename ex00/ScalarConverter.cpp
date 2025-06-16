#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter & copy ) {
	std::cout << "ScalarConverter: Copy constructor called" << std::endl;
	(void)copy;
}

ScalarConverter & ScalarConverter::operator=( const ScalarConverter & assign ) {
	std::cout << "ScalarConverter: Assignment operator called" << std::endl;
	if ( this != &assign ) {
	
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter: Destructor called" << std::endl;
}

std::ostream& operator<<( std::ostream & out, const ScalarConverter & value ) {
	(void)value;
	return out;
}

bool isFloat( std::string & literal ) {
	int len = literal.length();

	if ( literal[len - 1] == 'f' && literal.substr( 0, len - 1 ).find( '.' ) )
		return true;
	return false;
}

bool isDouble( std::string & literal ) {
	if ( isFloat( literal ) == false && literal.find( '.' ) != std::string::npos )
		return true;
		
	return false;
}

bool isChar( std::string & literal ) {
	int len = literal.length();
	
	if ( len == 1 && !std::isdigit( literal[0] ) && std::isprint( literal[0] ) )
		return true;
		
	return false;
}

bool isInt( std::string & literal ) {
	if ( !isFloat( literal ) && !isDouble( literal ) && !isChar( literal ) )
		return true;
		
	return false;
}

void toChar( std::string & literal ) {
	if ( isChar( literal ))
		std::cout << "char: '" << static_cast<char>( literal[0] ) << "'" << std::endl;
	else if ( isInt( literal ) || isFloat( literal ) || isDouble( literal )) {
		if ( std::isprint( atoi(literal.c_str() )))
			std::cout << "char: '" << static_cast<char>( atoi(literal.c_str() ) ) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void toInt( std::string & literal ) {
    long tmp = atol( literal.c_str() );
    
    if ( tmp < INT_MIN || tmp > INT_MAX )
  		std::cout << "int: impossible" << std::endl;
    else
  		std::cout << "int: " << static_cast<int>( tmp ) << std::endl;
}

void toFloat( std::string & literal ) {
    double tmp = atof( literal.c_str() );
    
    if ( tmp < FLT_MIN || tmp > FLT_MAX )
        std::cout << "float: impossible" << std::endl;
    else
  		std::cout << "float: " << static_cast<float>( tmp ) << ".0f" << std::endl;
}

void toDouble( std::string & literal ) {
    char **endptr = NULL;
    long double tmp = strtold( literal.c_str() , endptr );
    
    if ( tmp < LDBL_MIN || tmp > LDBL_MAX )
        std::cout << "double: impossible" << std::endl;
    else
  		std::cout << "double: " << static_cast<double>( tmp ) << std::endl;
}

void ScalarConverter::convert(std::string & literal) {
	toChar( literal );
	toInt( literal );
	toFloat( literal );
	toDouble( literal );
}
