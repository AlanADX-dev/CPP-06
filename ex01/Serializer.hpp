#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer {

	private:
		Serializer();
		Serializer(const Serializer& src);
		~Serializer();


	protected:

	public:
		Serializer& operator=(const Serializer& copy);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};


#endif
