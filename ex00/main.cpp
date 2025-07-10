#include "ScalarConverter.hpp"
#include <stdexcept>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		exit(1);
	}

	std::string literal = argv[1];
	
	try 
	{
	    ScalarConverter::convert(literal);
	}
	catch (const char* & e)
	{
	    std::cerr << e << std::endl;
	}
	
	return 0;
}
