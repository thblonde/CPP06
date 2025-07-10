#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	std::cout << "ScalarConverter: Copy constructor called" << std::endl;
	(void)src;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & rhs)
{
	std::cout << "ScalarConverter: Assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter: Destructor called" << std::endl;
}

std::ostream& operator<<( std::ostream& out, ScalarConverter const & value)
{
	(void)value;
	return out;
}

/* You have to first detect the type of the literal passed as a parameter, convert it from
	string to its actual type, then convert it explicitly to the three other data types. Lastly,
	display the results as shown below. */
	
bool	typeLimit(std::string const & literal, std::string type)
{
	if (type == "CHAR")
	{
		std::stringstream	ss(literal);
		int	test_limit;
		ss >> test_limit;
		if (test_limit > CHAR_MAX || test_limit < CHAR_MIN)
			return false;
	}
	else if (type == "INT")
	{
		std::stringstream	ss(literal);
		long	test_limit;
		ss >> test_limit;
		if (test_limit > INT_MAX || test_limit < INT_MIN)
			return false;
	}
	else if (type == "FLOAT")
	{
		std::stringstream	ss(literal);
		double	test_limit;
		ss >> test_limit;
		if (test_limit > FLT_MAX || test_limit < FLT_MIN)
			return false;
	}
	else if (type == "DOUBLE")
	{
		std::stringstream	ss(literal);
		long double	test_limit;
		ss >> test_limit;
		if (test_limit > DBL_MAX || test_limit < FLT_MIN)
			return false;
	}
	return true;
}

bool	isChar(std::string const & literal)
{
	int len = literal.length();

	if (len == 1 && !std::isdigit(literal[0]))
		return true;

	return false;
}

bool isFloat(std::string const & literal)
{
	if (literal.length() > 3 && literal.at(literal.length() - 1) == 'f'
	    && literal.find(".") != std::string::npos)
	    return true;

	return false;
}

bool isDouble(std::string const & literal)
{
	if (!isFloat(literal) && literal.find(".") != std::string::npos)
	    return true;

	return false;
}

bool	isInt(std::string const & literal)
{
	return !isFloat(literal) && !isDouble(literal)
	    && typeLimit(literal, "INT");
}

char	toChar(std::string const & literal)
{
	std::stringstream	ss(literal);
	char	c;

	ss >> c;
	return c;
}

int		toInt(std::string const & literal)
{
	std::stringstream	ss(literal);
	int	i;

	ss >> i;
	return i;
}

float	toFloat(std::string const & literal)
{
	std::string	floating = literal.substr(0, literal.length() - 1);
	std::stringstream	ss(floating);
	float	f;

	ss >> f;

	return f;
}

float	toDouble(std::string const & literal)
{
	std::stringstream	ss(literal);
	double	f;

	ss >> f;

	return f;
}

void ScalarConverter::convert(std::string const literal)
{
	if (isChar(literal))
	{
		char	c = toChar(literal);
		if (!std::isprint(c))
			std::cout << "char: Not displayable" << std::endl;
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else if (isInt(literal))
	{
		int		i = toInt(literal);
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else if (isFloat(literal))
	{
		float	f = toFloat(literal);
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f;
		f == toInt(literal) ? std::cout << ".0f" << std::endl : std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f);
		f == toInt(literal) ? std::cout << ".0" << std::endl : std::cout << std::endl;
	}
	else if (isDouble(literal))
	{
		double	d = toDouble(literal);
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d);
		d == toInt(literal) ? std::cout << ".0f" << std::endl : std::cout << "f" << std::endl;
		std::cout << "double: " << d;
		d == toInt(literal) ? std::cout << ".0" << std::endl : std::cout << std::endl;
	}
	
}
