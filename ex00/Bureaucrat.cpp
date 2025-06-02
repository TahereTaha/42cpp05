/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:23:33 by tatahere          #+#    #+#             */
/*   Updated: 2025/06/02 19:44:29 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

GradeTooLowException::GradeTooLowException(const std::string & msg) :std::range_error(msg)
{}

GradeTooHighException::GradeTooHighException(const std::string & msg) :std::range_error(msg)
{}

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat default constructor." << std::endl;
	this->_name = "no_name";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	std::cout << "Bureaucrat copy constructor." << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & src)
{
	std::cout << "Bureaucrat copy assigment." << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default destructor." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Bureaucrat constructor." << std::endl;
	this->_name = name;
	if (grade < 1)
		throw GradeTooLowException("grade to low for initialization.");
	if (grade > 150)
		throw GradeTooHighException("grade to high for initiaization.");
	this->_grade = grade;
}

std::string	Bureaucrat::getName(void) const
{
	std::cout << "Bureaucrat name geter." << std::endl;
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	std::cout << "Bureaucrat grade geter." << std::endl;
	return (this->_grade);
}

void		Bureaucrat::incrementGrade(void)
{
	std::cout << "Bureaucrat increment grade." << std::endl;
	if (this->_grade >= 150)
		throw GradeTooHighException("unable to increment grade.");
	this->_grade += 1;
}

void		Bureaucrat::decrementGrade(void)
{
	std::cout << "Bureaucrat decrement grade." << std::endl;
	if (this->_grade <= 1)
		throw GradeTooLowException("unable to decrement grade.");
	this->_grade -= 1;
}

std::ostream & operator << (std::ostream & out_s, const Bureaucrat & obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (out_s);
}

