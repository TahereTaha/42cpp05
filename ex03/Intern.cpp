#include "Intern.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

//
//	some suport definitions.
//
#define FORM_AMOUNT 3

const std::string form_names[FORM_AMOUNT] = { \
	"shrubbery creation", \
	"robotomy request", \
	"presidential pardon" \
};

typedef enum {
	SHRUBERY_CREATION = 0,
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON,
	UNRECOGNIZED_FORM_TYPE,
} form_type;

//	
//	some suport functions
//	

// definition of a array of form creators.
static AForm	*makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

//  the argumnet is the target of the form and the return is the form.
typedef AForm	*(*form_maker)(std::string);

const form_maker	form_makers[FORM_AMOUNT] = { \
	(form_maker) makeShrubberyCreationForm, \
	(form_maker) makeRobotomyRequestForm, \
	(form_maker) makePresidentialPardonForm \
};

// a funcion for identifying the form name.
static form_type identifyFormType(std::string form_name)
{
	int i = 0;
	while (i < FORM_AMOUNT)
	{
		if (!form_name.compare(form_names[i]))
			return ((form_type) i);
		i++;
	}
	return (UNRECOGNIZED_FORM_TYPE);
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	form_type	type = identifyFormType(form_name);
	if (type == UNRECOGNIZED_FORM_TYPE)
	{
		std::cout << "unrecognized form name." << std::endl;
		return (NULL);
	}
	AForm	*form = form_makers[type](target);
	std::cout << "Intern creates " << *form << std::endl;
	return (form);
}

