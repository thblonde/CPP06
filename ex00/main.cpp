#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		exit(1);
	}

	std::string literal = argv[1];
	ScalarConverter::convert(literal);
	int	i = 42;
	float	f = 42.0f;

	if (i == f)
		std::cout << "OK";
	else
		std::cout <<"KO";
	return 0;
}
