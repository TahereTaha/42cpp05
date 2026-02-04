#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
	private:
	public:
		Intern(void);
		Intern(const Intern & src);
		~Intern(void);
		Intern & operator = (const Intern & src);

		static AForm	*makeForm(std::string form_name, std::string target);
};
