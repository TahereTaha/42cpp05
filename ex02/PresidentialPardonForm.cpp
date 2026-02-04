/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:05 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/04 20:49:43 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Bureaucrat.hpp"

//	canonical orthodox form.
PresidentialPardonForm::PresidentialPardonForm(void): AForm("pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src):
	AForm(src)
{
	std::cout << "PresidentialPardonForm copy constructor." << std::endl;
}

PresidentialPardonForm &  PresidentialPardonForm::operator = (const PresidentialPardonForm & src)
{
	std::cout << "PresidentialPardonForm copy assigment." << std::endl;
	if (this != &src)
	{
		dynamic_cast<AForm&>(*this) = src;
	}
	return  (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

// constructors.
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm(target + "_pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor." << std::endl;
}

// methods.


static std::string	getTargetStr(std::string str)
{
	std::string	target_str;
	target_str = str.substr(0, str.size() - std::string("_pardon").size());

	return (target_str);
}

void	PresidentialPardonForm::acction(void) const 
{
	std::string	target = getTargetStr(this->getName());
	std::cout << target << " has ben pardoned." << std::endl;
}

