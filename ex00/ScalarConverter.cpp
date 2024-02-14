#include "ScalarConverter.hpp"

int my_stoi(const std::string& str)
{
	int result;
	std::istringstream iss(str);
	iss >> result;
	return result;
}

float my_stof(const std::string& str)
{
	float result;
	std::istringstream iss(str);
	iss >> result;
	return result;
}

double my_stod(const std::string& str)
{
	double result;
	std::istringstream iss(str);
	iss >> result;
	return result;
}

const char	*ScalarConverter::InvalidOutput::what(void) const throw()
{
	return ("ERROR: Invalid input\n");
}

void	ScalarConverter::convert(const char *input)
{
	char	c;
	int		i;
	float	f;
	double	d;
	std::string	type = ScalarConverter::getType(input);

	if (type == "error")
		throw(InvalidOutput());
	else if (type == "char")
		ScalarConverter::isChar(input, &c, &i, &f, &d);
	else if (type == "int")
		ScalarConverter::isInt(input, &c, &i, &f, &d);
	else if (type == "float")
		ScalarConverter::isFloat(input, &c, &i, &f, &d);
	else if (type == "double")
		ScalarConverter::isDouble(input, &c, &i, &f, &d);


	if (type == "special" and input[0] == 'n')
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: nanf" << std::endl << "double: nan" << std::endl;
	else if (type == "special")
		std::cout << "char: impossible" << std::endl << "int: " << input << std::endl << "float: " << input << "f" << std::endl << "double: " << input << std::endl;
	else
	{
		float	temp;
		double	temp2;

		if (c >= 32)
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non Displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		if (modff(f, &temp) != 0)
			std::cout << "float: " << f << "f" << std::endl;
		else
			std::cout << "float: " << f << ".0f" << std::endl;
		if (modf(d, &temp2) != 0)
			std::cout << "double: " << d << std::endl;
		else
			std::cout << "double: " << d << ".0" << std::endl;
	}
}

void	ScalarConverter::isChar(const std::string input, char *c, int *i, float *f, double *d)
{
	*c = static_cast<char>(input.at(0));
	*i = static_cast<int>(input.at(0));
	*f = static_cast<float>(input.at(0));
	*d = static_cast<double>(input.at(0));
}

void	ScalarConverter::isInt(const std::string input, char *c, int *i, float *f, double *d)
{
	*c = static_cast<char>(my_stoi(input));
	*i = static_cast<int>(my_stoi(input));
	*f = static_cast<float>(my_stoi(input));
	*d = static_cast<double>(my_stoi(input));
}

void	ScalarConverter::isFloat(const std::string input, char *c, int *i, float *f, double *d)
{
	*c = static_cast<char>(my_stof(input));
	*i = static_cast<int>(my_stof(input));
	*f = static_cast<float>(my_stof(input));
	*d = static_cast<double>(my_stof(input));
}

void	ScalarConverter::isDouble(const std::string input, char *c, int *i, float *f, double *d)
{
	*c = static_cast<char>(my_stod(input));
	*i = static_cast<int>(my_stod(input));
	*f = static_cast<float>(my_stod(input));
	*d = static_cast<double>(my_stod(input));
}

std::string	ScalarConverter::getType(const std::string input)
{
	if (input == "nan" or input == "-inf" or input == "+inf")
		return ("special");
	else if (input.size() == 1 && input.find_first_of("0123456789") == std::string::npos)
		return ("char");
	else if (input.find_first_not_of("+-0123456789") == std::string::npos)
		return ("int");
	else if (input.find_first_not_of("+-0123456789.") == std::string::npos)
	{
			return ("double");
	}
	else if (input.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
			return ("float");
	}
	else
		return ("error");
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	std::cout << "ScalarConvertor assignement operator called" << std::endl;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConvertor Copy Constructor called" << std::endl;
	*this = copy;
}

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}
