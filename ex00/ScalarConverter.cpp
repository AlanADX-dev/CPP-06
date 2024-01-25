#include "ScalarConverter.hpp"

void		ScalarConverter::convert(std::string& literal)
{
	/*-------------------CHAR-------------------*/
	std::cout << "char: ";
	if (literal.size() > 1 && !std::isdigit(literal[1]) && !std::isdigit(literal[2]))
		std::cout << "impossible" << std::endl;
	else if (literal.size() > 1 && std::isdigit(literal[1]) && std::isdigit(literal[2]) && std::stoi(literal) >= 32 && std::stoi(literal) <= 126)
		std::cout << "'" << convToChar(literal) << "'" << std::endl;
	else if (literal.size() > 1 && std::isdigit(literal[1]) && std::stoi(literal) >= 32 && std::stoi(literal) <= 126)
		std::cout << "'" << convToChar(literal) << "'" << std::endl;
	else if (std::isdigit(literal[0]))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << literal.at(0) << std::endl;


	/*-------------------INT-------------------*/
	if (!std::isdigit(literal[0]))
		std::cout << "int: impossible" << std::endl;
	else if (std::stoi(literal) >= -2147483648 && std::stoi(literal) <= 2147483647)
		std::cout << "int: " << convToInt(literal) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;


	// /*-------------------FLOAT-------------------*/
	if (literal.compare("-inf") == 0)
		std::cout << "float: -inff" << std::endl;
	else if (literal.compare("+inf") == 0)
		std::cout << "float: +inff" << std::endl;
	else if (literal.compare("nan") == 0)
		std::cout << "float: nanf" << std::endl;
	else if (!std::isdigit(literal[0]))
		std::cout << "float: impossible" << std::endl;
	else
	{
		float floatValue = convToFloat(literal);
		float integralPart;
		float fractionalPart = std::modf(floatValue, &integralPart);

		if (fractionalPart == 0 && literal.find('.') == std::string::npos)
			std::cout << "float: " << integralPart << ".0f" << std::endl;
		else if (fractionalPart == 0 && literal.find('.') != std::string::npos)
			std::cout << "float: " << integralPart << ".0f" << std::endl;
		else if (fractionalPart != 0 && literal.find('.') == std::string::npos)
			std::cout << "float: " << fractionalPart << "f" << std::endl;
		else
			std::cout << "float: " << floatValue << "f" << std::endl;
	}


	// /*-------------------DOUBLE-------------------*/
	if (literal.compare("-inf") == 0)
		std::cout << "double: -inf" << std::endl;
	else if (literal.compare("+inf") == 0)
		std::cout << "double: +inf" << std::endl;
	else if (literal.compare("nan") == 0)
		std::cout << "double: nan" << std::endl;
	else if (!std::isdigit(literal[0]))
		std::cout << "double: impossible" << std::endl;
	else
	{
		double doubleValue = convToDouble(literal);
		double intPart;
		double fractPart = std::modf(doubleValue, &intPart);

		if (fractPart == 0 && literal.find('.') == std::string::npos)
			std::cout << "double: " << intPart << ".0" << std::endl;
		else if (fractPart == 0 && literal.find('.') != std::string::npos)
			std::cout << "double: " << intPart << ".0" << std::endl;
		else if (fractPart != 0 && literal.find('.') == std::string::npos)
			std::cout << "double: " << fractPart << std::endl;
		else
			std::cout << "double: " << doubleValue << std::endl;
	}
}

char		ScalarConverter::convToChar(std::string& literal)
{
	return static_cast<char>(std::stoi(literal));
}

int			ScalarConverter::convToInt(std::string& literal)
{
	return static_cast<int>(std::stoi(literal));
}

float		ScalarConverter::convToFloat(std::string& literal)
{
	return static_cast<float>(std::stof(literal));
}

double		ScalarConverter::convToDouble(std::string& literal)
{
	return static_cast<double>(std::stod(literal));
}
