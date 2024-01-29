#include "Serializer.hpp"
#include "Data.hpp"

int		main()
{
	Data	dataObj;
	dataObj.value = 42;

	uintptr_t serialized = Serializer::serialize(&dataObj);

	Data* deserialized = Serializer::deserialize(serialized);

	// Check if the deserialized pointer is equal to the original pointer
	if (deserialized == &dataObj)
	{
		std::cout << "Serialization and deserialization successful!" << std::endl;
		std::cout << deserialized << std::endl;
		std::cout << &dataObj << std::endl;
	}
	else
	{
		std::cout << "Serialization and deserialization failed!" << std::endl;
		std::cout << deserialized << std::endl;
		std::cout << &dataObj << std::endl;
	}
	return 0;
}
