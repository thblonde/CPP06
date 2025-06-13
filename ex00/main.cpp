#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		exit(1);
	}
	std::string literal = argv[1];
	ScalarConverter::convert(literal);
	return 0;
}
