#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {

	private:

	protected:

	public:
		Data();
		Data(const Data& src);
		~Data();

		Data& operator=(const Data& copy);

		int		value;


};

#endif
