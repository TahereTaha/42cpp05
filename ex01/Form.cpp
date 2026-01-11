/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:05 by tatahere          #+#    #+#             */
/*   Updated: 2026/01/11 16:24:46 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

//	form exceptions.
Form::GradeTooLowException::GradeTooLowException(const std::string & msg)
	:std::range_error(msg)
{}

Form::GradeTooHighException::GradeTooHighException(const std::string & msg)
	:std::range_error(msg)
{}

//	canonical orthodox form.
Form::Form(void):
	_name(FORM_DEFAULT_NAME),
	_isSigned(FORM_NOT_SIGNED),
	_gradeToSign(FORM_DEFAULT_GRADE_TO_SIGN),
	_gradeToExecute(FORM_DEFAULT_GRADE_TO_EXECUTE)
{
	std::cout << "form default constructor." << std::endl;
}

Form::Form(const Form & src):
	_name(src._name),
	_isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << "form copy constructor." << std::endl;
}

Form &  Form::operator = (const Form & src)
{
	std::cout << "form copy assigment." << std::endl;
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return  (*this);
}

Form::~Form(void)
{
}

// constructors.
Form::Form(const std::string & name, const int gradeToSign, const int gradeToExecute)
	:_name(name),
	_gradeToSign(gradeToSign), 
	_gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign < FORM_GRADE_HIGHEST)
		throw (Form::GradeTooHighException("grade to sign too high for initialization"));
	if (this->_gradeToSign > FORM_GRADE_LOWEST)
		throw (Form::GradeTooLowException("grade to sign too low for initialization"));

	if (this->_gradeToExecute < FORM_GRADE_HIGHEST)
		throw (Form::GradeTooHighException("grade to execute too high for initialization"));
	if (this->_gradeToExecute > FORM_GRADE_LOWEST)
		throw (Form::GradeTooLowException("grade to execute too low for initialization"));

	this->_isSigned = 0;
}

// geters.
std::string	Form::getName(void) const
{
	return (this->_name);
}

int			Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int			Form::getGradeToSign(void) const 
{
	return (this->_gradeToSign);
}

int			Form::getGradeToExecute(void) const 
{
	return (this->_gradeToExecute);
}

// methods.
void	Form::beSigned(const Bureaucrat & signee)
{
	if (this->_isSigned)
		throw (Form::GradeTooLowException("form alredy signed"));
	if (signee.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException("bureaucrat grade to low for signing this form"));
	this->_isSigned = 1;
}

//	stream insertion operator overloading.
std::ostream & operator << (std::ostream & out_s, const Form & obj)
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

