/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:05 by tatahere          #+#    #+#             */
/*   Updated: 2026/01/31 16:17:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

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
	std::cout << "the ShrubberyCreationForm acction. with the name: " << this->getName() << std::endl;
}

