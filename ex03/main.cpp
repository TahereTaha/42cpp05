/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2026/02/05 00:35:08 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

#include "terminal_colors.h"

int	main(void)
{
	Intern	intern_4132;

	AForm	*form;

	std::cout << "\n" << std::endl;
	form = Intern::makeForm("shrubbery creation", "jose");	
	std::cout << *form << std::endl;
	delete form;
	std::cout << "\n" << std::endl;

	std::cout << "\n" << std::endl;
	form = Intern::makeForm("robotomy request", "jose");	
	std::cout << *form << std::endl;
	delete form;
	std::cout << "\n" << std::endl;

	std::cout << "\n" << std::endl;
	form = Intern::makeForm("presidential pardon", "jose");	
	std::cout << *form << std::endl;
	delete form;
	std::cout << "\n" << std::endl;

	std::cout << "\n" << std::endl;
	form = Intern::makeForm("something", "jose");\
	if (form)
		std::cout << *form << std::endl;
	else 
		std::cout << "makeForm returned NULL." << std::endl;
	delete form;

	
	return (0);
}
