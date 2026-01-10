#include "Form.hpp"
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include <iostream>

Form::GradeTooLowException::GradeTooLowException(const std::string & msg)
	:std::range_error(msg)
{}

Form::GradeTooHighException::GradeTooHighException(const std::string & msg)
	:std::range_error(msg)
{}

Form::Form(void)
	:_name("no_name"), 
	_isSigned(0),
	_gradeToSign(150), 
	_gradeToExecute(150)
{
	std::cout << "form default constructor." << std::endl;
}

Form::Form(const Form & src)
	:_name(src._name), 
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

Form::Form(const std::string & name, const int gradeToSign, const int gradeToExecute)
	:_name(name),
	_gradeToSign(gradeToSign), 
	_gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign < 1)
		throw (Form::GradeTooHighException("grade to sign too high for initialization"));
	if (this->_gradeToSign > 150)
		throw (Form::GradeTooLowException("grade to sign too low for initialization"));
	
	if (this->_gradeToExecute < 1)
		throw (Form::GradeTooHighException("grade to execute too high for initialization"));
	if (this->_gradeToExecute > 150)
		throw (Form::GradeTooLowException("grade to execute too low for initialization"));

	this->_isSigned = 0;
}

Form::~Form(void)
{
}

void	Form::beSigned(const Bureaucrat & signee)
{
	if (this->_isSigned)
		throw (Form::GradeTooLowException("form alredy signed"));
	if (signee.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException("bureaucrat grade to low for signing this form"));
	this->_isSigned = 1;
}
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

std::ostream & operator << (std::ostream & out_s, const Form & obj)
{
	std::cout << "form: <" << obj.getName() << ">\n";

	std::cout << "\tis signed: ";
	if (obj.getIsSigned())
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << "\n";

	std::cout << "\tgrade to sign:    " << obj.getGradeToSign() << "\n";
	std::cout << "\tgrade to execute: " << obj.getGradeToExecute() << std::endl;
	return (out_s);
}

