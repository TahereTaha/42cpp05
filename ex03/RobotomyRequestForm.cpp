/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:05 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/04 20:42:02 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Bureaucrat.hpp"

//	canonical orthodox form.
RobotomyRequestForm::RobotomyRequestForm(void): AForm("robotomy", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src):
	AForm(src)
{
	std::cout << "RobotomyRequestForm copy constructor." << std::endl;
}

RobotomyRequestForm &  RobotomyRequestForm::operator = (const RobotomyRequestForm & src)
{
	std::cout << "RobotomyRequestForm copy assigment." << std::endl;
	if (this != &src)
	{
		dynamic_cast<AForm&>(*this) = src;
	}
	return  (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

// constructors.
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target + "_robotomy", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor." << std::endl;
}

// methods.


static std::string	getTargetStr(std::string str)
{
	std::string	target_str;
	target_str = str.substr(0, str.size() - std::string("_robotomy").size());

	return (target_str);
}

void	RobotomyRequestForm::acction(void) const 
{
	std::cout << "making some drilling noises." << std::endl;

	std::string	target = getTargetStr(this->getName());
	srand(time(NULL));
	if (rand() % 2)
		std::cout << "robotomy on " << target << " succeed." << std::endl;
	else
		std::cout << "robotomy on " << target << " failed." << std::endl;
}

