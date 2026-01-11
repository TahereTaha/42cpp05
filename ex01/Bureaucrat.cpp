/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:23:33 by tatahere          #+#    #+#             */
/*   Updated: 2026/01/10 18:04:08 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

//	bureaucrat exceptions.
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string & msg)
	:std::range_error(msg)
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string & msg)
	:std::range_error(msg)
{}

//	canonical orthodox form.
Bureaucrat::Bureaucrat(void) :
	_name(BUREAUCRAT_DEFAULT_NAME),
	_grade(BUREAUCRAT_DEFAULT_GRADE)
{
	std::cout << "Bureaucrat default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src): _name(src._name)
{
	std::cout << "Bureaucrat copy constructor." << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & src)
{
	std::cout << "Bureaucrat copy assigment." << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default destructor." << std::endl;
}

//	constructors.
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor." << std::endl;
	if (grade < BUREAUCRAT_GRADE_HIGHEST)
		throw Bureaucrat::GradeTooHighException("grade to high for initiaization");
	if (grade > BUREAUCRAT_GRADE_LOWEST)
		throw Bureaucrat::GradeTooLowException("grade to low for initialization");
	this->_grade = grade;
}

//	geters.
std::string	Bureaucrat::getName(void) const
{
//	std::cout << "Bureaucrat name geter." << std::endl;
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
//	std::cout << "Bureaucrat grade geter." << std::endl;
	return (this->_grade);
}

//	methods.
void		Bureaucrat::decrementGrade(void)
{
	std::cout << "Bureaucrat decrement grade." << std::endl;
	if (this->_grade >= BUREAUCRAT_GRADE_LOWEST)
		throw Bureaucrat::GradeTooLowException("unable to decrement grade");
	this->_grade += 1;
}

void		Bureaucrat::incrementGrade(void)
{
	std::cout << "Bureaucrat increment grade." << std::endl;
	if (this->_grade <= BUREAUCRAT_GRADE_HIGHEST)
		throw Bureaucrat::GradeTooHighException("unable to increment grade");
	this->_grade -= 1;
}

//	stream insertion operator overloading.
std::ostream & operator << (std::ostream & out_s, const Bureaucrat & obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (out_s);
}

