/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:05 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/04 19:49:24 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

#include "Bureaucrat.hpp"

//	canonical orthodox form.
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("shrubery", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src):
	AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor." << std::endl;
}

ShrubberyCreationForm &  ShrubberyCreationForm::operator = (const ShrubberyCreationForm & src)
{
	std::cout << "ShrubberyCreationForm copy assigment." << std::endl;
	if (this != &src)
	{
		dynamic_cast<AForm&>(*this) = src;
	}
	return  (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

// constructors.
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target + "_shrubery", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor." << std::endl;
}

// methods.


void	ShrubberyCreationForm::acction(void) const 
{
	std::fstream	fs;
	fs.open(("./" + this->getName()).c_str(), std::fstream::out | std::fstream::trunc);

	fs	<< "       _-_\n"
		<< "    /~~   ~~\\\n"
		<< " /~~         ~~\\\n"
		<< "{               }\n"
		<< " \\  _-     -_  /\n"
		<< "   ~  \\\\ //  ~\n"
		<< "_- -   | | _- _\n"
		<< "  _ -  | |   -_\n"
		<< "      // \\\\\n" << std::endl;

	fs	<< "       _-_\n"
		<< "    /~~   ~~\\\n"
		<< " /~~         ~~\\\n"
		<< "{               }\n"
		<< " \\  _-     -_  /\n"
		<< "   ~  \\\\ //  ~\n"
		<< "_- -   | | _- _\n"
		<< "  _ -  | |   -_\n"
		<< "      // \\\\\n" << std::endl;

	fs	<< "       _-_\n"
		<< "    /~~   ~~\\\n"
		<< " /~~         ~~\\\n"
		<< "{               }\n"
		<< " \\  _-     -_  /\n"
		<< "   ~  \\\\ //  ~\n"
		<< "_- -   | | _- _\n"
		<< "  _ -  | |   -_\n"
		<< "      // \\\\\n" << std::endl;

	fs.close();

	std::cout << "the ShrubberyCreationForm created the file: " << this->getName() << std::endl;
}

