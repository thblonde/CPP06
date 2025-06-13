#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	std::cout << "ScalarConverter: Copy constructor called" << std::endl;
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& assign) {
	std::cout << "ScalarConverter: Assignment operator called" << std::endl;
	if (this != &assign) {
	
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter: Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ScalarConverter& value) {
	(void)value;
	return out;
}

bool isFloat(std::string& literal) {
	int len = literal.length();
	if (literal[len - 1] == 'f')
		return true;
	return false;
}

bool isDouble(std::string& literal) {
	if (isFloat(literal) == false && literal.find('.') != std::string::npos)
		return true;
	return false;
}

bool isChar(std::string& literal) {
	int len = literal.length();
	if (len == 1 && !std::isdigit(literal[0]))
		return true;
	return false;
}

bool isInt(std::string& literal) {
	if (!isFloat(literal) && !isDouble(literal) && !isChar(literal))
		return true;
	return false;
}

void ScalarConverter::convert(std::string& literal) {
	if (isFloat(literal))
		std::cout << "float";
	else if (isDouble(literal))
		std::cout << "double";
	else if (isChar(literal))
		std::cout << "char";
	else if (isInt(literal))
		std::cout << "int";
}