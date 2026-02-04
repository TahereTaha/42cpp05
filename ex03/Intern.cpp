#include "Intern.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

//	canonical orthodox form.
Intern::Intern(void)
{
	std::cout << "Intern default constructor." << std::endl;
}

Intern::Intern(const Intern & src)
{
	std::cout << "Intern copy constructor." << std::endl;
	*this = src;
}

Intern & Intern::operator = (const Intern & src)
{
	std::cout << "Intern copy assigment." << std::endl;
	if (this != &src)
	{
		//	copy all the parameters that they have in comon.
	}
	return (*this);
}

Intern::~Intern(void)
{
//	std::cout << "Intern default destructor." << std::endl;
}

