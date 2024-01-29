#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>

class ScalarConverter {
	private:
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter(void);
		ScalarConverter	&operator=(const ScalarConverter &src);
		ScalarConverter(void);

	public:
		static void	convert(const char *input);
		static void	isChar(const std::string input, char *c, int *i, float *f, double *d);
		static void	isInt(const std::string input, char *c, int *i, float *f, double *d);
		static void	isFloat(const std::string input, char *c, int *i, float *f, double *d);
		static void	isDouble(const std::string input, char *c, int *i, float *f, double *d);
		static std::string	getType(const std::string input);

		class InvalidOutput: public std::exception {
			public:
				const char* what(void) const throw();
		};
};

#endif
