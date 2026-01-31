/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:05 by tatahere          #+#    #+#             */
/*   Updated: 2026/01/31 17:03:38 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

//	form exceptions.
AForm::GradeTooLowException::GradeTooLowException(const std::string & msg)
	:std::range_error(msg)
{}

AForm::GradeTooHighException::GradeTooHighException(const std::string & msg)
	:std::range_error(msg)
{}

//	canonical orthodox form.
AForm::AForm(void):
	_name(FORM_DEFAULT_NAME),
	_isSigned(FORM_NOT_SIGNED),
	_gradeToSign(FORM_DEFAULT_GRADE_TO_SIGN),
	_gradeToExecute(FORM_DEFAULT_GRADE_TO_EXECUTE)
{
	std::cout << "form default constructor." << std::endl;
}

AForm::AForm(const AForm & src):
	_name(src._name),
	_isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << "form copy constructor." << std::endl;
}

AForm &  AForm::operator = (const AForm & src)
{
	std::cout << "form copy assigment." << std::endl;
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return  (*this);
}

AForm::~AForm(void)
{
}

// constructors.
AForm::AForm(const std::string & name, const int gradeToSign, const int gradeToExecute)
	:_name(name),
	_gradeToSign(gradeToSign), 
	_gradeToExecute(gradeToExecute)
{
	std::cout << "AForm constructor." << std::endl;
	if (this->_gradeToSign < FORM_GRADE_HIGHEST)
		throw (AForm::GradeTooHighException("grade to sign too high for initialization"));
	if (this->_gradeToSign > FORM_GRADE_LOWEST)
		throw (AForm::GradeTooLowException("grade to sign too low for initialization"));

	if (this->_gradeToExecute < FORM_GRADE_HIGHEST)
		throw (AForm::GradeTooHighException("grade to execute too high for initialization"));
	if (this->_gradeToExecute > FORM_GRADE_LOWEST)
		throw (AForm::GradeTooLowException("grade to execute too low for initialization"));

	this->_isSigned = 0;
}

// geters.
std::string	AForm::getName(void) const
{
	return (this->_name);
}

int			AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int			AForm::getGradeToSign(void) const 
{
	return (this->_gradeToSign);
}

int			AForm::getGradeToExecute(void) const 
{
	return (this->_gradeToExecute);
}

// methods.
void	AForm::beSigned(const Bureaucrat & signee)
{
	if (this->_isSigned)
		throw (std::logic_error("form alredy signed"));
	if (signee.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException("bureaucrat grade to low for signing this form"));
	this->_isSigned = 1;
}

void	AForm::execute(const Bureaucrat &executor) const 
{
	if (!this->getIsSigned())
		throw (std::logic_error("form not signed yet"));
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException("bureaucrat grade to low for executing this form"));
	this->acction();
}

//	stream insertion operator overloading.
std::ostream & operator << (std::ostream & out_s, const AForm & obj)
{
	//	form name.
	std::cout << obj.getName() << ", " ;
	//	signed status.
	std::cout << "is ";
	if (!obj.getIsSigned())
		std::cout << "not ";
	std::cout << "signed, ";
	//	grade to sign.
	std::cout << "grade to sign: " << obj.getGradeToSign() << ", ";
	//	grade to execute.
	std::cout << "grade to execute: " << obj.getGradeToExecute() << " ";
	return (out_s);
}

