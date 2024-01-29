#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cmath>
#include <ctime>

class	Base {

	private:

	protected:

	public:
		virtual ~Base();


};

		Base*		generate(void);
		void		identify(Base* p);
		void		identify(Base& p);


#endif
