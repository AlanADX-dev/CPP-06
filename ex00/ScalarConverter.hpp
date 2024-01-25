#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter(std::string& literal);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

	protected:

	public:
		static void		convert(std::string& literal);

		static char		convToChar(std::string& literal);
		static int		convToInt(std::string& literal);
		static float	convToFloat(std::string& literal);
		static double	convToDouble(std::string& literal);

};



#endif
