#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*		generate(void)
{
	std::srand(std::time(0));

	int randNum = (rand() % 3) + 1;

	if (randNum == 1)
		return new A;
	else if (randNum == 2)
		return new B;
	else if (randNum == 3)
		return new C;
	else
		return NULL;

}
void		identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "Unknown type" << std::endl;
	}

}


int			main()
{
	Base*  basePtr = generate();

	identify(*basePtr);
	identify(basePtr);

	delete basePtr;

	return 0;
}
