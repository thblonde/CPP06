#include "ScalarConverter.hpp"
#include <cctype>
#include <exception>
#include <pthread.h>
#include <string>

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
    for (unsigned int i = 0; i < literal.length(); ++i)
    {
        if (std::isalpha(literal[i]))
            return false;
    }

	return !isFloat(literal) && !isDouble(literal);
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

bool    isPseudoLiteral(std::string const literal)
{
    return literal == "-inff" || literal == "+inff" || literal == "nanf"
        || literal == "nan" || literal == "-inf" || literal == "+inf";
}

void    convertInput(std::string & literal, t_type *input)
{
    if (isPseudoLiteral(literal))
    {
        input->type = PSEUDO;
        input->value.pseudo = new char[7];
        strcpy(input->value.pseudo, literal.c_str());
    }
    else if (isChar(literal))
    {
        input->type = CHAR;
        input->value.c = toChar(literal);
    }
    else if (isInt(literal))
    {
        if (!typeLimit(literal, "INT"))
            throw "Int overflow";
        input->type = INT;
        input->value.i = toInt(literal);
    }
    else if (isFloat(literal))
    {
        if (!typeLimit(literal, "FLOAT"))
            throw "Float overflow";
        input->type = FLOAT;
        input->value.f = toFloat(literal);
    }
    else if (isDouble(literal))
    {
        if (!typeLimit(literal, "DOUBLE"))
            throw "Double overflow";
        input->type = DOUBLE;
        input->value.d = toDouble(literal);
    }
    else
        throw "Invalid literal";
}

void    printChar(t_type *input)
{
    switch (input->type)
    {
        case PSEUDO:
            std::cout << "char: impossible" << std::endl;
            break;
        case CHAR:
            std::cout << "char: '" << input->value.c << "'" << std::endl;
            break;
        case INT:
            if (!std::isprint(static_cast<char>(input->value.i)))
                std::cout << "char: Not displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(input->value.i)
                    << "'" << std::endl;
            break;
        case FLOAT:
            if (!std::isprint(static_cast<char>(input->value.f)))
                std::cout << "char: Not displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(input->value.f)
                    << "'" << std::endl;
            break;
        case DOUBLE:
            if (!std::isprint(static_cast<char>(input->value.d)))
                std::cout << "char: Not displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(input->value.d)
                    << "'" << std::endl;
            break;
        default:
            break;
    }  
}

void    printInt(t_type *input, std::string & literal)
{
    switch (input->type)
    {
        case PSEUDO:
            std::cout << "int: impossible" << std::endl;
            break;
        case CHAR:
            std::cout << "int: " << static_cast<int>(input->value.c)
                << std::endl;
            break;
        case INT:
            std::cout << "int: " << input->value.i << std::endl;
            break;
        case FLOAT:
            if (!typeLimit(literal, "INT"))
                std::cout << "int: overflow" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(input->value.f)
                << std::endl;
            break;
        case DOUBLE:
            if (!typeLimit(literal, "INT"))
                std::cout << "int: overflow" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(input->value.d)
                    << std::endl;
            break;
        default:
            break;
    }    
}

void    printFloat(t_type *input, std::string & literal)
{
    switch (input->type)
    {
        case PSEUDO:
            if (!strncmp(input->value.pseudo, "nan", 3)
                || !strncmp(input->value.pseudo, "nanf", 4))
                std::cout << "float: nanf" << std::endl;
            else if (!strncmp(input->value.pseudo, "+inf", 4)
                || !strncmp(input->value.pseudo, "+inff", 5))
                std::cout << "float: +inff" << std::endl;
            else
                std::cout << "float: -inff" << std::endl;
            break;
        case CHAR:
            std::cout << "float: " << static_cast<float>(input->value.c) 
                << ".0f" << std::endl;
            break;
        case INT:
            std::cout << "float: " << static_cast<float>(input->value.i);
             if (input->value.d >= 1e7 || input->value.d <= 1e-4)
                std::cout << "f" << std::endl;
            else
                std::cout << ".0f" << std::endl;
            break;
        case FLOAT:
            std::cout << "float: " << input->value.f;
             if (input->value.f >= 1e7 || input->value.f <= 1e-4)
                std::cout << "f" << std::endl;
            else
                input->value.f == toInt(literal) ? std::cout << ".0f"
                    << std::endl : std::cout << "f" << std::endl;
            break;
        case DOUBLE:
            if (!typeLimit(literal, "FLOAT"))
                std::cout << "float: overflow" << std::endl;
            else
            {
                std::cout << "float: " << static_cast<float>(input->value.d);
                if (input->value.d >= 1e7 || input->value.d <= 1e-4)
                    std::cout << std::endl;
                else
                    input->value.d == toInt(literal) ? std::cout << ".0f"
                        << std::endl : std::cout << "f" << std::endl;
            }
            break;
        default:
            break;
    }    
}

void    printDouble(t_type *input, std::string & literal)
{
    switch (input->type)
    {
        case PSEUDO:
            if (!strncmp(input->value.pseudo, "nan", 3)
                || !strncmp(input->value.pseudo, "nanf", 4))
                std::cout << "double: nan" << std::endl;
            else if (!strncmp(input->value.pseudo, "+inf", 4)
                || !strncmp(input->value.pseudo, "+inff", 5))
                std::cout << "double: +inf" << std::endl;
            else
                std::cout << "double: -inf" << std::endl;
            break;
        case CHAR:
            std::cout << "double: " << static_cast<double>(input->value.c) 
                << ".0" << std::endl;
            break;
        case INT:
            std::cout << "double: " << static_cast<double>(input->value.i);
            if (input->value.d >= 1e7 || input->value.d <= 1e-4)
                std::cout << std::endl;
            else
               std::cout << ".0" << std::endl;
            break;
        case FLOAT:
            std::cout << "double: " << input->value.f;
            if (input->value.d >= 1e7 || input->value.d <= 1e-4)
                std::cout << std::endl;
            else
                input->value.f == toInt(literal) ? std::cout << ".0"
                    << std::endl : std::cout << std::endl;
            break;
        case DOUBLE:
            std::cout << "double: " << input->value.d;
            if (input->value.d >= 1e7 || input->value.d <= 1e-4)
                std::cout << std::endl;
            else
                input->value.d == toInt(literal) ? std::cout << ".0"
                    << std::endl : std::cout << std::endl;
            break;
        default:
            break;
    }    
}

void    ScalarConverter::convert(std::string literal)
{
    t_type  input;
         
    convertInput(literal, &input);

    printChar(&input);
    printInt(&input, literal);
    printFloat(&input, literal);
    printDouble(&input, literal);
 
	if (input.type == PSEUDO)
	    delete input.value.pseudo;
}
